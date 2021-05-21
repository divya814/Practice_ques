// Stock span problem
//make a pair stack st for storing element and the no. of consecutive elements lesser than the current elements
// Recturn the array of integers

#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> a){
    vector<int>ans;
  // make a pair stack
    stack<pair<int,int>> s;
    
    int n=a.size();
    for(int i=0;i<n;i++){
        int days=1;
        while(!s.empty() and s.top().first<a[i]){
            days+=s.top().second;
            s.pop();            
        }
        s.push({a[i],days});
        ans.push_back(days);  // push_back is used because ans is an array not a stack
    }
    return ans;
}

int main() {
	vector<int> a={100,80,60,70,60,75,85};
	vector<int> res=stockspan(a);
	for(auto i:res){
	    cout<<i<<" ";
	}
}
