#include<stdio.h>
#include<memory.h>
struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};

struct list {
    struct treenode *head;
    struct treenode *tail;
};

typedef struct treenode TreeNode;
typedef struct list List;

List treeToListFunc(TreeNode * root){
    List *retp=(List*)malloc(sizeof(List));
    List ret=*retp;
    ret.head=root;
    ret.tail=ret.head;

    if(root==NULL) {
        return ret;
    }
    //fprintf(stderr,"%d\n",root->value);
    List left=treeToListFunc(root->left);
    List right=treeToListFunc(root->right);
    root->right=NULL;
    if(left.head==NULL&&right.head==NULL){
        return ret;
    }
    if(left.head==NULL){
        ret.head->left=right.head;
        ret.tail=right.tail;
        return ret;
    }
    if(right.head==NULL){
        ret.head->left=left.head;
        ret.tail=left.tail;
        return ret;
    }
    if(root->value%2){
        ret.head->left=right.head;
        right.tail->left=left.head;
        left.tail->left=NULL;
        ret.tail=left.tail;
        return ret;
    }
    if(root->value%2==0){
        ret.head->left=left.head;
        left.tail->left=right.head;
        right.tail->left=NULL;
        ret.tail=right.tail;
        return ret;
    }

}
