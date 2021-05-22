// Find maximum consecutive ones in an array
// you can change maximum k zeros to 1 to get maximum no. of 1s as answer

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
	vector<int> a(n);
	for(auto &i:a){
	    cin>>i;
	}
	int count1=0;
  // i is pointer
	int i=0,ans=0;
	for (int j=0;j<n;j++){
	    if(a[j]==0){
	        count1++;
	    }
	    while(count1>k){
	        if (a[i]==0){
	            count1--;
	        }
	        i++;
	    }
	    ans=max(ans,j-i+1);
	}
	cout<<ans;
}
