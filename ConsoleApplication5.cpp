#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char key[2];
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
void CreateTree(Tree& T)
{
    T = NULL;
}
Node* CreateNode(char x)
{
    Node* p;
    p = new Node;
    if (p == NULL)
        exit(1);
    p->key[0] = x;
    p->key[1] = '1';
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(Tree& T, char x)
{
    if (T)
    {
        if (T->key[0] == x)
        {
            T->key[1] = T->key[1] + 1;
            return 0;
        }
        if (T->key[0] > x)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}
void preorder(Tree Root)
{
    if (Root != NULL)
    {
        cout << "Phan tu '" << Root->key[0] << "' xuat hien: " << Root->key[1] << " lan." << endl;
        preorder(Root->pLeft);
        preorder(Root->pRight);
    }
}

int main()
{
    Tree T;
    CreateTree(T);
    string ChuoiChu;
    cin.ignore();
    getline(cin, ChuoiChu);
    for (int i = 0; i < ChuoiChu.size(); i++)
    {
        Insert(T, ChuoiChu[i]);
    }
    preorder(T);
    return 0;
}
