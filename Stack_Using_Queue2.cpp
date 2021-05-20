#include <bits/stdc++.h>
using namespace std;

// Stack using Queue

class Stack{
    int N;
    queue <int> q1;
    queue <int> q2;
    public:
    Stack(){
        N=0;
    }
    // push all elements in q1
    void push(int val){
        q1.push(val);
        N++;
    }
    
    // pop n-1 elements from q1 and push them into q2
    // then pop the last element of q1
    // and swap q1 and q2
    void pop(){
        if (q1.empty()){
            return;
        }
        while (q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
    }
    
    int top(){
        if (q1.empty()){
            return -1;
        }
        while (q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans= q1.front();
        q2.push(ans);
        
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
        return ans;
    }
    
    int count(){
        return N;
    }
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.count();
	return 0;
}
