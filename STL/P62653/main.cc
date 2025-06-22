// Programa que gestiona la tienda de tickets de un equipo

#include <iostream>
#include <queue>

using namespace std;

string tl;
struct compare {
	bool operator()(const string& a, const string& b) {
		if (a.length() == b.length()) {
			string ctl = tl.substr(0, a.length());
			if (a == ctl) return 0;
			if (b == ctl) return 1;
			if (a < b) {
				if (a < ctl and ctl < b) return 1;
				return 0;
			}
            else {
				if (b < ctl and ctl < a) return 0;
				return 1;
			}
		}
        else return a.length() > b.length();
	}
};


int main () {
    while (cin >> tl) {
        char op;
        int tickets = 0;
        // wait representara la cola de gente esperando a recibir su ticket
        priority_queue <string, vector <string>, compare> wait;
        while (cin >> op and op != 'E') {
            if (op == 'S') {
                string supporter;
                cin >> supporter;
                wait.push(supporter);
            }
            else ++tickets;
            // Repartir tickets
            for (; tickets > 0 and not wait.empty(); --tickets) {
                cout << wait.top() << endl;
                wait.pop();
            }
        }

        cout << tickets << " ticket(s) left" << endl;
        cout << wait.size() << " supporter(s) with no ticket" << endl << endl;
    }
}
