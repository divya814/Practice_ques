#include <iostream>
using namespace std;

int search(int a[], int n,int i, int key){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i+1;
    }
    return search(a,n,i+1,key);
}
int main(){
    int arr[]={2,4,5,7,87,1,9,3,62};
    cout<<search(arr,sizeof(arr)/sizeof(int),0,3);
}
