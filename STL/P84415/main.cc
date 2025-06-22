// Programa que gestiona una bolsa de palabras

#include <iostream>
#include <map>

using namespace std;

// Funcion que se encarga de hacer operaciones con la bolsa
// Pre: las palabras tienen exclusivamente una o dos letras minusculas 
// Post: para cada pregunta se ha escrito el max o min de la bolsa     
void operaciones_bolsa() {
    map<string, int> palabra_aparaciones;
    string op;
    while (cin >> op) {
        if (op == "store") {
            string palabra;
            cin >> palabra;
            if (palabra_aparaciones.count(palabra)) {
                palabra_aparaciones[palabra] += 1;
            }
            else {
                palabra_aparaciones[palabra] = 1;
            }
        }
        else if (op == "delete") {
            string palabra;
            cin >> palabra;
            if (palabra_aparaciones.count(palabra)) {
                map<string, int>::iterator it = palabra_aparaciones.find(palabra);
                if (it->second != 1) --it->second; 
                else palabra_aparaciones.erase(palabra);
            }
        }
        else if (op == "minimum?") {
            if (palabra_aparaciones.empty()) {
                cout << "indefinite minimum" << endl;
            }
            else {
                cout << "minimum: ";
                map<string, int>::iterator it = palabra_aparaciones.begin();
                cout << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else {
            if (palabra_aparaciones.empty()) {
                cout << "indefinite maximum" << endl;
            }
            else {
                cout << "maximum: ";
                map<string, int>::iterator it = palabra_aparaciones.end();
                --it;
                cout << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}

int main () {
    operaciones_bolsa();
}