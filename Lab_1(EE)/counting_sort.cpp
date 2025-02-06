#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++)
    cin>>arr[i];
    int r[100]={0}; 
    for(int i=0;i<=99;i++){
        r[i]=count(arr, arr + 100, i);
    }
    for(int i=0;i<100;i++)
    cout<<r[i]<<" ";
}