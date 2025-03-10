#pragma once

#include <algorithm>
#include <array>
#include <string_view>
#include <Windows.h>
 #define IMGUI_DEFINE_MATH_OPERATORS
 class KeyBind;

namespace ImGuiCustom
{
	static const char* KeyNames[] = {
	  "Press Key",
	  "Left Mouse",
	  "Right Mouse",
	  "Cancel",
	  "Middle Mouse",
	  "X1 Mouse",
	  "X2 Mouse",
	  "Unknown",
	  "Backspace",
	  "Tab",
	  "unknown",
	  "unknown",
	  "Clear",
	  "Return",
	  "unknown",
	  "unknown",
	  "Shift",
	  "Control",
	  "Menu",
	  "Pause",
	  "Caps Lock",
	  "Kana",
	  "unknown",
	  "vk_junja",
	  "vk_final",
	  "vk_kanji",
	  "unknown",
	  "Escape",
	  "Convert",
	  "Nonconvert",
	  "Accept",
	  "Modechange",
	  "Space",
	  "Page Up",
	  "Page Down",
	  "End",
	  "Home",
	  "Left",
	  "Up",
	  "Right",
	  "Down",
	  "Select",
	  "Print",
	  "Execute",
	  "Snapshot",
	  "Insert",
	  "Delete",
	  "Help",
	  "0",
	  "1",
	  "2",
	  "3",
	  "4",
	  "5",
	  "6",
	  "7",
	  "8",
	  "9",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "a",
	  "b",
	  "c",
	  "d",
	  "e",
	  "f",
	  "g",
	  "h",
	  "i",
	  "j",
	  "k",
	  "l",
	  "m",
	  "n",
	  "o",
	  "p",
	  "q",
	  "r",
	  "s",
	  "t",
	  "u",
	  "v",
	  "w",
	  "x",
	  "y",
	  "z",
	  "Windows",
	  "Windows",
	  "Apps",
	  "unknown",
	  "Sleep",
	  "Numpad 0",
	  "Numpad 1",
	  "Numpad 2",
	  "Numpad 3",
	  "Numpad 4",
	  "Numpad 5",
	  "Numpad 6",
	  "Numpad 7",
	  "Numpad 8",
	  "Numpad 9",
	  "Multiply",
	  "Add",
	  "Separator",
	  "Subtract",
	  "Decimal",
	  "Divide",
	  "F1",
	  "F2",
	  "F3",
	  "F4",
	  "F5",
	  "F6",
	  "F7",
	  "F8",
	  "F9",
	  "F10",
	  "F11",
	  "F12",
	  "F13",
	  "F14",
	  "F15",
	  "F16",
	  "F17",
	  "F18",
	  "F19",
	  "F20",
	  "F21",
	  "F22",
	  "F23",
	  "F24",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "Numlock",
	  "Scroll",
	  "vk_oem_nec_equal",
	  "vk_oem_fj_masshou",
	  "vk_oem_fj_touroku",
	  "vk_oem_fj_loya",
	  "vk_oem_fj_roya",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "unknown",
	  "Shift",
	  "Shift",
	  "Control",
	  "Control",
	  "Menu",
	  "Menu"
	};
	bool KeyPressed(int* key)
	{
		int i = 0;
		while (i < 256)
		{
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Unsafe but works
			{
				return true;
			}
			if (GetAsyncKeyState(i) & 0x8000) // Unsafe but works
			{
				*key = i;
				return true;
			}
			i++;
		}
		return false;
	}

	bool HotkeyButtonEx(const char* label, int* key, const ImVec2& size_arg, ImGuiButtonFlags flags)
	{
		if (ImGui::Button(KeyNames[*key]))
		{
			while (true)
			{
				Sleep(1);
				if (!GetAsyncKeyState(VK_LBUTTON)) // fucking dumb way to wait until button is no longer pressed but it works. Fix soon.
					break;
			}
			*key = 0;
		}
		if (*key == 0)
			KeyPressed(key);

		return true;
	}

	void hotkey(const char* label, KeyBind& key, float samelineOffset = 0.0f, const ImVec2& size = { 100.0f, 0.0f }) noexcept;
}





struct Key {
	constexpr Key(std::string_view name, int code) : name{ name }, code{ code } {  }

	std::string_view name;
	int code;
};

// indices must match KeyBind::KeyCode enum
static constexpr auto keyMap = std::to_array<Key>({
	{ "'", VK_OEM_7 },
	{ ",", VK_OEM_COMMA },
	{ "-", VK_OEM_MINUS },
	{ ".", VK_OEM_PERIOD },
	{ "/", VK_OEM_2 },
	{ "0", '0' },
	{ "1", '1' },
	{ "2", '2' },
	{ "3", '3' },
	{ "4", '4' },
	{ "5", '5' },
	{ "6", '6' },
	{ "7", '7' },
	{ "8", '8' },
	{ "9", '9' },
	{ ";", VK_OEM_1 },
	{ "=", VK_OEM_PLUS },
	{ "A", 'A' },
	{ "ADD", VK_ADD },
	{ "B", 'B' },
	{ "BACKSPACE", VK_BACK },
	{ "C", 'C' },
	{ "CAPSLOCK", VK_CAPITAL },
	{ "D", 'D' },
	{ "DECIMAL", VK_DECIMAL },
	{ "DELETE", VK_DELETE },
	{ "DIVIDE", VK_DIVIDE },
	{ "DOWN", VK_DOWN },
	{ "E", 'E' },
	{ "END", VK_END },
	{ "ENTER", VK_RETURN },
	{ "F", 'F' },
	{ "F1", VK_F1 },
	{ "F10", VK_F10 },
	{ "F11", VK_F11 },
	{ "F12", VK_F12 },
	{ "F2", VK_F2 },
	{ "F3", VK_F3 },
	{ "F4", VK_F4 },
	{ "F5", VK_F5 },
	{ "F6", VK_F6 },
	{ "F7", VK_F7 },
	{ "F8", VK_F8 },
	{ "F9", VK_F9 },
	{ "G", 'G' },
	{ "H", 'H' },
	{ "HOME", VK_HOME },
	{ "I", 'I' },
	{ "INSERT", VK_INSERT },
	{ "J", 'J' },
	{ "K", 'K' },
	{ "L", 'L' },
	{ "LALT", VK_LMENU },
	{ "LCTRL", VK_LCONTROL },
	{ "LEFT", VK_LEFT },
	{ "LSHIFT", VK_LSHIFT },
	{ "M", 'M' },
	{ "MOUSE1", 0 },
	{ "MOUSE2", 1 },
	{ "MOUSE3", 2 },
	{ "MOUSE4", 3 },
	{ "MOUSE5", 4 },
	{ "MULTIPLY", VK_MULTIPLY },
	{ "MWHEEL_DOWN", 0 },
	{ "MWHEEL_UP", 0 },
	{ "N", 'N' },
	{ "NONE", 0 },
	{ "NUMPAD_0", VK_NUMPAD0 },
	{ "NUMPAD_1", VK_NUMPAD1 },
	{ "NUMPAD_2", VK_NUMPAD2 },
	{ "NUMPAD_3", VK_NUMPAD3 },
	{ "NUMPAD_4", VK_NUMPAD4 },
	{ "NUMPAD_5", VK_NUMPAD5 },
	{ "NUMPAD_6", VK_NUMPAD6 },
	{ "NUMPAD_7", VK_NUMPAD7 },
	{ "NUMPAD_8", VK_NUMPAD8 },
	{ "NUMPAD_9", VK_NUMPAD9 },
	{ "O", 'O' },
	{ "P", 'P' },
	{ "PAGE_DOWN", VK_NEXT },
	{ "PAGE_UP", VK_PRIOR },
	{ "Q", 'Q' },
	{ "R", 'R' },
	{ "RALT", VK_RMENU },
	{ "RCTRL", VK_RCONTROL },
	{ "RIGHT", VK_RIGHT },
	{ "RSHIFT", VK_RSHIFT },
	{ "S", 'S' },
	{ "SPACE", VK_SPACE },
	{ "SUBTRACT", VK_SUBTRACT },
	{ "T", 'T' },
	{ "TAB", VK_TAB },
	{ "U", 'U' },
	{ "UP", VK_UP },
	{ "V", 'V' },
	{ "W", 'W' },
	{ "X", 'X' },
	{ "Y", 'Y' },
	{ "Z", 'Z' },
	{ "[", VK_OEM_4 },
	{ "\\", VK_OEM_5 },
	{ "]", VK_OEM_6 },
	{ "`", VK_OEM_3 }
	});
 
#include <string>

using namespace std;

class KeyBind {
public:
	KeyBind() : keybind{ "" } {};
	KeyBind(string _keybind) : keybind{ _keybind } {};
	string keybind;

	enum KeyCode : unsigned char {
		APOSTROPHE = 0,
		COMMA,
		MINUS,
		PERIOD,
		SLASH,
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		SEMICOLON,
		EQUALS,
		A,
		ADD,
		B,
		BACKSPACE,
		C,
		CAPSLOCK,
		D,
		DECIMAL,
		DEL,
		DIVIDE,
		DOWN,
		E,
		END,
		ENTER,
		F,
		F1,
		F10,
		F11,
		F12,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		G,
		H,
		HOME,
		I,
		INSERT,
		J,
		K,
		L,
		LALT,
		LCTRL,
		LEFT,
		LSHIFT,
		M,
		MOUSE1,
		MOUSE2,
		MOUSE3,
		MOUSE4,
		MOUSE5,
		MULTIPLY,
		MOUSEWHEEL_DOWN,
		MOUSEWHEEL_UP,
		N,
		NONE,
		NUMPAD_0,
		NUMPAD_1,
		NUMPAD_2,
		NUMPAD_3,
		NUMPAD_4,
		NUMPAD_5,
		NUMPAD_6,
		NUMPAD_7,
		NUMPAD_8,
		NUMPAD_9,
		O,
		P,
		PAGE_DOWN,
		PAGE_UP,
		Q,
		R,
		RALT,
		RCTRL,
		RIGHT,
		RSHIFT,
		S,
		SPACE,
		SUBTRACT,
		T,
		TAB,
		U,
		UP,
		V,
		W,
		X,
		Y,
		Z,
		LEFTBRACKET,
		BACKSLASH,
		RIGHTBRACKET,
		BACKTICK,

		MAX
	};

	//KeyBind() = default;
	explicit KeyBind(KeyCode keyCode) noexcept;
	explicit KeyBind(const char* keyName) noexcept;

	bool operator==(KeyCode keyCode) const noexcept { return this->keyCode == keyCode; }
	friend bool operator==(const KeyBind& a, const KeyBind& b) noexcept { return a.keyCode == b.keyCode; }

	[[nodiscard]] const char* toString() const noexcept;
	[[nodiscard]] const int toInt() const noexcept;
	[[nodiscard]] bool isPressed() const noexcept;
	[[nodiscard]] bool isDown() const noexcept;
	[[nodiscard]] bool isSet() const noexcept { return keyCode != KeyCode::NONE; }

	bool setToPressedKey() noexcept;
private:
	KeyCode keyCode = KeyCode::NONE;
};

class KeyBindToggle : public KeyBind {
public:
	using KeyBind::KeyBind;

	void handleToggle() noexcept;
	[[nodiscard]] bool isToggled() const noexcept { return toggledOn; }
private:
	bool toggledOn = true;
};


static_assert(keyMap.size() == KeyBind::MAX);
static_assert(std::ranges::is_sorted(keyMap, {}, & Key::name));

KeyBind::KeyBind(KeyCode keyCode) noexcept : keyCode{ static_cast<std::size_t>(keyCode) < keyMap.size() ? keyCode : KeyCode::NONE } {}

KeyBind::KeyBind(const char* keyName) noexcept
{
	if (const auto it = std::ranges::lower_bound(keyMap, keyName, {}, &Key::name); it != keyMap.end() && it->name == keyName)
		keyCode = static_cast<KeyCode>(std::distance(keyMap.begin(), it));
	else
		keyCode = KeyCode::NONE;
}

const char* KeyBind::toString() const noexcept
{
	return keyMap[static_cast<std::size_t>(keyCode) < keyMap.size() ? keyCode : KeyCode::NONE].name.data();
}

const int KeyBind::toInt() const noexcept
{
	return keyMap[static_cast<std::size_t>(keyCode) < keyMap.size() ? keyCode : KeyCode::NONE].code; //Key::code
}

bool KeyBind::isPressed() const noexcept
{
	if (keyCode == KeyCode::NONE)
		return false;

	if (keyCode == KeyCode::MOUSEWHEEL_DOWN)
		return ImGui::GetIO().MouseWheel < 0.0f;

	if (keyCode == KeyCode::MOUSEWHEEL_UP)
		return ImGui::GetIO().MouseWheel > 0.0f;

	if (keyCode >= KeyCode::MOUSE1 && keyCode <= KeyCode::MOUSE5)
		return ImGui::IsMouseClicked(keyMap[keyCode].code);

	return static_cast<std::size_t>(keyCode) < keyMap.size() && ImGui::IsKeyPressed(keyMap[keyCode].code, false);
}

bool KeyBind::isDown() const noexcept
{
	if (keyCode == KeyCode::NONE)
		return false;

	if (keyCode == KeyCode::MOUSEWHEEL_DOWN)
		return ImGui::GetIO().MouseWheel < 0.0f;

	if (keyCode == KeyCode::MOUSEWHEEL_UP)
		return ImGui::GetIO().MouseWheel > 0.0f;

	if (keyCode >= KeyCode::MOUSE1 && keyCode <= KeyCode::MOUSE5)
		return ImGui::IsMouseDown(keyMap[keyCode].code);

	return static_cast<std::size_t>(keyCode) < keyMap.size() && ImGui::IsKeyDown(keyMap[keyCode].code);
}

bool KeyBind::setToPressedKey() noexcept
{
	if (ImGui::IsKeyPressed(ImGui::GetIO().KeyMap[ImGuiKey_Escape])) {
		keyCode = KeyCode::NONE;
		return true;
	}
	else if (ImGui::GetIO().MouseWheel < 0.0f) {
		keyCode = KeyCode::MOUSEWHEEL_DOWN;
		return true;
	}
	else if (ImGui::GetIO().MouseWheel > 0.0f) {
		keyCode = KeyCode::MOUSEWHEEL_UP;
		return true;
	}
	else if (GetKeyState(keyMap[LSHIFT].code) & 0x8000) {
		keyCode = KeyCode::LSHIFT;
		return true;
	}
	else if (GetKeyState(keyMap[LALT].code) & 0x8000) {
		keyCode = KeyCode::LALT;
		return true;
	}
	else if (GetKeyState(keyMap[LCTRL].code) & 0x8000) {
		keyCode = KeyCode::LCTRL;
		return true;
	}
	else if (GetKeyState(keyMap[MOUSE4].code) & 0x8000) {
		keyCode = KeyCode::MOUSE4;
		return true;
	}
	else if (GetKeyState(keyMap[MOUSE5].code) & 0x8000) {
		keyCode = KeyCode::MOUSE5;
		return true;
	}

	for (int i = 0; i < IM_ARRAYSIZE(ImGui::GetIO().MouseDown); ++i) {
		if (ImGui::IsMouseClicked(i)) {
			keyCode = KeyCode(KeyCode::MOUSE1 + i);
			return true;
		}
	}

	for (int i = 0; i < IM_ARRAYSIZE(ImGui::GetIO().KeysDown); ++i) {
		if (!ImGui::IsKeyPressed(i))
			continue;

		if (const auto it = std::ranges::find(keyMap, i, &Key::code); it != keyMap.end()) {
			keyCode = static_cast<KeyCode>(std::distance(keyMap.begin(), it));
			// Treat AltGr as RALT
			if (keyCode == KeyCode::LCTRL && ImGui::IsKeyPressed(keyMap[KeyCode::RALT].code))
				keyCode = KeyCode::RALT;
			return true;
		}
	}
	return false;
}

void KeyBindToggle::handleToggle() noexcept
{
	if (isPressed())
		toggledOn = !toggledOn;
}

void ImGuiCustom::hotkey(const char* label, KeyBind& key, float samelineOffset, const ImVec2& size) noexcept
{
	const auto id = ImGui::GetID(label);
	ImGui::PushID(label);

	ImGui::TextUnformatted(label);
	ImGui::SameLine(samelineOffset);

	if (ImGui::GetActiveID() == id) {
		ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetColorU32(ImGuiCol_ButtonActive));
		ImGui::Button("...", size);
		ImGui::PopStyleColor();

		ImGui::GetCurrentContext()->ActiveIdAllowOverlap = true;
		if ((!ImGui::IsItemHovered() && ImGui::GetIO().MouseClicked[0]) || key.setToPressedKey())
			ImGui::ClearActiveID();
	}
	else if (ImGui::Button(key.toString(), size)) {
		ImGui::SetActiveID(id, ImGui::GetCurrentWindow());
	}

	ImGui::PopID();
}