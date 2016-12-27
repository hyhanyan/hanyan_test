#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    Node *pNext;
}Node;

Node *pHead=NULL;

void InitLink()
{
    pHead = (Node*)malloc(sizeof(Node));
    if(pHead == NULL){
        return ;
    }
    pHead->pNext=NULL;
}

void ShowLink()
{
    Node *pCur = pHead->pNext;
    while(pCur != NULL){
        printf("%d ",pCur->val);
        pCur = pCur->pNext;
    }
    putchar('\n');
}

bool InsertLink(int data)
{
    Node *pCur = NULL;
    pCur = (Node*)malloc(sizeof(Node));
    if(pCur == NULL){
        return false;
    }
    pCur->val = data;
    pCur->pNext = pHead->pNext;
    pHead->pNext = pCur;
    return true;
}

bool InsertEnd(int data)
{
    Node *pCur=NULL;
    Node *pEnd = pHead;
    while(pEnd->pNext != NULL){
        pEnd = pEnd->pNext;
    }

    pCur = (Node*)malloc(sizeof(Node));
    if(pCur ==NULL){
        return false;
    }
    pCur->val = data;

    pCur->pNext = pEnd->pNext;
    pEnd->pNext = pCur;
    return true;
}

void ReverseLink()
{
    Node *pCur = pHead->pNext;
    if(pCur == NULL || pCur->pNext==NULL){
        return;
    } 
    Node *pRecord = pCur;
    pHead->pNext = NULL;
    while(pCur != NULL){
        pRecord = pCur->pNext;
        
        pCur->pNext = pHead->pNext;
        pHead->pNext = pCur;

        pCur = pRecord;
    }

}

int main()
{
    InitLink();
    InsertLink(1);
    /*InsertLink(2);
    InsertLink(3);
    InsertLink(4);
    InsertLink(5);*/

    ShowLink();
    ReverseLink();
    ShowLink();
    return 0;
}
