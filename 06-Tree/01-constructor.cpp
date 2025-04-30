#include <iostream>

using namespace std;

int deep = 0;

// Constructor
class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr; 
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;
    public:
        BinarySearchTree(){
            root = nullptr;
        }
};

int main() {

    BinarySearchTree* myBST = new BinarySearchTree();

    return 0;
}