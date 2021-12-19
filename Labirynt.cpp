#include <time.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <cwchar>
#include <stdlib.h>
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
void legenda(string typ){
    if(typ == "gra"){
        cout << "Kontrola strzalkami:" << char(16) << char(17) << char(30) << char(31) << endl;
        cout << char(3) << " - To sa twoje zycia\n";
        cout << char(15) << " - To sa miny, unikaj ich, jesli na nie wejdziesz, stracisz jedno "<< char(3) << endl;
        cout << char(14) << " - To sa niespodzianki, jesli na nie wejdziesz, mozesz dostac cos przydatnego\n";
        cout << char(127) << " - To jest szpital, jesli do niego wejdziesz, zostaniesz uleczony\n";
        cout << "Kliknij esc, aby zobaczyc menu\n";
        
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
                if (tablica[j][i] == 5){
                    kolory(128);
                    cout << char(158);
                }
            }
            
        }
        cout << endl;
    }
    kolory(7);
    legenda("gra");
}

void randPath(int tabela[40][20]) {
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
    kolory(7);
    int n = 0;
    while (true){
        system("CLS");
        cout << "Wybierz poziom:\n";
        if (n == 0) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Easy\n";
        kolory(7);
        if (n == 1) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Medium\n";
        kolory(7);
        if (n == 2) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Hard\n";
        kolory(7);
        if (n == 3) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Custom\n";
        kolory(7);
        int i = getch();
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 3) n++;
        }
        if(i == 13){
            switch (n){
            case 0:
                bombs = 50;
                boxes = 30;
                hospitals = 15;
                lives = 8;
                return;
            case 1:
                bombs = 80;
                boxes = 20;
                hospitals = 8;
                lives = 5;
                return;
            case 2:
                bombs = 150;
                boxes = 10;
                hospitals = 3;
                lives = 3;
                return;
            case 3:
                do{
                    cout << "___Nowa gra___\n" << "wybierz opcje:\n";
                    cout << "Pamietaj, ze ich suma nie moze przekroczyc: 740\n";
                
                    cout << "Ile bomb?  -  ";
                    cin >> bombs;
                    cout << endl;
                    cout << "Ile niespodzianek?  -  ";
                    cin >> boxes;
                    cout << endl;
                    cout << "Ile szpitali?  -  ";
                    cin >> hospitals; 
                    cout << endl;
                    system("CLS");
                }while(740 < bombs + boxes + hospitals);
                cout << "Ile zyc?  -  ";
                cin >> lives;
                return;
            }
        }

    }
    
}
void randItems(int tabela[40][20], int bombs, int boxes, int hospitals) {
    srand(time(NULL));
    int X = 0, Y = 0;

    for (int i = 0; i < bombs; i++) {
        X = rand() % 40;
        Y = rand() % 20;
        cout << "Losowanie bomb...\n";
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 2;
            cout << "Znaleziono miejsce:" << X << ", " << Y << endl; 
        }else i--;
    }
    for (int i = 0; i < boxes; i++){
        X = rand() % 40;
        Y = rand() % 20;
        cout << "Losowanie niespodzianek...\n";
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 3;
            cout << "Znaleziono miejsce:" << X << ", " << Y << endl; 
        }else i--;
    }
    for (int i = 0; i < hospitals; i++){
        X = rand() % 40;
        Y = rand() % 20;
        cout << "Losowanie szpitali...\n";
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 4;
            cout << "Znaleziono miejsce:" << X << ", " << Y << endl; 
        }else i--;
    }
    system("pause");
    system("CLS");
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
        if (n == 0) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Kontynuuj\n";
        kolory(7);
        if (n == 1) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Zapisz gre\n";
        kolory(7);
        if (n == 2) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Zaladuj gre\n";
        kolory(7);
        if (n == 3) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wyjdz z gry\n";
        kolory(7);
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
                exit(0);
            }
        }

    }
    
}
void przebieg(int tabela[40][20], int lives){
    int x = 0, y = 0;
    int setlives = lives;
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
                tabela[x][y] = 5;
                lives--;
            }
            if(tabela[x][y] == 3){
                
            }
            if(tabela[x][y] == 4){
                lives = setlives;
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
        if (n == 0){ 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Nowa gra\n";
        kolory(7);
        if (n == 1){
            kolory(1); 
            cout << " " << char(175) << " ";
            }
        cout << "Zaladuj gre\n";
        kolory(7);
        if (n == 2){ 
            kolory(1);
            cout << " " << char(175) << " ";
        }
        cout << "Opcje\n";
        kolory(7);
        if (n == 3){
            kolory(1);
            cout << " " << char(175) << " ";
        }
        cout << "Wyjdz z gry\n";
        kolory(7);
        int i = getch();
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 3) n++;
        }
        if(i == 13){
            switch (n){
            case 0:
                
                randPath(tabela);
                newGameOptions(bombs, boxes, hospitals, lives);
                system("CLS");
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
                exit(0);
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