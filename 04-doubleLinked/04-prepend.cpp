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
            head = newNode;
            tail = newNode;
            length = 1;
        }
        // Deletar o último:
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
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        // adicionando no começo da lista
        void prepend(int value) {
            Node* newNode = new Node(value);
            if(length == 0) return;
            if(length == 1) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }
};


int main() {

    DoublyLinkedList* newDLL = new DoublyLinkedList(10);
    
    newDLL->append(11);
    newDLL->append(13);
    newDLL->append(15);
    newDLL->prepend(1);
    newDLL->deleteLast();
    
    newDLL->printList();

    return 0;
}