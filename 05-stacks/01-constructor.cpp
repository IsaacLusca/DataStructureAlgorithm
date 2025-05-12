#include <bits/stdc++.h>

using namespace std;

// Será feito utilizando listas encadeadas
// A classe Node será basicamente identica a de uma lista padrão
class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value =  value;
            next = nullptr;
        }
};

class Stack {
    // Não haverá tail por so poder adicionar e remover no topo de uma pilha
    private:
        Node* top;
        int height;

    public:
        // Construtor da pilha 
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
};

int main() {

    Stack* newStack = new Stack(4);

    newStack->printStack();

    return 0;
}