#include <iostream>
using namespace std;

void maxSubarray(int arr[],int n,int k ,int x){
    int sum=0,ans=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum<x){
        ans=max(ans,sum);
    }
    
    for (int i=k;i<n;i++){
        sum=sum-arr[i-k];
        sum=sum+arr[i];
        
        if(sum<x){
            ans=max(sum,ans);
        }
    }
    cout<<"Maximum Subarray sum= "<<ans;
}


int main() {
	int a[]={7,5,4,6,8,9};
	int k=3;
	int n=6;
	int x=20;
	maxSubarray(a,n,k,x);
	return 0;
}
