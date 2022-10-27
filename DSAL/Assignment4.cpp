#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    char data;
    node *left,*right;
    node(char c){
        left = NULL;
        right = NULL;
        data =c;
    }
    node(){
        left = NULL;
        right =NULL;
    }
    void inorder( node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data ;
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL) return;
    cout <<root->data ;
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
};

int main(){
    cout << "Please enter postfix expression : " ;
    string s;
    cin>>s;
    stack<node *>tree;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
            node *neww = new node(s[i]);
            tree.push(neww);
        }
        else{
            node *operation = new node(s[i]);
            node *second = tree.top();
            tree.pop();
            node *first = tree.top();
            tree.pop();
            operation->left = first;
            operation->right = second;
            tree.push(operation);
        }
    }
    node call;
    cout << "Inorder expression : ";
    call.inorder(tree.top());
    cout << endl;
    cout << "Postorder expression : ";
    call.postorder(tree.top());
    cout << endl;
    cout << "Preorder expression : ";
    call.preorder(tree.top());
    cout << endl;
}
