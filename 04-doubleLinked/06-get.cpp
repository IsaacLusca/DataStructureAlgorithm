#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
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

        void deleteLast() {
            if(length == 0) return;
            Node* temp = tail;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;    
                tail->next = nullptr;
            }
            delete temp;
            length--;
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

        void getLength() {
            cout << length << endl;
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
    return 0;
}   