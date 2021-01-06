#include <iostream>
using namespace std;

void primefactor(int n){
    int spf[100]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){      // spf[2]=2
            for(int j=i*i;j<=n;j+=i){          //j=4
                if(spf[j]==j){             //spf[4]=4
                    spf[j]=i;             //spf[4]=2
                }
            }
        }
    }
    while(n!=1){
        cout<<n<<" of "<<spf[n]<<" ";           //spf[10]=2
        n=n/spf[n];            // n=10/2 = 5
        
    }
}
int main(){
    int n;
    cin>>n;
    primefactor(n);
}
