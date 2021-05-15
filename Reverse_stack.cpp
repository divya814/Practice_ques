// Recursive way to Reverse Stack-> Suppose we have reversed all the stack using recursion, now we will puch the top element of our given stack at the bottom of the stack to make it reverse.

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack <int>&st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}

void reverse(stack <int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);  // put the top element at bottom of the stack 
}

int main() {
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;	
	return 0;
}
