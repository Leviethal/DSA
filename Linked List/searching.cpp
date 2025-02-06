#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void finding(Node *temp)
{
    int t;
    cin >> t;
    while (temp)
    {
        if (temp->data == t)
        {
            cout << "Found" << endl;
            return ;
        }
        temp = temp->next;
    }
    cout<<"NOT FOUND"<< endl;
    return ;
}
int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();

    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    Node *temp = head;
    finding(temp);
}