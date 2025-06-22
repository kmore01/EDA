// Programa que escribe la mediana de las palabras leidas en un conjunto

#include <iostream>
#include <set>

using namespace std;

int main () {
    set<string> conjunto;
    set<string>::iterator medio;
    string palabra;
    cin >> palabra;
    if (palabra != "END") {
        conjunto.insert(palabra);
        cout << palabra << endl;
        medio = conjunto.begin();
        cin >> palabra;
        while (palabra != "END") {
            conjunto.insert(palabra);
            if (*medio < palabra and conjunto.size() % 2 != 0) ++medio;
            else if (*medio > palabra and conjunto.size() % 2 == 0) --medio;
            cout << *medio << endl;
            cin >> palabra;
        }
    }
}