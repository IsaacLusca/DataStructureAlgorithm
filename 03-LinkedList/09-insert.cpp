#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node (int value) {
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
            tail = newNode;
            head = newNode;
            length = 1;
        }
        ~LinkedList() {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            cout << "Deletado." << endl;
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
            if(length == 0) return;
            if(length == 1) {
                head = nullptr;
                tail == nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        Node* get(int index) {
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
        bool set(int index, int value) {
            Node* temp = get(index);

            if(temp != nullptr) {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value) {
            if(index < 0 || index > length) return false;
            if(index == 0) {
                prepend(value);
                return true;
            } else if(index == length) {
                append(value);
                return true;
            } else{
                Node* newNode = new Node(value);
                Node* temp = head;
                Node* pre = head;
                for(int i = 0; i < index; i++) {
                    pre = temp;
                    temp = temp->next;
                }
                pre->next = newNode;
                newNode->next = temp;
                length++;
                return true;
            }
        }


};

int main() {

    LinkedList* newList = new LinkedList(5);

    newList->append(6);
    newList->append(7);
    newList->append(8);
    newList->append(9);

    newList->deleteLast();

    newList->prepend(4);
    newList->prepend(3);
    newList->prepend(2);
    newList->prepend(1);
    
    newList->deleteFirst();

    newList->set(0, 8);
    newList->set(6, 2);

    newList->printList();
    cout<< endl;    

    newList->insert(2, 300);
    newList->printList();
    
    cout << endl;

    cout<< newList->get(4)->value << endl;
    cout<< newList->get(3)->value << endl;
    cout<< newList->get(2)->value << endl;


    delete newList;

    return 0;
}