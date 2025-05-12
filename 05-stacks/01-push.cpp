#include <bits/stdc++.h>

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

class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        
        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << " " <<temp->value << endl;
                cout << " \\/" << endl;
                temp = temp->next;
            }
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }
};

int main() {

    Stack* newStack = new Stack(4);

    newStack->push(5);
    newStack->push(7);
    newStack->push(10);

    newStack->printStack();

    return 0;
}