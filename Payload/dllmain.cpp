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
            //SetWindowText(g_hWnd, L"Limited Notepad!");

            HMENU hMenu = GetMenu(g_hWnd);
            int numMenus = GetMenuItemCount(hMenu);

            for (int i = 0; i < numMenus; i++)
            {
                if (i == 0) {
                    HMENU su = GetSubMenu(hMenu, i);
                    int subMenus = GetMenuItemCount(su);
                    for (int d = 0; d < subMenus - 1; d++)
                    {
                        UINT sid = GetMenuItemID(su, d);
                        if (sid != -1) {
                            EnableMenuItem(su, sid, MF_DISABLED);
                        }

                    }

                    continue;
                }

                DeleteMenu(hMenu, 1, MF_BYPOSITION);
            }

           
           //SendMessage(g_hWnd, 0x1e2, 0, 0);
            //UpdateWindow(g_hWnd);
           DrawMenuBar(g_hWnd);
          
            
        }

        break;
    }
    return TRUE;
}


