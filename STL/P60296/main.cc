// Programa que calcula las ganancias de los jugadores en un casino

#include <iostream>
#include <map>
#include <set>

using namespace std;

struct compare {
	bool operator() (const pair <string, int> &a, const pair <string, int> &b) const {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

void accion(map<string, int> &registro, string op, map<string, bool> &conect) {
    string jugador1;
    cin >> jugador1;
    if (op == "LOGIN") {
        auto it = conect.find(jugador1);
        if (it == conect.end()) { // No lo he encontrado
            registro[jugador1] = 1200;
            conect[jugador1] = true;
        }
        else {
            it->second = true;
        }
    }
    else if (op == "LOGOUT") {
        auto it = conect.find(jugador1);
        if (it != conect.end()) {
            it->second = false;
        }
    }
    else if (op == "PLAY") {
        string jugador2;
        cin >> jugador2;
        auto it = conect.find(jugador1);
        auto it2 = conect.find(jugador2);
        if ((it != conect.end() and it->second) and (it2 != conect.end() and it2->second)) {
            auto _it = registro.find(jugador1);
            auto _it2 = registro.find(jugador2);
            _it->second += 10; // el juador ganador recibe su elo
            _it2->second -= 10;
            if (_it2->second < 1200) _it2->second = 1200; 
        }
        else { // los dos jugadores estan conectados
            cout << "jugador(s) no connectat(s)" << endl;
        }   
    }
    else { // "GET_ELO"
        auto it = registro.find(jugador1);
        cout << jugador1 << ' ' << it->second << endl;
    }
}

void imprimir_ranking(const map<string, int> &registro) {
    set <pair <string, int>, compare> items;
    for (pair <string, int >p : registro) items.insert(make_pair(p.first, p.second));
    cout << endl << "RANKING" << endl;
    for (auto it = items.begin(); it != items.end(); ++it) {
        cout << it->first << ' ' << it->second << endl;
    }
}

int main () {
    map<string, int> jugador_elo;
    map<string, bool> conectado;
    string operacion;
    while (cin >> operacion) accion(jugador_elo, operacion, conectado);
    imprimir_ranking(jugador_elo);
}