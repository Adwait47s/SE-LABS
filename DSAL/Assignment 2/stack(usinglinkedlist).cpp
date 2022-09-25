#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};

class stack{
  
private:
  
	node *top;
  
public:
  
	stack(){
		top = NULL;
	}
  
	bool isempty(){
		if(top==NULL) return 1;
		return 0;
	}
  
	void push(){
		node *neww = new node();
		cout << "Please enter element you want to insert" << endl;
		int element;
		cin>>element;
		neww->data = element;
		neww->next = top;
		top=neww;
	}		
  
	void pop(){
		if(isempty()){
			cout << "The stack is empty" << endl;
			return;
		}
		top = top->next;
	}
  
	void display(){
		node *temp;
		temp = top;
 		if(isempty()){
			cout << "The stack is empty" << endl;
			return;
		}
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
    
	}
};

int main(){
	stack s;
	while(1){
		cout << "Please select a choice" << endl;
		cout << "1.Display" << endl;
		cout << "2.Insert an element in the stack (Push)" << endl;
		cout << "3.Pop an element from the stack" << endl;
		cout << "4.Check if the stack is empty or not" << endl;
		cout << "5.Exit" << endl;
		int ch;
		cin>>ch;
		cout << endl;
		if(ch==1){
			s.display();
		}
		else if(ch==2){
			s.push();
		}
		else if(ch==3){
			s.pop();
		}
		else if(ch==4){
			if(s.isempty()){
				cout << "The stack is empty" << endl;
			}
			else{
				cout << "The stack is not empty" << endl;
			}
		}
		else if(ch==5){
			cout << "Exiting the code...";
			break;
		}
		else{
			cout << "Please enter a valid choice" << endl;
		}
		cout << endl;
	}
}

