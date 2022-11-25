package shoppingcart;
import java.util.Scanner;
public class creditcard implements payment {
    String name,cardno,cvv,expirydate;
    @Override
    public void pay(int cost) {
        System.out.println("Your payment of Rs "+cost + " is successful!");
    }
    creditcard(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter your name : ");
        name = sc.next();
        System.out.print("Please enter your cardno : ");
        cardno = sc.next();
        System.out.print("Please enter your cvv : ");
        cvv = sc.next();
        System.out.print("Please enter the expiry date of the card : ");
        expirydate = sc.next();

    }
}
