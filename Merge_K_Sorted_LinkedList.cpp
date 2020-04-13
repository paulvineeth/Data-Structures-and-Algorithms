#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
void display(struct node *hd){
    while(hd){
        cout<<hd->data<<"->";
        hd = hd->next;
    }
    if(!hd){
        cout<<"NULL";
    }
}
struct node *newnode(int d){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
}

struct node *merge(struct node *a, struct node *b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    struct node *result;
    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next,b);
    }
    else{
        result = b;
        result->next = merge(a,b->next);
    }
    return result;
}

struct node *mergeksorted(struct node *a[], int k){
    while(k!=0){
        int i = 0;
        while(i<k){
            a[i] = merge(a[i],a[k]);
            i++;
            k--;
        }
    }
    return a[0];
}

int main()
{
    struct node *head = NULL;
    int k = 3;
    int n = 3;
    node *arr[k-1];
    arr[0] = newnode(3);
    arr[0]->next = newnode(6);
    arr[0]->next->next = newnode(9);
    
    arr[1] = newnode(2);
    arr[1]->next = newnode(4);
    arr[1]->next->next = newnode(6);
    
    arr[2] = newnode(1);
    arr[2]->next = newnode(5);
    arr[2]->next->next = newnode(10);
    
    head = mergeksorted(arr, k-1);
    
    display(head);

    
    return 0;
}

