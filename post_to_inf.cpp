#include <iostream>
#include <stack>
using namespace std;

// Function to convert Postfix to Infix
string postfixToInfix(string postfix) {
    stack<string> st;
    
    for (char ch : postfix) {
        if (isalnum(ch)) {  // If operand, push onto stack
            string op(1, ch);
            st.push(op);
        } 
        else {  // If operator, pop two operands and form an infix expression
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = "(" + op1 + " " + ch + " " + op2 + ")";
            st.push(exp);
        }
    }
    
    return st.top();  // The final expression in the stack is the infix expression
}

int main() {
    string postfix = "ABC*DE^/+F+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
