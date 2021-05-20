#include <bits/stdc++.h>
using namespace std;

// Stack using Queue-> Make two queues q1 and q2
// push 1 element in q2 and if q1 has any element then push it in q2
// then swap both the queues
// popping q1 will give ans as stack

class Stack{
    int N;
    queue <int> q1;
    queue <int>q2;
    public:
    Stack(){
        N=0;
    }
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
    }
    
    void pop(){
        q1.pop();
        N--;
    }
    int top(){
        return q1.front();
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
	cout<<s.top();
	return 0;
}
