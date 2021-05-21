#include<bits/stdc++.h>
using namespace std;

int Max_water(vector <int> a){
    int n=a.size(), ans=0;
    stack <int> s;
    
    for (int i=0;i<n;i++){
        while(!s.empty() and a[s.top()]<a[i]){
            int curr=s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            
            // width= distance between left and right element of current element -1
            int width=i-s.top()-1;
            
            // min of left and right element- current element
            int height=min(a[s.top()],a[i])-a[curr];
            
            ans+=height * width;
        }        
        s.push(i);
    }
    return ans;
}

int main()
{   vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<Max_water(a);
}
