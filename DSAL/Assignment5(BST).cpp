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

    node* deletee(node *root,unordered_set<int>&s){
        if(root==NULL){
            cout << "Tree doesn't exist!" << endl;
            return root;
        }
        cout << "Please enter the data you want to delete : ";
        int key; cin>>key;
        if(s.count(key)){
            s.erase(key);
            if (root->data == key) {
                return BringRightNode(root);
            }
            node *dummy = root;
            while (root != NULL) {
                if (root->data > key) {
                    if (root->leftc != NULL && root->leftc->data == key) {
                        root->leftc = BringRightNode(root->leftc);
                        break;
                    } 
                    else {
                        root = root->leftc;
                    }
                } 
                else {
                    if (root->rightc != NULL && root->rightc->data == key) {
                        root->rightc = BringRightNode(root->rightc);
                        break;
                    } 
                    else{
                        root = root->rightc;
                    }
                }
            }
            return dummy;
        }
        else{
            cout << "The key is not present in the tree" << endl;
        }
        
    } 
    
    node* BringRightNode(node* root) {
        if (root->leftc == NULL) 
        {
            return root->rightc;
        } 
        else if (root->rightc == NULL)
        {
            return root->leftc;
        } 
        node* rightChild = root->rightc;
        node* lastRight = findLastRight(root->leftc);
        lastRight->rightc = rightChild;
        return root->leftc;
    }

    node* findLastRight(node* root) {
        if (root->rightc == NULL) {
            return root;
        }
        return findLastRight(root->rightc);
    }
    
    int depth(node *root ){
         if(root==NULL){
            return 0;
        }
        int lheight = depth(root->leftc);
        int rheight = depth(root->rightc);
        return max(lheight,rheight) +1;
    }

    node* godeep(node *root){
        if(root->rightc==NULL) return root;
        return godeep(root->rightc);
    }

    node* mirror(node *root,node *mirrorroot){
        mirrorroot->data=root->data;
        if(root->leftc!=NULL&&root->rightc!=NULL){
            mirrorroot->leftc = root->rightc;
            mirror(root->rightc,mirrorroot->leftc);
            mirrorroot->rightc = root->leftc;
            mirror(root->leftc,mirrorroot->rightc);
        }
        else{
            return mirrorroot;
        }
    }

    void leafnode(node *root){
        
        if(root==NULL) return;
        leafnode(root->leftc);
        if(root->leftc==NULL&&root->rightc==NULL){
            cout << root->data << " ";
        }
        leafnode(root->rightc);
    }

    node *createcopy(node *root){
        if(root==NULL) return NULL;
        node *copyroot = new node;
        copyroot->data = root->data;
        copyroot->leftc = createcopy(root->leftc);
        copyroot->rightc = createcopy(root->rightc);
        return copyroot;
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
    while(1){
        cout << "MENU" << endl; 
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Display tree (Traversal)" << endl;
        cout << "5.Display - Depth of tree" << endl;
        cout << "6.Display - Mirror image" << endl;
        cout << "7.Create a copy" << endl;
        cout << "8.Display all child nodes with their parent nodes" << endl;
        cout << "9.Display all leaf nodes" << endl;
        cout << "10.Display tree levelwise" << endl;
        cout << "11.Exit" << endl;
        cout << "Please select a choice : " ;
        int ch; cin>>ch;
        if(ch==1){
            root = call.insert(root,s);
        }
        else if(ch==2){
            root = call.deletee(root,s);
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
        else if(ch==5){
            cout << "The depth of the tree is "<<call.depth(root) << endl;
        }
        else if(ch==6){
            cout << "Work in progress!!, will be completed by tommorow!" << endl;
            cout << "If you have completed this part then make a pull request !" << endl;
            node *mirrorroot = new node(root->data);
            mirrorroot= call.mirror(root,mirrorroot);
            cout << "Inorder traversal : ";
            call.inorder(mirrorroot);
            cout << endl;
            cout << "Preorder traversal : " ;
            call.preorder(mirrorroot);
            cout << endl;
            cout << "Postorder traversal : " ;
            call.postorder(mirrorroot);
            cout << endl;
        }
        else if(ch==7){
            node *copyroot = new node(root->data);
            copyroot = call.createcopy(root);
            cout << "Inorder traversal : ";
            call.inorder(copyroot);
            cout << endl;
            cout << "Preorder traversal : " ;
            call.preorder(copyroot);
            cout << endl;
            cout << "Postorder traversal : " ;
            call.postorder(copyroot);
            cout << endl;
        }
        else if(ch==8){
            cout << "Work in progress !!" << endl;
        }
        else if(ch==9){
            call.leafnode(root);
            cout << endl;
        }
        else if(ch==10){
            cout << "Work in progress !!" << endl;
        }
        else if(ch==11){
            cout << "Exiting the code... " << endl;
            break;
        }
        else{
            cout << "Please enter correct choice " << endl;
        }
    }
}
