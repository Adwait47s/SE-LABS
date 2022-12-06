import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

class Bank{
    double money;
    String  password,name,phonenumber;
    int age,accountid;
    static ArrayList<Bank> accounts = new ArrayList<Bank>();
    boolean ispositive(int a){
        if(a<0) return false;
        return  true;
    }

    boolean ispositive(double a){
        if(a<0) return false;
        return true;
    }
    boolean agev(int a){
        if(a<=100&&a>=0){
            return true;
        }
        else{
            return false;
        }

    }
    boolean phonev(String s){
        if(s.length()!=10){
            return false;
        }
        else{
            return true;
        }
    }
    void createaccount(int id){

        Scanner sc = new Scanner(System.in);
        Bank obj = new Bank();

        System.out.print("Please enter your name : ");
        obj.name = sc.next();

        System.out.print("Please enter your age : ");
        obj.age = sc.nextInt();
        while(!agev(obj.age)){
            System.out.print("Please enter valid age :");
            obj.age = sc.nextInt();
        }

        System.out.print("Please enter your mobile number : ");
        obj.phonenumber = sc.next();
        while (!phonev(obj.phonenumber)){
            System.out.print("Please enter a valid mobile number : ");
            obj.phonenumber =sc.next();
        }

        System.out.print("Please enter the password for your account : ");
        obj.password =sc.next();

        System.out.println("PLEASE NOTE THAT YOUR BANK ACCOUNT ID IS " + id);
        obj.accountid= id;
        System.out.println();

        System.out.println("Please enter the starting amount in the bank account (Minimum balance required : Rs.3000)");
        obj.money= sc.nextDouble();
        while(obj.money<3000){
            System.out.println("Minimum balance required is Rs.3000");
            obj.money= sc.nextDouble();
        }

        accounts.add(obj);

        System.out.println("YOUR BANK ACCOUNT IS SUCCESSFULLY CREATED !");
        System.out.println();
    }

    Bank FindInDatabase(){
        Bank obj =null;
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter your account id : ");
        int idd = 0;
        try{
            String  iddd = sc.next();
            idd = Integer.parseInt(iddd);
        }
        catch (NumberFormatException e){
            System.out.println("Please enter a valid account id !");
        }
        boolean found =false;
        for (int i=0;i<accounts.size();i++){
            if(accounts.get(i).accountid == idd){
                obj = accounts.get(i);
                found=true;
            }
        }
        if(found){
            System.out.println("Please enter correct account password : ");
            String pass = sc.next();
            while (!Objects.equals(pass, obj.password)){
                System.out.println("Please enter correct password : ");
                pass = sc.next();
            }
            return obj;
        }
        return null;
    }
    void DisplayDetails(){
        Bank obj = FindInDatabase();
        if(obj==null){
            System.out.println("Bank account not found in the database !");
        }
        else{
            System.out.println("Accounts Details");
            System.out.println("Name : " +obj.name );
            System.out.println("Age : " + obj.age);
            System.out.println("Mobile Number : " + obj.phonenumber);
            System.out.println("Balance : " + obj.money);
        }
    }
    void depositemoney(){
        Bank obj = FindInDatabase();
        if(obj==null){
            System.out.println("Bank account not found in the database !");
        }
        else{
            Scanner sc = new Scanner(System.in);
            int deposite;
            System.out.print("Please enter the amount you want to deposit : ");
            deposite = sc.nextInt();
            if(ispositive(deposite)){
                obj.money += deposite;
                System.out.println();
                System.out.println("Your money is deposited in your bank account !");
                System.out.println();
                System.out.println("Your total balance is Rs." +obj.money);
                System.out.println();
            }
            else{
                System.out.println("Please enter the valid amount of money !");
            }
        }
    }

    void checkbalance(){
        Bank obj = FindInDatabase();
        if(obj==null){
            System.out.println("Bank account not found in the database ! ");
        }
        else{
            System.out.println("Your Balance is " +obj.money);
        }
    }

    void withdrawmoney(){

        Bank obj = FindInDatabase();
        if(obj==null){
            System.out.println("Bank account not found in the database ! ");
        }
        else{
            double amount;
            Scanner sc = new Scanner(System.in);
            System.out.print("Please enter the amount you want to withdraw : ");
            amount  = sc.nextInt();
            if(ispositive(amount)){
                if(obj.money - amount <3000){
                    double canspend = obj.money-3000;
                    System.out.println("Minimum balance required is Rs.3000, you can only withdraw upto Rs."+ canspend);
                }
                else{
                    obj.money -= amount;
                    System.out.println("The amount "+amount+" is deducted from your bank account! ");
                    System.out.println();
                    System.out.println("Total Balance : " + obj.money);
                    System.out.println();
                }
            }
            else{
                System.out.println("Please enter a valid amount !");
            }
        }
    }
    
    void updateaccount(){
        Bank obj = FindInDatabase();
        if(obj==null){
            System.out.println("Account not found in the database !");
        }
        else{
            Scanner sc = new Scanner(System.in);

            System.out.print("Please enter your updated mobile number : ");
            obj.phonenumber = sc.next();
            while (!phonev(obj.phonenumber)){
                System.out.print("Please enter a valid mobile number : ");
                obj.phonenumber =sc.next();
            }

            System.out.print("Please enter new password for your account : ");
            obj.password =sc.next();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int currid = 1051;
        while(true){
            System.out.println("MENU");
            System.out.println("1.Create a new account");
            System.out.println("2.Deposit money");
            System.out.println("3.Withdraw money");
            System.out.println("4.Check Balance");
            System.out.println("5.Display account information");
            System.out.println("6.Update account information");
            System.out.println("7.Break");
            System.out.print("Please select a choice : ");
            Scanner sc = new Scanner(System.in);
            Bank call = new Bank();
            int choice =  sc.nextInt();
            if(choice==1){
                call.createaccount(currid);
                currid--;
            }
            else if(choice==2){
                call.depositemoney();
            }
            else if(choice==3){
                call.withdrawmoney();
            }
            else if(choice==4){
                call.checkbalance();
            }
            else if(choice==5){
                call.DisplayDetails();
            }
            else if(choice==6){
                call.updateaccount();
            }
            else if(choice==7){
                System.out.println("Exiting the code...");
                break;
            }
            else{
                System.out.println("Please enter the correct choice !");
            }
        }

    }
}