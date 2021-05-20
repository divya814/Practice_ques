#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int height(Node* root){
    if (root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight,rheight)+1;
}

int diameter(Node* root){
    if (root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    int calHeight=lheight+rheight+1;
    
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    return max(calHeight,max(ldiameter,rdiameter));
}

//     1
//    / \
//   2   3
//  / \
// 4   5

int main() {
	struct Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	cout<<diameter(root);
	return 0;
}
