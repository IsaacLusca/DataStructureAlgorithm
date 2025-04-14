#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            // this->next = nullptr;
            next = nullptr;
        }
};

class LinkedList {
    // primeiros atributos/variaveis
    private:
        Node* head;
        Node* tail;
        int length;

    // Constructor
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    };

int main() {

    LinkedList* primeiroNo = new LinkedList(4);
        
    return 0;
}