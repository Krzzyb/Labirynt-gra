#include <time.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
void kolory(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void pokaz(int tablica[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << " " << tablica[j][i];
        }
        cout << endl;
    }
}

void prettyShow(int tablica[20][20], int x, int y) {

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (y == i && x == j) {
                kolory(1);
                cout << char(1);
            }
            else {
                if (tablica[j][i] == 2) {
                    kolory(4);
                    cout << char(15);
                }
                if (tablica[j][i] == 1) {
                    kolory(10);
                    cout << char(176);
                }
                if (tablica[j][i] == 0) {
                    kolory(15);
                    cout << char(219);
                }

            }
            
        }
        cout << endl;
    }
}



void randPath(int tabela[20][20] = {0}) {
    srand(time(NULL));
    int I, X = 0, Y = 0;
    tabela[X][Y] = 1;
    while (tabela[19][19] == 0) {
        I = rand() % 2;
        if (I == 0 && X + 1 != 20) {
            X++;
            tabela[X][Y] = 1;
        }
        if (I == 1 && Y + 1 != 20) {
            Y++;
            tabela[X][Y] = 1;
        }
    }
}
void randItems(int tabela[20][20]) {
    srand(time(NULL));
    int X = 0, Y = 0, amount = 80;

    for (int i = 0; i <= amount; i++) {
        X = rand() % 20;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 2;
        }
    }
}
void livescounter(int lives){
    for(int i=0; i<lives; i++){
        kolory(4);
        cout<<char(3);
    }
}

void przebieg(int tabela[20][20], int lives){
    int x = 0, y = 0;
    livescounter(lives);
    cout << endl;
    prettyShow(tabela,x,y);
     while (lives>0) {
        int rozmiar = 20;
        int i = getch();
        if (i == 0 || i == 224){
            i = getch();
            if (i == 72) y--;
            else if (i == 80) y++;
            else if (i == 75) x--;
            else if (i == 77) x++;

            // teleport
            /*y = (y + rozmiar) % rozmiar;
            x = (x + rozmiar) % rozmiar;*/
            // ściany
            if (y < 0) y = 0;
            else if (y >= rozmiar) y = rozmiar - 1;
            if (x < 0) x = 0;
            else if (x >= rozmiar) x = rozmiar - 1;
            system("CLS");
            if(tabela[x][y] == 2){
                lives--;
            }
            if( x == 19 && y == 19){
                cout<<"koniec gry";
                break;
            }
            livescounter(lives);
            cout<<endl;
            prettyShow(tabela,x,y);
        }
    }
}
int main()
{
    int tabela[20][20] = { 0 };
    randPath(tabela);
    randItems(tabela);
    przebieg(tabela,3);
}