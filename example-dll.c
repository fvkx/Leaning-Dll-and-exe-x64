BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hInst);
    }
    return TRUE;
}



__declspec(dllexport)
void Init() {
    MessageBoxA(NULL, "DLL Initialized Safely", "Info", MB_OK);
}
