/* 
Problem Statement
Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
*/

#include <iostream>
using namespace std;
const int maxx=10;
class queuee{                                                     // creating a class queue
private:
    int front,rear;
    int arr[maxx];
public:
    queuee(){                                                     // default constructor to initialize front, rear and an array
        front =-1; rear=-1;
        for(int i=0;i<maxx;i++){
            arr[i] = 0;
        }
    }
    bool sizefull(){                                              // function to check if queue is full or not
        if(rear==maxx-1&&front==0 || rear+1==front) return 1;
        return 0;
    }
    bool emptyy(){                                                // function to check if queue is empty or not
        if(front==-1&&rear==-1) return 1;
        return 0;
    }
    void addition(){                                          
        if(sizefull()){                                          // function to insert ans element in queue
            cout << "Queue is full" << endl;
            return;
        }
        else{
            cout << "Please enter the element you want to insert" << endl;
            int element;
            cin>>element;
            rear = (rear+1)%maxx;
            arr[rear] = element;
            if(front==-1){
                front=0;
            }
        }
    }
    void deletation(){                                          // function to delete an element in queue
        if(emptyy()){
            cout << "Queue is empty" << endl;
            return;
        }
        else{
            arr[front]=0;
            if(front==rear){
                front =-1; rear=-1;
            }
            else{
                front = (front+1)%maxx;
            }
        }
    }
    void display(){                                            // function to diplay queue
        if(emptyy()){
            cout << "Queue is empty" << endl;
        }
        for(int i=0;i<maxx;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    queuee q;
    while(1){
        cout << "Please enter choice" << endl;
        cout << "1.Add element in queue" << endl;
        cout << "2.Delete element in queue" << endl;
        cout << "3.Display queue" << endl;
        cout << "4.To cheak if queue is full " << endl;
        cout << "5.To check if queue is empty " << endl;
        cout << "6.Exit" << endl;
        int ch;
        cin>>ch;                                                // taking input for choice
        
        if(ch==1){
            q.addition();
        }
        else if(ch==2){
            q.deletation();
        }
        else if(ch==3){
            cout << endl;
            q.display();
        }
        else if(ch==4){
            if(q.sizefull()){
                cout << "Queue is full" << endl;
            }
            else{
                cout << "Queue is not full" << endl;
            }
        }
        else if(ch==5){
            if(q.emptyy()){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "Queue is not empty" << endl;
            }
        }
        else{
            break;
        }
        cout << endl;
    }
}
