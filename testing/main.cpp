#include <windows.h>   // Windows API for LoadLibrary, GetProcAddress, FreeLibrary
#include <iostream>    // For console output

int main() {
    std::cout << "Loading DLL..." << std::endl;  // Tell the user we are loading the DLL

    // Dynamically load the DLL at runtime
    HMODULE hDLL = LoadLibraryA("mal.dll");  // Returns handle to the DLL
    if (!hDLL) {
        // If DLL failed to load, stop the program
        std::cout << "Failed to load DLL!" << std::endl;
        return 1;
    }

    // Define a pointer type for the Init function in the DLL
    typedef void (*InitFunc)();

    // Get the memory address of the Init function inside the DLL
    InitFunc Init = (InitFunc)GetProcAddress(hDLL, "Init");
    
    if (Init) {
        // If function found, call it
        // This runs after the DLL is loaded → SAFE to do work
        Init();  // Shows the MessageBox from the DLL
    } else {
        std::cout << "Failed to find Init function!" << std::endl;
    }

    // When done, unload the DLL
    FreeLibrary(hDLL);  // Cleans up and releases resources

    return 0;  // Program ends successfully
}
