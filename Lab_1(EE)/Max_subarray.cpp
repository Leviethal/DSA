#include<bits/stdc++.h>
using namespace std;
int Max_subarray(int arr[], int s){
    int maxsum=INT_MIN;
    int current=0;
    for(int i=0;i<s;i++){
        current+=arr[i];
        if(current<0)
        current=0; 
        maxsum=max(maxsum,current);
    }
    return maxsum;
}
int Max_subseq(int arr[], int s) {
    int sum=0;
    int max_element=INT_MIN;
    bool has_positive=false;

    for(int i=0;i<s;i++) {
        if(arr[i]>0) {
            sum+=arr[i];
            has_positive=true;
        }
        max_element=max(max_element, arr[i]);
    }
    return has_positive ? sum : max_element;
}

int main(){
    int t;
    cin>>t;
    int max_arr[t]={0},max_seq[t]={0};
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        max_arr[i]=Max_subarray(arr,n);
        max_seq[i]=Max_subseq(arr,n);
        
    }
    for(int i=0;i<t;i++){
        cout<<max_arr[i]<<" "<<max_seq[i]<<endl;
    }
}