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

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data<<" ";
}

void DiagonalorderUtil(struct node *root, int d, map<int,vector<int>> &Dmap){
    if(root == NULL){
        return;
    }
    Dmap[d].push_back(root->data);
    DiagonalorderUtil(root->left,d+1,Dmap);
    DiagonalorderUtil(root->right,d,Dmap);
}

void Diagonalorder(struct node *root){
    map<int,vector<int>> Dmap;
    DiagonalorderUtil(root,0,Dmap);
    
    for(auto it = Dmap.begin(); it != Dmap.end(); it++){
        for(auto itr = it->second.begin(); itr != it->second.end(); itr++){
            cout<<*itr<<"-";
        }
        cout<<endl;
    }
    
}

int main()
{
    struct node *root = newnode(1);
    
    root->left = newnode(2);
    root->right = newnode(3);
    
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    
    root->left->left->left = newnode(8);
    root->left->left->right = newnode(9);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(11);
    root->right->left->left = newnode(12);
    // root->right->left->right = newnode(13);
    // root->right->right->left = newnode(14);
    // root->right->right->ri+ght = newnode(15);
    
    
    postorder(root);
    cout<<endl;
    Diagonalorder(root);
    cout<<endl;
    //inorder(root);

    return 0;
}





