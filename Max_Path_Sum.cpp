// Find maximum path sum between any two nodes (nodes can be negative)

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

int maxPath(Node *root,int &ans){
    if (root==NULL){
        return 0;
    }
    int left=maxPath(root->left,ans);
    int right=maxPath(root->right,ans);
    int nodeMax=max(max(root->data,root->data+left+right),
                    max(root->data+left,root->data+right));
    ans=max(nodeMax,ans);
    int singlePath=max(root->data,max((root->data+left),(root->data+right)));
    return singlePath;
}

int maxAns(Node *root){
    int ans=INT_MIN;
    maxPath(root,ans);
    return ans;
}

int main() {
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->left=new Node(5);
	root->right->right=new Node(6);
	root->right->left->left=new Node(7);
	
	cout<<maxAns(root);
	
}
