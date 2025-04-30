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

    // Diferente do linked list (e opcional) 
    // Será permitido criar uma arvore inicialmente vazia
    BinarySearchTree(){
        root = nullptr;
    }

    bool insert(int value) {
        Node* newNode = new Node(value);

        // Se não tiver raiz
        if (root == nullptr) {
            root = newNode;
            return true;
        }

        Node* temp = root;
        while(true) {
            // primeira verificação: impedir mesmos valores
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

    return 0;
}