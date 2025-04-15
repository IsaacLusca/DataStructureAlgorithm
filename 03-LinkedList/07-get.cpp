#include <iostream>

using namespace std;

//Classe nó
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
        // criando a lista 
        LinkedList (int value) {
            Node* newNode = new Node(value);
            tail = newNode;
            head = newNode;
            length = 1;
        }
        // Destructor
        ~LinkedList () {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            cout << "Deletado com sucesso." << endl;
        }

        // adicionar nó no começo
        void append(int value) {
            Node* newNode = new Node(value);

            if(length == 0) {
                tail = newNode;
                head = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

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

        void printList() {
            Node* temp = head;
            while(temp) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }

        void deleteLast() {
            if(length == 0) return;

            if(length == 1) {
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
            length--;
        }

        void deleteFirst() {
            if (length == 0) return;
            if (length == 1) {
                tail = nullptr;
                head = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        // Função get
        Node* get(int index) {
            if (index < 0 || index >= length) {
                return nullptr;
            } else {
                Node* temp = head;
                while (index > 0) {
                    temp = temp->next;
                    index--;
                }
                return temp;
            }
        }

        Node* getFor(int index) {
            if (index < 0 || index >= length) {
                return nullptr;
            } else {
                Node* temp = head;

                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp;
            }
        }

};

int main() {

    LinkedList* newList = new LinkedList(0);
    newList->append(4);
    newList->append(8);
    newList->append(7);
    newList->append(4);
    newList->append(9);
    
    newList->prepend(100);
    newList->prepend(69);

    // newList->deleteLast();

    // newList->deleteFirst();

    cout << endl;

    
    newList->printList();

    cout << endl;
    cout << "Nó selecionado: " << newList->get(0)->value << endl;
    cout << "Nó com for: " << newList->get(0)->value << endl;
    
    delete newList;
    return 0;
}