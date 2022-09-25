import java.util.Scanner;

class Publication{
    String title;
    int price,copies;
    int salecopy(int p,int c){
        return p*c;
    }
}

class book extends Publication{
    String author;
    Scanner s = new Scanner(System.in);
    void ordercopies(){
        System.out.println("Please enter the title of the book ");
        title = s.nextLine();
        System.out.println("Please enter the author of the book");
        author = s.nextLine();
        System.out.println("Please enter the price of the book");
        price = s.nextInt();
        System.out.println("Please enter total copies of book");
        copies = s.nextInt();
        System.out.println("The total sale from "+title+" is "+salecopy(price,copies));
        System.out.println("===============================================================================");
    }
}

class Magzine extends Publication{
    Scanner s = new Scanner(System.in);
    void receiveissue(){
        System.out.println("Please enter the price of the Magzine");
        price = s.nextInt();
        System.out.println("Please enter total copies of Magzine");
        copies = s.nextInt();
        System.out.println("The total sale from the Magzine is "+salecopy(price,copies));
        System.out.println("===============================================================================");
    }
}

public class publication{
    public static void main(String[] args){
        book b = new book();
        b.ordercopies();
        Magzine m = new Magzine();
        m.receiveissue();
        int salee = b.salecopy(b.price,b.copies);
        salee = salee + m.salecopy(m.price,m.copies);
        System.out.println("The total sale of the publication is " + salee);
        System.out.println("===============================================================================");
    }
}
