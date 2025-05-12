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

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << " " <<temp->value << endl;
                cout << " \\/" << endl;
                temp = temp->next;
            }
        }

        // remover topo
        void pop() {
            if(height == 0) return;

            Node* temp = top;
            top = top->next;
            delete temp;
            height--;
        }

        // remover com o retorno sendo int:

        int popInt() {
            if(height == 0) return INT_MIN;

            Node* temp = top;
            int valorRemov = top->value;
            top = top->next;
            delete temp;
            height--;

            return valorRemov;
        }
};

int main() {

    Stack* newStack = new Stack(4);

    newStack->push(5);
    newStack->push(7);
    newStack->push(10);
    // remove 10;
    newStack->pop();

    newStack->printStack();
    cout << "----" << endl;
    // remove e retorna 7;
    cout << newStack->popInt() << endl;
    cout << "----" << endl;
    newStack->printStack();
    return 0;
}




