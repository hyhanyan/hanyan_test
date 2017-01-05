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


//把二叉搜索树转换成有序的双向链表，，这个是有头结点的
BiTreeNode* TreeToLink(BiTreeNode* root)
{
    if(NULL == root){
        return NULL;
    }
    stack<BiTreeNode *> st;
    BiTreeNode *p = root;
    BiTreeNode *pStart = new BiTreeNode;
    pStart->leftChild = NULL;
    pStart->rightChild = NULL;
    BiTreeNode *s = pStart;
    while(p != NULL || !st.empty()){
        
        while(p != NULL){
            st.push(p);
            p = p->leftChild;
        }
        if(!st.empty()){
            BiTreeNode *ps = st.top();
            s->rightChild = ps;
            ps->leftChild = s;
            s = s->rightChild;
            st.pop();
            p = ps->rightChild;
        }
    }

    return pStart;
}
/*
 *注意，当转为没有头结点的有序双向链表时，要用头结点来连接所有的节点，然后在delete掉，如果不用，那么在进入栈之后，树的最左面的孩子的右孩子会被遗弃，要注意
 *
*/
//把二叉搜索树转换成有序的双向链表，，这个是没有头结点的
BiTreeNode* TreeToNoLink(BiTreeNode* root)
{
    if(NULL == root){
        return NULL;
    }
    stack<BiTreeNode *> st;
    BiTreeNode *p = root;
    BiTreeNode *pStart = new BiTreeNode;
    pStart->leftChild = NULL;
    pStart->rightChild = NULL;
    BiTreeNode *s = pStart;
    while(p != NULL || !st.empty()){
        
        while(p != NULL){
            st.push(p);
            p = p->leftChild;
        }
        if(!st.empty()){
            BiTreeNode *ps = st.top();
            s->rightChild = ps;
            ps->leftChild = s;
            s = s->rightChild;
            st.pop();
            p = ps->rightChild;
        }
    }

    s = pStart;
    pStart = pStart->rightChild;
    delete s;
    return pStart;
}

int main()
{
    BiTree T;
    createBiTree(T);
    //TraverseBiTree(T);
    printf("\n");
    //abf##dG##H##Cg##eM##N##
    //621##43##5##87##9##
    //PrintZSBiTree(T);
/*
    BiTreeNode *pS = TreeToLink(T);
    pS = pS->rightChild;
    BiTreeNode *pEnd = pS;
    while(pEnd->rightChild != NULL){
        pEnd = pEnd->rightChild;
    }
    while(pS != NULL){
        printf("%c ",pS->data);
        pS = pS->rightChild;
    }
    while(pEnd != NULL){
        printf("%c ",pEnd->data);
        pEnd = pEnd->leftChild;
    }

*/
    BiTreeNode *pS = TreeToNoLink(T);
    if(pS == NULL){
        printf("jjjj\n");
    }
    BiTreeNode *pEnd = pS;
    while(pEnd->rightChild != NULL){
        pEnd = pEnd->rightChild;
    }
    while(pS != NULL){
        printf("%c ",pS->data);
        pS = pS->rightChild;
    }
   while(pEnd != NULL){
        printf("%c ",pEnd->data);
        pEnd = pEnd->leftChild;
    }

    printf("\n");
    //PrintPreBiTree(T);
    //printf("\n");
    //PrintDeepBiTree(T);
    //TraverseBiTree(T);
    return 0;
}
