// check if the given tree is BST or not

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

bool checkBST(Node *root, Node *min=NULL, Node *max=NULL){
    if (root==NULL){
        return true;
    }
    if (min!=NULL && min->data>root->data){
        return false;
    }
    if (max!=NULL && max->data<root->data){
        return false;
    }
    bool leftcheck=checkBST(root->left,min,root);
    bool rightcheck=checkBST(root->right,root,max);
    
    return leftcheck and rightcheck;
}

int main() {
	Node *root=new Node(3);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(6);
	root->right->left=new Node(4);
	if (checkBST(root,NULL,NULL)){
	    cout<<"BST";
	}
	else{
	    cout<<"Not a BST";
	}
	return 0;
}
