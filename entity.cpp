#include "overlay.h"
#include "xorstr.h"
#include "memmane.h"
#include "SDK.h"
#include "hotkeys.h"
#include <thread>
#include <map>
#include <iosfwd>
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <DirectXMath.h>
#include "GLFW/glfw3.h"


#define UENGINE __stdcall
float INSVeh[] = { 255, 0, 255, 255.f };
float INSVeh1[] = { 255, 122, 31, 255.f };
float INSVeh2[] = { 255, 0, 0, 255.f };
float BRTVeh[] = { 233, 255, 0, 255.f };
float RUSVeh[] = { 255, 0, 255, 255.f };
float FOVRADIO[] = { 0, 255, 255, 255.f };
float HAB[] = { 0, 0, 255, 255.f };
float ammocratee[] = { 0, 0, 255, 255.f };
float RUSVeh1[] = { 255, 0, 255, 255.f };
float RUSVeh11[] = { 0, 0, 255, 255.f };
float SkeletCollor[] = { 0, 0, 0, 255.f };
float SkeletCollorvisible[] = { 0, 0, 0, 255.f };
float FOVCOLORR[] = { 0, 0, 0, 255.f };
float USAVeh[] = { 0, 0, 0, 255.f };
float MEAVeh[] = { 0, 0, 0, 255.f };
float TesTESP[] = { 255, 255, 255, 255.f };
std::vector<player_t> entities = {};
std::vector<item_t> items = {};
bool qualidade;
int boneidddd = 0;
bool inventoryesp = 0;
bool LootTeleport = 0;
bool SilentAim;
int isnpc = 0;
bool Cargoesp = 0;
bool ToggleFov = 1;
bool ToggleCross = 1;
bool Filtrarlloot = 0;
const int MaxTextLength = 255;
bool uppercaseMode = false;  // Variável de controle

char NamesFilter[MaxTextLength + 1] = "";  // +1 for the null terminator
bool showplayerSlaplines;

int LimiteDoSilent = 1500;
float aimfov = 100;
float fovcross = 2;
bool inventoryespfull = 0;

std::vector<uintptr_t*> valid_players;
std::vector<uintptr_t*> valid_players1;
std::vector<uintptr_t*> valid_players2;
uintptr_t* resultant_target_entity = nullptr;
bool inventoryespcaixa;

int bonechoose = 0;


void init1()
{
	globals.process_id = FindProcessID("DayZ_x64.exe");
	globals.handle = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION, FALSE, globals.process_id);

	globals.Base = GetModule("DayZ_x64.exe");
	globals.World = mem1->RVM<uint64_t>(globals.Base + OFF_WORLD);
	// CreateThread(0, 0, (LPTHREAD_START_ROUTINE)update_list, 0, 0, 0);

	//std::thread(update_list).detach();
}

bool comida;
bool Containers;
bool BackPack;
bool comida1;
bool medicine;
bool medicine1;
bool drinks;
bool drinks1;
bool clothing;
bool clothing1;
bool inventoryItem;
bool inventoryItemsss;
bool misc;
bool recoil_modify;
bool recoil_modify1;
bool sight_zoom;
bool field_of_view_modify;
bool rapid_fire;
bool unlimited_ammo;
bool speed_multiplier;
float speed_multipler_value = 1.f;
float recoil_value;
float zoom_value;
float fov_value_modify;
float spread_value;
bool sway_modify;
bool unlimitedammo;
bool Norecoil;
float sway_value;
bool debug_camera;
bool debug_mode;
bool othervehicles;
int bone_limiter;
bool climb_walls;
bool no_fall;
bool auto_weapons;
bool third_person;
bool fast_bullet;
bool thick_bullet;
bool no_range;
bool no_spread;
bool high_step;
bool no_gravity;
bool unlock_shoot_restriction;
int aim_Key;
int selected_item_key;
int selected_item_bone;
float font_size = 16.f;
int bone_choice;
bool norecoil;
bool norecoil2;
bool toogle_2dbox; bool showplayer = 1;
bool Skelet1Player = 1;
bool esp_player_team = 1;

bool cornervis, cornernotvis;
void update_list()
{
	while (true)
	{
		HMODULE hModule = LoadLibrary("BEClient_x64.dll");

		//if (hModule){
	///		FreeLibraryAndExitThread(hModule, 0);
		//	}

		if (hModule)
			FreeLibrary(hModule);



		Sleep(1000);
	}
}

class USQAnimInstanceSoldier1P1
{
public:
	void UENGINE RecoilCameraOffsetFactor(int zoom)
	{
		*(int*)(this) = zoom;

	}

};
class USQAnimInstanceSoldier1P
{
public:

};
bool IsValidPtr(void* pointer)
{
	if (!pointer)
		return false;

	if (pointer < (void*)0xFFFF)
		return false;

	if (pointer > (void*)0x7FFFFFFFFFFF)
		return false;

	return true;
}

bool City_Esp1,
City_Esp2,
City_Esp3,
City_Esp4,
City_Esp5,
City_Esp6,
City_Esp7,
City_Esp8,
City_Esp9,
City_Esp10,
City_Esp11,
City_Esp12,
City_Esp13,
City_Esp14,
City_Esp15,
City_Esp16,
City_Esp17,
City_Esp18,
City_Esp19,
City_Esp20,
City_Esp21,
City_Esp22,
City_Esp23,
City_Esp24,
City_Esp25,
City_Esp26,
City_Esp27,
City_Esp28;
bool twaeawe;
bool twaeawe1;
bool awaysday;
float horas;
bool City_Esp;
bool Iemtelist = 0;



float  maxplayer = 10000, maxzombie = 10000, maxanimal = 10000, maxcar = 10000, maxloot = 100000;
struct nameid
{
	UINT64 pt1;
	UINT64 pt2;
};
std::map<UINT64, std::string> nameCache;
std::string getNameFromId(uintptr_t namePointer)
{
	nameid ID = mem1->RVM<nameid>(namePointer + 0x10);

	std::map<UINT64, std::string>::iterator it = nameCache.find(ID.pt1 + ID.pt2);

	if (it == nameCache.end())
	{

		int size = mem1->RVM<int>(namePointer + 0x8);
		if (size < 1)
			return "";
		char* name = new char[size];
		ZwCopyMemory(namePointer + 0x10, name, size, false);

		if (strstr(name, xorstr_("Animal")) != NULL || strstr(name, xorstr_("Zmb")) != NULL || strstr(name, xorstr_("Firewood")) != NULL || strstr(name, xorstr_("Barrel")) || strstr(name, xorstr_("Watchtower")) || strstr(name, xorstr_("Wood Pillar")) || strstr(name, xorstr_("Roof")) || strstr(name, xorstr_("Wall")) != NULL || strstr(name, xorstr_("Floor")) || strstr(name, xorstr_("Fireplace")) != NULL || strstr(name, xorstr_("Wire Mesh Barrier")) != NULL || strstr(name, xorstr_("Fence")) != NULL)
		{
			std::string text = "";
			nameCache.insert(std::pair<UINT64, std::string>(ID.pt1 + ID.pt2, text));
			delete name;
			return text;
		}

		std::string text = std::string(name);
		delete name;
		nameCache.insert(std::pair<UINT64, std::string>(ID.pt1 + ID.pt2, text));
		return text;
	}
	else
	{
		return it->second;
	}
}
ImU32 ColoroU32(uint64_t Entity)
{



	auto quality = mem1->RVM<int>(Entity + 0x180);

	if (quality == 1) {

		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(196, 201, 34, 255));
		return colorweapon;

	}
	if (quality == 2) {

		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(247, 95, 0, 255));
		return colorweapon;
	}
	if (quality == 3) {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(252, 185, 0, 255));
		return colorweapon;
	}
	if (quality == 4) {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 0, 255));
		return colorweapon;
	}
	else {
		ImU32 colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
		return colorweapon;

	}
	return	ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
}
bool weapon;
bool weaponToggle;
int weaponkey;
bool ProxyMagazines;
bool ProxyMagazines1;
bool Miras;
bool rodas;
bool inventoryItem12 = 0;
bool inventoryItem132 = 0;
bool inventoryItem2 = 0;
bool inventoryItem22 = 1;

bool inventoryItem222 = 1;
bool inventoryItem2222 = 1;
bool inventoryItem22221 = 1;
std::string get_quality(uint64_t Entity)
{
	auto quality = mem1->RVM<int>(Entity + 0x180);

	if (quality == 1) return xorstr_("Worn");
	else if (quality == 2) return xorstr_("Damaged");
	else if (quality == 3) return xorstr_("Badly Damaged");
	else if (quality == 4) return xorstr_("Ruined");

	else return xorstr_("Pristine");
}

bool Skelet1Zombie;
bool showzombie;
bool showzombie1;
bool showAnimal;
bool car;
bool debugged;
bool debugg;
bool debugg2, debugg3, debugg4, debugg5;
bool MEAVehicles;
bool BRTVehicles;
bool MILVehicles;
bool RUSVehicles;
bool INSVehicles;
bool USAVehicles;

//int num1 = 22, num2 = 21, num3 = 21, num4 = 61, num5 = 61, num6 = 63, num7 = 63, num8 = 65, num9 = 21, num10 = 94, num11 = 94, num12 = 97, num13 = 97, num14 = 99, num15 = 15, num16 = 9;
//int num17 = 0, num18 = 0,num19 = 0, num20 = 0, num21 = 0, num22 = 0, num23= 0, num24 = 0, num25 = 0, num26 = 0, num27 = 0, num28 = 0, num29 = 0;

int num1 = 24;
int num2 = 21;
int num3 = 21;
int num4 = 61;
int num5 = 61;
int num6 = 63;
int num7 = 63;
int num8 = 65;
int num9 = 21;
int num10 = 94;
int num11 = 94;
int num12 = 97;
int num13 = 97;
int num14 = 99;
int num15 = 21;
int num16 = 18;
int num17 = 18;
int num18 = 1;
int num19 = 1;
int num20 = 4;
int num21 = 4;
int num22 = 6;
int num23 = 18;
int num24 = 9;
int num25 = 9;
int num26 = 11;
int num27 = 11;
int num28 = 14;
void DrawBoxFilledmod(const DirectX::XMFLOAT2& from, const DirectX::XMFLOAT2& size, DirectX::XMFLOAT4 color, float rounding)
{
	auto* window = ImGui::GetOverlayDrawList();

	window->AddRectFilled(ImVec2(from.x, from.y), ImVec2(size.x, size.y), ImGui::GetColorU32(ImVec4(color.x / 255, color.y / 255, color.z / 255, color.w / 255)), rounding, ImDrawCornerFlags_All);
}

void DrawInventoryList(std::vector<std::string> item, std::string name_str, DirectX::XMFLOAT2 screen_resolution, DirectX::XMFLOAT4 tag_color)
{
	/* Gray Frame Background */

	auto y_ = screen_resolution.y / 4.f;
	auto x_ = screen_resolution.x / 6.f;
	auto x__ = screen_resolution.x - x_;
	auto x__x = x__ + 200.f;
	auto mid_point = (x__x - x__) / 2;
	auto list_size = item.size() * 25.f;
	ImVec2 textSize = ImGui::CalcTextSize(name_str.c_str(), 0, false, -1.0f);
	auto x_text_ = textSize.x / 2;

	float totat_y_text_size = textSize.y + textSize.y + textSize.y + textSize.y;
	for (const auto& name_size : item)
	{
		ImVec2 textSizeitem = ImGui::CalcTextSize(name_size.c_str(), 0, false, -1.0f);
		totat_y_text_size += textSizeitem.y + 10;
	}

	DrawBoxFilledmod({ x__, y_ }, { x__x, y_ + totat_y_text_size }, { 0.f, 0.f, 0.f, 120.f }, 2.8f);

	/* Color Tag */
	DrawBoxFilledmod({ x__, y_ }, { x__x, y_ + 5.f }, tag_color, 2.8f);

	/* Name */
	//ImGuiWindow* window = ImGui::GetCurrentWindow();
	auto* window = ImGui::GetOverlayDrawList();

	window->AddText({ x__x - mid_point - x_text_, y_ + textSize.y + textSize.y }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name_str.c_str());

	float decrement = textSize.y + textSize.y + textSize.y + textSize.y + textSize.y;

	for (const auto& name : item)
	{
		ImVec2 textSizeitem = ImGui::CalcTextSize(name.c_str(), 0, false, -1.0f);
		auto x_text_item = textSizeitem.x / 2;
		window->AddText({ x__x - mid_point - x_text_item, y_ + decrement }, ImGui::GetColorU32({ 255.f / tag_color.x, 255.f / tag_color.y, 255.f / tag_color.z, 255.f / tag_color.w }), name.c_str());
		decrement += textSizeitem.y;

	}
}

void DrawSkeleton(uintptr_t Entity, ImVec4 color, int s2)
{

	if (s2 == 1)
		num1 = 24;
	if (s2 == 2)
		num1 = 0;

	int vBone[][4] =
	{
		{ num1 ,num2 },{ num3 , num4 },{num5 , num6 },{num7 , num8},
		{ num9 , num10 },{ num11 ,num12 },{ num13 , num14 },{num15 , num16 },
		{ num17 , num18 },{ num19 ,num20 },{ num21 , num22 },{num23 , num24 },
		{ num25 , num26 },{ num27 ,num28 }
	};




	auto* window = ImGui::GetOverlayDrawList();

	for (auto part : vBone)
	{
		Vector3 previous = Vector3(0, 0, 0);
		for (int i = 0; i < 4; i++)
		{
			if (!part[i]) break;

			Vector3 current;//= ValSDK::valorant::GetBoneWithRotation(Mesh, part[i]);
			int s3 = s2;
			Game::GetBonePosition(Game::GetSkeleton(Entity, s3), Game::GeVisualState(Entity), part[i], &current);
			if (previous.x == 0.f)
			{
				previous = current;
				continue;
			}
			Vector3 p1, c1 = Vector3(0, 0, 0);

			if (!Game::WorldToScreen(previous, p1))
				continue;
			if (!Game::WorldToScreen(current, c1))
				continue;
			window->AddLine({ p1.x, p1.y }, { c1.x, c1.y }, ImGui::GetColorU32(color), 0.5f);

			previous = current;
		}
	}
}
std::string get_player_name(uint64_t entity) {
	std::string playerName = "IA";

	uint64_t network_client = mem1->RVM<uint64_t>(globals.Base + OFF_NETWORK_MANAGER + OFF_NETWROK_CLIENT);
	if (!IsValidPtr((void*)network_client))
		return playerName;

	uint32_t entity_network_id = mem1->RVM<uint32_t>(entity + OFF_NETWORK_ID);
	if (entity_network_id < 1)
		return playerName;
	uint64_t scoreboard = mem1->RVM<uint64_t>(network_client + OFF_NETWORK_SCOREBOARD);

	uint32_t scoreboard_size = mem1->RVM<uint32_t>(network_client + OFF_NETWORK_SCOREBOARD_SIZE);
	if (scoreboard_size < 1)
		return playerName;



	for (uint32_t i = 0; i < scoreboard_size; i++) {
		uint64_t current_identity = mem1->RVM<uint64_t>(scoreboard + (i * sizeof(uint64_t)));
		if (!IsValidPtr((void*)current_identity))
			return xorstr_("Dead");
		uint32_t current_id = mem1->RVM<uint32_t>(current_identity + OFF_NETWORK_SCOREBOARD_ID);

		if (current_id == entity_network_id)
		{
			uint64_t namePtr = mem1->RVM<uint64_t>(current_identity + OFF_NETWORK_SCOREBOARD_NAME);
			playerName = ReadArmaString(namePtr);
			return playerName;
		}
	}

	return playerName;
}

int desynckey;
int LootKey = VK_F3;
int LootTP = VK_F6;



float sqrtf1(float _X
) {
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(_X)));
}

uintptr_t* get_closest_Item(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);


		Game::WorldToScreen(Pos, currentworld);
		auto dx = currentworld.x - (io.DisplaySize.x / 2);

		auto dy = currentworld.y - (io.DisplaySize.y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}


	}

	return resultant_target_entity_temp;
}
uintptr_t* get_closest_Item1(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);

		Game::WorldToScreen(Pos, currentworld);
		auto dx = currentworld.x - (io.DisplaySize.x / 2);

		auto dy = currentworld.y - (io.DisplaySize.y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}


	}

	return resultant_target_entity_temp;
}
uintptr_t* get_closest_Item2(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;

	for (auto curr_entity : list)
	{


		Vector3 currentworld;

		Vector3 Pos = Game::GetObjectVisualState((uintptr_t)curr_entity);

		Game::WorldToScreen(Pos, currentworld);


		float pythag_result = sqrtf(pow((((float)io.DisplaySize.x / 2) - currentworld.x), 2) + pow((((float)io.DisplaySize.y / 2) - currentworld.y), 2));

		auto closest_fov = aimfov;


		if (pythag_result <  aimfov && closest_fov > pythag_result)
		{


			resultant_target_entity_temp = curr_entity;
			closest_fov = pythag_result;

		}


	}

	return resultant_target_entity_temp;
}


uintptr_t* get_closest_player(std::vector<uintptr_t*> list, float field_of_view)
{
	ImGuiIO& io = ImGui::GetIO();

	uintptr_t* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;

	for (auto curr_entity : list)
	{

		uint64_t Skeleton = mem1->RVM<uint64_t>((uint64_t)curr_entity + OFF_skeletonPlayer);


		if (!IsValidPtr((void*)Skeleton))
			continue;

		Vector3 current;
		Vector3 currentworld;


		Game::GetBonePosition(Skeleton, Game::GeVisualState((uint64_t)curr_entity), 18, &current);


		Game::WorldToScreen(current, currentworld);
		auto dx = currentworld.x - (io.DisplaySize.x / 2);

		auto dy = currentworld.y - (io.DisplaySize.y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);

		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}
	}

	return resultant_target_entity_temp;
}

void SilentAim1(uint64_t Entity, int ss)
{
	auto* window = ImGui::GetOverlayDrawList();
	ImGuiIO& io = ImGui::GetIO();

	if (!Entity)
		return;



	int index = 0;


	if (bonechoose == 0)
		index = 24;

	if (bonechoose == 1)
		index = 31;

	if (bonechoose == 2)
		index = 17;

	if (bonechoose == 3)
		index = 15;

	if (bonechoose == 4)
		index = 5;

	if (bonechoose == 5)
		index = 14;




	if (ss == 2)
		index = 15;


	Vector3 worldPosition = Game::GetCoordinate((uintptr_t)resultant_target_entity);

	Vector3 outPos;


	Vector3 Pos = Game::GetObjectVisualState((uintptr_t)resultant_target_entity);


	int distance = Game::GetDistanceToMe(worldPosition);

	Game::WorldToScreen(Pos, outPos);


	uintptr_t	Skeleton = mem1->RVM<uint64_t>((uint64_t)Entity + OFF_skeletonPlayer);



	Vector3 current;
	Vector3 currentworld;


	Game::GetBonePosition(Skeleton, Game::GeVisualState((uint64_t)resultant_target_entity), index, &current);


	Game::WorldToScreen(current, currentworld);

	window->AddLine(ImVec2{ (float)io.DisplaySize.x / 2, (float)io.DisplaySize.y / 2 }, ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 0, 255)), 1.5f);

	const auto pUWorld = *reinterpret_cast<USQAnimInstanceSoldier1P**>(globals.Base + OFF_WORLD);
	if (!IsValidPtr((void*)pUWorld))
		return;


	uintptr_t entityTable = mem1->RVM<uintptr_t>((uintptr_t)pUWorld + OFF_BULLET);
	if (!IsValidPtr((void*)entityTable))
		return;

	int objectTableSz = mem1->RVM<int>((uintptr_t)pUWorld + OFF_BULLETSIZE);
	if (objectTableSz < 1)
		return;
	//TransData transData = world.GetTransData();
	for (uint64_t i = NULL; i < objectTableSz; i++)
	{
		if (!entityTable)
			continue;

		uint64_t entity = mem1->RVM<uint64_t>(entityTable + (i * 0x8));
		if (!IsValidPtr((void*)entity))
			continue;




		if (SilentAim)
			Game::SetPosition(entity, current);




	}



}

inline void __stdcall main_aimboo2(int ss)
{
	auto* window = ImGui::GetOverlayDrawList();
	ImGuiIO& io = ImGui::GetIO();

	if (!GetAsyncKeyState(desynckey))
		resultant_target_entity = nullptr;

	if (GetAsyncKeyState(desynckey))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(valid_players, aimfov);
		if (!resultant_target_entity)
			return;

		Vector3 worldPosition = Game::GetCoordinate((uint64_t)resultant_target_entity);

		int dist = Game::GetDistanceToMe(worldPosition);


		//	if (dist > LimiteDoSilent) {

				//resultant_target_entity = nullptr;
				//return;
			//}
		//	Vector3 currentworld;

		//	Game::WorldToScreen(worldPosition, currentworld);	

			//window->AddLine(ImVec2{ (float)io.DisplaySize.x / 2, (float)io.DisplaySize.y }, ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 0, 255)), 1.5f);

	//	SilentAim1((uintptr_t)resultant_target_entity, ss);






	}


}


void lootteleport() {

	ImGuiIO& io = ImGui::GetIO();
	auto* window = ImGui::GetOverlayDrawList();

	uint64_t ff = (uint64_t)get_closest_Item1(valid_players2, aimfov);
	if (!ff)
		return;
	Vector3 currentworld;

	Vector3 Pos = Game::GetObjectVisualState(ff);


	Game::WorldToScreen(Pos, currentworld);

	window->AddLine(ImVec2{ (float)io.DisplaySize.x / 2, (float)io.DisplaySize.y / 2 }, ImVec2{ currentworld.x, currentworld.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255)));




	if (GetAsyncKeyState(LootTP))
	{
		auto MyPlayer = Game::GetLocalPlayer();
		if (!IsValidPtr((void*)MyPlayer))
			return;
		Vector3 worldPosition2 = Game::GetCoordinate(MyPlayer);

		Game::SetPosition(ff, worldPosition2);

	}
}


void IterateAll(uintptr_t worldptr, uintptr_t offset)
{
	auto* window = ImGui::GetOverlayDrawList();
	ImGuiIO& io = ImGui::GetIO();

	auto color = ImGui::ColorConvertFloat4ToU32(ImVec4(RUSVeh11[0], RUSVeh11[1], RUSVeh11[2], RUSVeh11[3]));
	auto color1 = ImGui::ColorConvertFloat4ToU32(ImVec4(BRTVeh[0], BRTVeh[1], BRTVeh[2], BRTVeh[3]));
	auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(RUSVeh[0], RUSVeh[1], RUSVeh[2], RUSVeh[3]));
	auto color3 = ImGui::ColorConvertFloat4ToU32(ImVec4(FOVRADIO[0], FOVRADIO[1], FOVRADIO[2], FOVRADIO[3]));
	auto color4 = ImGui::ColorConvertFloat4ToU32(ImVec4(HAB[0], HAB[1], HAB[2], HAB[3]));

	int objectTableSz = mem1->RVM<int>(worldptr + offset + 0x8);

	if (objectTableSz < 1)
		return;


	std::stringstream all{};
	uintptr_t entityTable = mem1->RVM<uintptr_t>(worldptr + offset);
	if (!IsValidPtr((void*)entityTable))
		return;
	Vector3 outPos;

	std::map<std::pair<float, float>, bool> textPositions;

	for (size_t i = 0; i < objectTableSz; i++)
	{
		if (!entityTable)
			continue;
		uint64_t entity = mem1->RVM<uint64_t>(entityTable + i * 0x8);

		if (!IsValidPtr((void*)entity))
			continue;

		if (entity)
		{


			Vector3 worldPosition = Game::GetCoordinate(entity);



			Vector3 Pos = Game::GetObjectVisualState(entity);


			int distance = Game::GetDistanceToMe(worldPosition);

			if (!Game::WorldToScreen(Pos, outPos))
				continue;

			int dist = Game::GetDistanceToMe(worldPosition);




			uintptr_t objectBase = mem1->RVM<uintptr_t>(entity + 0x180);

			if (!IsValidPtr((void*)objectBase))
				continue;

			uintptr_t cleanNamePtr = mem1->RVM<uintptr_t>(objectBase + 0x4E8);

			if (!IsValidPtr((void*)cleanNamePtr))
				continue;



			std::string text = getNameFromId(cleanNamePtr);
			if (text.empty()) continue;

			std::stringstream all;
			all << text;
			all << " " << dist;
			auto get = (xorstr_("[ ") + std::to_string(dist) + xorstr_("]"));
			auto get1 = text;
			auto get2 = get1 + get;
			auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(INSVeh2[0], INSVeh2[1], INSVeh2[2], INSVeh2[3]));


			if (showzombie) {
				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzinfected")) {


					if (distance > maxzombie)
						continue;

					isnpc = 2;
					valid_players.push_back((uintptr_t*)entity);
					valid_players2.push_back((uintptr_t*)entity);

					if (Skelet1Zombie)
						DrawSkeleton(entity, { 0,0,0,255 }, 2);

					Vector3 outPoszombie;

					if (!Game::WorldToScreen(Pos, outPoszombie))
						continue;

					window->AddText(ImVec2(outPoszombie.x, outPoszombie.y), color2, (std::to_string(distance)).c_str());

				}
			}
			if (showplayer) {

				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzplayer")) {
					if (distance > maxplayer)
						continue;


					if (distance < 2)
						continue;
					valid_players.push_back((uintptr_t*)entity);

					Vector3 outPosplayer;

					if (!Game::WorldToScreen(Pos, outPosplayer))
						continue;

					//	auto entityt = GetNetworkId(entity);
					// 
					//	if (!entityt)

					if (esp_player_team) {
						window->AddText(ImVec2(outPosplayer.x, outPosplayer.y), color1, ("  " + get_player_name(entity) + "  [ " + std::to_string(distance) + "  ]").c_str());


					}
					else {
						//		continue;
						ImVec2 textPosition(outPosplayer.x, outPosplayer.y);

						// Verificar e ajustar se a posição já está ocupada por outro texto
						while (textPositions[std::make_pair(textPosition.x, textPosition.y)]) {
							textPosition.y += 20.0f; // Ajuste conforme necessário para a separação
						}

						// Marcar a posição atual como ocupada
						textPositions[std::make_pair(textPosition.x, textPosition.y)] = true;

						// Desenhar a entidade...
						// Adicionar texto na posição ajustada
						//window->AddText(textPosition, color1, (" 123123 s" + std::to_string(distance) + "  ").c_str());
						window->AddText(textPosition, color1, ("  " + get_player_name(entity) + "  [ " + std::to_string(distance) + "  ]").c_str());

						//window->AddText(ImVec2(outPos.x, outPos.y + yOffset), color1, (" " +  std::to_string(distance) + "  ").c_str());

					}
					//	window->AddText(ImVec2(outPos.x, outPos.y+15), color, ("" + GetPlayerNameByID(entity) + "[  " + std::to_string(distance) + "  ]").c_str());

					if (showplayerSlaplines)
						window->AddLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y), ImVec2(outPos.x, outPos.y), color1);


					valid_players.push_back((uintptr_t*)entity);
					valid_players1.push_back((uintptr_t*)entity);

					if (Skelet1Player)
						DrawSkeleton(entity, { 255,0,0,255 }, 1);




				}
			}

			if (showAnimal) {

				if (Game::GetEntityTypeName2(entity) == xorstr_("dayzanimal")) {

					if (distance > maxanimal)
						continue;

					valid_players2.push_back((uintptr_t*)entity);


					valid_players.push_back((uintptr_t*)entity);
					window->AddText(ImVec2(outPos.x, outPos.y), color3, get2.c_str());
				}

			}
			if (car) {
				if (Game::GetEntityTypeName2(entity) == xorstr_("car")) {



					if (distance > maxzombie)
						continue;


					window->AddText(ImVec2(outPos.x, outPos.y), color3, get2.c_str());

				}
			}




		}
	}
}

void IterateItems(uintptr_t pUWorld)
{
	auto* window = ImGui::GetOverlayDrawList();
	auto color = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 255, 255));



	int objectTableSz = mem1->RVM<int>(pUWorld + off_world_itemtable + 0x8);


	std::stringstream all;
	uintptr_t entityTable = mem1->RVM<uintptr_t>(pUWorld + off_world_itemtable);
	if (!IsValidPtr((void*)entityTable))
		return;
	float spacing = 20.0f;
	std::map<std::pair<int, int>, bool> textPositionsitems;

	for (size_t i = 0; i < objectTableSz; i++)
	{

		if (!IsValidPtr((void*)entityTable))
			continue;



		uintptr_t entity = mem1->RVM<uintptr_t>(entityTable + i * 0x18 + 0x8);
		if (!IsValidPtr((void*)entity))
			continue;
		const auto flag = mem1->RVM<uint32_t>(entityTable + i * 0x18);
		if (flag != 1)
			continue;


		if (entity)
		{

			Vector3 worldPosition = Game::GetCoordinate(entity);

			Vector3 outPos;

			Vector3 Pos = Game::GetObjectVisualState(entity);


			Game::WorldToScreen(Pos, outPos);


			ImVec2 textPosition(outPos.x, outPos.y);

			while (textPositionsitems[std::make_pair((int)textPosition.x, (int)textPosition.y)]) {
				textPosition.y += spacing; // Ajuste para a próxima posição baseada no espaçamento
			}
			textPositionsitems[std::make_pair((int)textPosition.x, (int)textPosition.y)] = true;



			int dist = Game::GetDistanceToMe(worldPosition);
			if (dist < 1)
				continue;
			int dist1 = Game::GetDistanceToMe(Pos);
			if (dist1 < 1)
				continue;

			if (dist <= maxloot && dist > 0)
			{
				uintptr_t objectBase = mem1->RVM<uintptr_t>(entity + 0x180);

				if (!IsValidPtr((void*)objectBase))
					continue;
				uintptr_t cleanNamePtr = mem1->RVM<uintptr_t>(objectBase + 0x4E8);

				if (!IsValidPtr((void*)cleanNamePtr))
					continue;

				uintptr_t cleanNamePtr5 = mem1->RVM<uintptr_t>(objectBase + 0x88);

				if (!IsValidPtr((void*)cleanNamePtr5))
					continue;

				uintptr_t cleanNamePtr2 = mem1->RVM<uintptr_t>(objectBase + 0Xa8);

				if (!IsValidPtr((void*)cleanNamePtr2))
					continue;


				std::string text = getNameFromId(cleanNamePtr);
				std::string text2 = getNameFromId(cleanNamePtr2);

				std::string text3 = getNameFromId(cleanNamePtr5);



				std::stringstream all;
				all << text;
				all << " " << dist;
				auto get = (xorstr_("[ ") + std::to_string(dist) + xorstr_(" ]"));
				auto get1 = text;
				auto get2 = get1 + get;
				auto color2 = ImGui::ColorConvertFloat4ToU32(ImVec4(INSVeh2[0], INSVeh2[1], INSVeh2[2], INSVeh2[3]));
				auto colorweapon = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 0, 0, 255));
				auto corcomida = ImGui::ColorConvertFloat4ToU32(ImVec4(153, 0, 153, 255));
				auto colorcloting = ImGui::ColorConvertFloat4ToU32(ImVec4(232, 41, 145, 180));
				auto colorinventor = ImGui::ColorConvertFloat4ToU32(ImVec4(110, 141, 145, 200));
				auto coloriMagazines = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 255, 200));
				auto corrodas = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 255, 200));
				auto coloriMagazines2 = ImGui::ColorConvertFloat4ToU32(ImVec4(0, 255, 0, 255));
				auto colorcomida = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 0, 255));

				if (text2.empty())
					continue;
				if (text3.empty())
					continue;




				if (weapon) {
					//if (text2 == xorstr_("Weapon")) {

					if (std::string(text2).find(xorstr_("Weapon")) != std::string::npos) {


						window->AddText(ImVec2((int)textPosition.x, (int)textPosition.y), colorweapon, get2.c_str());

						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());

					}

				}
				if (BackPack) {
					//if (text2 == xorstr_("Weapon")) {

					if (std::string(text3).find(xorstr_("backpacks")) != std::string::npos) {
						window->AddText(textPosition, colorweapon, get2.c_str());


					}

				}
				if (Containers) {
					if (std::string(text3).find(xorstr_("containers")) != std::string::npos) {

						window->AddText(textPosition, corcomida, get2.c_str());


					}
					if (std::string(text3).find(xorstr_("cooking")) != std::string::npos) {

						window->AddText(textPosition, corcomida, get2.c_str());


					}
				}
				if (comida) {
					if (std::string(text3).find(xorstr_("food")) != std::string::npos) {
						//if (text3 == xorstr_("food")) {

						window->AddText(textPosition, corcomida, get2.c_str());

						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());

					}
				}
				if (medicine) {
					if (std::string(text3).find(xorstr_("medical")) != std::string::npos) {
						//if (text3 == xorstr_("medical")) {

						window->AddText(textPosition, corcomida, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
				}

				if (drinks) {
					if (std::string(text3).find(xorstr_("drinks")) != std::string::npos) {
						//	if (text3 == xorstr_("drinks")) {

						window->AddText(textPosition, corcomida, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
				}
				if (clothing) {
					if (std::string(text2).find(xorstr_("clothing")) != std::string::npos) {
						//if (text2 == xorstr_("clothing")) {

						window->AddText(textPosition, colorcloting, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
				}
				if (inventoryItem) {
					if (std::string(text).find(xorstr_("Cerca")) != std::string::npos)
						//if (text2 == xorstr_("Cerca"))
						continue;
					if (std::string(text3).find(xorstr_("food")) != std::string::npos)
						//if (text3 == xorstr_("food"))
						continue;
					if (std::string(text3).find(xorstr_("medical")) != std::string::npos)
						//	if (text3 == xorstr_("medical"))
						continue;
					if (std::string(text3).find(xorstr_("drinks")) != std::string::npos)
						continue;
					if (std::string(text3).find(xorstr_("Fogueira")) != std::string::npos)
						continue;
					//if (text2 == xorstr_("inventoryItem")) {

					if (std::string(text2).find(xorstr_("inventoryItem")) != std::string::npos) {



						window->AddText(textPosition, colorinventor, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}






				}
				if (ProxyMagazines) {
					//if (text2 == xorstr_("ProxyMagazines")) {

					if (std::string(text2).find(xorstr_("ProxyMagazines")) != std::string::npos) {
						window->AddText(textPosition, coloriMagazines, get2.c_str());
					}
					if (std::string(text3).find(xorstr_("ammunition")) != std::string::npos) {
						window->AddText(textPosition, coloriMagazines, get2.c_str());
					}
				}
				if (Miras) {
					if (std::string(text2).find(xorstr_("itemoptics")) != std::string::npos) {
						//if (text2 == xorstr_("itemoptics")) {

						window->AddText(textPosition, coloriMagazines, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
				}
				if (rodas) {
					if (std::string(text2).find(xorstr_("carwheel")) != std::string::npos) {
						//	if (text2 == xorstr_("carwheel")) {
//
						window->AddText(textPosition, corrodas, get2.c_str());
						if (qualidade)
							window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
					}
				}
				if (inventoryItem2) {

					window->AddText(textPosition, coloriMagazines, get2.c_str());
					window->AddText(ImVec2(outPos.x, outPos.y - 15), coloriMagazines, text.c_str());
					if (qualidade)
						window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entity), get_quality(entity).c_str());
				}
				if (inventoryItem12) {

					window->AddText(textPosition, coloriMagazines, get2.c_str());
					//	window->AddText(ImVec2(outPos.x, outPos.y - 15), coloriMagazines, text2.c_str());
					//	if (qualidade)
						//	window->AddText(ImVec2(outPos.x, outPos.y + 15), ColoroU32(entit y), get_quality(entity ).c_str());
				}
				if (Filtrarlloot) {

					if (std::string(get2).find(NamesFilter) != std::string::npos)
						window->AddText(ImVec2(outPos.x, outPos.y), coloriMagazines, get2.c_str());
				}

				valid_players2.push_back((uintptr_t*)entity);



				



			}
		}
	}


}
bool executartudo = 0;

void __stdcall main_cheat_handler()
{
	if (GetAsyncKeyState(VK_NUMPAD1))
		executartudo = 1;

	if (GetAsyncKeyState(VK_NUMPAD2))
		executartudo = 0;


	if (GetAsyncKeyState(LootKey)) {
		Iemtelist = !Iemtelist;
		Sleep(500);
	}

	if (GetAsyncKeyState(VK_F1))
		ov::toggle_menu = 1;

	if (GetAsyncKeyState(VK_F2))
		ov::toggle_menu = 0;

	auto* window = ImGui::GetOverlayDrawList();
	ImGuiIO& io = ImGui::GetIO();
	if (ToggleFov)
		window->AddCircle(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2), aimfov, ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])));

	if (ToggleCross)
		window->AddCircleFilled(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2), fovcross, ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), 30);

	const auto pUWorld = *reinterpret_cast<USQAnimInstanceSoldier1P**>(globals.Base + OFF_WORLD);
//	window->AddText({ 200,200 }, ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), ("pUWorld " + std::to_string((UINT64)pUWorld)).c_str());

	if (!IsValidPtr((void*)pUWorld))
		return;
	
	if (City_Esp)
	{
		Vector3 berezino_down_world_position = { 12972, 6, 10058 };
		Vector3 berezino_screen_position;

		Vector3 solnechniy_world_position = { 13453, 7, 6239 };
		Vector3 solnechniy_screen_position;

		Vector3 kamyshovo_world_position = { 12010, 7, 3486 };
		Vector3 kamyshovo_screen_position;

		Vector3 electrozavodsk_world_position = { 10430, 7, 2277 };
		Vector3 electrozavodsk_screen_position;

		Vector3 prigorodki_world_position = { 7762, 5, 3171 };
		Vector3 prigorodki_screen_position;

		Vector3 chernogorsk_world_position = { 6400, 10, 2679 };
		Vector3 chernogorsk_screen_position;

		Vector3 svetloyarsk_world_position = { 13929, 20, 13234 };
		Vector3 svetloyarsk_screen_position;

		Vector3 mogilevka_world_position = { 7500, 220, 5238 };
		Vector3 mogilevka_screen_position;

		Vector3 guglovo_world_position = { 8412, 360, 6688 };
		Vector3 guglovo_screen_position;

		Vector3 kabanino_world_position = { 5297, 336, 8564 };
		Vector3 kabanino_screen_position;

		Vector3 kozlovka_world_position = { 4452, 230, 4578 };
		Vector3 kozlovka_screen_position;

		Vector3 nadezhdino_world_position = { 5865, 133, 4827 };
		Vector3 nadezhdino_screen_position;

		Vector3 airfield_vybor_world_position = { 4617, 340, 10438 };
		Vector3 airfield_vybor_screen_position;

		Vector3 novodmitrovsk_world_position = { 11619, 43, 14392 };
		Vector3 novodmitrovsk_screen_position;

		Vector3 zelenogorsk_world_position = { 2739, 200, 5223 };
		Vector3 zelenogorsk_screen_position;

		Vector3 krasnostav_world_position = { 11252, 194, 12231 };
		Vector3 krasnostav_screen_position;

		Vector3 severograd_world_position = { 7951, 115, 13688 };
		Vector3 severograd_screen_position;

		Vector3 stariy_sobor_world_position = { 6075, 300, 7757 };
		Vector3 stariy_sobor_screen_position;

		Vector3 military_base_pavlovo_world_position = { 2144, 91, 3369 };
		Vector3 military_base_pavlovo_screen_position;

		Vector3 military_base_kabanino_world_position = { 4570, 318, 8266 };
		Vector3 military_base_kabanino_screen_position;

		Game::WorldToScreen(berezino_down_world_position, berezino_screen_position);

		Game::WorldToScreen(solnechniy_world_position, solnechniy_screen_position);
		Game::WorldToScreen(kamyshovo_world_position, kamyshovo_screen_position);
		Game::WorldToScreen(electrozavodsk_world_position, electrozavodsk_screen_position);
		Game::WorldToScreen(prigorodki_world_position, prigorodki_screen_position);
		Game::WorldToScreen(chernogorsk_world_position, chernogorsk_screen_position);
		Game::WorldToScreen(svetloyarsk_world_position, svetloyarsk_screen_position);
		Game::WorldToScreen(mogilevka_world_position, mogilevka_screen_position);
		Game::WorldToScreen(guglovo_world_position, guglovo_screen_position);
		Game::WorldToScreen(kabanino_world_position, kabanino_screen_position);
		Game::WorldToScreen(kozlovka_world_position, kozlovka_screen_position);
		Game::WorldToScreen(nadezhdino_world_position, nadezhdino_screen_position);
		Game::WorldToScreen(airfield_vybor_world_position, airfield_vybor_screen_position);
		Game::WorldToScreen(novodmitrovsk_world_position, novodmitrovsk_screen_position);
		Game::WorldToScreen(zelenogorsk_world_position, zelenogorsk_screen_position);
		Game::WorldToScreen(krasnostav_world_position, krasnostav_screen_position);
		Game::WorldToScreen(severograd_world_position, severograd_screen_position);
		Game::WorldToScreen(stariy_sobor_world_position, stariy_sobor_screen_position);
		Game::WorldToScreen(military_base_pavlovo_world_position, military_base_pavlovo_screen_position);
		Game::WorldToScreen(military_base_kabanino_world_position, military_base_kabanino_screen_position);

		int distance_berezino = Game::GetDistanceToMe(berezino_down_world_position);
		int distance_solnechniy = Game::GetDistanceToMe(solnechniy_world_position);
		int distance_kamyshovo = Game::GetDistanceToMe(kamyshovo_world_position);
		int distance_electrozavodsk = Game::GetDistanceToMe(electrozavodsk_world_position);
		int distance_prigorodki = Game::GetDistanceToMe(prigorodki_world_position);
		int distance_chernogorsk = Game::GetDistanceToMe(chernogorsk_world_position);
		int distance_svetloyarsk = Game::GetDistanceToMe(svetloyarsk_world_position);
		int distance_mogilevka = Game::GetDistanceToMe(mogilevka_world_position);
		int distance_guglovo = Game::GetDistanceToMe(guglovo_world_position);
		int distance_kabanino = Game::GetDistanceToMe(kabanino_world_position);
		int distance_kozlovka = Game::GetDistanceToMe(kozlovka_world_position);
		int distance_nadezhdino = Game::GetDistanceToMe(nadezhdino_world_position);
		int distance_airfield_vybor = Game::GetDistanceToMe(airfield_vybor_world_position);
		int distance_novodmitrovsk = Game::GetDistanceToMe(novodmitrovsk_world_position);
		int distance_zelenogorsk = Game::GetDistanceToMe(zelenogorsk_world_position);
		int distance_krasnostav = Game::GetDistanceToMe(krasnostav_world_position);
		int distance_severograd = Game::GetDistanceToMe(severograd_world_position);
		int distance_stariy_sobor = Game::GetDistanceToMe(stariy_sobor_world_position);
		int distance_military_base_pavlovo = Game::GetDistanceToMe(military_base_pavlovo_world_position);
		int distance_military_base_kabanino = Game::GetDistanceToMe(military_base_kabanino_world_position);


		if (City_Esp1)
			window->AddText(ImVec2(berezino_screen_position.x, berezino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Berezino (Down)   ") + std::to_string((int)distance_berezino)).c_str());
		if (City_Esp2)
			window->AddText(ImVec2(solnechniy_screen_position.x, solnechniy_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Solnechniy    ") + std::to_string((int)distance_solnechniy)).c_str());
		if (City_Esp3)
			window->AddText(ImVec2(kamyshovo_screen_position.x, kamyshovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kamyshovo   ") + std::to_string((int)distance_kamyshovo)).c_str());
		if (City_Esp4)
			window->AddText(ImVec2(electrozavodsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Electrozavodsk    ") + std::to_string((int)distance_electrozavodsk)).c_str());
		if (City_Esp5)
			window->AddText(ImVec2(electrozavodsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Prigorodki   ") + std::to_string((int)distance_prigorodki)).c_str());
		if (City_Esp6)
			window->AddText(ImVec2(chernogorsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Chernogorsk  ") + std::to_string((int)distance_chernogorsk)).c_str());
		if (City_Esp7)
			window->AddText(ImVec2(svetloyarsk_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Svetloyarsk  ") + std::to_string((int)distance_svetloyarsk)).c_str());
		if (City_Esp8)
			window->AddText(ImVec2(mogilevka_screen_position.x, electrozavodsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Mogilevka  ") + std::to_string((int)distance_mogilevka)).c_str());
		if (City_Esp9)
			window->AddText(ImVec2(guglovo_screen_position.x, guglovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Guglovo  ") + std::to_string((int)distance_guglovo)).c_str());
		if (City_Esp10)
			window->AddText(ImVec2(kabanino_screen_position.x, kabanino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kabanino  ") + std::to_string((int)distance_kabanino)).c_str());
		if (City_Esp11)
			window->AddText(ImVec2(kozlovka_screen_position.x, kozlovka_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Kozlovka  ") + std::to_string((int)distance_kozlovka)).c_str());
		if (City_Esp12)
			window->AddText(ImVec2(nadezhdino_screen_position.x, nadezhdino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("KozlNadezhdinoovka  ") + std::to_string((int)distance_nadezhdino)).c_str());
		if (City_Esp13)
			window->AddText(ImVec2(airfield_vybor_screen_position.x, airfield_vybor_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Air-Field (Vybor)  ") + std::to_string((int)distance_airfield_vybor)).c_str());
		if (City_Esp14)
			window->AddText(ImVec2(novodmitrovsk_screen_position.x, novodmitrovsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Novodmitrovsk ") + std::to_string((int)distance_novodmitrovsk)).c_str());
		if (City_Esp15)
			window->AddText(ImVec2(zelenogorsk_screen_position.x, zelenogorsk_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Zelenogorsk ") + std::to_string((int)distance_zelenogorsk)).c_str());
		if (City_Esp16)
			window->AddText(ImVec2(krasnostav_screen_position.x, krasnostav_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Krasnostav ") + std::to_string((int)distance_krasnostav)).c_str());
		if (City_Esp17)
			window->AddText(ImVec2(severograd_screen_position.x, severograd_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Severograd ") + std::to_string((int)distance_severograd)).c_str());
		if (City_Esp18)
			window->AddText(ImVec2(stariy_sobor_screen_position.x, stariy_sobor_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Stariy Sobor ") + std::to_string((int)distance_stariy_sobor)).c_str());
		if (City_Esp19)
			window->AddText(ImVec2(military_base_pavlovo_screen_position.x, military_base_pavlovo_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Military base (Pavlovo)") + std::to_string((int)distance_military_base_pavlovo)).c_str());
		if (City_Esp20)
			window->AddText(ImVec2(military_base_kabanino_screen_position.x, military_base_kabanino_screen_position.y), ImGui::ColorConvertFloat4ToU32(ImVec4(TesTESP[0], TesTESP[1], TesTESP[2], TesTESP[3])), (xorstr_("Military base (Kabanino) ") + std::to_string((int)distance_military_base_kabanino)).c_str());


	}


	

	if (Iemtelist)
		IterateItems((uintptr_t)pUWorld);


	//if (executartudo) //
	//	return;

	if (inventoryItem22)
		IterateAll((uintptr_t)pUWorld, OFF_NEAR_ENTITY_TABLE);

	if (inventoryItem222)
		IterateAll((uintptr_t)pUWorld, OFF_SLOW_ENTITY_TABLE);

	if (inventoryItem2222)
		IterateAll((uintptr_t)pUWorld, OFF_FAR_ENTITY_TABLE);

	if (LootTeleport)
		lootteleport(); 

	if (SilentAim)
	 
		main_aimboo2(isnpc);



	valid_players.clear();
	valid_players1.clear();
	valid_players2.clear();
}


float VisualTabx = 600;
float VisualTaby = 400;

void drawwews()
{
	static const char* lowercaseKeyboardLayout[] = {
	  "1234567890",
	  "qwertyuiop",
	  "asdfghjkl",
	  "zxcvbnm"
	};

	static const char* uppercaseKeyboardLayout[] = {
		"1234567890",
		"QWERTYUIOP",
		"ASDFGHJKL",
		"ZXCVBNM"
	};

	const char** currentLayout = uppercaseMode ? uppercaseKeyboardLayout : lowercaseKeyboardLayout;

	for (int i = 0; i < sizeof(lowercaseKeyboardLayout) / sizeof(lowercaseKeyboardLayout[0]); ++i)
	{
		ImGui::Separator();

		for (int j = 0; j < strlen(lowercaseKeyboardLayout[i]); ++j)
		{
			const char key = currentLayout[i][j];

			// Crie um botão com a letra correspondente
			if (ImGui::Button(&key, ImVec2(40, 40)))
			{
				// Adicione a letra ao texto
				if (strlen(NamesFilter) < MaxTextLength)
				{
					strcat(NamesFilter, &key);
				}
			}

			// Adicione um espaçamento entre as teclas para melhorar a aparência
			ImGui::SameLine();
		}

		// Adicione uma nova linha após cada linha de teclas
		ImGui::NewLine();
	}
}

void draw_abigsquare()
{
	static int MenuTab = 1;
	static int VisualTab = 0;
	float
		TextSpaceLine = 90.f,
		SpaceLineOne = 120.f,
		SpaceLineTwo = 280.f,
		SpaceLineThr = 420.f;

	static auto flags = ImGuiWindowFlags_NoCollapse;


	ImGuiStyle& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(256, 300);
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
	style.FrameBorderSize = 1;
	style.ChildBorderSize = 1;
	style.WindowBorderSize = 1;
	style.WindowRounding = 0;
	style.FrameRounding = 0;
	style.ChildRounding = 0;
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_WindowBg] = ImColor(25, 25, 25, 250);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.90f, 0.43f, 0.80f);
	style.Colors[ImGuiCol_Border] = ImColor(70, 70, 70);
	style.Colors[ImGuiCol_Button] = ImColor(32, 32, 32);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_ChildBg] = ImColor(45, 45, 45);
	style.Colors[ImGuiCol_FrameBg] = ImColor(32, 32, 32);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 255);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 255);






	// MENU ABAIXO














	ImGui::Begin(_("DxrkY"), NULL, flags);
	{
		//ImGui::SetWindowSize(ImVec2(VisualTabx, VisualTaby));
		{
			ImGui::BeginChild(_("##Tabs"), ImVec2(-1, 30.0f));
			{
				//	style->ItemSpacing = ImVec2(1, 1);
					//	ImGui::PushFont(SkeetFont);
				{
					//if (ImGui::Button(_("Player"), ImVec2(100, 20)))
					//{
					//	MenuTab = 0;
					//}
					//ImGui::SameLine();
					if (ImGui::Button(_("Visuals"), ImVec2(100, 20)))
					{
						MenuTab = 1;
					}
					ImGui::SameLine();
					if (ImGui::Button(_("City ESP"), ImVec2(100, 20)))
					{
						MenuTab = 2;
					}
					ImGui::SameLine();
					if (ImGui::Button(_("Aimbot"), ImVec2(100, 20)))
					{
						MenuTab = 3;
					}
					ImGui::SameLine();
					if (ImGui::Button(_("Loot Filter"), ImVec2(100, 20)))
					{
						MenuTab = 4;
					}

				}

			}
			ImGui::EndChild();


			if (MenuTab == 1)
			{
				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::Text(_("ESP:"));
				ImGui::SetCursorPos(ImVec2(10, 100));
				ImGui::BeginChild(_("##Players1"), ImVec2(240.f, 275), true);
				{
					ImGui::Checkbox(_(" Player "), &showplayer);
					if (showplayer)
						ImGui::SliderFloat(xorstr_("##MaxDistancep"), &maxplayer, 0, 1500);
					if (showplayer)
						ImGui::Checkbox(_("Player Skeleton"), &Skelet1Player);

					if (showplayer) {

						ImGui::Checkbox(xorstr_("Player Name"), &esp_player_team);

					}
					ImGui::Checkbox(_("Player Lines"), &showplayerSlaplines);

					ImGui::Checkbox(xorstr_("Zombie"), &showzombie);
					if (showzombie)
						ImGui::Checkbox(xorstr_("Zombie Skeleton"), &Skelet1Zombie);
					if (showzombie)
						ImGui::SliderFloat(xorstr_("##MaxDistancez"), &maxzombie, 0, 1500);
					ImGui::Checkbox(xorstr_("Animals"), &showAnimal);
					if (showAnimal)
						ImGui::SliderFloat(xorstr_("##Animald"), &maxanimal, 0, 1500);
					ImGui::Checkbox(xorstr_("Vehicles"), &car);
					if (car)
						ImGui::SliderFloat(xorstr_("##Vehicled"), &maxcar, 0, 1500);



				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(260, 80));
				ImGui::Text(_("Items:"));
				ImGui::SetCursorPos(ImVec2(260, 100));
				ImGui::BeginChild(_("##Players22"), ImVec2(0, 290), true);
				{






					ImGui::PushItemWidth(170.f);
					ImGui::Checkbox(xorstr_("Show Items"), &Iemtelist);
					ImGui::SameLine();
					ImGuiCustom::HotkeyButtonEx(xorstr_("Key Item"), &LootKey, ImVec2(150, 150), 0);

					if (Iemtelist)
					{

						ImGui::Checkbox(xorstr_("Loot Teleport"), &LootTeleport);
						if (LootTeleport) {
							ImGui::SameLine();
							ImGuiCustom::HotkeyButtonEx(xorstr_("Key TP"), &LootTP, ImVec2(50, 50), 0);
						}
						ImGui::Checkbox(xorstr_("ESP Weapon"), &weapon);
						ImGui::Checkbox(xorstr_("ESP ProxyMagazines"), &ProxyMagazines);
						ImGui::Checkbox(xorstr_("ESP Scoop"), &Miras);
						ImGui::Checkbox(xorstr_("ESP Well"), &rodas);
						ImGui::Checkbox(xorstr_("ESP Clothing"), &clothing);
						ImGui::Checkbox(xorstr_("ESP Others"), &inventoryItem);


						ImGui::Checkbox(xorstr_("ESP Food"), &comida);
						ImGui::Checkbox(xorstr_("ESP Drinks"), &drinks);
						ImGui::Checkbox(xorstr_("ESP Medicine"), &medicine);
						ImGui::Checkbox(xorstr_("ESP Containers"), &Containers);
						ImGui::Checkbox(xorstr_("ESP BackPack"), &BackPack);
						ImGui::Checkbox(xorstr_("EPS All"), &inventoryItem12);

						ImGui::SliderFloat(xorstr_("##Msho2wzos2asmbie"), &maxloot, 0, 1500);

					}






					ImGui::PopItemWidth();

				}
				ImGui::EndChild();
			}
			if (MenuTab == 2)
			{
				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::SetCursorPos(ImVec2(10, 100));
				ImGui::BeginChild(_("##P2layewrs1"), ImVec2(240.f, 300), true);
				{
					ImGui::Checkbox(xorstr_("Show City"), &City_Esp);
					if (City_Esp) {
						ImGui::Checkbox(xorstr_("Berezino (Down)"), &City_Esp1);
						ImGui::Checkbox(xorstr_("Solnechniy"), &City_Esp2);
						ImGui::Checkbox(xorstr_("Kamyshovo"), &City_Esp3);
						ImGui::Checkbox(xorstr_("Electrozavodsk"), &City_Esp4);
						ImGui::Checkbox(xorstr_("Prigorodki"), &City_Esp5);
						ImGui::Checkbox(xorstr_("Chernogorsk"), &City_Esp6);
						ImGui::Checkbox(xorstr_("Svetloyarsk"), &City_Esp7);
						ImGui::Checkbox(xorstr_("Mogilevka"), &City_Esp8);
						ImGui::Checkbox(xorstr_("Guglovo"), &City_Esp9);
					}
				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(260, 80));
				ImGui::SetCursorPos(ImVec2(260, 100));
				ImGui::BeginChild(_("##cwdsdw"), ImVec2(-1, 300), true);
				{
					ImGui::PushItemWidth(170.f);
					if (City_Esp) {
						ImGui::Checkbox(xorstr_("Kozlovka"), &City_Esp11);
						ImGui::Checkbox(xorstr_("Nadezhdino"), &City_Esp12);
						ImGui::Checkbox(xorstr_("Air-Field (Vybor)"), &City_Esp13);
						ImGui::Checkbox(xorstr_("Novodmitrovsk"), &City_Esp14);
						ImGui::Checkbox(xorstr_("Zelenogorsk"), &City_Esp15);
						ImGui::Checkbox(xorstr_("Krasnostav"), &City_Esp16);
						ImGui::Checkbox(xorstr_("Severograd"), &City_Esp17);
						ImGui::Checkbox(xorstr_("Stariy Sobor"), &City_Esp18);
						ImGui::Checkbox(xorstr_("Military base (Pavlovo)"), &City_Esp19);
						ImGui::Checkbox(xorstr_("Military base (Kabanino)"), &City_Esp20);
						ImGui::Checkbox(xorstr_("Kabanino"), &City_Esp10);
					}

					ImGui::PopItemWidth();

				}
				ImGui::EndChild();
			}
			if (MenuTab == 3)
			{

				//ImGui::ColorPicker3(xorstr_("Collor"), TesTESP);
			//	ImGui::Checkbox(xorstr_("Sleep"), &SleepBbutton);
				ImGui::Checkbox(xorstr_("SilentAim"), &SilentAim); ImGui::SameLine();  
				ImGui::Checkbox(xorstr_("Show FOV"), &ToggleFov);
				ImGui::Checkbox(xorstr_(" CrossHair "), &ToggleCross);

				ImGuiCustom::HotkeyButtonEx(xorstr_(".Key Silent"), &desynckey, ImVec2(50, 50), 0);

				if (bonechoose == 0)
					ImGui::Text(xorstr_("Head"));

				if (bonechoose == 1)
					ImGui::Text(xorstr_("Neck"));

				if (bonechoose == 2)
					ImGui::Text(xorstr_("Chest"));

				if (bonechoose == 3)
					ImGui::Text(xorstr_("Pelvis"));

				if (bonechoose == 4)
					ImGui::Text(xorstr_("Laft Leg"));

				if (bonechoose == 5)
					ImGui::Text(xorstr_("Right Leg"));

				ImGui::SliderInt(xorstr_("Bone:"), &bonechoose, 0, 5);


				ImGui::SliderInt(xorstr_("SilentAim Distance"), &LimiteDoSilent, 1, 1500);
				ImGui::SliderFloat(xorstr_("FOV Size"), &aimfov, 1, 999);
				ImGui::SliderFloat(xorstr_("Cross Size"), &fovcross, 0, 10);


			}
			if (MenuTab == 4)
			{

				ImGui::Checkbox(xorstr_("Loot Filter"), &Filtrarlloot);

				if (Filtrarlloot) {
					drawwews();
					ImGui::Text(" ");
					ImGui::Text(" ");
					ImGui::SameLine();
					ImGui::TextColored({ 255,255,0,255 }, "Name = %s ", NamesFilter);

				}
				ImGui::Text("       ");

				ImGui::SameLine();
				if (ImGui::Button("Caps Lock"))
				{
					uppercaseMode = !uppercaseMode;
				}
				ImGui::Text("");

				ImGui::Text("       ");
				ImGui::SameLine();
				if (ImGui::Button(_("Reset"), ImVec2(100, 20)))
				{
					memset(NamesFilter, 0, sizeof(NamesFilter));
				}





			}

		}
		ImGui::End();
	}
	return;
}
