#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

struct node *newnode(int d){
    struct node *temp = new node;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}

void levelOrderQ(struct node *root){
    if(root == NULL){
        return;
    }
    struct node *temp;
    queue<node*> q;
    q.push(root);
    while(q.empty() == false){
        temp = q.front();
        cout<<temp->data<<"-";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    
}

int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    levelOrderQ(root);

    return 0;
}

