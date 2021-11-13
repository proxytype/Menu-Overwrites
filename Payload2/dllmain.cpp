// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <WinUser.h>

const int CALC = 9111;
const int PAINT = 9112;

HWND g_hWnd = NULL;
WNDPROC wndProcOriginal = NULL;




BOOL CALLBACK EnumProc(HWND hWnd, LPARAM p)
{
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);

    if (p == pid)
    {
        g_hWnd = hWnd;
        return FALSE;
    }

    return TRUE;
}

LRESULT APIENTRY FilterProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_COMMAND)
    {
        if (LOWORD(wParam) == CALC)
        {
            OutputDebugString(L"Running Calculator");
            WinExec("calc.exe", SW_NORMAL);
            return NULL;
        }
        else if (LOWORD(wParam) == PAINT)
        {
            OutputDebugString(L"Running Paint");
            WinExec("mspaint.exe", SW_NORMAL);
            return NULL;
        }
    }

    return CallWindowProc(wndProcOriginal, hwnd, uMsg, wParam, lParam);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        EnumWindows(EnumProc, GetCurrentProcessId());
        Sleep(1000);
        if (g_hWnd)
        {

            HMENU hMenu = GetMenu(g_hWnd);
            HMENU hDropdown = CreatePopupMenu();

            AppendMenu(hDropdown, MF_STRING, CALC, L"Calculator");
            AppendMenu(hDropdown, MF_STRING, PAINT, L"Paint");

            AppendMenu(hMenu, MF_STRING | MF_ENABLED | MF_POPUP, (UINT_PTR)hDropdown, L"Tools");

            //x64
            wndProcOriginal = (WNDPROC)SetWindowLongPtr(g_hWnd, GWLP_WNDPROC, (LONG_PTR)FilterProc);

            //x32
            //wndProcOriginal = (WNDPROC)SetWindowLong(g_hWnd, GWL_WNDPROC, (LONG)(WNDPROC)FilterProc);


            DrawMenuBar(g_hWnd);

        }

        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

