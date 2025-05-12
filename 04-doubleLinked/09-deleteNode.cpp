#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int valor) {
            value = valor;
            prev = nullptr;
            next = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = tail = newNode;
            length = 1;
        }
        void printList() {
            Node* temp = head;
            while(temp) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }

        void getLength() {
            cout << length << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if(length == 0) return;
            Node* temp = head;
            if(length == 1) {
                head = tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        void deleteLast() {
            if(length == 0) return;
            Node* temp = tail;

            if(length == 1) {
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            } 
            delete temp;
            length--;
        }

        Node* get(int index) {
            if(index < 0 || index >= length) return nullptr;
            Node* temp = head;
            if(index < length/2) {
                for(int i = 0; i < index; i++) {
                    temp = temp->next;
                }
            } else {
                temp = tail; 
                for(int i = length - 1; i > index; i--) {
                    temp = temp->prev;
                }
            }
            return temp;
        }

        bool set(int index, int value) {
            Node* temp = get(index);

            if(temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        // inserir em um índice:

        bool insert(int index, int value) {
            if(index < 0 || index > length) return false;
            if(index == 0) {
                prepend(value);
                return true;
            }
            if(index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;

            newNode->next = after;
            newNode->prev = before;
            before->next = newNode;
            after->prev = newNode;
            length++;
            return true;
        }

        // Excluir o nó de um indice
        void deleteNode(int index) {
            if(index < 0 || index >= length) return;
            if(index == 0) return deleteFirst();
            if(index == length - 1) return deleteLast();
            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }
};

int main() {

    DoublyLinkedList* newDLL = new DoublyLinkedList(10);

    newDLL->append(11);
    newDLL->append(13);
    newDLL->append(15);
    newDLL->prepend(2);
    newDLL->prepend(1);
    newDLL->deleteLast();
    newDLL->deleteFirst();
    

    newDLL->printList();
    cout << endl;
    cout << newDLL->get(1)->value << endl;
    newDLL->getLength();

    newDLL->set(1, 70);
    newDLL->set(0, 12);
    newDLL->insert(2, 43);
    newDLL->insert(3, 66);
    newDLL->deleteNode(3);

    newDLL->printList();
    return 0;
}   