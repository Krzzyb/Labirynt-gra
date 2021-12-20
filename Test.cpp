#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cwchar>
#include <vector>
using namespace std;

void kolor(int k){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void size(int size){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = size;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
int arrayToVector(int tablica[40][20]){
    vector<vector<int>> vtablica(begin(tablica), end(tablica));
    return vtablica;
}
int main(){
    for (int i = 0; i<256; i++){
        kolor(i);
        cout << i<< endl;
    }
    kolor(7);
    for (int i = 0; i<=256; i++){
        cout << i << ". " << char(i)<<endl;
    }
    while(true){
        int i = getch();
        cout << i << endl;
    }
    size(30);
    cout << "Font: Consolas, Size: 24\n";

    int array[40][20] = {0};
    int vtablica = arrayToVector(array);
    for (int i = 0; i < vtablica.size(); i++)
    {
        for (int j = 0; j < vtablica[i].size(); j++)
        {
            cout << vtablica[i][j] << " ";
        }   
        cout << endl;
    }
    return 0;
}