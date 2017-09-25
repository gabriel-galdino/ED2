#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data, balanceFactor;
        Node *right, *left;
        Node(int _data, int _balanceFactor = 0) : data (_data), balanceFactor(_balanceFactor), left(nullptr), right(nullptr){}
};


class AVLTree
{
    public:
        AVLTree(){};
        Node *root;
        
        void rootostorder(Node* root, int indent=0);

        int search(int data, Node *root);

        void inorder(Node* root);

        int height(Node* root);

        int getBalanceFactor(Node* root);

        void leftRotate(Node* &x);

        void rightRotate(Node* &x);
        
        void balance(Node* &root);
        
        Node* min(Node *root);
        
        void insert(int data, Node* &root);
        
        void remove(int data, Node* &root);
        
};
