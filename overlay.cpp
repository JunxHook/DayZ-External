#include <iostream>
#include <thread>
#include "overlay.h"
#include "font.h"
#pragma warning(disable : 4996).
IDirect3D9Ex* p_Object = NULL;
IDirect3DDevice9Ex* p_Device = NULL;
D3DPRESENT_PARAMETERS p_Params = { NULL };
WNDPROC oriWndProc = NULL;

bool ov::toggle_menu = 0;
bool ov::toggle_menu2 = 0;
void ov::create_window(bool console)
{
    //if (!console)
    //  ShowWindow(GetConsoleWindow(), SW_HIDE);

    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpszClassName = "CROSSHAIRv2:99991191811";
    wc.lpfnWndProc = WinProc;
    if (!RegisterClassEx(&wc))
        return;

    globals.TargetWnd = FindWindowA(NULL, "DayZ");

    if (globals.TargetWnd)
    {
        globals.Width = GetSystemMetrics(SM_CXSCREEN);
        globals.Height = GetSystemMetrics(SM_CYSCREEN);
        globals.OverlayWnd = (CreateWindowEx)(NULL, "CROSSHAIRv2:99991191811", "CROSS HAIR V.2", WS_POPUP | WS_VISIBLE, 0, 0, globals.Width, globals.Height, 0, 0, 0, 0);

        //SetWindowDisplayAffinity(globals.OverlayWnd, WDA_EXCLUDEFROMCAPTURE);

        const MARGINS Margin = { 0, 0, globals.Width, globals.Height };

        DwmExtendFrameIntoClientArea(globals.OverlayWnd, &Margin);
        (SetWindowLong)(globals.OverlayWnd, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);

        ShowWindow(globals.OverlayWnd, SW_SHOW);
        (UpdateWindow)(globals.OverlayWnd);
    }

    setup_directx(globals.OverlayWnd);
}

void ov::setup_directx(HWND hWnd)
{
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
        exit(3);

    ZeroMemory(&p_Params, sizeof(p_Params));
    p_Params.Windowed = TRUE;
    p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    p_Params.hDeviceWindow = hWnd;
    //SetWindowDisplayAffinity(p_Params.hDeviceWindow, WDA_EXCLUDEFROMCAPTURE);
    //SetWindowDisplayAffinity(hWnd, WDA_EXCLUDEFROMCAPTURE);

    p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
    p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
    p_Params.BackBufferWidth = globals.Width;
    p_Params.BackBufferHeight = globals.Height;
    p_Params.EnableAutoDepthStencil = TRUE;
    p_Params.AutoDepthStencilFormat = D3DFMT_D16;
    p_Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
    {
        p_Object->Release();
        exit(4);
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    //SetWindowDisplayAffinity(hWnd, WDA_EXCLUDEFROMCAPTURE);

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX9_Init(p_Device);
    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.FontDataOwnedByAtlas = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;
    static const ImWchar ranges[] = {

       0x0020, 0x00FF,
       0x0400, 0x052F,
       0x2DE0, 0x2DFF,
       0xA640, 0xA69F,
       0xE000, 0xE226,
       0,
    };
    font_config.GlyphRanges = ranges;
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 14, &font_config, ranges);

    io.Fonts->AddFontFromMemoryCompressedTTF(Cousine_compressed_data, Cousine_compressed_size, 15.f);
    p_Object->Release();
}

void ov::update_overlay()
{
    HWND hwnd_active = GetForegroundWindow();
    if (hwnd_active == globals.TargetWnd)
    {
        HWND temp_hwnd = GetWindow(hwnd_active, GW_HWNDPREV);
        SetWindowPos(globals.OverlayWnd, temp_hwnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
}

void ov::render()
{
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    update_overlay();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0)); // Invisible 
    ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);
    ImGui::Begin(("##scene"), nullptr, ImGuiWindowFlags_NoTitleBar);

    int tWidth = globals.Width; int tHeight = globals.Height;
    if (ov::toggle_menu) {
        HWND hwnd_active = GetForegroundWindow();

        if (hwnd_active == FindWindowA(NULL, "DayZ")) {
            HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
            SetWindowPos(globals.OverlayWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        RECT rc;
        POINT xy;

        ZeroMemory(&rc, sizeof(RECT));
        ZeroMemory(&xy, sizeof(POINT));
        GetClientRect(FindWindowA(NULL, "DayZ"), &rc);
        ClientToScreen(FindWindowA(NULL, "DayZ"), &xy);
        rc.left = xy.x;
        rc.top = xy.y;

        ImGuiIO& io = ImGui::GetIO();
        io.ImeWindowHandle = FindWindowA(NULL, "DayZ");
        io.DeltaTime = 1.0f / 60.0f;

        POINT p;
        GetCursorPos(&p);
        io.MousePos.x = p.x - xy.x;
        io.MousePos.y = p.y - xy.y;

        if (GetAsyncKeyState(VK_LBUTTON)) {
            io.MouseDown[0] = true;
            io.MouseClicked[0] = true;
            io.MouseClickedPos[0].x = io.MousePos.x;
            io.MouseClickedPos[0].x = io.MousePos.y;
        }
        else
            io.MouseDown[0] = false;
        draw_abigsquare();
    }

    if (ov::toggle_menu2)
        draw_abigsquare();

    if (GetAsyncKeyState(VK_F1))
        ov::toggle_menu = 1;

    if (GetAsyncKeyState(VK_F2))
        ov::toggle_menu = 0;

    if (GetAsyncKeyState(VK_F3))
        ov::toggle_menu2 = 1;

    if (GetAsyncKeyState(VK_F4))
        ov::toggle_menu2 = 0;

    main_cheat_handler();

    ImGui::GetWindowDrawList()->PushClipRectFullScreen();
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);

    ImGui::EndFrame();
    p_Device->SetRenderState(D3DRS_ZENABLE, false);
    p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
    p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
    p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

    if (p_Device->BeginScene() >= 0)
    {
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        p_Device->EndScene();
    }
    HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

    if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
    {
        ImGui_ImplDX9_InvalidateDeviceObjects();
        p_Device->Reset(&p_Params);
        ImGui_ImplDX9_CreateDeviceObjects();
    }
}

WPARAM ov::loop()
{
    MSG msg;

    while (true)
    {
        ZeroMemory(&msg, sizeof(MSG));
        if (::PeekMessage(&msg, globals.OverlayWnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        ov::render();
    }
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    clean_directx();
    DestroyWindow(globals.OverlayWnd);

    return msg.wParam;
}

void ov::clean_directx()
{
    if (p_Device != NULL)
    {
        p_Device->EndScene();
        p_Device->Release();
    }
    if (p_Object != NULL)
    {
        p_Object->Release();
    }
}
