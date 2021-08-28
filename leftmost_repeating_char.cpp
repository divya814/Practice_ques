// Find the leftmost repeating character in the given string

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
	int res=INT_MAX;
	int fi[256];
	for(int i=0;i<256;i++){
	    fi[i]=-1;
	}
	for(int i=0;i<str.length();i++){
	    if(fi[str[i]]==-1){
	        fi[str[i]]=i;
	    }
	    else{
	        res=min(res,fi[str[i]]);
	    }
	}
	cout<<res;
	return 0;
}

// for better complexity/traversal, we can traverse the string from right to left and then we just have to do res=fi[str[i]]
