#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};
// Estruturas do tipo queue - filas são do tipo FIFO: primeiro entra, primeiro sai

// No caso da fila, precisamos de um nó apontado para o primeiro e ultimo
class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = last = newNode;
            length = 1;
        }

        void print() {
            Node* temp = first;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        // Func para adicionar item a fila:
        void enqueue(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                first = last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        //  func para remover o primeiro no:

        int dequeue() {
            if(length == 0) return INT_MIN;
            Node* temp = first;
            int dequeueVal = first->value;
            if(length == 1) {
                first = last = nullptr;
            } else {
                first = first->next;
            }
            delete temp;
            length--;
            return dequeueVal;
        }

        void dequeueVoid() {
            if(length == 0) return;
            Node* temp = first;
            if(length == 1) {
                first = last = nullptr;
            } else {
                first = first->next;
            }
            delete temp;
            length--;
        }
};

int main() {

    Queue* newQueue = new Queue(10);

    newQueue->enqueue(12);
    newQueue->enqueue(14);
    newQueue->enqueue(2);

    // removendo o primeiro valor, no caso 10.
    newQueue->dequeueVoid();
    newQueue->print();

    return 0;
}