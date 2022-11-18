import java.util.Scanner;
abstract class car{
    abstract void construct();
}

class Hatchback extends car{
    @Override
    void construct() {
        System.out.println("Getting the design..");
        System.out.println("Collecting all parts..");
        System.out.println("Construction in progress..");
        System.out.println("Hatchback car is constructed !");
    }
}
class  Sedan extends car{
    @Override
    void construct() {
        System.out.println("Getting the design..");
        System.out.println("Collecting all parts..");
        System.out.println("Construction in progress..");
        System.out.println("Sedan car is constructed !");
    }
}
class SUV extends car{
    @Override
    void construct() {
        System.out.println("Getting the design..");
        System.out.println("Collecting all parts..");
        System.out.println("Construction in progress..");
        System.out.println("SUV car is constructed !");
    }
}

class factory{
    public static car builder(String name){
        car carr = null;
        if(name == "Hatchback"){
            carr = new Hatchback();
        }
        else if(name == "SUV"){
            carr = new SUV();
        }
        else if(name == "Sedan"){
            carr = new Sedan();
        }
        return carr;
    }
}
public class testfactory {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("MENU");
        System.out.println("1.Hatchback");
        System.out.println("2.SUV");
        System.out.println("3.Sedan");
        System.out.print("Please select a choice : ");
        int ch;
        ch = sc.nextInt();
        car carr = null;
        if(ch==1){
            carr = factory.builder("Hatchback");
        }
        else if(ch==2){
            carr = factory.builder("SUV");
        }
        else if(ch==3){
            carr = factory.builder("Sedan");
        }
        else{
            System.out.println("Please enter the valid choice");
        }
        carr.construct();
    }
}