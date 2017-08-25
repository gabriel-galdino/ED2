#include "AVL.hpp"

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
    Node *root = nullptr;
    bool f = true;
    int x, y;

    while(cin >> x and x)
        insert(x, root);
       
    /*while(f)
    {  
        cout << "1. Inserir\n";
        cout << "2. Remover\n";
        cout << "3. Pesquisar\n";
        cout << "0. Sair\n";
        cin >> y;
        switch(y)
        {
            case 1:
                cin >> x;
                insert(x, root);
                break;
            case 2:
                cin >> x;
                remove(x, root);
                break;
            case 3:
                cin >> x;
                if(search(x, root)) cout << x << " existe\n";
                else cout << x << " nao existe\n";
            case 0:
                f = false;
        }
    }*/
   	rootostorder(root, 4);
    //inorder(root);
    //cout << root->data << root->balanceFactor << '\n';
    return 0;
}
