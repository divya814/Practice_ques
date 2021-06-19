// Print zig zig traversal of nodes in a binary tree

#include "bits/stdc++.h"
#include <stack>
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

void zigzag(Node *root){
    if(root==NULL){
        return;
    }
    
    stack<Node *> currstack;
    stack<Node *> nextstack;
    bool leftToRight=true;
    
    currstack.push(root);
    while (!currstack.empty()){
        Node * temp= currstack.top();
        currstack.pop();
        
        if(temp){
            cout<<temp->data<<" ";
            if (leftToRight){
                if(temp->left){
                    nextstack.push(temp->left);
                }
                if (temp->right){
                    nextstack.push(temp->right);
                }
            }
            else{
                if (temp->right){
                    nextstack.push(temp->right);
                }
                if(temp->left){
                    nextstack.push(temp->left);
                }
                
            }
        }
        
        if (currstack.empty()){
            leftToRight=!leftToRight;
            swap(nextstack,currstack);
        }
    }
};

int main() {
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	zigzag(root);
	cout<<endl;
	return 0;
}
