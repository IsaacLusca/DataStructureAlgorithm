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

        bool insertB(int value) {
            Node* newNode = new Node(value);

            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if(newNode->value == temp->value) return false;
                if(newNode->value < temp->value) {
                    if(temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
        
};

int main() {

    BinarySearchTree* myBST = new BinarySearchTree();
    BinarySearchTree* myBSTs = new BinarySearchTree();

    cout << "Root: " << myBST->root << endl;

    cout << "Árvore: " << endl;
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    
    myBST->insert(27);
    
    cout << myBST->root->left->right->value << endl;
    
    
    cout << "Árvore bool: " << endl;
    myBSTs->insertB(47);
    myBSTs->insertB(21);
    myBSTs->insertB(76);
    myBSTs->insertB(18);
    myBSTs->insertB(52);
    myBSTs->insertB(82);

    myBSTs->insertB(27);
    cout << myBSTs->root->left->right->value << endl;
    
    return 0;
}