#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
int X, Y;
int **tablica;
void create(){
    tablica = new int*[Y];
    for(int j = 0; j < Y; j++){
        tablica[j] = new int[X];
    }
}
void resetArray(){
    for(int j = 0; j < Y; j++){
        for(int i = 0; i < X; i++){
            tablica[j][i] = 0;
        }
    }
}
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
void surpriseSound(){
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (392,100);Sleep(700);
}
void bombSound(){
    Beep (400,300);Sleep(125);
    Beep (300,300);Sleep(125);
    Beep (200,500);Sleep(125);
}

void pokaz() {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
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
        cout << ", aby wylosowac element wyposazenia.\n";
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
    if(typ == "brak"){
        cout << "Legenda zostala wylaczona, udaj sie do ustawien glownych, by ja przywrocic";
    }
}
void prettyShow(int x, int y) {
// już nieaktualna funkcja
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
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
void darkShow(int x, int y, string wyposazenie, string mapKeyType){
    if(wyposazenie == "nic"){
        for (int j = 0; j < Y; j++) {
            for (int i = 0; i < X; i++) {
                if(y == j && x == i){
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
        for (int j = 0; j < Y; j++) {
            for (int i = 0; i < X; i++) {
                if(y == j && x == i){
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
        for (int j = 0; j < Y; j++) {
            for (int i = 0; i < X; i++) {
                if(y == j && x == i){
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
    legenda(mapKeyType);
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
void saveSettings(int size, bool pasekLadowania, string mapKeyType){
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
    plik << "legenda: \n" << mapKeyType << endl;
    plik.close();
}
void loadSettings(int &size, bool &pasekLadowania, string &mapKeyType){
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
        getline(plik, linijka);
        getline(plik, linijka);
        mapKeyType = linijka;
    }else{
        cout << "Nie otwarto pliku" << endl;
    }
    plik.close();
}
void loadGame(int &x, int &y, int &lives, int &luckFactor, string &wyposazenie){
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
        getline(plik, linijka);
        getline(plik, linijka);
        X = stoi(linijka);
        getline(plik, linijka);
        Y = stoi(linijka);
        for (int i = 0; i < Y; i++) {
            getline(plik, linijka);
            for (int j = 0; j < X; j++) {
                tablica[i][j] = (int) linijka[j];
            }
        }
    }else{
        cout << "Nie otwarto pliku" << endl;
    }
    plik.close();
    cout << lives << " " << x << " " << y << endl;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << " " << tablica[i][j];
        }
        cout << endl;
    }
    system("CLS");
}
void saveGame (int x, int y, int lives, int luckFactor, string wyposazenie){
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
    plik << "matrix size x, y: \n" << X << endl << Y << endl;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            plik << tablica[i][j];
        }
        plik << endl;
    }
    plik.close();
}
void randPath() {
    create();
    resetArray();
    srand(time(NULL));
    int I, x = 0, y = 0;
    tablica[y][x] = 1;
    do{
        I = rand() % 2;
        if (I == 0 && x+1 != X) {
            x++;
            tablica[y][x] = 1;
        }
        if (I == 1 && y+1  != Y) {
            y++;
            tablica[y][x] = 1;
        }
    }while (tablica[Y-1][X-1] == 0);
}
int newGameOptions(int &bombs, int &boxes, int &hospitals, int &lives, int &luckFactor){
    bombs = 0;
    boxes = 0;
    hospitals = 0;
    bool done = false;
    system("CLS");
    kolory(7);
    int n = 0;
    while (true){
        system("CLS");
        cout << "Wybierz wielkosc planszy:\n";
        if (n == 0) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Small - 20x10\n";
        kolory(7);
        if (n == 1) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Medium - 40x20\n";
        kolory(7);
        if (n == 2) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Big - 60x30\n";
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
        if(i == 27){
            return 1;
        }
        if(i == 13){
            switch (n){
            case 0:
                X = 20, Y = 10;
                done = true;
                break;
            case 1:
                X = 40, Y = 20;
                done = true;
                break;
            case 2:
                X = 60, Y = 30;
                done = true;
                break;
            case 3:
                do{
                    system("CLS");
                    cout << "___Nowa gra___\n" << "Wpisz wartosci wielkosci planszy:\n"; 
                    cout << "Pamietaj o ograniczeniach swojego wyswietlacza - jesli wartosc Y bedzie zbyt duza, plansza bedzie sie obnizala do dolu!\n";
                    cout << "Aby zyskac wiecej miejsca mozesz w ustawieniach glownych wylaczyc wyswietlanie legendy\n";
                    cout << "Maks: 150x50\n";
                
                    cout << "Jakie X?  -  ";
                    cin >> X;
                    cout << endl;
                    cout << "Jakie Y?  -  ";
                    cin >> Y;
                    cout << endl;
                    
                    
                }while(!(X <= 150 && Y <= 50));
                done = true;
            }
        }
        if(done == true)break;
    }
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
        if(i == 27){
            return 1;
        }
        if(i == 13){
            switch (n){
            case 0:
                bombs = 50;
                boxes = 30;
                hospitals = 15;
                lives = 8;
                luckFactor = 5;
                return 0;
            case 1:
                bombs = 80;
                boxes = 20;
                hospitals = 8;
                lives = 5;
                luckFactor = 2;
                return 0;
            case 2:
                bombs = 150;
                boxes = 10;
                hospitals = 3;
                lives = 3;
                luckFactor = 0;
                return 0;
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
                cout << "Jaki luckFactor?\n" << "(jest to wartosc od 0 do 10, ktora definuje szczescie w losowaniu wyposazenia\n";
                cout << " - jesli chcesz miec pewnosc, ze zawsze cos wylosujesz, wpisz wartosc wieksza od 10):\n";
                cin >> luckFactor;
                return 0;
            }
        }

    }
    
}
void randItems(int bombs, int boxes, int hospitals, bool pasekLadowania) {
    srand(time(NULL));
    int x = 0, y = 0;
    
    for (int i = 0; i <= bombs; i++) {
        cout << "\x1B[2K";           // To są ANSI escape code - szybsze niż system("CLS")
        if(i < bombs){// Tu i w dalszych przypadkach zastosowałem if'a, ponieważ musiałem dać w pętli for wyżej, mniejszy równy, aby w wypadku małych wartości pasek postępu na końcu losowania był pełny
            x = rand() % X;
            y = rand() % Y;
            if (tablica[y][x] == 0) {
                tablica[y][x] = 2;
            }else i--;
        } 
        cout << "Losowanie min...\n";
        cout << "\x1B[2K";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50; n++ ){
                if(n <= 50 * i / bombs) cout << char(178);
                if(n > 50 * i / bombs) cout << " ";
                
            }
            cout << "|"; 
        }
        cout << "\x1B[1F";
    }
    
    cout << "\x1B[2E";
    
    for (int i = 0; i <= boxes; i++){
        cout << "\x1B[2K";
        if(i < boxes){
            x = rand() % X;
            y = rand() % Y;
            if (tablica[y][x] == 0) {
                tablica[y][x] = 3;
            }else i--;
        }
        cout << "Losowanie niespodzianek...\n";
        cout << "\x1B[2K";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50; n++ ){
                if(n <= 50*i/boxes) cout << char(178);
                if(n > 50 * i/boxes) cout << " ";
            }
            cout << "|"; 
        }
        cout << "\x1B[1F";
    }
    
    cout << "\x1B[2E";
    for (int i = 0; i <= hospitals; i++){
        cout << "\x1B[2K";
        if(i < hospitals){    
            x = rand() % X;
            y = rand() % Y;
            if (tablica[y][x] == 0) {
                tablica[y][x] = 4;
            }else i--;
        }
        cout << "Losowanie szpitali...\n";
        cout << "\x1B[2K";
        if(pasekLadowania == true){ 
            cout << "|";
            for(int n = 0; n < 50; n++ ){
                if(n <= 50 * i / hospitals) cout << char(178);
                if(n > 50 * i / hospitals) cout << " ";
            }
            cout << "|"; 
        }
        cout << "\x1B[1F";
    }
    
    cout << "\x1B[2E";
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

int menu(int x, int y, int lives, int luckFactor, string wyposazenie, string mapKeyType){
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
                darkShow(x,y,"nic", mapKeyType);
                return 1;
            case 1:
                system("CLS");
                saveGame(x, y, lives, luckFactor, wyposazenie);
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
void przebieg(int lives, int x, int y, int luckFactor, string wyposazenie, string mapKeyType){
    int setlives = lives;
    livescounter(lives);
    cout << endl;
    darkShow(x, y, wyposazenie, mapKeyType);
    while (lives>0) {
        int rozmiary = Y, rozmiarx = X;
        int i = getch();
        if (i == 27){
            int wynikMenu = menu(x, y, lives, luckFactor, wyposazenie, mapKeyType);
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
            if(tablica[y][x] == 2){
               
                tablica[y][x] = 5;
                lives--;
            }
            if(tablica[y][x] == 3){
                randEquip(wyposazenie, luckFactor);
                
                tablica[y][x] = 6;
            }
            if(tablica[y][x] == 4){
                lives = setlives;
            }
            if( x+1 == X && y+1 == Y){
                surpriseSound();
                cout<<"Gratulacje! Dotarles do punktu zbiorki - jestes teraz bezpieczny.\n";
                cout << "Nacisnij ENTER, aby wrocic do main Menu";
                getchar();
                break;
            }
            livescounter(lives);
            cout<<endl;
            darkShow(x,y,wyposazenie, mapKeyType);
        }
    }
    if (lives <= 0){
        system("CLS");
        bombSound();
        cout << "Koniec gry, straciles wszystkie swoje zycia\n";
        cout << endl;
        cout << "Oto plansza po ktorej sie poruszales:\n";
        prettyShow(x,y);
        cout << endl;
        cout << "nacisnij ENTER, aby wrocic do main Menu\n";
        getchar();
    }
}
void mainOptions(int &size, bool &pasekLadowania, string &mapKeyType){
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
        cout << "Wyswietlanie legendy: ";
        if(mapKeyType == "gra")cout << "Wlaczone\n";
        else cout << "Wylaczone\n";
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
        cout << endl;
        cout << "____Opcje graficzne____\n";
        cout << "Pasek ladowania - (ekran paska postepu jest dosc zasobozerny) - teraz juz nie wiec to tylko kwestia gustu\n";
        if (n == 4) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wlacz\n";
        kolory(7);
        if (n == 5) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wylacz\n";
        kolory(7);
        
        cout << endl;
        cout << endl;
        cout << "Opcje wyswietlania legendy:\n";
        if (n == 6) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wlacz\n";
        kolory(7);
        if (n == 7) { 
            kolory(1);
            cout << " " << char(175) << " ";
            }
        cout << "Wylacz\n";
        kolory(7);
        cout << endl << endl;
        cout << "Nacisnij ESC aby wrocic do main Manu\n";
        
        int i = getch();
        if(i == 27){
            return;
        }
        if(i == 0 || i == 224){
            i = getch();
            if (i == 72 && n > 0) n--;
            else if (i == 80 && n < 7) n++;
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
            case 6:
                mapKeyType = "gra";
                break;
            case 7:
                mapKeyType = "brak";
                break;
            }
        }
    }
}

void startMenu(){
    kolory(7);
    int n = 0, x = 0, y = 0;
    int bombs, boxes, hospitals, lives, size, luckFactor;
    string wyposazenie, mapKeyType;
    bool pasekLadowania = true;
    
    loadSettings(size, pasekLadowania, mapKeyType);
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
                x = 0, y = 0;
                
                wyposazenie = "nic";
                
                if(newGameOptions(bombs, boxes, hospitals, lives, luckFactor) == 1){ 
                    break;
                }
                
                randPath();
                system("CLS");
                randItems(bombs, boxes, hospitals, pasekLadowania);
                przebieg(lives, x, y, luckFactor, wyposazenie, mapKeyType);
                resetArray();
                break; 
            case 1:
                system("CLS");
                loadGame(x, y, lives, luckFactor, wyposazenie);
                przebieg(lives, x, y, luckFactor, wyposazenie, mapKeyType);
                break;
            case 2:
                mainOptions(size, pasekLadowania, mapKeyType);
                saveSettings(size, pasekLadowania, mapKeyType);
                break;
            case 3:
                exit(0);
            }
        }
    }
}

int main()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    startMenu();
}