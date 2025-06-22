#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
    S'utilitza ordre lexicogràfic

    Si en un map fas M[k] y k no existeix al map, el crea a 0!
*/

    struct comp {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
            // if (lhs.first + lhs.second > rhs.first + rhs.second) return true
            // else return false

            return (lhs.first + lhs.second > rhs.first + rhs.second);
        }
    };

int main () {
    // priority_queue(tipus, vector<tipus>, ordre>
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q2;
    q2.push({1, 2});
    q2.push({2, 3});
    q2.push({0, 5});

    while (not q2.empty()) {
        cout << "(" << q2.top().first << ", " << q2.top().second << ")" << endl;
        q2.pop();
    }

    cout << "---------------------------------------------------------" << endl;

    set<int> s1;
    s1.insert(2);
    s1.insert(7);
    s1.insert(9);

    auto it = s1.insert(2);

    cout << it.second << endl;

    for (int x : s1) cout << x << endl;

    cout << "---------------------------------------------------------" << endl;

    vector<int> v = {3, 4, 2, 1, 1};
    cout << v[5] << endl;

    // assert(op == "strore") si op != store, el programa se detiene
}