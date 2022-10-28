import java.util.Scanner;
import java.util.Random;
class Bank{
    int accountnumber,amount,age;
    String name,password;
    Bank(){
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        System.out.print("Please enter your name : ");
        name = sc.nextLine();
        System.out.println();
        System.out.print("Please enter your age : ");
        age = sc.nextInt();
        System.out.println();
        System.out.print("Please set a 4 digit password : ");
        password = sc.next();
        while (!valid((password))){
            System.out.print("Please enter valid 4 digit password : ");
            password = sc.next();
        }
        System.out.println();
        int x = random.nextInt(1000,9999);
        accountnumber = x;
        System.out.print("NOTE : Your bank account number is : " +x);
        System.out.println();
        System.out.println();
        amount=0;
        System.out.print("Bank account is successfully created.");
        System.out.println();
        System.out.println();
        System.out.print("Please enter the amount you want to deposit in your bank account (NOTE: Minimum amount required is 3000 Rs) : ");
        amount = sc.nextInt();
        while (!valid((amount))){
            System.out.println("Please enter the amount greater Rs 3000");
            System.out.print("Amount : ");
            amount = sc.nextInt();
        }
        System.out.println();
        System.out.println("Rs "+amount +" are added to your account");
        System.out.println();

    }
    boolean valid(String s){
        if(s.length()==4) return true;
        return false;
    }
    boolean valid(int amountt){
        if(amountt>=3000) return true;
        return false;
    }
}
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char option;
        int curr=0;
        while (true) {
            System.out.println("Please choose an option from below :");
            System.out.println("a - Create new account");
            System.out.println("b - Login to your account");
            System.out.println("c - Exit program");
            System.out.println();
            System.out.print("Your Choice [a/b/c] > ");
            option = sc.next().charAt(0);
            System.out.println();
            Bank[] arr = new Bank[100000];
            if(option=='a'){
                Bank obj = new Bank();
                arr[curr] = obj;
                curr++;
            }
            else if(option=='b'){
                System.out.println("Please choose an option from below :");
                System.out.println("a - Display Balance");
                System.out.println("b - Deposit money");
                System.out.println("c - Withdraw money");
                System.out.println("d - Exit");
                System.out.println();
                System.out.print("Your Choice [a/b/c/d] > ");
            }
            else if(option=='c'){
                System.out.println("Exiting the code...");
            }
            else{
                System.out.println("Please enter the valid choice");
            }
        }
    }
}