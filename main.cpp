/* 
 * File:   main.cpp
 * Author: nano
 *
 * Created on 4 de marzo de 2013, 20:20
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

bool equilibrada(const char cadena[], int n);
bool llaves(const char cadena[], int n, const char caracterAbertura, const char caracterCierre);
bool parentesis(const char cadena[], int n);

void formatIndices(const char cadena[], const int i, const int j);

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "La cadena: int main() { void caca() { int a[] } }" << " es: ";
    
    bool equilib = equilibrada("int main() { void caca() { int a[] } }", 38);
    string eq = "";
    
    if(equilib) {
        eq = "completa";
    }
    else {
        eq = "no completa";
    }
    
    cout << eq << endl;
    
    return 0;
}

bool equilibrada(const char cadena[], int n) {
    
    bool equilibrada = false;
 
    equilibrada = llaves(cadena, n, '{', '}');
    equilibrada = llaves(cadena, n, '[', ']');
    equilibrada = llaves(cadena, n, '(', ')');
    
    
    return equilibrada;
}
    
bool llaves(const char cadena[], int n, const char caracterAbertura, const char caracterCierre) {
    
    bool completos = true;
    
    int i = 0;
    int j = n-1;
    
    int abiertos = 0;
    int cerrados = 0;
    
    while(i <= j) {
        
//        formatIndices(cadena, i, j);
        
        if (cadena[j] != caracterCierre) {
            j--;
        } else if (cadena[j] == caracterCierre && cadena[i] != caracterAbertura ) {
            i++;
            
        } else if (cadena[j] == caracterCierre && cadena[i] == caracterAbertura) {
            j--;
            i++;
            
            completos = true;
        } else {
            completos = false;
        }
        
    }
    return completos = (abiertos == cerrados);
}
    
void formatIndices(const char cadena[], const int i, const int j) {

    int dif = j-i-1;
    
    cout << cadena << endl;

    for(int a=0; a<i; a++) {
        cout << " ";
    }

    cout << "^";

    for(int a=0; a < dif; a++) {
        cout << " ";
    }

    cout << "^" << endl;

    for(int a=0; a<i; a++) {
        cout << " ";
    }

    cout << "i";

    for(int a=0; a < dif; a++) {
        cout << " ";
    }

    cout << "j" << endl;
}