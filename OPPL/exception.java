import javax.lang.model.type.NullType;
import java.util.Scanner;
class eexception{
    int[] arr = {1,2,3};
    int a = 50;
    String s ;
    void arrexception(){
        try{
            arr[3] = 40;
        }
        catch (Exception ArrayOutOfBox ){
            System.out.println("Not Possible to access the given index of array ");
        }
    }
    void arithmatic(){
        try{
            int c = a/0;
        }
        catch (Exception Arithmatic){
            System.out.println("Not possible to divide by zero");
        }
    }
    void numberf(){
        s = "123Adwait";
        try{
            a = Integer.parseInt(s);
        }
        catch(Exception NumberFormat){
            System.out.println("Not possible to convert this string to int");
        }
  }
  void nullp(){
        String s =null;
        try{
            System.out.println(s.length());
        }
        catch (Exception NullPointer){
            System.out.println("Not possible to print null value");
        }
  }
}
public class exception{
    public static void main(String args[]){
        eexception obj = new eexception();
        obj.arrexception();
        obj.arithmatic();
        obj.numberf();
        obj.nullp();
        String ss,sss;
        Scanner s = new Scanner(System.in);
        System.out.println("Please enter first number : ");
        ss = s.nextLine();
        System.out.println("Please enter second number : ");
        sss = s.nextLine();
        int a,b,result;
        try{
             a =  Integer.parseInt(ss);
             b =  Integer.parseInt(sss);
             try{
                 result = a/b;
                 System.out.println("Division is : "+result);
             }
             catch (Exception Arithmatic){
                 System.out.println("Division by zero is not allowed");
             }
        }
        catch(Exception NumberFormatException ){
            System.out.println("Please enter integer value");
        }
    }
}
