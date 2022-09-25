import java.util.Scanner;
abstract class shape{
    double a,b;
    abstract void compute_area();
}
class triangle extends shape{
    Scanner sc =new Scanner(System.in);
    void compute_area(){
        System.out.println("Please enter base of the triangle");
        a = sc.nextInt();
        System.out.println("Please enter height of the triangle");
        b= sc.nextInt();
        double ans = 0.5*a*b;
        System.out.println("Area of the tringle is "+ans);
    }
}
class rectangle extends shape{
    Scanner sc =new Scanner(System.in);
    void compute_area(){
        System.out.println("Please enter one side of the rectangle");
        a = sc.nextInt();
        System.out.println("Please enter other side of the rectangle");
        b= sc.nextInt();
        double ans = a*b;
        System.out.println("Area of the rectangle is "+ans);
    }
}
public class Shape{
    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);
        while(true){
            int ch;
            System.out.println("Please select the choice");
            System.out.println("1.Compute area of rectangle ");
            System.out.println("2.Compute area of triangle ");
            System.out.println("3.Exit");
            ch = sc.nextInt();
            if(ch==1){
                shape s = new rectangle();
                s.compute_area();
                System.out.println();
            }
            else if(ch==2){
                shape ss = new triangle();
                ss.compute_area();
                System.out.println();
            }
            else{
                break;
            }
        }

    }
}
