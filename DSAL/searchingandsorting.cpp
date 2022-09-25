/* 
Problem statement:-
Consider a student database of SEIT class (at least 15 records). Database contains different fields
of every student like Roll No, Name and SGPA. (array of structure)
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
   (Use Bubble Sort)
b. Arrange list of students alphabetically. (Use Insertion sort)
c. Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d. Search students according to SGPA. If more than one student having same SGPA,
   then print list of all students having same SGPA.
e. Search a particular student according to name using binary search without recursion.
   (All the student records having the presence of search key should be displayed)
   (Note: Implement either Bubble sort or Insertion Sort.)*/

#include <iostream>
#include <iomanip>
using namespace std;

class seit {                                               // Declaring a class

private:
    int rollno;
    string name;
    float sgpa;

public:

    void getdata(int n, class seit s[])                    // To take the input from the user
    {
        for (int i = 0; i < n; i++){
    bool flag =0; int temp; 
    cout << "Please enter your roll no ";                  // To take input of roll no
    while(!flag){
        cin>>temp;
        flag= checkr(s,temp,i);                            // To check is input roll no is unique and valid
        if(!flag){
            cout << "Please enter valid and unique roll No" << endl;
        }
    }
    s[i].rollno = temp ;

    cout << "Please enter your full name ";                // To take input of name
    cin>>s[i].name;

    cout << "Please enter you sgpa ";                      // To take input of sgpa
    float tempp;
    
    flag =0;
    while(!flag){
        cin>>tempp;
        flag = checks(tempp);                             // To check validity of sgpa
        if(!flag){
            cout << "Please enter valid sgpa" << endl;
        }
    }
    s[i].sgpa = tempp;
}
}

void qs(class seit s[],int low,int high){                 // Quick sort function
    int piv = low;
    int si = low,ei = high;
    low = low+1;
    bool flagl =0,flagh=0;
    while(low<=high){                               
        if(s[low].sgpa>s[piv].sgpa&&!flagl){

            flagl=1;
        }
        else if(!flagl){
            low++;
        }
        if(s[high].sgpa<s[piv].sgpa&&!flagh){

            flagh=1;
        }
        else if(!flagh){
            high--;
        }
        if(flagl&&flagh){
            swap(s[high],s[low]);
            flagl=0,flagh=0;
        }
    }
    swap(s[piv],s[high]);                                 // Swapping of pivot to its correct position
    if(si<=high-1){
        qs(s,si,high-1);
    }
    if(high+1<=ei){
        qs(s,high+1,ei);
    }
}

void displaydata(class seit s[],int n){                   // Dislay data
    cout  << left << setw(20)<< "Name" <<left <<  setw(20) << "Roll No" <<left<< setw(20) << "sgpa" << endl;
    for(int i=0;i<n;i++){
        cout << setw(20) << s[i].name << setw(20) << s[i].rollno << setw(20) << s[i].sgpa << endl;
    }
}

int checktillsorted(class seit s[],int n){                // Funtion to check till what index roll numbers are already sorted
	bool flag =1; int index,tillnow;
	for(int i=0;i<n-1;i++){
        if(s[i].rollno>s[i+1].rollno){
            index = i;
            tillnow = s[i].rollno;
            flag =0;
            break;
        }
    }
    if(flag) return n-1;                                 // If data is already sorted then it will return from here itself without executing an entire program
    for(int i=index+1;i<n;i++){
        if(s[i].rollno<tillnow){
            for(int j = index;j>=0;j--){
                if(s[i].rollno>=s[j].rollno){
                    index =j;
                    tillnow = s[j].rollno;
                    break;
                }
            }
        }
        if(index==0){
            break;
        }
    }
    return index;                                       // It will return an index till the data is sorted
}
int checktillsortedname(class seit s[],int n){          // To check till what index data is sorted(names)
	bool flag =1; int index; string tillnow;
	for(int i=0;i<n-1;i++){
        if(s[i].name>s[i+1].name){
            index = i;
            tillnow = s[i].name;
            flag =0;
            break;
        }
    }
    if(flag) return n-1;                                // If data is already sorted then it will return from here itself without executing an entire program
    for(int i=index+1;i<n;i++){
        if(s[i].name<tillnow){
            for(int j = index;j>=0;j--){
                if(s[i].name>=s[j].name){
                    index =j;
                    tillnow = s[j].name;
                    break;
                }
            }
        }
        if(index==0){
            break;
        }
    }
    return index;                                       // It will return an index till the data is sorted
}

int checktillsortedsgpa(class seit s[],int n){          // To check till what index data is sorted (sgpa)
	bool flag =1; int index; float tillnow;
	for(int i=0;i<n-1;i++){
        if(s[i].sgpa>s[i+1].sgpa){
            index = i;
            tillnow = s[i].sgpa;
            flag =0;
            break;
        }
    }
    if(flag) return n-1;                                // If data is already sorted then it will return from here itself without executing an entire program
    for(int i=index+1;i<n;i++){
        if(s[i].sgpa<tillnow){
            for(int j = index;j>=0;j--){
                if(s[i].sgpa>=s[j].sgpa){
                    index =j;
                    tillnow = s[j].sgpa;
                    break;
                }
            }
        }
        if(index==0){
            break;
        }
    }
    return index;                                        // It will return an index till the data is sorted
}

void sortrollnumberbubblesort(class seit s[],int n){    // Bubble sort for roll numbers
    int index = checktillsorted(s,n);
    if(index==n-1){
        cout << "Data is already sorted!" << endl;
        return;
    }
    cout << "Data is sorted till index " <<index+1  << endl;
    if(index==0){
    	index--;
    }
  for(int i=index+1;i<n-1;i++){                        // For loop for total number of passes
    for(int j=index+1;j<n-1;j++){                      // For loop for compairing each element in an array of struct
        if(s[j].rollno>s[j+1].rollno){

            int temp = s[j].rollno;                    // Swapping roll numbers
            s[j].rollno = s[j+1].rollno; 
            s[j+1].rollno = temp;

            string temps = s[j].name;                  // Swapping names
            s[j].name = s[j+1].name;
            s[j+1].name = temps;

            float tempspga = s[j].sgpa;                // Swapping sgpas
            s[j].sgpa = s[j+1].sgpa;
            s[j+1].sgpa = tempspga;
            
        }
    }
}
}

void findsgpa(class seit s[],int n){                          // Linear search for finding sgpa
    float element;                                            // Taking input sgpa to find it in database
    cout << "Please enter sgpa you want to search " << endl;
    cin>>element;

    bool flag=0;
    for (int i = 0; i < n; i++)
    {
    /* code */
        if(element==s[i].sgpa){
            cout  << "sgpa :"<< " " << s[i].sgpa << " " << "Name:"<< " "<< s[i].name << " " << "Roll no:"<<" " << s[i].rollno << endl;
            flag =1;
        }
    }
    if(!flag){
        cout << "sgpa not found" << endl;
    }
    cout << endl;
}

void findnamebinarysearch(class seit s[],int n){             // Sorting data before Binary search by bubble sort
	int index = checktillsortedname(s,n);
  for(int i=index+1;i<n-1;i++){                              // For loop for total number of passes
    for(int j=index+1;j<n-1;j++){                            // For loop for compairing each element in an array of struct
        if(s[j].name>s[j+1].name){

            int temp = s[j].rollno;                          // Swapping roll numbers
            s[j].rollno = s[j+1].rollno;
            s[j+1].rollno = temp;

            string temps = s[j].name;                        // Swapping names
            s[j].name = s[j+1].name;
            s[j+1].name = temps;

            float tempspga = s[j].sgpa;                      // Swapping sgpas
            s[j].sgpa = s[j+1].sgpa; 
            s[j+1].sgpa = tempspga;
            
        }
    }
}
int low = 0,high = n-1,mid;                                 // Binary Search
bool flagg =0;
string namee;
cout << "Please enter name you want to search: ";
cin>>namee;
while(high>=low){
    mid = (high+low)/2;
    if(namee==s[mid].name){
        flagg =1;
        break;
    }
    else if(namee>s[mid].name){
        low = mid+1;
    }
    else{
        high = mid-1;
    }
}
if(flagg){
    cout << "Name:" << s[mid].name << " " << "Roll no:" << " " << s[mid].rollno << " " << "sgpa: "<< s[mid].sgpa << endl;
}
else{
    cout << "Name not found" << endl;
}
cout << endl;
}

void sortnameinsertionsort(class seit s[],int n){               // Insertion sort function
	int index = checktillsortedname(s,n);
	if(index==n-1){
		cout << "Data is already sorted!" << endl;
		return;
	}
	cout << "Data is sorted till index " << index+1 << endl; 
	if(index==0){
		index= -1;
	}
    for(int i=index+2;i<n;i++){
        if(s[i].name<s[i-1].name){
            int j = i;
            while(s[j].name<s[j-1].name&&j>0){
                swap(s[j],s[j-1]);
                j--;
                if(j==0){
                	break;
                }
            }
        }
    }
}

void toppers10quicksort(class seit s[],int n){                   // Quick sort function
	int index = checktillsortedsgpa(s,n);
	if(index!=n-1){
		if(index==1){
			index =-1;
		}
		qs(s,index+1,n-1);
	}
    cout  << left << setw(20)<< "Name" <<left <<  setw(20) << "Roll No" <<left<< setw(20) << "sgpa" << endl;
    for(int i= n-1;i>=max(0,n-10);i--){
        cout << setw(20) << s[i].name << setw(20) << s[i].rollno << setw(20) << s[i].sgpa << endl;
    }
}

bool checkr(class seit s[],int a,int i){                         // Function for checking unique and valid roll no
    if(a<=0) return 0;
    for (int ii = 0; ii < i; ii++)
    {
        /* code */
        if(a==s[ii].rollno) return 0;
    }
    return 1;
}
bool checks(float a){                                           // Function for checking validity of sgpa
    if(a>=0&&a<=10) return 1;
    return 0;
}
};

int main(){
cout << "Please enter total number of students " << endl;      // To take total number of students as input
int n;
cin>>n;
seit s[n];
s[0].getdata(n,s);
while(1){
    cout << "Please enter your choice" << endl;
    cout << "1.Display Data" << endl;
    cout << "2.Sorting according to Roll numbers (Bubble sort)" << endl;
    cout << "3.Sorting according to Names in alphabetical order (Insertion sort)" << endl;
    cout << "4.Display first 10 Toppers (Quick Sort)" << endl;
    cout << "5.Search student according to sgpa (Linear Search)" << endl;
    cout << "6.Search student according to Name (Binary Search)" << endl;
    cout << "7.Exit" << endl;
    int nn; cin>>nn;                                 // Taking choice as a input to perform an operation
    cout << endl;
    if(nn==1){
        s[0].displaydata(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==2){
        s[0].sortrollnumberbubblesort(s,n);
        s[0].displaydata(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==3){
        s[0].sortnameinsertionsort(s,n);
        s[0].displaydata(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==4){
        s[0].toppers10quicksort(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==5){
        s[0].findsgpa(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==6){
        s[0].findnamebinarysearch(s,n);
        cout << endl;
        cout << "======================================================" << endl;
        cout << endl;
    }
    else if(nn==7){
        break;
    }
    else{
    	cout << "Please enter a valid choice" << endl;
    }
}
}
