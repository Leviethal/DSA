#include<bits/stdc++.h>
using namespace std;
class Base{
    public:

};
class A{
    public:
    A(){
        cout<<"A's constructor"<<endl;
    }
};
class B:public A{

};
class C:public A{
    public:
    C(){
        cout<<"C's constructor"<<endl;
    }
};
class D{
    A a;
    public:
    D()
    {
        cout<<"D's constructor"<<endl;
    }
};
int main(){
    Base base;
    B b;
    C c;
    D d;
    return 0;
}