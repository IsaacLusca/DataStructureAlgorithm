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
        int length = 0;

    public:
    
    LinkedList(int value) {
        Node* newNode = new Node(value);
        tail = newNode;
        head = newNode;
        length = 1;
    }
    ~LinkedList () {
        Node* temp = head;

        while (head) {
            head = head->next;
            delete temp;
            temp = head;
            length--;
        }
        cout << "Lista deletada" << endl;
    }

    void printList() {
        Node* temp = head;
        while(temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void append(int value) {
        Node* newNode =  new Node(value);
        if (length == 0) {
            tail = newNode;
            head = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void getLength() {
        cout << "Tamanho: " << length << endl;
    }
    void getHead () {
        cout << "Cabeça: " << head->value << endl;
    }
    void getTail () {
        cout << "Cauda: " << tail->value << endl;
    }

    void deleteLast() {
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
            return;
        } else if (length == 1) {
            delete tail;
            head = nullptr;
            tail = head;
        } else {
            Node* temp = head; 
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }
    // OUTRA FORMA:
    void deleteLastNode() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* pre = head;
            // Se ainda tiver o proximo nó
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        length--;
        delete temp;

    }
};


int main() {

    LinkedList* newNode = new LinkedList(5);

    newNode->append(1);
    newNode->append(2);
    newNode->append(3);
    newNode->append(4);
    newNode->deleteLastNode();

    newNode->getHead();
    newNode->getTail();
    cout << "Lista encadeada: " << endl;
    newNode->printList();
    cout << endl;
    newNode->getLength();
    delete newNode;


    
    return 0;
}