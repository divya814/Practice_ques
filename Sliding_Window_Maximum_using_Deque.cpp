#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector <int> a(n);
	for (auto &i:a){
	    cin>>i;
	}
  
	deque <int> q;
	vector <int> ans;
	
  // for 1st k elements
	for(int i=0; i<k;i++){
	    while(!q.empty() && a[q.back()]<a[i]){
	        q.pop_back();
	    }
	    // it will initially contain only 1 element
	    q.push_back(i);
	}
	ans.push_back(a[q.front()]);
	
  // for remaining elements
	for(int i=k; i<n;i++){
	    // if q has element(index of a) which is outside the range of k
	    if(q.front()==i-k){
	        q.pop_front();
	    }
	    while(!q.empty() && a[q.back()]<a[i]){
	        q.pop_back();
	    }
	    // it will initially contain only 1 element
	    q.push_back(i);
	    ans.push_back(a[q.front()]);
	}
	
	for (auto i:ans){
	    cout<<i<<" ";
	}
	return 0;
}

//6 2
//1 3 4 8 0 1
