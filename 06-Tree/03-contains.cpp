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
    
        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value) {
            Node* newNode = new Node(value);

            if(root == nullptr) {
                root = newNode;
                return true;
            }

            Node* temp = root;
            while(true) {
                if(value == temp->value) return false;
                if(value < temp->value) {
                    if(temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if(temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        // insert void
        void insertV(int value) {
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

        // Checar se um valor está na árvore:
        bool check(int value) {
            if (root == nullptr) return false;

            Node* temp = root;

            while(temp) {
                if(value < temp->value) {
                    temp = temp->left;
                } else if(value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }
};

int main() {

    BinarySearchTree* myBST = new BinarySearchTree();

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

    cout << "Valor foi encontrado? " << endl;

    if (myBST->check(27) == 1) {
        cout << "Sim :D";
    } 
    else cout << "Não :(";

    return 0;
}