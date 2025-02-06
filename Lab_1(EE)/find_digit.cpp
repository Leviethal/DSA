#include<bits/stdc++.h>
using namespace std;
int num_div(int n){
    int d=0;
    while(n>0){
        if(n%10==0)
        {
            n/=10;
            continue;
        }
        else
        {
            if(n%(n%10)==0)
            d++;
            n/=10;
        }
    }
    return d;
}
int main(){
    int t;
    cin>>t;
    int r[t]={0};
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        r[i]=num_div(n);
    }
    for(int i=0;i<t;i++)
    cout<<r[i]<<endl;
}