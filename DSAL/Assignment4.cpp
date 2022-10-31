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
    void inordernonrecursive(node *root){
        stack<node *> s;
        node *curr = root;
        
        while (curr != NULL || !s.empty()){
            while (curr !=  NULL){           
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data ;    
            curr = curr->right;  
        } 
    }
    void preordernonrecursive(node *root){
        stack<node *>s;
        s.push(root);
        while(!s.empty()){
            node *curr = s.top();
            cout << s.top()->data;
            s.pop();
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
        }
    }
    void postordernonrecursive(node *root){
        stack<node *>s;
        s.push(root);
        while (!s.empty()) {
        node * current_node = s.top();
        if (current_node->left) {
            s.push(current_node ->left);
            current_node -> left = NULL;
        } else if (current_node-> right) {
            s.push(current_node -> right);
            current_node -> right = NULL;
        } else {
            cout << current_node->data;
            s.pop();
        }
    }
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
    cout << endl;
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
    cout << "Inorder expression (recursion) : ";
    call.inorder(tree.top());
    cout << endl;
    cout << endl;
    cout << "Postorder expression (recursion) : ";
    call.postorder(tree.top());
    cout << endl;
    cout << endl;
    cout << "Preorder expression (recursion) : ";
    call.preorder(tree.top());
    cout << endl;
    cout << endl;
    cout << "Inorder expression (non-recursive way) : ";
    call.inordernonrecursive(tree.top());
    cout << endl;
    cout << endl;
    cout << "Preorder expression (non-recursive way) : ";
    call.preordernonrecursive(tree.top());
    cout << endl;
    cout << endl;
    cout << "Postorder expression (non-recursive way) : ";
    call.postordernonrecursive(tree.top());
    cout << endl;
    cout << endl;
}
