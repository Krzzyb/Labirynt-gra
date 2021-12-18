#include <time.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <cwchar>
using namespace std;
void kolory(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void textSize (int size){
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
void pokaz(int tablica[40][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            cout << " " << tablica[j][i];
        }
        cout << endl;
    }
}

void prettyShow(int tablica[40][20], int x, int y) {

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (y == i && x == j) {
                kolory(1);
                cout << char(1);
            }
            else {
                if (tablica[j][i] == 2) {
                    kolory(100);
                    cout << char(15);
                }
                if (tablica[j][i] == 1) {
                    kolory(10);
                    cout << char(176);
                }
                if (tablica[j][i] == 0) {
                    kolory(102);
                    cout << char(219);
                }
                if (tablica[j][i] == 3){
                    kolory(109);
                    cout << char(14);
                }
                if (tablica[j][i] == 4){
                    kolory(108);
                    cout << char(127);
                }
            }
            
        }
        cout << endl;
    }
    kolory(0);
}



void randPath(int tabela[40][20] = {0}) {
    srand(time(NULL));
    int I, X = 0, Y = 0;
    tabela[X][Y] = 1;
    while (tabela[39][19] == 0) {
        I = rand() % 2;
        if (I == 0 && X + 1 != 40) {
            X++;
            tabela[X][Y] = 1;
        }
        if (I == 1 && Y + 1 != 20) {
            Y++;
            tabela[X][Y] = 1;
        }
    }
}
void newGameOptions(int &bombs, int &boxes, int &hospitals, int &lives){
    system("CLS");
    cout << "___Nowa gra___\n" << "wybierz opcje:\n";
    cout << "Ile bomb?  -  ";
    cin >> bombs;
    cout << endl;
    cout << "Ile niespodzianek?  -  ";
    cin >> boxes;
    cout << endl;
    cout << "Ile szpitali?  -  ";
    cin >> hospitals; 
    cout << endl;
    cout << "Ile zyc?  -  ";
    cin >> lives;
}
void randItems(int tabela[40][20], int bombs, int boxes, int hospitals) {
    srand(time(NULL));
    int X = 0, Y = 0;

    for (int i = 0; i <= bombs; i++) {
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 2;
        }
    }
    for (int i = 0; i<=boxes; i++){
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 3;
        }
    }
    for (int i = 0; i<=hospitals; i++){
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 4;
        }
    }
}
void livescounter(int lives){
    for(int i=0; i<lives; i++){
        kolory(4);
        cout<<char(3);
    }
}


void menu(int tabela [40][20], int x, int y, int lives){
    system("CLS");
    kolory(7);
    int n = 0;
    while (true){
        system("CLS");
        cout << "____MENU____\n";
        if (n == 0) cout << " " << char(16) << " ";
        cout << "Kontynuuj\n";
        if (n == 1) cout << " " << char(16) << " ";
        cout << "Zapisz gre\n";
        if (n == 2) cout << " " << char(16) << " ";
        cout << "Zaladuj gre\n";
        if (n == 3) cout << " " << char(16) << " ";
        cout << "Wyjdz z gry\n";
        int i = getch();
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 3) n++;
        }
        if(i == 13){
            switch (n){
            case 0:
                system("CLS");
                livescounter(lives);
                cout << endl;
                prettyShow(tabela,x,y);
                return;
            case 1:
                system("CLS");
                break;
            case 2:
                system("CLS");
                break;
            case 3:
                system("CLS");
                break;
            }
        }

    }
    
}
void przebieg(int tabela[40][20], int lives){
    int x = 0, y = 0;
    livescounter(lives);
    cout << endl;
    prettyShow(tabela,x,y);
     while (lives>0) {
        int rozmiary = 20, rozmiarx = 40;
        int i = getch();
        if (i == 27) menu(tabela, x, y, lives);
        if (i == 0 || i == 224){
            i = getch();
            if (i == 72) y--;
            else if (i == 80) y++;
            else if (i == 75) x--;
            else if (i == 77) x++;
            
            if (y < 0) y = 0;
            else if (y >= rozmiary) y = rozmiary - 1;
            if (x < 0) x = 0;
            else if (x >= rozmiarx) x = rozmiarx - 1;
            system("CLS");
            if(tabela[x][y] == 2){
                lives--;
            }
            if(tabela[x][y] == 3){
                
            }
            if( x == 39 && y == 19){
                cout<<"koniec gry";
                break;
            }
            livescounter(lives);
            cout<<endl;
            prettyShow(tabela,x,y);
        }
    }
}
void mainOptions(int &size){
    cout << "___ main Options ___\n";
    cout << "Wielkosc tekstu: - \n";
    cin >> size;
    textSize(size);
}
void startMenu(int tabela [40][20] = {0}){
    kolory(7);
    int n = 0;
    int bombs, boxes, hospitals, lives, size;
    while (true){
        system("CLS");
        cout << "____main MENU____\n";
        if (n == 0) cout << " " << char(16) << " ";
        cout << "Nowa gra\n";
        if (n == 1) cout << " " << char(16) << " ";
        cout << "Zaladuj gre\n";
        if (n == 2) cout << " " << char(16) << " ";
        cout << "Opcje\n";
        if (n == 3) cout << " " << char(16) << " ";
        cout << "Wyjdz z gry\n";
        int i = getch();
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 3) n++;
        }
        if(i == 13){
            switch (n){
            case 0:
                newGameOptions(bombs, boxes, hospitals, lives);
                system("CLS");
                randPath(tabela);
                randItems(tabela, bombs, boxes, hospitals);
                przebieg(tabela, lives);
                return;
            case 1:
                system("CLS");
                break;
            case 2:
                mainOptions(size);
                break;
            case 3:
                system("CLS");
                break;
            }
        }

    }
}
int main()
{
    int tabela[40][20] = { 0 };
    textSize(20);
    startMenu(tabela);
}