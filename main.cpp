#include "overlay.h"
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
//#pragma comment (lib, "RebirthGuard.lib")       //Lib pra deletar dll
//#include "RebirthGuardSDK.h"
//#include "RGString.h"
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:

		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;

}
void Hookkasamerda() {

	init1();

	ov::create_window();

	ov::loop();
}



int main1()
{


	Hookkasamerda();

}
bool __stdcall DllMain(HMODULE module, std::uint32_t call_reason, void*)
{
	//AllocConsole();
	//freopen("CONIN$", "r", stdin);
	//freopen("CONOUT$", "w", stdout);

	//DisableThreadLibraryCalls(module);
	Sleep(500);
	if (call_reason != DLL_PROCESS_ATTACH && call_reason != DLL_PROCESS_DETACH)
		return false;
	Sleep(500);

	if (call_reason == DLL_PROCESS_ATTACH)
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)main1, 0, 0, nullptr));

	}

	return true;
}