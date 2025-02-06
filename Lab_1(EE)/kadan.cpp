#include<bits/stdc++.h>
using namespace std;
int max_sum(int arr[],int n){
    int maxsum=INT_MIN;
    int current=0;
    for(int i=0;i<n;i++){
        current+=arr[i];
        if(current<0)
        current=0; 
        maxsum=max(maxsum,current);
    }
    return maxsum;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<max_sum(arr,n);
}