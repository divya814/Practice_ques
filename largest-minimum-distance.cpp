// Find largest minimum distance between k elements of an array

#include <iostream>
#include <algorithm>   // for using sort function
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
    int pos=arr[0], count;
    for (int i=0;i<n;i++){
        if ((arr[i]-pos)>=mid){
            pos=arr[i];
            count++;
            if(count==k){
                return true;
            }
        }
        
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k){
    sort(arr,arr+n);
    int result=-1;
    int left=1;   // first
    int right=arr[n-1];   // last element
    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(mid,arr,n,k)){
            result=max(result,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return result;
}


int main() {
	int n=5;
	int arr[]={1,2,8,4,9};
	int k=3;
	cout<<largestMinDistance(arr,n,k);
	return 0;
}
