// Flattening Binary Tree using linked list only

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(Node *root){
    if(root==NULL || root->left==NULL || root->right==NULL){
        return;
    }
    
    // If root->left is not NULL then we have to flatten it
    // then add it to root's right by temporarily assigning root->right to temp Node
    
    if((root->left)!=NULL){
        flatten(root->left);
        
        Node * temp=root->right;
        root->right=root->left;
        root->left=NULL;
        
        Node*t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}

void InOrder(Node *root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main() {
	Node *root=new Node(4);
	root->left=new Node(9);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(3);
	root->right->right=new Node(7);
	flatten(root);
	InOrder(root);
	cout<<endl;
	return 0;
}
