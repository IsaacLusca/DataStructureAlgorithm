#include <bits/stdc++.h>
using namespace std;

// a primeira complexidade é O(n^2)
// a segunda é O(n);
// A notação seria O(n^2 + n), como n^2 é o que aumenta mais rapido
// Se escreveria O(n^2)

void printar(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        if ((i % 5) != 0) {
            cout << i << " ";
        } else cout << i << endl;
    }
}

// cout << i << (i != n ? ", ": ".");  


int main() {
    printar(10);
    return 0;
}