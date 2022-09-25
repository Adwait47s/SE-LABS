
import java.util.Scanner;



public class Complex_op{
    public static void main(String[] args){
        class complex_op{
            float real,imaginary;
            complex_op(float C1,float C2){
                this.real = C1;
                this.imaginary =C2;
            }
            private void prefection(float a, float b) {
                if(a>0&&b>0){
                    System.out.println(a+" "+"+"+b+"i");
                }
                else if(a>0&&b<0){
                    System.out.println(a+" "+b+"i");
                }
                else if(a<0&&b<0){
                    System.out.println(a+" "+b+"i");
                }
                else if(a==0&&b!=0){
                    System.out.println(b+"i");
                }
                else if(b==0){
                    System.out.println(a);
                }
                else{
                    System.out.println(a+" "+"+"+b+"i");
                }
            }

            void addition(complex_op C1, complex_op C2){
                float reall,imainaryy;
                reall = C1.real + C2.real;
                imainaryy = C1.imaginary + C2.imaginary;
                System.out.print("The first complex number is ");
                prefection(C1.real,C1.imaginary);
                System.out.print("The second complex number is ");
                prefection(C2.real,C2.imaginary);
                System.out.print("The addition of given complex numbers is ");
                prefection(reall,imainaryy);
                for(int i=0;i<=51;i++){
                    System.out.print("_");
                }
                System.out.println("_");
            }



            void sub(complex_op C1, complex_op C2){
                float reall,imaginaryy;
                reall = C1.real -C2.real;
                imaginaryy = C1.imaginary - C2.imaginary;
                System.out.print("The first complex number is ");
                prefection(C1.real,C1.imaginary);
                System.out.print("The second complex number is ");
                prefection(C2.real,C2.imaginary);
                System.out.print("The subtraction of given complex numbers is ");
                prefection(reall,imaginaryy);
                for(int i=0;i<=51;i++){
                    System.out.print("_");
                }
                System.out.println("_");
            }
            void multiplication(complex_op C1, complex_op C2){
                float reall,imaginary;
                reall = C1.real*C2.real - C1.imaginary* C2.imaginary;
                imaginary = C1.real*C2.imaginary + C1.imaginary*C2.real;
                System.out.print("The first complex number is ");
                prefection(C1.real,C1.imaginary);
                System.out.print("The second complex number is ");
                prefection(C2.real,C2.imaginary);
                System.out.print("The multiplication of given complex numbers is ");
                prefection(reall,imaginary);
                for(int i=0;i<=51;i++){
                    System.out.print("_");
                }
                System.out.println("_");
            }
            void division(complex_op C1, complex_op C2){
                float reall,imaginary;
                reall = (C1.real*C2.real + C1.imaginary*C2.imaginary)/ (C2.real*C2.real + C2.imaginary*C2.imaginary);
                imaginary = (C1.real*(-C2.imaginary) + -C2.imaginary*(C1.real))/(C2.real*C2.real + C2.imaginary*C2.imaginary);
                System.out.print("The first complex number is ");
                prefection(C1.real,C1.imaginary);
                System.out.print("The second complex number is ");
                prefection(C2.real,C2.imaginary);
                System.out.print("The division of given complex numbers is ");
                prefection(reall,imaginary);
                for(int i=0;i<=51;i++){
                    System.out.print("_");
                }
                System.out.println("_");
            }


        }
        Scanner S = new Scanner(System.in);
        System.out.print("Please enter real part of first complex number ");
        float a,b,c,d;
        a = S.nextFloat();
        System.out.print("Please enter imaginary part of first complex number ");
        b =S.nextFloat();
        complex_op C1=  new complex_op(a,b);
        System.out.print("Please enter real part of second complex number ");
        c =S.nextFloat();
        System.out.print("Please enter imaginary part of second complex number ");
        d =S.nextFloat();
        complex_op C2 = new complex_op(c,d);
        for(int i=0;i<=51;i++){
            System.out.print("_");
        }
        System.out.println("_");
        int choice;
        while(true){
            System.out.println("Please select the operation");
            System.out.println("1.Addition");
            System.out.println("2.Subtraction");
            System.out.println("3.Multiplication");
            System.out.println("4.Division");
            System.out.println("5.Change input");
            System.out.println("6.Exit");
            choice = S.nextInt();
            int flag =0;
            switch (choice){
                case 1:
                    C1.addition(C1,C2);
                    break;
                case 2:
                    C1.sub(C1,C2);
                    break;
                case 3:
                    C1.multiplication(C1,C2);
                    break;
                case 4:
                    C1.division(C1,C2);
                    break;
                case 5:
                    System.out.print("Please enter real part of first complex number ");
                    a = S.nextFloat();
                    System.out.print("Please enter imaginary part of first complex number ");
                    b =S.nextFloat();
                    complex_op C3=  new complex_op(a,b);
                    C1=C3;
                    System.out.print("Please enter real part of second complex number ");
                    c =S.nextFloat();
                    System.out.print("Please enter imaginary part of second complex number ");
                    d =S.nextFloat();
                    complex_op C4 = new complex_op(c,d);
                    C2=C4;
                    flag=1;

            }
            if(choice==6){
                break;
            }
        }

    }
}
