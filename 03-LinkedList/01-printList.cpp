#include <iostream>
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

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    // constructor
    public:
        LinkedList (int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        
        // função para printar:
        void printList() {
            // variavel temp apontando para o primeiro nó
            Node* temp = head;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }   
        void getHead() {
            cout << "Head: " << head->value << endl;
        }
        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }
        void getLength() {
            cout << "Length: " << length << endl;
        }
};

int main() {

    LinkedList* lista = new LinkedList(4);

    lista->getHead();
    lista->getTail();
    lista->getLength();
    
    return 0;
}