#pragma once
#include <Windows.h>
#include <string>

#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")

#include "drawings.h"
#include "globals.h"

extern IDirect3D9Ex* p_Object;
extern IDirect3DDevice9Ex* p_Device;
extern D3DPRESENT_PARAMETERS p_Params;
extern WNDPROC oriWndProc ;

namespace ov
{
	extern bool toggle_menu;
	extern bool toggle_menu2;

	void create_window(bool console = false);
	void setup_directx(HWND hWnd);
	void render();
	void update_overlay();
	WPARAM loop();

	void clean_directx();
}

void draw_esp();
void draw_abigsquare();
void init1();
void update_list();
void main_cheat_handler();