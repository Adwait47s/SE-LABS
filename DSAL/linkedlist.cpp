#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class linkedlist{
    public:
    node *head;
    linkedlist()
    {
        head =NULL;
    }
  
    void additionbegin(int dataa){                      // Function to add an element at the begining of the linked-list
        node *temp;
        temp = new node();
        temp->data = dataa;
        if(head==NULL)                                  // If head==NULL then initializing linked list
        {
            temp->next = NULL;
            head  = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
  
    void addatend(int dataa){                          // Function to add an element at then end of the linked-list
        node *neww,*temp;
        neww = new node();
        temp =head;
        if(head==NULL){                                // If head==NULL then initializing linked list
            neww->data= dataa;
            neww->next =NULL;
            head=neww;
            return;
        }
        while(temp->next!=NULL){                       // If head==NULL then initializing linked list
            temp= temp->next;
        }
        neww->data = dataa;
        neww->next = NULL;
        temp->next = neww;
    }
  
    void addwish(int element,int dataa){               // Function to add an element after a certain element
        node *temp,*neww;
        temp = head;    
        neww = new node();
        bool flag =0;
        if(head==NULL){
          cout << "The linked-list is empty" << endl;
          return;
        }
        while(temp!=NULL){
            if(temp->data==element){
                flag =1;                               // First checking if that element is present in the linked-list or not
                break;
            }
        } 
        if(!flag){                                     // If element not found then returning "Element not found"
            cout << "Element not found" << endl;
            return;
        }
        
        neww->data = dataa;
        neww->next = temp->next;
        temp->next=neww;
    }
  
    void deletee(int dataa){                           // Function to delete an element in linked-list
        node *temp,*pre;
        temp = head;
        if(head==NULL){
            cout << "Linked list is empty" << endl;
            return;
        }
        if(head->data==dataa){                        // If first element is for deletition then deleting first element and changing head
            head =head->next;
            return;
        }
        bool flag =0;
        while(temp!=NULL){
            if(temp->data==dataa){
                flag =1;                             // First checking if that element is present in the linked-list or not
                break;
            }
            pre = temp;
            temp = temp->next;
        }
        if(!flag){
            cout << "Element not found" << endl;     // If element not found then returning "Element not found"
            return;
        }
        else{
            pre->next = temp->next;
        }
    }
  
    void display(){                                  // Function to display linked list
        node *temp;
        temp = head;
        if(head==NULL){
            cout << "Linked list is empty" << endl;
            return;
        }
        while(temp!=NULL){
            cout << temp->data  << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    linkedlist l ;
    while(1){
        cout << "1.Display" << endl;
        cout << "2.Add element in the begining" << endl;
        cout << "3.Add element in the end" << endl;
        cout << "4.Add element after an element" << endl;
        cout << "5.Delete element" << endl;
        cout << "6.Exit" << endl;
        int ch;
        cin>>ch;
        if(ch==1){
            cout << endl;
            l.display();
        }
        else if(ch==2){
            cout << "Enter the element you want to insert" << endl;
            int ele; cin>>ele;
            l.additionbegin(ele);
        }
        else if(ch==3){
            cout << "Enter the element you want to insert" << endl;
            int ele; cin>>ele;
            l.addatend(ele);
        }
        else if(ch==4){
            cout << "Enter the element after which you want to insert an element" << endl;
            int ele; cin>>ele;
            cout << "Enter the element you want to insert" << endl;
            int addd; cin>>addd;
            l.addwish(ele,addd);
        }
        else if(ch==5){
            cout << "Please enter the element you want to delete" << endl;
            int ele; cin>>ele;
            l.deletee(ele);
        }
        else if(ch==6){
            break;
        }
        else{
            cout << "Please enter a valid choice" << endl;
        }
        cout << endl;

    }
}
