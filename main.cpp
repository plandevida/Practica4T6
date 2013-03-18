/* 
 * File:   main.cpp
 * Author: nano
 *
 * Created on 4 de marzo de 2013, 20:20
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Pila.h"

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
    
    Pila<int> colaAbiertos;
    
    bool completos = true;
    
    int i = 0;
    int j = n-1;
    
    while(i < n) {
        
        if(cadena[i] == caracterAbertura) {
            
            colaAbiertos.apila(cadena[i]);
            
        } else if (cadena[i] == caracterCierre) {
            
            try {
                colaAbiertos.desapila();
            } catch(EPilaVacia e) {
                cout << e.msg() << endl;
            }
        }
        i++;
    }

    if ( ! colaAbiertos.esVacia()) {
        completos = false;
    }
    
    return completos;
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