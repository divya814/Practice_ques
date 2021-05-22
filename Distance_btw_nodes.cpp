// Find the shortest distance between two nodes n1 and n2
// Steps: Find Least Common Ancestor of n1 and n2
//        Then find distance of n1 and n2 from LCA as d1 and d2 resp.
//        Then return d1+d2

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

Node * LCA(Node *root,int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    // if we got data then return root
    if(root->data==n1 || root->data==n2){
        return root;
    }
    
    // otherwise search data in left or right subtree
    Node *left=LCA(root->left,n1,n2);
    Node *right=LCA(root->right,n1,n2);
    
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL){     // if right==NULL
        return left;
    }
    return right;
}

int findDist(Node *root,int key, int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return dist;
    }
    
    int left=findDist(root->left,key,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,key,dist+1);
}

int distbtwNodes(Node *root,int n1, int n2){
    Node* lca=LCA(root,n1, n2);
    int d1=findDist(lca,n1,0);
    int d2=findDist(lca,n2,0);
    return d1+d2;
}

int main() {
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<distbtwNodes(root,4,7);
	return 0;
}
