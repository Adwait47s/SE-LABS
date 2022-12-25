import java.io.*;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;
import java.io.File;
import java.io.*;
class file{
    int rollno,marks;
    String name, address,id;



    public int  showmenu(){
        System.out.println("MENU");
        System.out.println("1.Display records");
        System.out.println("2.Add record");
        System.out.println("3.Delete a record");
        System.out.println("4.Search a record");
        System.out.println("5.Update a record");
        System.out.println("6.Exit");
        System.out.print("Please select a choice : ");
        int ch;
        Scanner sc= new Scanner(System.in);
        ch = sc.nextInt();
        return ch;

    }
    String takerecord(){
        Scanner sc= new Scanner(System.in);
        String temp,add="";
        int tempp;
        System.out.print("Please enter your name : ");
        temp = sc.next();
        add+= temp;
        add+=" ";
        System.out.print("Please enter your id : ");
        temp = sc.next();
        add+= temp;
        add+=" ";
        System.out.print("Please enter your roll number : " );
        temp = sc.next();
        add+= temp;
        add+=" ";
        System.out.print("Please enter your marks : ");
        temp = sc.next();
        add+= temp;
        add+=" ";
        System.out.print("Please enter your address in one word : ");
        temp = sc.next();
        add+=temp;
        add+=" ";
        return add;
    }

    void addrecord(String add,String name){
        try{
            PrintWriter pw = new PrintWriter(new BufferedWriter (new FileWriter(name, true)));
            pw.println(add);
            pw.close();
        }
        catch (Exception e){
            System.out.println("Cannot write in the file");
        }
    }

    void display(String name) throws IOException {
        BufferedReader readd = new BufferedReader(new FileReader(name));
        String line="";
        while((line= readd.readLine())!=null){
            System.out.println(line);
            System.out.println("");
        }
    }

    void search(String name){
        Scanner sc= new Scanner(System.in);
        System.out.print("Please enter the roll number of a student you want search : ");
        String key = sc.next();
        Boolean flag=false;
        try{
            BufferedReader filee = new BufferedReader(new FileReader(name));
            String line="";
            while((line=filee.readLine())!=null){
                String[] linee = line.split(" ");
                if(Objects.equals(linee[2], key)){
                    flag = true;
                    System.out.println("The record is present");
                    return;
                }

            }
            if(flag ==false){
                System.out.println("Record not found! ");
            }
        }
        catch (Exception e){
            System.out.println("Unable to locate file/ unable to read the file");
        }
    }

    void delete(String name){
        Scanner sc= new Scanner(System.in);
        try{
            BufferedReader file = new BufferedReader(new FileReader(name));
            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("temp.txt")));
            String line;
            String[] linee;
            boolean flag =false;
            System.out.println("Please enter the roll number of student you want to delete");
            String key = sc.next();
            while((line=file.readLine())!=null){
                linee = line.split(" ");
                if(Objects.equals(linee[2], key)){
                    flag =true;
                }
                else{
                    pw.println(line);
                }
            }
            pw.close();
            file.close();
            if(flag){
                PrintWriter pww = new PrintWriter(new BufferedWriter(new FileWriter(name)));
                BufferedReader bf = new BufferedReader(new FileReader("temp.txt"));
                String linne="";
                while ((linne = bf.readLine())!=null){
                    pww.println(linne);
                }
                pww.close();
                bf.close();
            }
            else{
                System.out.println("The record not found!");
            }
        }
        catch (Exception e){
            System.out.println("File cannot be created");
        }
    }

};
public class Main {
    public static void main(String[] args) throws IOException {
        System.out.print("Please enter the name for the file : ");
        Scanner sc= new Scanner(System.in);
        String name= sc.next();
        name+=".txt";
        FileWriter cinn =  new FileWriter(name);
        cinn.close();
        file call = new file();
        System.out.print("Please enter the number of entries you want to enter in the file : ");
        int n;
        n = sc.nextInt();
        for (int i=0;i<n;i++){
            String add = call.takerecord();
            call.addrecord(add,name);
        }
        while(true){
            int ch =call.showmenu();
            if(ch==1){
                call.display(name);
            }
            if(ch==2){
                String add = call.takerecord();
                call.addrecord(add,name);
            }
            else if(ch==3){
                call.delete(name);
            }
            else if(ch==4){
                call.search(name);
            }
            else if(ch==6){
                System.out.println("Exiting the code...");
                break;
            }
        }

    }
}
