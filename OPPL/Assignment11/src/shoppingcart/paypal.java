package shoppingcart;
import java.util.Scanner;
public class paypal implements payment{
    String email,password;
    @Override
    public void pay(int cost) {
        System.out.println("Your payment of Rs "+cost + " is successful!");
    }
    paypal(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter your email id : ");
        email = sc.next();
        System.out.print("Please enter your password : ");
        password = sc.next();
    }
}
