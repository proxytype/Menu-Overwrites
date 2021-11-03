// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>

HWND g_hWnd = NULL;

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

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        EnumWindows(EnumProc, GetCurrentProcessId());

        if (g_hWnd)
        {
            SetWindowText(g_hWnd, L"Limited Notepad!");

            HMENU hMenu = GetMenu(g_hWnd);
            int numMenus = GetMenuItemCount(hMenu);

            for (int i = 1; i < numMenus; i++)
            {
                DeleteMenu(hMenu, 1, MF_BYPOSITION);
            }

            numMenus = GetMenuItemCount(hMenu);
            for (int i = 0; 0 < numMenus; i++)
            {
                HMENU su = GetSubMenu(hMenu, i);
                int subMenus = GetMenuItemCount(su);
                for (int d = 0; d < subMenus; d++)
                {
                    UINT sid = GetMenuItemID(su, d);
                    EnableMenuItem(su, sid, MF_DISABLED);
                }
            }

            DrawMenuBar(g_hWnd);
        }

        break;
    }
    return TRUE;
}


