import java.io.*;
import java.util.Objects;
import java.util.Scanner;
import java.io.File;
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
            //cinn.write(add);
            //cinn.close();
            pw.println(add);
            pw.close();
        }
        catch (Exception e){
            System.out.println("Cannot write in the file");
        }
    }

    void display(String name){
        try{
            FileReader cout = new FileReader(name);
            int i;
            boolean fir=true;
            while ((i = cout.read()) != -1){
                if(fir){
                    fir=false;
                }
                System.out.print((char)i);
            }
            if(fir){
                System.out.println("The file is empty!!");
            }
            cout.close();
        }
        catch (Exception e){
            System.out.println("Unable to locate file/ unable to read the file");
        }
    }

    void search(String name){
        Scanner sc= new Scanner(System.in);
        System.out.print("Please enter the roll number of a student you want search : ");
        String key = sc.next();
        Boolean flag=false;
        try{
            BufferedReader readerr = new BufferedReader(new FileReader(name));
            String readd = readerr.readLine();
            if(readd==null){
                System.out.println("The file is empty!!");
                return;
            }
            String data[] = new String[0];
            while(readd!=null){
                String line[] = readd.split(" ");
                if(Objects.equals(line[2], key)){
                    flag=true;
                    data=line;
                    break;
                }
                // read next line
                readd = readerr.readLine();
            }
            if(flag){
                System.out.println("Student found!");
                System.out.println("Name : "+data[0]);
                System.out.println("Student id : "+data[1]);
                System.out.println("Roll Number : "+data[2]);
                System.out.println("Marks : "+data[3]);
                System.out.println("Address : "+data[4]);
            }
            else{
                System.out.println("Stundent not found!");
            }
        }
        catch (Exception e){
            System.out.println("Unable to locate file/ unable to read the file");
        }
    }

    void delete(String name){
        Scanner sc= new Scanner(System.in);
        try{
            FileWriter fw = new FileWriter("temp.txt");
            fw.close();
            System.out.print("Please enter the roll no you want to delete : ");
            String rn = sc.next();
            BufferedReader readerr = new BufferedReader(new FileReader(name));
            String readd = readerr.readLine();
            if(readd==null){
                System.out.println("The file is empty!!");
                return;
            }
            String data[] = new String[0];
            while(readd!=null){
                String line[] = readd.split(" ");
                if(Objects.equals(line[2], key)){
                    flag=true;
                    data=line;
                    break;
                }
                // read next line
                readd = readerr.readLine();
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