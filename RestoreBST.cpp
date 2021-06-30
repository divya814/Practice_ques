// Restore BST

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void calcPointers(Node *root, Node **first, Node ** mid, Node ** last, Node** prev){
    if(root==NULL){
        return;
    }
    calcPointers(root->left,first,mid,last,prev);
    
    if (*prev && root->data<(*prev)->data){
        if (!*first){
            *first=*prev;
            *mid=root;
        }
        // if not for the first Time
        // case 2 (distinct elements are to be swapped)
        else{
            *last=root;
        }
        
        // in case of adjacent elements last will be null
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}

void restoredBST(Node *root){
    Node *first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    
    calcPointers(root,&first,&mid,&last,&prev);
    if (first && last){
        swap(&(first->data),&(last->data));
    }
    else if (first && mid){
        swap(&(first->data),&(mid->data));
    }
    
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Driver Program to test above functions
int main()
{
    Node *root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->left=new Node(13);
    
    inorder(root);
    cout<<endl;
    
    restoredBST(root);
    cout<<endl;
    
    inorder(root);
    cout<<endl;
	
	
	return(0);
}
