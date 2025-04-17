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
                tail = newNode;
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
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
            if(length == 0) return;
            if(length == 1) {
                tail = nullptr;
                head = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length --;
        }

        Node* get(int index) {
            if(index < 0 || index >= length) return nullptr;
            Node* temp = head;
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
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
            }
            if(index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);

            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void deleteNo (int index) {
            if(index < 0 || index > length) return;
            if(index == 0) return deleteFirst();
            if(index == length - 1) return deleteLast();

            Node* prev = get(index - 1);
            Node* temp = prev->next;

            prev->next = temp->next;
            delete temp;
            length--;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* after = temp->next;
            Node* before = nullptr;

            for(int i = 0; i < length; i++) {
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }
};  


int main() {

    LinkedList* newList = new LinkedList(50);
    
    newList->append(60);
    newList->append(70);
    newList->append(80);
    
    newList->prepend(40);
    newList->prepend(30);
    newList->prepend(20);

    
    newList->deleteFirst();
    newList->deleteLast();

    newList->set(0, 29);

    newList->insert(1, 49);
    newList->deleteNo(5);

    newList->printList();
    
    cout<<endl;
    newList->reverse();
    cout<<endl;
    newList->printList();

    cout<<endl; 
    cout<< newList->get(2)->value;
    cout<<endl;


    cout << endl;
    delete newList;

    return 0;
}