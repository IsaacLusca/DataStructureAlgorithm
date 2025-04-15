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
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;

            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            cout << "Deletado" << endl;
        }

        void printList() {
            Node* temp = head;

            while(temp) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);

            if(length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);

            if(length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                tail = nullptr;
                head = nullptr;
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
            if(length == 0) return;
            if(length == 1) {
                tail = nullptr;
                head = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        Node* getNode(int index) {
            if(index < 0 || index >= length) {
                return nullptr;
            } else {
                Node* temp = head;
                for(int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp;
            }
        }

        bool setValue(int index, int value) {
            if( index < 0 || index > length) return false;
            Node* temp = head;

            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }

            temp->value = value;
            return true;
        }

        bool set(int index, int value) {
            Node* temp = getNode(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

};

int main() {

    LinkedList* myList = new LinkedList(5);

    myList->append(6);
    myList->append(7);

    myList->prepend(4);
    myList->prepend(3);

    // myList->deleteFirst();
    // myList->deleteLast();

    myList->setValue(0, 50);
    myList->set(1, 100);
    
    myList->printList();
    cout << endl;
    cout << "Nó na posição: " << myList->getNode(3)->value << endl;
    
    cout << endl;

    delete myList;

    return 0;
}