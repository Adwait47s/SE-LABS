#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "Please enter postfix expression : ";
    string s; cin>>s;
    stack<string>ss;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
            string add(1,s[i]);
            ss.push(add);
        }
        else{
            string first,second,expression;
            second = ss.top();
            ss.pop();
            first = ss.top();
            ss.pop();
            expression = s[i];
            string ans = "(" + first +expression +second + ")";
            ss.push(ans);
        }
    }
    while(!ss.empty()){
        cout << ss.top();
        ss.pop();
    }
    cout << endl;

}
