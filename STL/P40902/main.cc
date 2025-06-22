// Programa que calcula las ganancias de los jugadores en un casino

#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string, int> persona_dinero;
    string nombre;
    while (cin >> nombre) {
        string op;
        cin >> op;
        if (op == "enters") {
            if (persona_dinero.count(nombre)) {
                cout << nombre << " is already in the casino" << endl;
            }
            else persona_dinero[nombre] = 0;
        }
        else if (op == "leaves") {
            if (not persona_dinero.count(nombre)) {
                cout << nombre << " is not in the casino" << endl;
            }
            else {
                map<string, int>::iterator it = persona_dinero.find(nombre);
                cout << nombre << " has won " << it->second << endl;
                persona_dinero.erase(nombre);
            }
        }
        else {
            if (not persona_dinero.count(nombre)) {
                cout << nombre << " is not in the casino" << endl;
            }
            int dinero;
            cin >> dinero;
            map<string, int>::iterator it = persona_dinero.find(nombre);
            it->second += dinero;
        }
    }
    cout << "----------" << endl;
    for (map<string, int>::iterator it = persona_dinero.begin(); it != persona_dinero.end(); ++it) {
        cout << it->first << " is winning " << it->second << endl;
    }
}