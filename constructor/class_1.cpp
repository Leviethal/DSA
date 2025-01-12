#include<bits/stdc++.h>
using namespace std;

class student{
    int rno;
    string name;
    double fee;

    public:
    student()
    {
        cout<<"Enter your name: "<<endl;
        cin>>name;
        cout<<"Enter your roll number: "<<endl;
        cin>>rno;
        cout<<"Enter your fee amount: "<<endl;
        cin>>fee;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll number: "<<rno<<endl;
        cout<<"Fee: "<<fee<<endl;
    }
};
int main(){
    student s1;
    s1.display();
    return 0;
}