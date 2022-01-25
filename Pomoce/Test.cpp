#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cwchar>
#include <vector>
#include <time.h>
#include <cmath>
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
void win()
{
Beep (330,100);Sleep(100);
Beep (330,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (330,100);Sleep(300);
Beep (392,100);Sleep(700);
Beep (196,100);Sleep(700);
Beep (262,300);Sleep(300);
Beep (196,300);Sleep(300);
Beep (164,300);Sleep(300);
Beep (220,300);Sleep(100);
Beep (246,100);Sleep(300);
Beep (233,200);
Beep (220,100);Sleep(300);
Beep (196,100);Sleep(150);
Beep (330,100);Sleep(150);
Beep (392,100);Sleep(150);
Beep (440,100);Sleep(300);
Beep (349,100);Sleep(100);
Beep (392,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(100);
Beep (247,100);Sleep(500);
Beep (262,300);Sleep(300);
Beep (196,300);Sleep(300);
Beep (164,300);Sleep(300);
Beep (220,300);Sleep(100);
Beep (246,100);Sleep(300);
Beep (233,200);
Beep (220,100);Sleep(300);
Beep (196,100);Sleep(150);
Beep (330,100);Sleep(150);
Beep (392,100);Sleep(150);
Beep (440,100);Sleep(300);
Beep (349,100);Sleep(100);
Beep (392,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(100);
Beep (247,100);Sleep(900);
Beep (392,100);Sleep(100);
Beep (370,100);Sleep(100);
Beep (349,100);Sleep(100);
Beep (311,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (207,100);Sleep(100);
Beep (220,100);Sleep(100);
Beep (262,100);Sleep(300);
Beep (220,100);Sleep(100);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(500);
Beep (392,100);Sleep(100);
Beep (370,100);Sleep(100);
Beep (349,100);Sleep(100);
Beep (311,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (523,100);Sleep(300);
Beep (523,100);Sleep(100);
Beep (523,100);Sleep(1100);
Beep (392,100);Sleep(100);
Beep (370,100);Sleep(100);
Beep (349,100);Sleep(100);
Beep (311,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (207,100);Sleep(100);
Beep (220,100);Sleep(100);
Beep (262,100);Sleep(300);
Beep (220,100);Sleep(100);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(500);
Beep (311,300);Sleep(300);
Beep (296,300);Sleep(300);
Beep (262,300);Sleep(1300);
Beep (262,100);Sleep(100);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(300);
Beep (330,200);Sleep(50);
Beep (262,200);Sleep(50);
Beep (220,200);Sleep(50);
Beep (196,100);Sleep(700);
Beep (262,100);Sleep(100);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(100);
Beep (330,100);Sleep(700);
Beep (440,100);Sleep(300);
Beep (392,100);Sleep(500);
Beep (262,100);Sleep(100);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (294,100);Sleep(300);
Beep (330,200);Sleep(50);
Beep (262,200);Sleep(50);
Beep (220,200);Sleep(50);
Beep (196,100);Sleep(700);
/*Intro*/
Beep (330,100);Sleep(100);
Beep (330,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (330,100);Sleep(300);
Beep (392,100);Sleep(700);
Beep (196,100);Sleep(700);
Beep (196,100);Sleep(125);
Beep (262,100);Sleep(125);
Beep (330,100);Sleep(125);
Beep (392,100);Sleep(125);
Beep (523,100);Sleep(125);
Beep (660,100);Sleep(125);
Beep (784,100);Sleep(575);
Beep (660,100);Sleep(575);
Beep (207,100);Sleep(125);
Beep (262,100);Sleep(125);
Beep (311,100);Sleep(125);
Beep (415,100);Sleep(125);
Beep (523,100);Sleep(125);
Beep (622,100);Sleep(125);
Beep (830,100);Sleep(575);
Beep (622,100);Sleep(575);
Beep (233,100);Sleep(125);
Beep (294,100);Sleep(125);
Beep (349,100);Sleep(125);
Beep (466,100);Sleep(125);
Beep (587,100);Sleep(125);
Beep (698,100);Sleep(125);
Beep (932,100);Sleep(575);
Beep (932,100);Sleep(125);
Beep (932,100);Sleep(125);
Beep (932,100);Sleep(125);
Beep (1046,675);
}
int main(){
    PlaySound(("Testsound"), NULL,SND_SYNC);
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

    
    
    X = 20, Y = 10;
    create();
    resetArray();
   // randPath();
    //pokaz();
    getchar();
    //win();
    Beep (400,300);Sleep(125);
    Beep (300,300);Sleep(125);
    Beep (200,500);Sleep(125);
    float cos = 3.00*(X*Y-X-Y)/740;
    cout << ceil(cos); 
    getchar();
    return 0;
}