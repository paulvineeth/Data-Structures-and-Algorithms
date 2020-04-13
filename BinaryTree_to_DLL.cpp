#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
};

void displaylist(struct node *hd){
    struct node *temp;
    while(hd){
        cout<<hd->data<<"->";
        temp = hd;
        hd = hd->right;
    }
    if(!hd){
        cout<<"NULL"<<endl;
    }
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->left;
    }
    if(!temp){
        cout<<"NULL";
    }
}

struct node *newnode(int d){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = temp->right = NULL;
}

void traverse(struct node *rt){
    if(rt == NULL){
        return;
    }
    cout<<rt->data<<" ";
    traverse(rt->left);
    traverse(rt->right);
}

void bintreetodll(struct node *rb, struct node **hr, struct node **tl){
    if(rb == NULL){
        return;
    }
    
    struct node *l = rb->left;
    struct node *r = rb->right;
    bintreetodll(l,hr,tl);
    
   
    
    if(*hr == NULL){
        *hr = rb;
    }
    if(*tl == NULL){
        *tl = rb;
        rb->left = rb->right = NULL;
    }
    else{
        (*tl)->right = rb;
        rb->left = (*tl);
        rb->right = NULL;
        *tl = rb;
    }
    
    bintreetodll(r, hr,tl);
    
}

int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    
    root->left->left = newnode(5);
    root->right->left = newnode(6);
    
    traverse(root);
    cout<<endl;
    
    struct node *head = NULL;
    struct node *tail = NULL;
    bintreetodll(root, &head, &tail);
    displaylist(head);
    return 0;
}

