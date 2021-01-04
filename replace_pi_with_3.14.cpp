#include <iostream>
using namespace std;

int main(){
    string s,s1;
    cin>>s;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]=='p' and s[i+1]=='i')
        {
            s.erase(i,2);
            s1=s.insert(i,"3.14");
        }
    }
    cout<<s1;
}
