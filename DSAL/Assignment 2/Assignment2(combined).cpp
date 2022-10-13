#include <bits/stdc++.h>
using namespace std;
class conversion{
public:
    void infixtopostfix(string s){
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

void infixtoprefix(string s){
    string ans;
    reverse(s.begin(),s.end());
    cout << endl;
    cout << "Prefix expression : ";
    stack<char>ss;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            s[i] = ')';
        }
        else if(s[i]==')'){
            s[i]= '(';
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
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

bool postfixevaluation(){
    cout << "Please enter postfix expression: ";
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
        if(s[i]>=48){
            ss.push(m[s[i]]);
        }
        else{
            double first,second,newadd;
            char expression,v1,v2;
            if(ss.empty()){
                cout << "Please enter valid postfix expression" << endl;
                return 1;
            }
            second = ss.top();
            ss.pop();
            if(ss.empty()){
                cout << "Please enter valid postfix expression" << endl;
                return 1;
            }
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
    if(ss.size()>1){
        cout << "Please enter valid postfix expression" << endl;
        return 1;
    }
    cout << endl;
    cout << "Value of postfix expression : ";
    cout << ss.top()<< endl;
    cout << endl;
    return 0;
}
bool prefixevalution(){
    cout << "Please enter prefix expression : ";
    string s; cin>>s;
    map<char,double>m;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
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
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>=48){
            ss.push(m[s[i]]);
        }
        else{
            double first,second,newadd,value1,value2;
            char expression,v1,v2;
            if(ss.empty()){
                cout << "Please enter valid prefix expression" << endl;
                return 1;
            }
            second = ss.top();
            ss.pop();
            if(ss.empty()){
                cout << "Please enter valid prefix expression" << endl;
                return 1;
            }
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
    if(ss.size()>1){
        cout << "Please enter valid prefix expression" << endl;
        return 1;
    }
    cout << "Value of prefix expression : ";
    cout << ss.top()<< endl;
    cout << endl;
    return 0;
}
bool checkinfix(string s){
    for(int i=0;i<s.size()-1;i++){
        if(s[i]<48 && s[i+1]<48&&s[i]!='('&&s[i+1]!=')'&&s[i]!=')'&&s[i+1]!='('){
            cout << "This is not a valid infix expression";
            return 1;
        }
        else if(s[i]>=48&&s[i+1]>=48){
            cout << "This is not a valid infix expression";
            return 1;
        }
    }
    return 0;
}
};
int main(){
    while(1){
        cout << endl;
        cout << "Please select choice" << endl;
        cout << "1.Enter infix expression to convert it into prefix and postfix" << endl;
        cout << "2.Evaluate given postfix expression" << endl;
        cout << "3.Evaluate given prefix expression" << endl;
        cout << "4.Exit" << endl;
        cout << endl;
        cout << "Please enter choice : ";
        int ch; cin>>ch;
        conversion sh;
        if(ch==1){
            cout << "Please enter your expression : ";
            string s; cin>>s;
            while(sh.checkinfix(s)){
                cout << endl; cout << endl;
                cout << "Please enter a valid infix expression :";
                cin>>s;
            }
            sh.infixtopostfix(s);
            sh.infixtoprefix(s);
        }
        else if(ch==2){
            while(sh.postfixevaluation()){};
        }
        else if(ch==3){
            while(sh.prefixevalution()){};
        }
        else if(ch==4){
            cout << "Exiting the code..." << endl;
            break;
        }
        else{
            cout << "Please enter valid choice" << endl;
        }
    }
}
