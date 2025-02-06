#include<bits/stdc++.h>
using namespace std;

void genper(string s,int i=0){
    if(i==s.length()){
        cout<<s<<endl;
        return;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        genper(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string str;
    cin>>str;
    genper(str);
}