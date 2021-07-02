// Find subarray of minimum length having sum greater than x

#include <iostream>
using namespace std;

int smallestSubarray(int arr[],int n,int k ,int x){
    int sum=0,minLength=n+1,start=0,end=0;
    while (end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        while(sum>x && start<n){
            if(end-start<minLength){
                minLength=end-start;
            }
            sum-=arr[start++];
        }
    }
    return minLength;
}


int main() {
	int a[]={7,5,4,6,8,9};
	int k=3;
	int n=6;
	int x=20;
	if (smallestSubarray(a,n,k,x)==n+1){
	    cout<<"No subarray with sum greater than x exists"<<endl;
	}
	else{
	    cout<<smallestSubarray(a,n,k,x)<<endl;
	}
	return 0;
}
