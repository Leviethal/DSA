#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int sum[t]={0};
    for(int i=0;i<t;i++){
        int arr[5];
        for(int j=0;j<5;j++){
            cin>>arr[j];
            sum[i]+=arr[j];
        }
    }
    int r=0;
    for(int i=1;i<t;i++){
        if(sum[i]>sum[0])
        r++;
    }
    cout<<r<<endl;
}