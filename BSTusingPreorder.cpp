// Form a BST using its Preorder array

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node *constBST(int preorder[],int *preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    
    Node *root=NULL;
    if (key>min and key<max){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;
        
        if (*preorderIdx<n){
            // key will be the current value in the array
            root->left=constBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if (*preorderIdx<n){
            // key will be the current value in the array
            root->right=constBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
        
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
	int preorder[]={10,2,1,13,11};
	int n=5;
	int preorderIdx=0;
	Node * root=constBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
	inorder(root);
	return 0;
}
