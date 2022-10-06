#include <bits/stdc++.h>
class conversion{
    public:
    void infixtopostfix(string s)
    {
    stack<char> ss;
    cout << endl;
    cout << "Postfix Expression: ";
    for(int i=0;i<s.size();i++)
    {

        if(s[i]>=48){                                     // Ascii value of zero is 48. Hence to differtiate between operators and variables we do this comparison
            cout << s[i];                                 // If it is a varialbe then we just print it
        }
        else{
            if(ss.empty()){
                ss.push(s[i]);
            }
            else{
                if(s[i]==40){                           
                    ss.push(s[i]);
                }
                else if(s[i]==40){
                    while(ss.top()!=40){
                        cout << ss.top();
                        ss.pop();
                    }
                    ss.pop();
                }
                else if(s[i]=='+'||s[i]=='-'){
                    while(!ss.empty()){
                        if(ss.top()==40){
                            break;
                        }
                        cout << ss.top();
                        ss.pop();
                    }
                    ss.push(s[i]);
                }
                else if(s[i]=='*'||s[i]=='/'){
                    while(!ss.empty()){
                        if(ss.top()=='('){
                            break;
                        }
                        if(ss.top()=='+'||ss.top()=='-'){
                            break;
                        }
                        cout << ss.top();
                        ss.pop();
                    }
                    ss.push(s[i]);
                }
            }
        }
    }
    
    if(!ss.empty()){
        while(!ss.empty()){
            cout << ss.top();
            ss.pop();
        }
    }
    cout << endl;
    cout << endl;
    }
    
int main()
{
    cout << "Please select choice" << endl;
    cout << "1.Enter infix expression to convert it into prefix and postfix" << endl;
    cout << "2.Evaluate given postfix expression" << endl;
    cout << "3.Evaluate given prefix expression" << endl;
    cout << "Please enter choice : ";
    cout << "4.Exit" << endl;
    int ch; cin>>ch;
    if(ch==1)
    {
        cout << "Please enter your expression : ";
        string s; cin>>s;
        conversion sh = new conversion();
        sh.infixtopostfix(s);
    }
    
