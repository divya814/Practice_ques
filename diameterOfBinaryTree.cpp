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

int diameter(Node * root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    // lh and rh will be udated by one in every recursion
    int ldiameter=diameter(root->left,&lh);
    int rdiameter=diameter(root->right,&rh);
    
    // update value of lh and rh 
    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    
    return max(currDiameter,max(ldiameter,rdiameter));
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
	int height=0;
	cout<<diameter(root,&height);
	return 0;
}
