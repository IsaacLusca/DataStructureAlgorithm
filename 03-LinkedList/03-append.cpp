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
            cout << "Deletado." << endl;
        }
        void append(int value) {
            Node* add = new Node(value);
            if (length == 0) {
                head = add;
                tail = add;
            } else {
                tail->next = add;
                tail = add;
            }
            length++;
        }
        
        void printar() {
            Node* temp = head;
            while (temp) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }
};
        

int main() {
    LinkedList* novaLista = new LinkedList(5);
    novaLista->append(3);
    novaLista->append(2);
    novaLista->append(1);
    novaLista->append(9);

    novaLista->printar();
    delete novaLista;
    
    return 0;
}