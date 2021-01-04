#include <iostream>
using namespace std;

bool sorted(int a[], int n){
    if (n==1){
        return true;
    }
    bool rest=sorted(a+1,n-1);
    return (a[0]<a[1] && rest);
}
int main(){
    int arr[]={2,4,5,7,87,1,9,3,62};
    if(sorted(arr,sizeof(arr)/sizeof(int))){
        cout<<"Sorted";
    }
    
    else{
        cout<<"Unsorted";
    }
}
