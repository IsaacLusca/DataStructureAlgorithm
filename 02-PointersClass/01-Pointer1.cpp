#include <bits/stdc++.h>

using namespace std;

void noPointer() {

    int num1 = 11;
    int num2 = num1;

    num1 = 22;

    cout << "Sem ponteiro: " << endl;
    cout << "   Num1 = " << num1 << endl;
    cout << "   Num2 = " << num2 << endl;

}

void Pointer() {

    int* num1 = new int(11);
    int* num2 = num1;

    * num1 = 22;

    cout << "Com ponteiro:" << endl;
    cout << "Sem *, para num2, está sendo passado a referencia de num1." << endl;
    cout << "   Num1 = " << num1 << endl;
    cout << "   Num2 = " << num2 << endl;
    
    cout << "Com *, vai mostrar o valor que num1 e num2 está apontando." << endl;
    cout << "   *Num1 = " << *num1 << endl;
    cout << "   *Num2 = " << *num2 << endl;
}

int main() {

    noPointer();
    cout << endl;
    Pointer();
    cout << endl;
    cout << "Resumindo: Ao chamar na saida o num1 e num2 sem *, o que vai mostrar é o endereço de memória que tanto num1 quanto num2 está apontando \ne quando uso o *, ele mostra o valor que está no endereço da memória que ambos os endereços está apontando." << endl;


    return 0;
}
