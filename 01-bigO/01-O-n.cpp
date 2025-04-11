#include <bits/stdc++.h>

using namespace std;

void printItems(int n) {
    for(int i = 1; i <= n; i++)
    {
        cout << i << (i != n ? ", ": ".");
    }
}

int main(){

    printItems(10);
    return 0;
}