// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#pragma data_seg("Shared")

_declspec(allocate("Shared")) char someString[1024] = {0};

#pragma data_seg()

#pragma comment(linker, "/SECTION:Shared,RWS")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

HANDLE sEvent = CreateEvent(NULL, FALSE, FALSE, "SendEvent");


extern "C"
{
    _declspec(dllexport) void _stdcall SetData(char* _str, int len, int t_idx)
    {
        memcpy(someString, _str, len);
        SetEvent(sEvent);
    }

    _declspec(dllexport) char* _stdcall GetStr()
    {
        return someString;
    }

}