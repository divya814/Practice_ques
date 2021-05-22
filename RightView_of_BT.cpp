// Print Right View of a Binary Tree
// A slighly better approach than Level Order Traversal

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

void rightView(Node *root){
    if(root==NULL){
        return;
    }
    queue <Node *> q;
    q.push(root);
    
    while(!q.empty()){
        // calculate again and again for all the levels of BT
        int n=q.size();
        
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();
            if(i==n-1){
                cout<<node->data<<" ";
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}

int main() {
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	rightView(root);
	return 0;
}
