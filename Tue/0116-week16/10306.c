#include<stdio.h>
#include<memory.h>
typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;

typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;

void insert(LinkedList *list, int data){
    ListNode *tmp=list->head;
    ListNode *tmp2=(ListNode*)malloc(sizeof(ListNode));
    tmp2->data=data;
    tmp2->prev=NULL;
    tmp2->next=NULL;
    if(list->head==NULL){
        list->head=tmp2;
        list->tail=tmp2;
        return ;
    }
    while(tmp!=NULL&&tmp->data<data){
        tmp=tmp->next;
    }

    if(tmp==NULL) {
        tmp2->prev=list->tail;
        list->tail->next=tmp2;
        list->tail=tmp2;
        return;
    }
    if(tmp==list->head) {
        tmp2->next=list->head;
        list->head->prev=tmp2;
        list->head=tmp2;
        return;
    }

    tmp->prev->next=tmp2;
    tmp2->prev=tmp->prev;
    tmp->prev=tmp2;
    tmp2->next=tmp;
}
void delete_head(LinkedList *list){
    if(list->head==list->tail) {
        list->head=list->tail=NULL;
        return ;
    }
    list->head=list->head->next;
    list->head->prev=NULL;
}
void delete_tail(LinkedList *list){
    if(list->head==list->tail) {
        list->head=list->tail=NULL;
        return ;
    }
    list->tail=list->tail->prev;
    list->tail->next=NULL;
}
