/*
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Resources : https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

*/

#include <cstdlib>
#include <iostream>
#include <windows.h>

#define gProc hProc

// The hotkeys
#define ALT VK_MENU

// GTA:SA window
HWND GTASA;

using namespace std;

int hesoyam = 0x969133;

// Get GTA:SA window
bool get_gta_window(HWND GTA)
{
    GTA = FindWindow(NULL, "GTA:SA");
}

void healtharmourmoney(int amt)
{
    DWORD dwID;
    HANDLE hProc;

    HWND sa;
    get_gta_window(sa);
    GetWindowThreadProcessId(sa, &dwID);
    hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, dwID);
    WriteProcessMemory(hProc, (LPVOID)hesoyam, (LPVOID)amt, sizeof(amt), NULL );

}

void get_hot_keys()
{
while(1)
            {
                if(GetAsyncKeyState(ALT) && GetAsyncKeyState(0x51)) //Q key
                {
                        healtharmourmoney;
                }
        	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[])
{
    printf("ALT + Q = Get health, armour, and money.\n");
    while(1)
    {
            if(get_gta_window(GTASA))
            { 
            get_hot_keys();
             }
            
    }
}
