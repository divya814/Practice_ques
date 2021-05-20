// Find the maximum area of rectangle formed in a histogram (bar chart)
// find the element that's height is less than its previous element's height (a[i])

#include "bits/stdc++.h"
using namespace std;

int max_area(vector<int> a){
    int i=0, n=a.size(), ans=0;
    stack <int> st;
    a.push_back(0);
    
    while (i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int h=a[st.top()];
            st.pop();            
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,len*h);
            }
        }        
        st.push(i);
        i++;
    }
    return ans;    
}

int32_t main() {
	vector <int> a={2,4,5,6,3};
	cout<< max_area(a);
}
