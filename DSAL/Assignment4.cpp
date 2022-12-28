#include <iostream>
using namespace std;
class node{
public:
    char data;
    node *left,*right,*next;
    node(char c){
        left = NULL;
        right = NULL;
        next = NULL;
        data =c;
    }
    node(){
        left = NULL;
        right =NULL;
        next= NULL;
    }
};

class stack{
    public:
    node* top;
    
    stack(){
        top =NULL;
    }

    void push(node *data){
        data->next = top;
        top = data;
    }
    
    node * pop(){
        if(top==NULL){
            cout << "The stack is empty!" << endl;
        }
        else{
            node * temp = top;
            top = top->next;
            return temp;
        }
    }
    
    node *topp(){
        if(top==NULL){
            cout << "The stack is empty !" << endl;
        }
        return top;
    }
    
    bool empty(){
        if(top==NULL) return 1;
        return 0;
    }
};

class mytree{
public:
    void inorder( node *root){
        if(root==NULL) return;
        inorder(root->left);
        cout << root->data ;
        inorder(root->right);
    }
    void inordernonrecursive(node *root){
        stack s;
        node *curr = root;
        
        while (curr != NULL || !s.empty()){
            while (curr !=  NULL){           
                s.push(curr);
                curr = curr->left;
            }
            curr = s.topp();
            s.pop();
            cout << curr->data ;    
            curr = curr->right;  
        } 
    }
    void preordernonrecursive(node *root){
        stack s;
        s.push(root);
        while(!s.empty()){
            node *curr = s.topp();
            cout << s.topp()->data;
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
        stack s;
        s.push(root);
        while (!s.empty()) {
        node * current_node = s.topp();
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
    stack tree;
    cout << endl;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48){
            node *neww = new node(s[i]);
            tree.push(neww);
        }
        else{
            node *operation = new node(s[i]);
            node *second = tree.topp();
            tree.pop();
            node *first = tree.topp();
            tree.pop();
            operation->left = first;
            operation->right = second;
            tree.push(operation);
        }
    }
    mytree call;
    cout << "Inorder expression (recursion) : ";
    call.inorder(tree.topp());
    cout << endl;
    cout << endl;
    cout << "Postorder expression (recursion) : ";
    call.postorder(tree.topp());
    cout << endl;
    cout << endl;
    cout << "Preorder expression (recursion) : ";
    call.preorder(tree.topp());
    cout << endl;
    cout << endl;
    cout << "Inorder expression (non-recursive way) : ";
    call.inordernonrecursive(tree.topp());
    cout << endl;
    cout << endl;
    cout << "Preorder expression (non-recursive way) : ";
    call.preordernonrecursive(tree.topp());
    cout << endl;
    cout << endl;
    cout << "Postorder expression (non-recursive way) : ";
    call.postordernonrecursive(tree.topp());
    cout << endl;
    cout << endl;
}
