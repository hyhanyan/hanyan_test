#include<cstdio>
#include<stack>
#include<deque>
#include<iostream>
using namespace std;

typedef struct node
{
    struct node *leftChild;
    struct node *rightChild;
    char data;
}BiTreeNode, *BiTree;

void createBiTree(BiTree &T)
{
    char c;
    cin >> c;
    if('#' == c)
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data = c;
        createBiTree(T->leftChild);
        createBiTree(T->rightChild);
    }
}

void TraverseBiTree(BiTree T)
{
    if (NULL == T)
        return ;
    printf("%c ", T->data);
    TraverseBiTree(T->leftChild);
    TraverseBiTree(T->rightChild);

}


void PrintZSBiTree(BiTreeNode* root)
{
    if(NULL == root){
        return;
    }
    stack<BiTreeNode *> st1;
    stack<BiTreeNode *> st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            BiTreeNode *p = st1.top();
            printf("%c ",p->data);
            st1.pop();
            if(p->leftChild){
                st2.push(p->leftChild);
            }
            if(p->rightChild){
                st2.push(p->rightChild);
            }
        }

        while(!st2.empty()){
            BiTreeNode *s = st2.top();
            printf("%c ",s->data);
            st2.pop();
            if(s->rightChild){
                st1.push(s->rightChild);
            }
            if(s->leftChild){
                st1.push(s->leftChild);
            }
        }
    }
}

int main()
{
    BiTree T;
    createBiTree(T);
    //abf##dG##H##Cg##eM##N##
    PrintZSBiTree(T);
    //TraverseBiTree(T);
    return 0;
}
