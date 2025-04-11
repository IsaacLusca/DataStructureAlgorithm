#include <bits/stdc++.h>
using namespace std;

// COMO HÁ dois for, a complexidade vai ser
// N * N = N^2, ou seja O(N^2)

void printar(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << " ";
        }
        cout << endl;
    }
}

int main() {
    printar(10);
    return 0;
}

// int atual = 1;
// for (int i = 0; atual <= n; i++) {
//     for (int j = 0; j < 3 && atual <= n; j++) {
//         cout << atual << " ";
//         atual++;
//     }
//     cout << endl;
// }