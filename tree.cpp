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

void PrintPreBiTree(BiTreeNode* root)
{
    if(root == NULL){
        return ;
    }
    stack<BiTreeNode *> st;
    BiTreeNode *p = root;
    while(!st.empty() || p != NULL){
        while(p != NULL){
            st.push(p);
            printf("%c ",p->data);
            p = p->leftChild;
        }
        if(!st.empty()){
            p = st.top();
            st.pop();
            p = p->rightChild;
        }
    }

}

void PrintDeepBiTree(BiTreeNode *root)
{
    if(NULL == root){
        return;
    }
    stack<BiTreeNode *> st;
    st.push(root);
    while(!st.empty()){
        BiTreeNode * p = st.top();
        printf("%c ",p->data);
        st.pop();
        if(p->rightChild){
            st.push(p->rightChild);
        }
        if(p->leftChild){
            st.push(p->leftChild);
        }
    }
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
    TraverseBiTree(T);
    printf("\n");
    //abf##dG##H##Cg##eM##N##
    //PrintZSBiTree(T);
    PrintPreBiTree(T);
    printf("\n");
    PrintDeepBiTree(T);
    //TraverseBiTree(T);
    return 0;
}
