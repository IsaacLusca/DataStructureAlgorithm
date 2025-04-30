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
        ~LinkedList() {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            cout << "Deletado." << endl;
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
                cout << temp->value<< " ";
                temp = temp->next;
            }
        }

        void deleteLast() {
            if (length == 0) return;
            if(length == 1) {
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
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        Node* get(int index) {
            if(index < 0 || index >= length) return nullptr;

            Node* temp = head;
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        bool setOpcional(int index, int value) {
            if (index < 0 || index >= length) return false;
            Node* temp = head;

            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->value = value;
            return true;
        } 
        bool set(int index, int value) {
            Node* temp = get(index);

            if(temp != nullptr) {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value){
            if(index < 0 || index >= length) return false;

            if(index == 0) {
                prepend(value);
                return true;
            }
            if(index == length) {
                append(value);
                return true;
            } else {
                Node* newNode = new Node(value);
                Node* temp = get(index - 1);

                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return true;
            }

        
        }

        bool deleteNo(int index) {
            if(index < 0 || index >= length) return false;
            if(index == 0) {
                deleteFirst();
                return true;
            }
            if(index == length - 1) {
                deleteLast();
                return true;
            }
            Node* pre = get(index - 1);
            // Aumenta a complexidade de forma desnecessária
            // Node* temp = get(index);
            Node* temp = pre->next;

            pre->next = temp->next;
            delete temp;
            length--;

            return true;
        }

        // sem ser do tipo bool:
        void deleteNode2(int index) {
            if(index < 0 || index >= length) return;
            if(index == 0) return deleteFirst();
            if(index == length - 1) return deleteLast();
            
            Node* pre = get(index - 1);
            Node* temp = pre->next;
            
            pre->next = temp->next;
            delete temp;
            length--;
        }
};

int main() {

    LinkedList* newList = new LinkedList(10);

    newList->append(15);
    newList->append(20);
    newList->append(25);
    newList->append(30);

    newList->prepend(10);
    newList->prepend(5);
    newList->prepend(0);

    newList->deleteFirst();
    newList->deleteLast();

    cout<<endl;
    cout<< newList->get(0)->value;;
    cout<<endl;

    newList->set(1, 11);

    newList->insert(1, 9);

    newList->deleteNo(1);
    newList->deleteNo(0);
    newList->deleteNo(4);

    newList->printList();

    cout<<endl;
    delete newList;

    
    return 0;
}