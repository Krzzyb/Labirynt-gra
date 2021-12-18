#include <iostream>
#include <windows.h>

using namespace std;

void kolor(int k){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
int main(){
    for (int i = 0; i<256; i++){
        kolor(i);
        cout << i<< endl;
    }
    return 0;
}