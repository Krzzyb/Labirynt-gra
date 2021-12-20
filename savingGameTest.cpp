#include <iostream>
#include <cstdlib>
#include <fstream> // file stream
#include <string.h>
#include <dirent.h>
#include <stdio.h>
using namespace std;

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
    system("pause");*/

    //listFiles(".");
    
    string tekst;

    ifstream file("Zapis_gry_nowy.txt");

    while(getline(file, tekst)){
        cout << tekst << endl;
    }
    file.close();
    system("pause");
return 0;
}