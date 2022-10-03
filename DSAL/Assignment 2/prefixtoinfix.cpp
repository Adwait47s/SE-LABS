#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "Please enter prefix expression : ";
    string s; cin>>s;
    stack<string>ss;
    for(int i=s.size()-1;i>=0;i--){
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
    string ans;
    while(!ss.empty()){
        ans +=ss.top();
        ss.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        if(ans[i]==')'){
            ans[i]='(';
        }
        else if(ans[i]=='('){
            ans[i]=')';
        }
    }
    cout << ans << endl;

}
