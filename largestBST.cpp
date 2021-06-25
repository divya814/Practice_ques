// Find largest BST in Binary tree

#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *right,*left;
    Node (int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    Info leftinfo=largestBST(root->left);
    Info rightinfo=largestBST(root->right);
    
    Info current;
    current.size=(1+leftinfo.size+rightinfo.size);
    if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->data && rightinfo.min>root->data){
        current.min=min(leftinfo.min, min(rightinfo.min,root->data));
        current.max=max(leftinfo.max, max(rightinfo.max,root->data));
        current.ans=current.size;
        current.isBST=true;
        return current;
    }
    // else
    
    current.ans=max(leftinfo.ans,rightinfo.ans);
    
    current.isBST=false;
    return current;
}

//      15
//  10      20
//5


int main(){
    Node *root=new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(5);
    cout<<"Largest BST size: "<<largestBST(root).ans<<endl;
    return 0;
}







