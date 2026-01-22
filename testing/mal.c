#include <windows.h>  // Include Windows API definitions (HINSTANCE, WINAPI, MessageBox, etc.)

// DLL entry point called automatically by Windows when DLL is loaded/unloaded
BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    // Check why Windows is calling DllMain
    if (fdwReason == DLL_PROCESS_ATTACH) {
        // DLL is being loaded into the process
        DisableThreadLibraryCalls(hInstDLL);  
        // Tell Windows not to call us for thread creation/destruction
        // This avoids unnecessary calls and potential deadlocks
    }

    // Always return TRUE to indicate DLL loaded successfully
    return TRUE;
}

// This is the function that EXE will call explicitly
// We export it so other programs can find it
__declspec(dllexport)
void Init(void)
{
    // Safe to do real work here (runs after DLL fully loaded)
    // Display a simple MessageBox as a “Hello World” example
    MessageBoxA(NULL, "DLL Initialized Safely", "Info", MB_OK);
}
