#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "This code only works for one digit numbers" << endl;
    cout << endl;
    cout << "Please enter postfix expression : ";
    string s; cin>>s;
    stack<double>ss;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
            string news(1,s[i]);
            int add = stoi(news);
            ss.push(add);
        }
        else{
            double first,second,newadd;
            char expression;
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
    while(!ss.empty()){
        cout << ss.top();
        ss.pop();
    }
    cout << endl;
    cout << endl;

}
