#include <iostream>
using namespace std;

void swap(int a[],int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void dnf(int a[], int n){
    int low=0;
    int mid=0;
    int high=n-1;
    
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else if(a[mid]==2){
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    dnf(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
