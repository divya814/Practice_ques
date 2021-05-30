// Delete node from BST

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


Node * inordersuccessor(Node*root){
    Node * curr=root;
    
    // if its left is not NULL
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    // otherwise
    return curr;
}


Node * deleteinBST(Node*root,int key){
    if (key< root->data){
        root->left=deleteinBST(root->left,key);
    }
    else if(key> root->data){
        root->right=deleteinBST(root->right,key);
    }
    // now if the key is found
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        // case 3
        // if the key is found and it has both left and right subtree
        // now swap the value of root and its inorder successor
        
        Node* temp=inordersuccessor(root->right);
        root->data=temp->data;
        
        // delete that root as it is now in the right of our new root
        // i.e, delete the value of our inorder successor
        
        root->right=deleteinBST(root->right,temp->data);
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

//      4
//  2       5
//1   3       6

int main() {
	Node*root=new Node(4);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(3);
	root->right->right=new Node(6);
	int key=5;
	inorder(root);
	cout<<endl;
	deleteinBST(root,key);
	inorder(root);
}
