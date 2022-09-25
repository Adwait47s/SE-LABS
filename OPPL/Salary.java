import java.util.Scanner;
class employee{
  
    int empid;
    String empname,addr,mobileno,email;
    double bp,salary,da,hra,pf,club,gross,net;
  
    employee(){
        empid =0;
        empname = " ";
        addr = " ";
        mobileno = " ";
        email = " ";
    }
  
    void getdata(employee e, int i,employee ee[]){
        e.getid(e,i,ee);
        System.out.println("Please enter your mobile number");
        boolean flag ;
        flag =e.getmobilen(e);
        while(flag==false){
            System.out.println("Please enter valid mobile number");
            flag = e.getmobilen(e);
        }
        e.getrest(e);
    }
  
    boolean getmobilen(employee e){
        Scanner s = new Scanner(System.in);

        String number = s.nextLine();
        if(number.length()!=10){
            return  false;
        }
        else{
            e.mobileno = number;
            return true;
        }
    }

    void getid(employee e,int i,employee ee[]){
        Scanner S = new Scanner(System.in);
        System.out.println("Please enter your employee id");
        int id;
        boolean flagg = false;
        id  = S.nextInt();
        while(!flagg){
            flagg =true;
            for(int ii=0;ii<i;ii++){
                if(ee[ii].empid==id){
                    flagg = false;
                    break;
                }
            }
            if(!flagg){
                System.out.println("Please enter unique employee id");
                id  = S.nextInt();
            }
        }
        e.empid = id;
    }
  
    boolean emailc(String s){
        int id = s.indexOf('@');
        if(id!=-1)return true;
        return false;
    }
  
    void getrest(employee e){
        Scanner s = new Scanner(System.in);
        System.out.println("Please enter your name");
        String name = s.nextLine();
        e.empname = name;
        System.out.println("Please enter your address");
        String ss = s.nextLine();
        e.addr = ss;
        System.out.println("Please enter your email id");
        boolean flag =false;
        String sss = s.nextLine();
        flag = emailc(sss);
        while (!flag){
            System.out.println("Please enter valid email address");
            sss = s.nextLine();
            flag = emailc(sss);
        }
        e.email = sss;
    }
  
    void display(employee e){
        System.out.println("The name of the employee  : "+ e.empname);
        System.out.println("Employee id               : " + e.empid);
        System.out.println("Employee Moblie Number    : "+ e.mobileno);
        System.out.println("Employee email id         : " + e.email);
        System.out.println("Employee Address          : " +e.addr);

    }
  
    void salarycal(){
        Scanner p = new Scanner(System.in);
        System.out.print("BASIC PAY:");
        this.bp=p.nextDouble();
        da=(97*bp)/100;
        hra=(10*bp)/100;
        pf=(12*bp)/100;
        club=(bp)/1000;
        gross=bp+hra;
        net=gross-pf-club;
    }
  
    void displaysal(){
        System.out.println("Gross salary = "+gross);
        System.out.println("Net salary = "+net);
        System.out.println();
    }
};

class Programmer extends employee{
    Programmer(employee e,int i,employee ee[]){
        e.getdata(e,i,ee);
        e.salarycal();
        e.display(e);
        System.out.println("Employee type: Programmer");
        System.out.println("===========================================================================");
        e.displaysal();
        System.out.println("===========================================================================");
    }
};

class Project_Manager extends employee{
    Project_Manager(employee e,int i,employee[]ee){
        e.getdata(e,i,ee);
        e.salarycal();
        e.display(e);
        System.out.println("Employee type: Project Manager");
        System.out.println("===========================================================================");
        e.displaysal();
        System.out.println("===========================================================================");
    }
};

class Team_lead extends employee{
    Team_lead(employee e,int i,employee ee[]){
        e.getdata(e,i,ee);
        e.salarycal();
        e.display(e);
        System.out.println("Employee type: Team lead");
        System.out.println("===========================================================================");
        e.displaysal();
        System.out.println("===========================================================================");
    }
};

class Assistant_Manager extends employee{
    Assistant_Manager(employee e,int i,employee []ee){
        e.getdata(e,i,ee);
        e.salarycal();
        e.display(e);
        System.out.println("Employee type: Assistant Manager");
        System.out.println("===========================================================================");
        e.displaysal();
        System.out.println("===========================================================================");
    }
};

public class Salary{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Please enter number of employees");
        int n = s.nextInt();
        employee e[] = new employee[n];
        int arr[]; arr = new int[n];
        for(int i=0;i<n;i++){
            System.out.println("MENU\n1.Programmer\n2.Team Lead\n3.Assistant Manager\n4.Project Manager\n5.Exit");
            System.out.print("Select your choice:");
            int k = s.nextInt();
            if(k==1){
                e[i] = new employee();
                Programmer pr = new Programmer(e[i],i,e);

            }
            else if(k==2){
                e[i] = new employee();
                Team_lead t = new Team_lead(e[i],i,e);
            }
            else if(k==3){
                e[i] = new employee();
                Assistant_Manager am = new Assistant_Manager(e[i],i,e);
            }
            else if(k==4){
                e[i] = new employee();
                Project_Manager pm = new Project_Manager(e[i],i,e);
            }
            else{
                System.out.println("Please make a valid choice");
            }
        }
    }
};
