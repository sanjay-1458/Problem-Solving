//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool isOperand(char value){
        string operators="+-*^/()";
        if(operators.find(value)==string::npos){
            return true;
        }
        else{
            return false;
        }
    }
    int precedence(char value){
        switch (value){
            case '^':
                return 3;
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }
    void evaluate(stack<char>&operators,stack<string>&operands){
        char topValue=operators.top();
        operators.pop();
        string operandB=operands.top();
        operands.pop();
        string operandA=operands.top();
        operands.pop();
        operands.push(operandA+operandB+string(1,topValue));
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here-+
        int size=s.size();
        stack<char> operators;
        stack<string> operands;
        for(int i=0;i<size;++i){
            char currValue=s[i];
            if(isOperand(currValue)){
                operands.push(string(1,currValue));
            }
            else{
                if(currValue=='('){
                    operators.push(currValue);
                }
                else if(currValue==')'){
                    while(operators.top()!='('){
                        evaluate(operators,operands);
                    }
                    operators.pop();
                }
                else{
                    while(!operators.empty() && precedence(currValue)<=precedence(operators.top())){
                        evaluate(operators,operands);
                    }
                    operators.push(currValue);
                }
            }
        }
        while(!operators.empty()){
            evaluate(operators,operands);
        }
        return operands.top();
        
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
