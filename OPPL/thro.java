import java.sql.SQLOutput;
import java.util.Scanner;
class ex{
    double a,b,result;
    String ss,sss;
     void division() throws ArithmeticException , NumberFormatException {
        Scanner s = new Scanner(System.in);
         System.out.print("Please enter first number : ");
         ss  = s.nextLine();
         System.out.print("Please enter second number : ");
         sss = s.nextLine();
         a =  Integer.parseInt(ss);
         b =  Integer.parseInt(sss);
        result = a/b;
         System.out.println(result);
    }
}

public class thro {
   public static void main(String args[]){
       ex objj = new ex();
       try{
           objj.division();
       }
       catch (ArithmeticException e){
           System.out.println("Division by zero is not allowed");
       }
       catch (NumberFormatException e ){
           System.out.println("Numbers should be integer");
       }
   }
}
