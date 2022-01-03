#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cwchar>
#include <vector>
#include <time.h>
using namespace std;
int X, Y;
int **tablica;
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
void randPath() {
    srand(time(NULL));
    int I, x = 0, y = 0;
    tablica[x][y] = 1;
    while (tablica[X-1][Y-1] == 0) {
        I = rand() % 2;
        if (I == 0 && x+1 != X) {
            x++;
            tablica[x][y] = 1;
        }
        if (I == 1 && y+1  != Y) {
            y++;
            tablica[x][y] = 1;
        }
    }
}
void create(){
    tablica = new int*[Y];
    for(int j = 0; j < Y; j++){
        tablica[j] = new int[X];
    }
    cout << "Succesfully created\n";
}
void pokaz() {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << " " << tablica[j][i];
        }
        cout << endl;
    }
    cout << "Succesfully wrote";
}
void resetArray(){
    for(int j = 0; j < Y; j++){
        for(int i = 0; i < X; i++){
            tablica[j][i] = 0;
        }
    }
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

    size(20);
    cout << "Font: Consolas, Size: 24\n";

    
    
    X = 10, Y = 10;
    create();
    resetArray();
    randPath();
    pokaz();
    getchar();
    return 0;
}