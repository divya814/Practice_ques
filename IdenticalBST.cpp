// check if the two given BSTs are identical or not

#include "bits/stdc++.h"
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


bool identical(Node * root1, Node * root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if (root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cond1=(root1->data==root2->data);
        bool cond2=identical(root1->left,root2->left);
        bool cond3=identical(root1->right,root2->right);
        
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
    
}

int main() {
	Node *root1=new Node(1);
	root1->left=new Node(2);
	root1->right=new Node(3);
	
	Node *root2=new Node(1);
	root2->left=new Node(2);
	root2->right=new Node(3);
	
	if (identical(root1,root2)){
	    cout<<"Identical";
	}
	else{
	    cout<<"Not Identical";
	}
	cout<<endl;
	return 0;
}
