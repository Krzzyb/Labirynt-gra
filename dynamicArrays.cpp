#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

void funkcja(int ** m)
{
m[0][0] = 12345;
}

void tworzenie(int **& matrix)
{
matrix = new int*[3];
matrix[0] = new int[5];
matrix[1] = new int[2];
matrix[2] = new int[4];
}
void zapelnianie(int **& tablica, int X, int Y, int n){
    for(int j = 0; j < Y; j++){
        for(int i = 0; i < X; i++){
            tablica[j][i] = n;
        }
    }
}
void create(int **& tablica, int X, int Y){
    tablica = new int*[Y];
    for(int j = 0; j < Y; j++){
        tablica[j] = new int[X];
    }
}
void print(int **& tablica, int X, int Y){
    for(int i=0; i < Y; i++){
        for(int j = 0; j < X; j++){
            cout << tablica[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int **matrix;
    create(matrix, 20, 10);
    zapelnianie(matrix, 20, 10, 5);
    print(matrix, 20, 10);

 delete [] matrix;
getchar();
PlaySound(("Testsound"), NULL,SND_SYNC);
 return 0;
}