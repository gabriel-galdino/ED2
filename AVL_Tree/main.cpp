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
    AVLTree *tree = new AVLTree();
    bool f = true;
    char c;
    int x;

    while(f)
    {
        cin >> c;
        switch(c)
        {
            case 'i':
            {
                cin >> x;
                tree->insert(x, tree->root);
                break;
            }
            case 'r':
            {
                cin >> x;
                tree->remove(x, tree->root);
                break;
            }
            case 'p':
            {
                tree->rootostorder(tree->root, 4);
                break;
            }
            default:
                f = false;
        }
    }

    return 0;
}
