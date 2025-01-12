#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int sum=0;
    A(){
        cout<<"Default constructor"<<endl;
    }
    A(int a,int x=0){
        sum=a+x;
    }
    void display(){
        cout<<"Sum: "<<sum<<endl;
    }
};
int main(){
    A obj;
    A obj1(1,2);
    A obj2(4);
    obj1.display();
    obj2.display();
}