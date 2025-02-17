#include <windows.h>
#include <stdio.h>
#include <time.h>
#include<fileapi.h>
#include<winternl.h>
#include<WinUser.h>
#include<libloaderapi.h>
#include<sysinfoapi.h>

extern "C" {
    COLORREF  __declspec(dllexport) __stdcall MyTextColor(HDC hdc, COLORREF crColor);
    HANDLE __declspec(dllexport) __stdcall wrap_CreateFileA(
                   LPCSTR                lpFileName,
                   DWORD                 dwDesiredAccess,
                   DWORD                 dwShareMode,
         LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                   DWORD                 dwCreationDisposition,
                   DWORD                 dwFlagsAndAttributes,
         HANDLE                hTemplateFile
    );
    int __declspec(dllexport) __stdcall wrap_LoadStringA(
         HINSTANCE hInstance,
                   UINT      uID,
                  LPSTR     lpBuffer,
                   int       cchBufferMax
    );
    HGLOBAL __declspec(dllexport) __stdcall wrap_LoadResource(
         HMODULE hModule,
                   HRSRC   hResInfo
    );
    DWORD __declspec(dllexport) __stdcall wrap_GetFileSize(
                    HANDLE  hFile,
         LPDWORD lpFileSizeHigh
    );

    int __declspec(dllexport) __stdcall wrap_GetSystemMetrics(
        int nIndex
    );

    FARPROC __declspec(dllexport) __stdcall wrap_GetProcAddress(
         HMODULE hModule,
         LPCSTR  lpProcName
    );
    void __declspec(dllexport) __stdcall wrap_GetSystemInfo(
         LPSYSTEM_INFO lpSystemInfo
    );
};