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

    public:
        // Criando o primeiro nó da lista
        LinkedList(int value) {
            Node* newNode = new Node(value);
            tail = newNode;
            head = newNode;
            length = 1;
        }
        // Func para deletar a lista
        ~LinkedList () {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
                length --;
            }
        }

        // Func para imprimir

        void printList() {
            while(head) {
                cout << head->value << " ";
                head = head->next;
            }
            cout << endl;
        }
        // Adicionar nó no final da lista
        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                tail = newNode;
                head = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        // Deletar o último:
        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                while(temp->next != tail) {
                    temp = temp->next;                  
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
            length++;
        }
        // Prepend/acrescentar no começo
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                tail = newNode;
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
};


int main() {

    LinkedList* newList = new LinkedList(0);
    newList->append(1);
    newList->append(2);
    newList->append(3);
    newList->append(4);
    newList->append(5);
    newList->append(6);
    newList->prepend(100);
    newList->deleteLast();

    cout << "Lista: ";
    newList->printList();
    delete newList;
    return 0;
}