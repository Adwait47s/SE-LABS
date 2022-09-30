#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
    cout << endl;
    cout << "Please enter you expression without spaces " << endl;
    string s;
    cin>>s;
    stack<char> ss;
    cout << endl;
    cout << "Postfix Expression: ";
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){                                     // Ascii value of zero is 48. Hence to differtiate between operators and variables we do this comparison
            cout << s[i];                                 // If it is a varialbe then we just print it
        }
        else{
            if(ss.empty()){
                ss.push(s[i]);
            }
            else{
                if(s[i]=='('){                           
                    ss.push(s[i]);
                }
                else if(s[i]==')'){
                    while(ss.top()!='('){
                        cout << ss.top();
                        ss.pop();
                    }
                    ss.pop();
                }
                else if(s[i]=='+'||s[i]=='-'){
                    while(!ss.empty()){
                        if(ss.top()=='('){
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
