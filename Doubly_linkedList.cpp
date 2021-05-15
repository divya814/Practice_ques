#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }    
};    // class always ends with ;

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    
    if (head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head, int val){
    
    if (head==NULL){
        insertAtHead(head,val);
        return;
    }
    
    // new node for new value
    node* n=new node(val);
    node* temp=head;
    
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    
    delete todelete;
}

void deletion(node* &head, int pos){
    // if we are deleting 1st node ,i.e, head
    if (pos==1){
        deleteHead(head);
        return;
    }
    int c=1;
    node* temp=head;
    while (temp!=NULL && c!=pos){
        temp=temp->next;
        c++;
    }
    temp->prev->next=temp->next;
    if (temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;    
}

int main() {
	node* head=NULL;
	insertAtTail(head,4);
	insertAtTail(head,3);
	insertAtTail(head,2);
	insertAtTail(head,1);
	display(head);
	insertAtHead(head,5);
	display(head);	
	deletion(head,3);
	display(head);
	return 0;
}
