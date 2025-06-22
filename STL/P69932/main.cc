// Programa que dado unos numeros, calcula la combinacion de numeros mas larga 
// que se puede hacer de manera creciente sin que haya dos numeros de la misma 
// paridad seguidos

#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main () {
    string lin;
    while (getline(cin, lin)) {
        set<int> seq;
        int num;
        istringstream iss(lin);
        while (iss >> num) seq.insert(num);

        int max = 0;
        bool par = false; // inicializar
        set<int>::iterator it = seq.begin();
        for (int i = 0; i < seq.size(); ++i) {
            // Paso inicial
            if (it == seq.begin()) {
                ++max;
                par = (*it % 2 == 0);
            }
            // Si el anterior numero ha sido par, el que voy a poner ahora 
            // tiene que ser impar
            else if (par and *it % 2 != 0) {
                ++max;
                par = false;
            }
            // Si el anterior numero ha sido impar, el que voy a poner ahora  
            // tiene que ser par
            else if (not par and *it % 2 == 0) {
                ++max;
                par = true;
            }
            ++it; // Siguiente elemento
        }
        cout << max << endl;
    }
}