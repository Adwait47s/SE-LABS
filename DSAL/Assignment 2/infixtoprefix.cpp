#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << endl;
    cout << "Please enter you infix expression without bracket : ";
    string s,ans;
    cin>>s;
    reverse(s.begin(),s.end());
    cout << "Prefix expression : ";
    stack<int>ss;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            s[i] = ')';
        }
        else if(s[i]==')'){
            s[i]= '(';
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>=97){
            ans+= s[i];
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
                        ans+= ss.top();
                        ss.pop();
                    }
                    ss.pop();
                }
                else if(s[i]=='+'||s[i]=='-'){
                    while(!ss.empty()){
                        if(ss.top()=='('){
                            break;
                        }
                        ans+=ss.top();
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
                        ans+= ss.top();
                        ss.pop();
                    }
                    ss.push(s[i]);
                }
            }
        }
    }
    
    if(!ss.empty()){
        while(!ss.empty()){
            ans+= ss.top();
            ss.pop();
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    cout << endl;
}
