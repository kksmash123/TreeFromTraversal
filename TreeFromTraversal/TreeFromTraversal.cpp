// TreeFromTraversal.cpp
//with inorder and preorder creating a tree.


#include <iostream>

using namespace std;

struct Node
{
    char data;
    struct Node* lc;
    struct Node* rc;
}*root=NULL;

int search(char* I, int sin, int ein, char x);
struct Node* createNode(char x);
struct Node* createTree(char* I, char* P, int sin, int ein);
void InorderTraversal(struct Node* p);




int search(char* I, int sin, int ein, char x)
{
    for (int i = 0;i < ein;i++)
    {
        if (I[i] == x)
            return i;
    }
}

struct Node* createNode(char x)
{
    struct Node* p = new Node;
    p->data = x;
    p->lc = NULL;
    p->rc = NULL;
    return p;
}

struct Node* createTree(char* I,char* P,int sin,int ein)
{

    static int pin = 0;

    //leaf node termination point.
    if (sin > ein)
        return NULL;


    struct Node* p = createNode(P[pin++]);

    //single node tree
    if (sin == ein)
        return p;

    //search for the element index in inorder.
    int ele_in = search(I, sin, ein, p->data);

    p->lc = createTree(I, P, sin, ele_in - 1);
    p->rc = createTree(I, P, ele_in + 1, ein);

    return p;

}

void InorderTraversal(struct Node* p)
{
    if (p)
    {
        InorderTraversal(p->lc);
        cout << p->data << " ";
        InorderTraversal( p->rc);
    }
}


int main()
{
    char I[] = { 'D','B','E','A','F','C' };
    char P[] = { 'A','B', 'D','E','C','F'};
    

    int sin=0, ein=sizeof(I)/sizeof(I[0]);

    root=createTree(I,P,sin,ein);

    InorderTraversal(root);
   
}
