#include <bits/stdc++.h>

using namespace std;

struct Node
{
    //int balanceFactor = 0;
    int data, height;
    Node *right;
    Node *left;
    Node(int _data, int _height = 0)
    {
        data = _data, height = _height;
        left = nullptr;
        right = nullptr;
    }
    //MUDEI
};

void bfs(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) 
	{
		//Node *s = q.front(); q.pop();
		// process node s
		int size = q.size(); 
		for(int i = 0; i < size; i++) {
			if(q.front() != nullptr)
			{
				q.push(q.front()->left);
				q.push(q.front()->right);
			}
			if(q.front() == nullptr) cout << "* ";
			else cout << q.front()->data << ' ';
			q.pop();
		}
		cout << '\n';
	}
}

/*
int search(int data, Node *root)
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
*/
/*
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << ' ' << root->balanceFactor << '\n';
        inorder(root->right);
    }
}
*/
int height(Node* root)
{
	if(root == nullptr)
		return -1;
	else
		return root->height; 
	//MUDEI
		
    /*if(root == nullptr)
        return 0;
    int lh = 0, rh = 0;
    lh = height(root->left);
    rh = height(root->right);
    return max(lh, rh) + 1;*/
}

int getBalanceFactor(Node *root)
{
    return height(root->left) - height(root->right);
}

void leftRotate(Node *&x)
{
    Node *aux, *aux1;
    
    aux = x->right;
    x->right = aux->left;
    aux->left = x;
	x->height = max(height(x->right), height(x->left)) + 1;
	aux->height = max(height(aux->right), height(aux->left)) + 1;
    x = aux;
    //MUDEI
    /* aux = x;
    aux1 = x->right;
    aux->right = aux1->left;
    aux1->left = aux;
    x = aux1; */
    
    //cout << aux->left->balanceFactor << ' ' << aux->balanceFactor << ' ' << aux->right->balanceFactor<< '\n';
    //x->balanceFactor = getBalanceFactor(x);
    //aux->balanceFactor = getBalanceFactor(aux);
    //aux->right->balanceFactor = getBalanceFactor(aux->right);
    //cout << aux->left->balanceFactor << ' ' << aux->balanceFactor << ' ' << aux->right->balanceFactor << '\n';
    
    //     return aux;
}

Node* rightRotate(Node *&x)
{
    Node *aux;
    
    aux = x->left;
    x->left = aux->right;
    aux->right = x;
	x->height = max(height(x->right), height(x->left)) + 1;
	aux->height = max(height(aux->right), height(aux->left)) + 1;
    x = aux;
    //MUDEI
    /* aux = x;
    aux1 = x->left;
    aux->left = aux1->right;
    aux1->right = aux;
    x = aux1; */
    
    //cout << aux->left->balanceFactor << ' ' << aux->balanceFactor << ' ' << x->balanceFactor << '\n';
    //x->balanceFactor = getBalanceFactor(x);
    //aux->balanceFactor = getBalanceFactor(aux);
    //aux->left->balanceFactor = getBalanceFactor(aux->left);
    //cout << aux->left->balanceFactor << ' ' << aux->balanceFactor << ' ' << x->balanceFactor << '\n';
    //return aux;
}

void balance(Node *&root)
{
	if(height(root->left) - height(root->right) > 1 
	   and height(root->left->right) > height(root->left->left))
	{
		leftRotate(root->left);
		rightRotate(root);
	}
	else if(height(root->left) - height(root->right) > 1)
		rightRotate(root);
	else if(height(root->right) - height(root->left) > 1 
	   and height(root->right->left) > height(root->right->right))
	{
		rightRotate(root->right);
		leftRotate(root);
	}
	else if(height(root->right) - height(root->left) > 1)
		leftRotate(root);
	root->height = max(height(root->right), height(root->left)) + 1;
	//MUDEI
	
    /*if(root->balanceFactor == -2 and root->right->balanceFactor == 1)
    {
        rightRotate(root->right);
        leftRotate(root);
    }
    else if(root->balanceFactor == -2 and root->right->balanceFactor == -1)
        leftRotate(root);
    else if(root->balanceFactor == 2 and root->left->balanceFactor == -1)
    {
        leftRotate(root->left);
        rightRotate(root);
    }
    else rightRotate(root);*/
}

void insert(int data, Node *&root)
{
	if(root == nullptr)
		root = new Node(data);
	else if(data < root->data)
		insert(data, root->left);
	else
		insert(data, root->right);
	
	balance(root);
	//MUDEI
	
    /*if(root == nullptr)
        return new Node(data);
    else
    {
        if(data <= root->data)
            root->left = insert(data, root->left);
        {
            root->balanceFactor = getBalanceFactor(root);
        }
        else
        {
            root->right = insert(data, root->right);
            root->balanceFactor = getBalanceFactor(root);
        }
        return root;    
    }*/
}
/*
8 9 10
8 10 9
9 8 10
9 10 8
10 8 9
10 9 8
*/
int main()
{
	//MUDEI
    Node *root = nullptr;
    int x;
    
    while(cin >> x)
    {
        insert(x, root);
        /*else
        {
            insert(x, root);
            if(abs(root->balanceFactor) > 1)
               balance(root);
            //cout << root->data << ' ' << root->balanceFactor << '\n';
        }*/
    }
    bfs(root);
    //leftRotate(root);
    //cout << root->left->data << ' ' <<  root->data << ' ' << root->right->data << ' ' << root->balanceFactor << '\n';
    //inorder(root);
    return 0;
}
