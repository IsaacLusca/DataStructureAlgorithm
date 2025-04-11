#include <bits/stdc++.h>

using namespace std;

// A função abaixo, note que ela recebe dois parâmetros
void printar(int a, int b) {
    for (int i = 0; i < a; i++) {
        cout << i << endl;
    }

    for (int i = 0; i < b; i++) {
        cout << i << endl;
    }

    // Normalmente pensamos que a complexidade é O(N + N) = O(N) 
    // mas como os parametros são diferentes, seria O(a + b)
}