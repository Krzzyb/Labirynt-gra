#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

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
void equipment(string wyposazenie){
    cout << "____Twoje wyposazenie____\n";
    if(wyposazenie == "nic"){
        cout << "Jeszcze nic nie masz, wejdz na pole ";
        kolory(13);
        cout << char(14); 
        kolory(7);
        cout << " ,aby wylosowac element wyposazenia.\n";
    }
    if(wyposazenie == "wykrywacz"){
        cout << " - wykrywacz metalu (dziala na kratke do przodu, do tylu i na boki)\n";
    }
    if(wyposazenie == "sonar"){
        cout << " - wykrywacz metalu (dziala na kratke do przodu, do tylu i na boki\n";
        cout << " - sonar (dziala jak wykrywacz metalu, ale na wieksza odleglosc\n";
    }
    cout << "________________________________________\n";
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
// już nieaktualna funkcja
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (y == i && x == j) {
                kolory(98);
                cout << char(197);
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
                if(tablica[j][i] == 6){
                    kolory(104);
                    cout << char(14);
                }
            }
            
        }
        cout << endl;
    }
    kolory(7);
    //legenda("gra");
}
void darkShow(int tablica[40][20], int x, int y, string wyposazenie){
    if(wyposazenie == "nic"){
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if(y == i && x == j){
                    kolory(97);
                    cout << char(1);
                }else{
                    if (tablica[j][i] == 4){
                        kolory(108);
                        cout << char(127);
                    }
                    if(tablica[j][i] == 3){
                        kolory(109);
                        cout << char(14);
                    }
                    if(tablica[j][i] == 0 || tablica[j][i] == 1 || tablica[j][i] == 2){
                        kolory(108);
                        cout << " ";
                    }
                    if(tablica[j][i] == 5){
                        kolory(128);
                        cout << char(158);
                    }
                    if(tablica[j][i] == 6){
                        kolory(104);
                        cout << char(14);
                    }
                }
                
            }
            cout << endl;
        }
    }
    bool check = false;
    if(wyposazenie == "wykrywacz"){
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if(y == i && x == j){
                    kolory(97);
                    cout << char(1);
                    check = true;
                }
                if((y-1 == i && x == j)||(y == i && x-1 == j)||(y+1 == i && x == j)||(y == i && x+1 == j)){
                    if (tablica[j][i] == 2) {
                        kolory(100);
                        cout << char(15);
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
                    if (tablica[j][i] == 1){
                        kolory(102);
                        cout << char(219);
                    }
                    if(tablica[j][i] == 6){
                        kolory(104);
                        cout << char(14);
                    }
                }
                else if(check == false){
                    if (tablica[j][i] == 4){
                        kolory(108);
                        cout << char(127);
                    }
                    if(tablica[j][i] == 3){
                        kolory(109);
                        cout << char(14);
                    }
                    if(tablica[j][i] == 0 || tablica[j][i] == 1 || tablica[j][i] == 2){
                        kolory(108);
                        cout << " ";
                    }
                    if(tablica[j][i] == 5){
                        kolory(128);
                        cout << char(158);
                    }
                    if(tablica[j][i] == 6){
                        kolory(104);
                        cout << char(14);
                    }
                    
                }
               check = false; 
            }
            
            cout << endl;
        }

    }

    if(wyposazenie == "sonar"){
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if(y == i && x == j){
                    kolory(97);
                    cout << char(1);
                    check = true;
                }
                if((y-1 == i && x == j)||(y-2 == i && x == j)||
                    (y == i && x-1 == j)||(y == i && x-2 == j)||
                    (y+1 == i && x == j)||(y+2 == i && x == j)||
                    (y == i && x+1 == j)||(y == i && x+2 == j)||
                    (y-1 == i && x-1 == j)||(y+1 == i && x+1 == j)||
                    (y-1 == i && x+1 == j)||(y+1 == i && x-1 ==j)){
                    if (tablica[j][i] == 2) {
                        kolory(100);
                        cout << char(15);
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
                    if (tablica[j][i] == 1){
                        kolory(102);
                        cout << char(219);
                    }
                    if(tablica[j][i] == 6){
                        kolory(104);
                        cout << char(14);
                    }
                }
                else if(check == false){
                    if (tablica[j][i] == 4){
                        kolory(108);
                        cout << char(127);
                    }
                    if(tablica[j][i] == 3){
                        kolory(109);
                        cout << char(14);
                    }
                    if(tablica[j][i] == 0 || tablica[j][i] == 1 || tablica[j][i] == 2){
                        kolory(108);
                        cout << " ";
                    }
                    if(tablica[j][i] == 5){
                        kolory(128);
                        cout << char(158);
                    }
                    if(tablica[j][i] == 6){
                        kolory(104);
                        cout << char(14);
                    }
                    
                }
               check = false; 
            }
            
            cout << endl;
        }

    }
    kolory(7);
    equipment(wyposazenie);
    legenda("gra");
}
void randEquip(string &wyposazenie, int luckFactor){
    srand(time(NULL));
    int i = 0;
    if(wyposazenie == "sonar"){}
    if(wyposazenie == "wykrywacz"){
        i = rand() %10;
        if(i < luckFactor){
            wyposazenie = "sonar";
        }
    }
    if(wyposazenie == "nic"){
        i = rand() %10;
        if(i < luckFactor + 2){
            wyposazenie = "wykrywacz";
        }
    }
}
void saveSettings(int size, bool pasekLadowania){
    string pasekLadowaniaString;
    if (pasekLadowania == true){
        pasekLadowaniaString = "true";
    } 
    if (pasekLadowania == false){
        pasekLadowaniaString = "false";
    }
    fstream plik;
    plik.open("C:\\Intel\\Labirynt_gra\\settings.txt", ios::out);
    plik << "text size: \n" << size << endl;
    plik << "pasek ladowania: \n" << pasekLadowaniaString << endl;
    plik.close();
}
void loadSettings(int &size, bool &pasekLadowania){
    fstream plik;
    string linijka;
    plik.open("C:\\Intel\\Labirynt_gra\\settings.txt", ios::in);
    if(plik.is_open()){
        getline(plik, linijka);
        getline(plik, linijka);
        size = stoi(linijka);
        getline(plik, linijka);
        getline(plik, linijka);
        if(linijka == "true"){
            pasekLadowania = true;
        }
        if(linijka == "false"){
            pasekLadowania = false;
        }
    }else{
        cout << "Nie otwarto pliku" << endl;
    }
    plik.close();
}
void loadGame(int tablica[40][20], int &x, int &y, int &lives, int &luckFactor, string &wyposazenie){
    fstream plik;
    string linijka;
    plik.open("C:\\Intel\\Labirynt_gra\\zapis_gry.txt", ios::in);
    if(plik.is_open()){
        getline(plik, linijka);
        getline(plik, linijka);
        lives = stoi(linijka);
        getline(plik, linijka);
        getline(plik, linijka);
        x = stoi(linijka);
        getline(plik, linijka);
        y = stoi(linijka);
        getline(plik, linijka);
        getline(plik, linijka);
        luckFactor = stoi(linijka);
        getline(plik, linijka);
        getline(plik, linijka);
        wyposazenie = linijka;
        for (int i = 0; i < 20; i++) {
            getline(plik, linijka);
            for (int j = 0; j < 40; j++) {
                tablica[j][i] = linijka[j] - 48;
            }
        }
    }else{
        cout << "Nie otwarto pliku" << endl;
    }
    plik.close();
    cout << lives << " " << x << " " << y << endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            cout << " " << tablica[j][i];
        }
        cout << endl;
    }
    system("CLS");
}
void saveGame (int tablica[40][20], int x, int y, int lives, int luckFactor, string wyposazenie){
    string nazwa = "C:\\Intel\\Labirynt_gra\\";
    string tmp = "zapis_gry";
    //cin >> tmp; moze gdzies w przyszlosci zostanie dodane menu roznych zapisow gry
    tmp = nazwa + tmp + ".txt";
    fstream plik;
    plik.open(tmp.c_str(), ios::out);
    plik << "lives: \n" << lives << endl;
    plik << "player coordinates: \n" << x << endl << y << endl;
    plik << "luckFactor: \n" << luckFactor << endl;
    plik << "equipment: \n" << wyposazenie << endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            plik << tablica[j][i];
        }
        plik << endl;
    }
    plik.close();
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
void newGameOptions(int &bombs, int &boxes, int &hospitals, int &lives, int &luckFactor){
    bombs = 0;
    boxes = 0;
    hospitals = 0;
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
                luckFactor = 5;
                return;
            case 1:
                bombs = 80;
                boxes = 20;
                hospitals = 8;
                lives = 5;
                luckFactor = 2;
                return;
            case 2:
                bombs = 150;
                boxes = 10;
                hospitals = 3;
                lives = 3;
                luckFactor = 0;
                return;
            case 3:
                do{
                    system("CLS");
                    cout << "___Nowa gra___\n" << "Wpisz wartosci:\n";
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
                cout << "Jaki luckFactor?\n" << "(jest to wartosc od 0 do 10, ktora definuje szczescie w losowaniu wyposazenia";
                cout << " - jesli chcesz miec pewnosc, ze zawsze cos wylosujesz, wpisz wartosc wieksza od 10)";
                cin >> luckFactor;
                return;
            }
        }

    }
    
}
void randItems(int tabela[40][20], int bombs, int boxes, int hospitals, bool pasekLadowania) {
    srand(time(NULL));
    int X = 0, Y = 0;
    
    for (int i = 0; i < bombs; i++) {
    
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 2;
        }else i--;
        cout << "Losowanie min...\n";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50 * i / bombs; n++ ){
                cout << char(178);
            }
            for(int j=0; j < 50 - 50 * i / bombs; j++){
                cout << " ";
            }
            cout << "|"; 
            //getchar();
            system("CLS");
        }
    }
    for (int i = 0; i < boxes; i++){
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 3;
        }else i--;
        cout << "Losowanie niespodzianek...\n";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50 * i / boxes; n++ ){
                cout << char(178);
            }
            for(int j=0; j < 50 - 50 * i / boxes; j++){
                cout << " ";
            }
            cout << "|"; 
            //getchar();
            system("CLS");
        }
    }
    for (int i = 0; i < hospitals; i++){
        X = rand() % 40;
        Y = rand() % 20;
        if (tabela[X][Y] == 0) {
            tabela[X][Y] = 4;
        }else i--;
        cout << "Losowanie szpitali...\n";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50 * i / hospitals; n++ ){
                cout << char(178);
            }
            for(int j=0; j < 50 - 50 * i / hospitals; j++){
                cout << " ";
            }
            cout << "|"; 
            //getchar();
            system("CLS");
        }
    }
    cout << "Zakonczono losowanie, nacisnij ENTER, aby rozpoczac gre";
    getchar();
    system("CLS");
}
void livescounter(int lives){
    for(int i=0; i<lives; i++){
        kolory(4);
        cout<<char(3);
    }
}
void resetArray(int tabela[40][20] = {0}){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            tabela[j][i] = 0;
        }
    }
}
int menu(int tabela [40][20], int x, int y, int lives, int luckFactor, string wyposazenie){
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
        if (n == 1){ 
            kolory(1);
            cout << " " << char(175) << " ";
        }
        cout << "Zapisz gre\n";
        kolory(7);
        if (n == 2){ 
            kolory(1);
            cout << " " << char(175) << " ";
        }
        cout << "Wyjdz do main Menu\n";
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
                system("CLS");
                livescounter(lives);
                cout << endl;
                darkShow(tabela,x,y,"nic");
                return 1;
            case 1:
                system("CLS");
                saveGame(tabela, x, y, lives, luckFactor, wyposazenie);
                cout << "Zapisano";
                break;
            case 2:
                return 0;
            case 3:
                exit(0);
            }
        }

    }
    
    
}
void przebieg(int tabela[40][20], int lives, int x, int y, int luckFactor, string wyposazenie){
    int setlives = lives;
    livescounter(lives);
    cout << endl;
    darkShow(tabela,x,y,wyposazenie);
    while (lives>0) {
        int rozmiary = 20, rozmiarx = 40;
        int i = getch();
        if (i == 27){
            int wynikMenu = menu(tabela, x, y, lives, luckFactor, wyposazenie);
            if(wynikMenu == 0){
                return;
            }
        } 
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
                randEquip(wyposazenie, luckFactor);
                tabela[x][y] = 6;
            }
            if(tabela[x][y] == 4){
                lives = setlives;
            }
            if( x == 39 && y == 19){
                cout<<"Gratulacje! Dotarles do punktu zbiorki - jestes teraz bezpieczny.\n";
                cout << "Nacisnij ENTER, aby wrocic do main Menu";
                getchar();
                break;
            }
            livescounter(lives);
            cout<<endl;
            darkShow(tabela,x,y,wyposazenie);
        }
    }
    system("CLS");
    cout << "Koniec gry, straciles wszystkie swoje zycia\n";
    cout << endl;
    cout << "Oto plansza po ktorej sie poruszales:\n";
    prettyShow(tabela, x,y);
    cout << endl;
    cout << "nacisnij ENTER, aby wrocic do main Menu\n";
    getchar();
}
void mainOptions(int &size, bool &pasekLadowania){
    kolory(7);
    int n = 0;
    while (true){
        system("CLS");
        cout << "Aktualne ustawienia:\n" << "Wielkosc obrazu: " << size << endl;
        cout << "Pasek ladowania: ";
        if(pasekLadowania == true){
            cout << "wlaczony\n";
        }else{
            cout << "wylaczony\n";
        }
        cout << endl;
        cout << "____Opcje wielkosci obrazu____\n";
        if (n == 0) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Male(10)\n";
        kolory(7);
        if (n == 1) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Srednie(20)\n";
        kolory(7);
        if (n == 2) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Duze(30)\n";
        kolory(7);
        if (n == 3) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Custom\n";
        kolory(7);
        cout << endl;
        cout << "____Opcje graficzne____\n" << "(ekran paska postepu jest dosc zasobozerny)\n";
        if (n == 4) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wlacz pasek postepu (piekny pasek postepu kosztem nieco wydluzonego czasu ladowania planszy)\n";
        kolory(7);
        if (n == 5) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wylacz pasek postepu (brak paska postepu, ale szybsze ladowanie)\n";
        kolory(7);
        cout << endl;
        
        cout << "Nacisnij ESC aby wrocic do main Manu\n";
        
        int i = getch();
        if(i == 27){
            return;
        }
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 5) n++;
        }
        if(i == 13){
            switch (n){
            case 0:
                size = 15;
                textSize(15);
                break;
            case 1:
                size = 20;
                textSize(20);
                break;
            case 2:
                size = 30;
                textSize(30);
                break;
            case 3:
                cout << "Wpisz wielkosc obrazu:\n";
                cin >> size;
                textSize(size);
                break;
            case 4:
                pasekLadowania = true;
                break;
            case 5:
                pasekLadowania = false;
                break;
            }
        }
    }
}

void startMenu(int tabela [40][20] = {0}){
    kolory(7);
    int n = 0, x = 0, y = 0;
    int bombs, boxes, hospitals, lives, size, luckFactor;
    string wyposazenie;
    bool pasekLadowania = true;
    loadSettings(size, pasekLadowania);
    textSize(size);
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
                resetArray(tabela);
                wyposazenie = "nic";
                randPath(tabela);
                newGameOptions(bombs, boxes, hospitals, lives, luckFactor);
                system("CLS");
                randItems(tabela, bombs, boxes, hospitals, pasekLadowania);
                przebieg(tabela, lives, x, y, luckFactor, wyposazenie);
                resetArray(tabela);
                break; 
            case 1:
                system("CLS");
                loadGame(tabela, x, y, lives, luckFactor, wyposazenie);
                przebieg(tabela, lives, x, y, luckFactor, wyposazenie);
                break;
            case 2:
                mainOptions(size, pasekLadowania);
                saveSettings(size, pasekLadowania);
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
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    startMenu(tabela);
}