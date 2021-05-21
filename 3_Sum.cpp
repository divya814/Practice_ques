// Q. Find any three elements whose sum is equal to target
// Sort the array
// use 2 pointer technique
// then solve it like 2 sum problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int target,n;
    cin>>n>>target;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    bool found=false;
    // solution
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        // two pointer
        int l=i+1;
        int h=n-1;
        while(l<h){
            int curr=a[i]+a[l]+a[h];
            if (curr==target){
                found=true;
            }
            if(curr<target){
                l++;
            }
            else{
                h--;
            }
        }
    }
    if (found==true){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
