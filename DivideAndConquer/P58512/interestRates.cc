// Program that computes the minimum number of days that Prof. Obokaman 
// should wait before returning the money to get a deal that is better than the 
// banks' offer

#include <iostream>

using namespace std;

// Function that computes (1 + diaryFactor / 100)^day
double quickExponence(double diaryFactor, int day) {
    // Base case
    if (day == 0) return 1;
    // General case
    else {
        double aux = quickExponence(diaryFactor, day / 2);
        if (day % 2 == 0) return (aux * aux);
        else { // day % 2 != 0
            return (aux * aux) * diaryFactor;
        }
    }
}

/*
La idea principal es hacer una busqueda binaria como si estuvieramos trabajando con un vector donde se almacenan todos los dias posibles (pongamos el caso n0 y n1 tal que n0<n1, si calculamos el dinero que se le debe al profesor Oak en el dia n0, seguro que el dinero que le debera en el dia n1 sera mayor al que le debia en el dia n0. Esto tambien occure con el dinero que se le debe al banco.
*/
int days(int min, int max, double m, double oak, double bank) {
    // Base case
    if (min > max) return min;
    // General case
    int mid = (min + max) / 2;
    double moneyBank = m * quickExponence(bank, mid);
    double moneyOak = (oak * mid) + m;
    if (moneyOak > moneyBank) return days(mid + 1, max, m, oak, bank);
    else if (moneyOak < moneyBank) return days(min, mid - 1, m, oak, bank);
    else return mid;
}

int main () {
    double m, f, p; // 0.1 ≤ m ≤ 1000, 0.1 ≤ f ≤ 1000, and 0.001 ≤ r ≤ 10
    while (cin >> m >> f >> p) {
        cout << days(1, 100000000, m, f, 1 + (p / 100)) << endl;
    }
}