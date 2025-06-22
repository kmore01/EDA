// Programa que hace operaciones con una coleccion de numeros

#include <iostream>
#include <queue>

using namespace std;

int main () {
    priority_queue<int> coleccio;
    char op;
    while (cin >> op) {
        if (op == 'S') {
            int x;
            cin >> x;
            coleccio.push(x);
        }
        else if (op == 'A') {   // print del numero mas grande
            if (coleccio.empty()) cout << "error!" << endl;
            else cout << coleccio.top() << endl; 
        }
        else if (op == 'R') {   // eliminamos el numero mas grande
            if (coleccio.empty()) cout << "error!" << endl;
            else coleccio.pop();    
        }
        else if (op == 'I') {   // +x al numero mas grande
            int x;
            cin >> x;  
            if (coleccio.empty()) cout << "error!" << endl;
            else {
                int nuevo_top = coleccio.top() + x;
                coleccio.pop();
                coleccio.push(nuevo_top);
            }
        }
        else {                  // -x al numero mas grande
            int x;
            cin >> x;  
            if (coleccio.empty()) cout << "error!" << endl;
            else {
                int nuevo_top = coleccio.top() - x;
                coleccio.pop();
                coleccio.push(nuevo_top);
            }
        }
    }
}