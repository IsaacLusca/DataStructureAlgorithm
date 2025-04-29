#include <iostream>

using namespace std;

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

        void insert(int value) {
            Node* newNode = new Node(value);
        
            if (root == nullptr) {
                root = newNode;
                return;
            }
        
            Node* temp = root;
            while (true) {
                if (value <= temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
            }
        }
        
};

int main() {

    BinarySearchTree* myBST = new BinarySearchTree();

    cout << "Root: " << myBST->root;

    return 0;
}