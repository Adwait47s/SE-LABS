#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *leftc,*rightc;
    node(int dataa){
        data = dataa;
        leftc = NULL;
        rightc = NULL;
    }
    node(){
        leftc = NULL;
        rightc =NULL;
    }
    node* insert(node *root,unordered_set<int>&s){
        cout << "Please enter the element you want to insert : ";
        int key; cin>>key;
        while(s.count(key)){
            cout << "Please enter an unique element : ";
            cin>>key;
        }
        s.insert(key);
        node *ptr = new node(key);
        if(root==NULL){
            root = ptr;
            return root;
        }
        node *curr = root;
        while(curr!=NULL){
            if(key>curr->data){
                if(curr->rightc ==NULL){
                    curr->rightc = ptr;
                    return root;
                }
                curr= curr->rightc;
            }
            else{
                if(curr->leftc ==NULL){
                    curr->leftc = ptr;
                    return root;
                }
                curr= curr->leftc;
            }
            
        }

    }
    void preorder(node *root){
        if(root==NULL) return;
        cout <<root->data << " ";
        preorder(root->leftc);
        preorder(root->rightc);
    }
    void postorder(node *root){
        if(root==NULL) return;
        postorder(root->leftc);
        postorder(root->rightc);
        cout << root->data << " ";
    }
    void inorder( node *root){
        if(root==NULL) return;
        inorder(root->leftc);
        cout << root->data << " " ;
        inorder(root->rightc);
    }
};
int main(){
    cout << "First create a tree" << endl;
    bool first = true;
    node *root=NULL;
    node call;
    unordered_set<int>s;
    while(1){
        if(first){
            cout << "Please enter root node :";
            int date; cin>>date;
            s.insert(date);
            node *ptr = new node(date);
            root = ptr;
            first =0;
        }
        else{
            cout << "You want to insert more elements ? (Y/N) : ";
            char c; cin>>c;
            if(c=='y'||c=='Y'){
                root = call.insert(root,s);
            }
            else if(c=='N'||c=='n'){
                break;
            }
            else{
                cout << "Please enter a valid choice" << endl;
            }
        }
    }
    cout << "MENU" << endl; 
    cout << "1.Insert" << endl;
    cout << "2.Delete" << endl;
    cout << "3.Search" << endl;
    cout << "4.Display tree (Traversal)" << endl;
    cout << "5.Display - Depth of tree" << endl;
    cout << "6.Display - Mirror image" << endl;
    cout << "Please select a choice : " ;
    int ch; cin>>ch;
    if(ch==1){
        call.insert(root,s);
    }
    else if(ch==3){
        cout << "Please enter the element you want to search : ";
        int key; cin>>key;
        if(s.count(key)){
            cout << "Element is present in the given tree" << endl;
        }
        else{
            cout << "Element is not present in the given binary tree" << endl;
        }
    }
    else if(ch==4){
        cout << "Inorder traversal : ";
        call.inorder(root);
        cout << endl;
        cout << "Preorder traversal : " ;
        call.preorder(root);
        cout << endl;
        cout << "Postorder traversal : " ;
        call.postorder(root);
        cout << endl;
    }
}
