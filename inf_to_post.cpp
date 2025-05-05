#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;  // Exponentiation has highest precedence
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char ch : infix) {
        if (isalnum(ch)) {  // If operand, add to output
            postfix += ch;
        } 
        else if (ch == '(') {  // If left parenthesis, push to stack
            st.push(ch);
        } 
        else if (ch == ')') {  // If right parenthesis, pop until '(' is found
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // Remove '(' from stack
        } 
        else {  // If operator
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*C/D^E+F";
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}
