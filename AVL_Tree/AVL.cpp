#include "AVL.hpp"

void AVLTree::rootostorder(Node* root, int indent)
{
    if(root != nullptr) {
        if(root->right) {
            rootostorder(root->right, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (root->right) cout<<" /\n" << setw(indent) << ' ';
        cout << root->data << "\n ";
        if(root->left) {
            cout << setw(indent) << ' ' << " \\\n";
            rootostorder(root->left, indent+4);
        }
    }
}

int AVLTree::search(int data, Node* root)
{
    if(data == root->data)
        return 1;
    if(data < root->data and root->left == nullptr)
        return 0;
    else if(data < root->data and root->left != nullptr)
        search(data, root->left);
    else if(data > root->data and root->right == nullptr)
        return 0;
    else search(data, root->right);
}

void AVLTree::inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << root->balanceFactor <<'\n';
        inorder(root->right);
    }
}

int AVLTree::height(Node* root)
{
    if(root == nullptr)
        return -1;
    int lh = 0, rh = 0;
    lh = height(root->left);
    rh = height(root->right);
    return max(lh, rh) + 1;
}

int AVLTree::getBalanceFactor(Node* root)
{	
	return height(root->left) - height(root->right);
}

void AVLTree::leftRotate(Node* &x)
{
    Node *aux;
    
    aux = x->right;
    x->right = aux->left;
    aux->left = x;
    x->balanceFactor = getBalanceFactor(x);
    aux->balanceFactor = getBalanceFactor(aux);
	//x->height = max(height(x->right), height(x->left)) + 1;
	//aux->height = max(height(aux->right), height(aux->left)) + 1;
    x = aux;
  
}

void AVLTree::rightRotate(Node* &x)
{
    Node *aux;
    
    aux = x->left;
    x->left = aux->right;
    aux->right = x;
    x->balanceFactor = getBalanceFactor(x);
    aux->balanceFactor = getBalanceFactor(aux);
	//x->height = max(height(x->right), height(x->left)) + 1;
	//aux->height = max(height(aux->right), height(aux->left)) + 1;
    x = aux;

}

void AVLTree::balance(Node* &root)
{
	if(root == nullptr)
		return;
	root->balanceFactor = getBalanceFactor(root);
    if(root->balanceFactor == -2)
    {
    	if(root->right->balanceFactor == 1)
    	{
        	rightRotate(root->right);
        	leftRotate(root);
    	}
    	else leftRotate(root);
    }
    else if(root->balanceFactor == 2)
    {
		if(root->left->balanceFactor == -1)
    	{
        	leftRotate(root->left);
        	rightRotate(root);
    	}
    	else rightRotate(root);
    } 
}

Node* AVLTree::min(Node* root)
{
	if(root == nullptr)
		return nullptr;
	if(root->left == nullptr)
		return root;
	return min(root->left); 
	
}

void AVLTree::insert(int data, Node* &root)
{
	if(root == nullptr)
		root = new Node(data);
	else
	{
		if(data < root->data)
			insert(data, root->left);
		else
			insert(data, root->right);
		balance(root);
	}
}

void AVLTree::remove(int data, Node* &root)
{
	if(root == nullptr)
		return;
	if(data < root->data)
		remove(data, root->left);
	else if(data > root->data)
		remove(data, root->right);
	else if(root->left != nullptr and root->right != nullptr)
	{
		root->data = min(root->right)->data;
		remove(root->data, root->right);
	}
	else
	{
		Node *temp = root;
		root = (root->left != nullptr) ? root->left : root->right;
		delete(temp);
	}
	balance(root);
}
