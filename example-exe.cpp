#include <iostream>
#include <windows.h>


using namespace std;

int main() {
    cout << "Loading DLL..." << endl;
    HINSTANCE hDLL; 
    hDLL = LoadLibrary (TEXT("mal.dll"));

    return 0;
}   