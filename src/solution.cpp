#include "solution.h"

bool isContains(Node* node, int key) {
    if (!node)
        return false;
    if (node->key == key)
        return true;
    if (key < node->key)
        return isContains(node->left, key);
                
    return isContains(node->right, key);
}

Node* insert(Node* node, int value) {
    if(!node)
    {
        Node* newNode = new Node(value);
        return newNode;
        }
    if (value < node->key){
        return insert(node->left, value);
    }else {
        return insert(node->right, value);
    }
        
    return node;
}

Node* getMax(Node* node) {
    if (!node)
        return nullptr;
    if (!node->right)
        return node;    
    return getMax(node->right);
}

Node* getMin(Node* node) {
    if (!node){
        return nullptr;
    }
    if (!node->left){
        return node;
    }
    return getMin (node->left);
}

Node* remove(Node* node, int key) {
    if (!node){
        return node;
    }
    if (node->key == key){
        if (!node->left && !node->right){
            delete node;
            return nullptr;
        }else if (!node->left || !node->right){
            if (node->left){
                Node* temp = node->left;
                delete node;
                return temp;
            }else {
                Node* temp = node->right;
                delete node;
                return temp;
            }
        }else{
                Node* temp = getMin(node->left);
                node->key = temp->key;
                temp->right = remove(temp->right, temp->key);
                return node;
        }
    }else if (node->key > key){
        remove(node->left, key);
    }else {
        node->right = remove (node->right, key);
    }
    return node;
}

Node* section(const Node* l, const Node* r) {
    return nullptr;
}

bool areCousins(const Node*, int key1, int key2) {
    return false;
}

int LCA(const Node*, int key1, int key2) {
    return -1;
}