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
        Node* tail;
        Node* head;
        int length;
    
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            tail = newNode;
            head = newNode;
            length = 1;
        }

        ~LinkedList () {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
                length --;
            }
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
            if (length == 0) {
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

        void getLength() {
            cout << length << endl;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail= nullptr;
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
            Node* temp = head;
            head = head->next;
            delete temp;
        }

};

int main() {

    LinkedList* newList = new LinkedList(10);
    newList->append(4);
    newList->append(5);
    newList->append(7);
    newList->append(8);
    newList->append(5);

    newList->deleteLast();
    newList->deleteFirst();
    newList->deleteFirst();

    newList->printList();
    cout << endl;
    delete newList;
    return 0;
}