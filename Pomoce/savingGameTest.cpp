#include <iostream>
#include <cstdlib>
#include <fstream> // file stream
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <filesystem>
using namespace std;
//namespace fs = std::filesystem;

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    printf("Reading files in: %s\n", dirname);

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        printf("%s %s\n", entity->d_name);
        /*if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }*/
        entity = readdir(dir);
    }

    closedir(dir);
}
void loadGame(int tablica[40][20], int &x, int &y, int &lives){
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
    system("pause");
}
int main()
{
    /*string nazwa = "C:\\Users\\zybur\\OneDrive\\Pulpit\\Pulpit\\Projekty\\Kod\\Visual Studio\\Szkolne\\Labirynt gra\\saves\\";
    string tmp = "";
    cin >> tmp;
    tmp = nazwa + tmp + ".txt";
    fstream plik;
    plik.open(tmp.c_str(), ios::out);

    for (int i = 0; i < 10; i++)
    {
        plik << i << " ";
    }
    plik.close();*/

    //ofstream zapis("Zapis_gry_nowy.txt");
    //zapis << "lives: " << "5\n";
    //zapis.close();

    /*fstream plik;
plik.open("C:\\Intel\\test.txt", ios::in);  
    
    if(plik.is_open()){
        for (int i = 0; i<10; i++){
            int tmp = -1;
            plik >> tmp;
            cout << tmp << " ";
        }
    }else{
        cout << "NIe otwarto poliku" << endl;
    }
    plik.close();
    system("pause");

    //listFiles(".");
    
    string tekst;

    ifstream file("Zapis_gry_nowy.txt");

    while(getline(file, tekst)){
        cout << tekst << endl;
    }
    file.close();
    system("pause");*/
    //int tabela[40][20] = {0};
    //int x = 1, y = 1, lives = 0;
    //loadGame(tabela, x, y, lives);
    char command[50] = "ls -l";
    system(command);
    getchar();
return 0;
}