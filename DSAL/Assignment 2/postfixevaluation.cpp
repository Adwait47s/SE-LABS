#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << endl;
    cout << "Please enter postfix expression in the form of variables : ";
    string s; cin>>s;
    map<char,double>m;
    for(int i=0;i<s.size();i++){
        if(s[i]>=65){
            m[s[i]] = 0;
        }
    }
    cout << "Please enter values for variables" << endl;
    for(auto it:m){
        cout << it.first << " = ";
        double a; cin>>a;
        m[it.first] = a;
    }
    stack<double>ss;
    for(int i=0;i<s.size();i++){
        if(s[i]>=65){
            ss.push(m[s[i]]);
        }
        else{
            double first,second,newadd,value1,value2;
            char expression,v1,v2;
            second = ss.top();
            ss.pop();
            first = ss.top();
            ss.pop();
            expression = s[i];
            if(expression=='+'){
                newadd = first +second;
            }
            else if(expression=='-'){
                newadd = first-second;
            }
            else if(expression=='*'){
                newadd = first*second;
            }
            else if(expression=='/'){
                newadd = first/second;
            }
            ss.push(newadd);
        }
    }
    cout << endl;
    cout << "Value of postfix expression : ";
    cout << ss.top()<< endl;
    cout << endl;
}
