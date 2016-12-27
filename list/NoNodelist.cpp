#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>
using namespace std;


typedef struct Node
{
    int data;
    Node *next;
}Node;

Node *pFirst = NULL;
Node *BuyNode(int data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    p->next = NULL;
    p->data = data;

    return p;
}

void InsertHead(int data)
{
    if(pFirst == NULL){
        pFirst = BuyNode(data);
    }else{
        Node * pCur = BuyNode(data);
        pCur->next = pFirst->next;
        pFirst->next = pCur;
    }
}

void InsertEnd(int data)
{
    if(pFirst == NULL){
        pFirst = BuyNode(data);
    }else{
        Node *pCur = BuyNode(data);
        Node *s = pFirst;
        while(s->next != NULL){
            s = s->next;
        }
        s->next = pCur;
    }
}

void DestoryLink()
{
    while(pFirst != NULL){
        Node *p = pFirst;
        pFirst = pFirst->next;
        free(p);
    }
}
void ReverseLink()
{
    if(pFirst != NULL && pFirst->next != NULL){
        Node *p1 = pFirst;
        Node *p2 = pFirst->next;
        pFirst = pFirst->next;
        p1->next = NULL;

        while(pFirst != NULL){
            pFirst = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = pFirst;
        }
        pFirst = p1;
    }
}

void ShowLink()
{
    if(pFirst != NULL){
        Node *p = pFirst;
        while(p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main()
{
    InsertEnd(1);
    InsertEnd(2);
    InsertEnd(3);
    InsertEnd(4);
    InsertEnd(5);
    ShowLink();
    ReverseLink();
    ShowLink();
    DestoryLink();
    ShowLink();
    return 0;
}
