#include <bits/stdc++.h>

using namespace std;

// Como no caso está sendo percorrido duas vezes, 
// em teoria a complexidade seria O(2N), mas no contexto
// de analisar complexidade sempre se remove a constante;
void printar(int n) {
    int i = 1;
    cout << "Primeiro laço com While: ";
    while (i < n) {
        cout << i << ", ";
        i ++;
    } cout << i << "." << endl;

    cout << "Segundo laço com For: ";

    i = 1;
    for (i; i <= n; i++) {
        cout << i << (i != n ? ", ": ".");  
    }
}

int main() {

    printar(10);

return 0;
}

