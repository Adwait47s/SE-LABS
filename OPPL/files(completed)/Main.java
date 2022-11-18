import java.io.*;
import java.util.*;
import java.io.File;
import java.util.Scanner;
public class Main{
    public float marks;
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    public void addRecords(String namee) throws IOException{
        PrintWriter pw=new PrintWriter(new BufferedWriter(new FileWriter(namee,true)));
        String studentname,address;
        int rollno,div;
        boolean addMore;
        String s;
        do{
            System.out.println("Enter Student's Name : ");
            studentname=br.readLine();
            System.out.println("Enter Student's Roll No : ");
            rollno=Integer.parseInt(br.readLine());
            System.out.println("Enter Student's Address : ");
            address=br.readLine();
            System.out.println("Enter Student's Division : ");
            div=Integer.parseInt(br.readLine());
            System.out.println("Enter Student's Marks : ");
            marks=Float.parseFloat(br.readLine());
            pw.println(studentname+" "+rollno+" "+address+" "+div+" "+marks);
            System.out.println("Records Added Successfully !\nDo you want to add more records ? (y/n)");
            s=br.readLine();
            if(s.equalsIgnoreCase("y")){
                addMore=true;
                System.out.println();
            }
            else
                addMore=false;
        }
        while(addMore);
        pw.close();
        showMenu(namee);
    }
    public void readRecords(String namee) throws IOException{
        try{
            BufferedReader file=new BufferedReader(new FileReader(namee));
            String name;
            int i=1;
            while((name=file.readLine())!=null){
                System.out.println(name);
                System.out.println("");
            }
            file.close();
            showMenu(namee);
        }
        catch(FileNotFoundException e){
            System.out.println("ERROR : File Not Found !");
        }
    }
    public void searchRecords(String namee) throws IOException{
        try{
            BufferedReader file=new BufferedReader(new FileReader(namee));
            String name;
            int flag=0;
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter Student's Roll No to search : ");
            String searchroll=sc.next();
            while((name=file.readLine())!=null){
                String[] line=name.split(" ");
                if(searchroll.equalsIgnoreCase(line[1])){
                    System.out.println("Record Found !");
                    System.out.println(name);
                    System.out.println("");
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                System.out.println("Record Not Found !");
            file.close();
            showMenu(namee);
        }
        catch(FileNotFoundException e){
            System.out.println("ERROR : File Not Found !");
        }
    }
    public void deleteRecords(String namee) throws IOException{
        try{
            BufferedReader file1=new BufferedReader(new FileReader(namee));
            PrintWriter pw=new PrintWriter(new BufferedWriter(new FileWriter("temp.txt",true)));
            String name;
            int flag=0;
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter Student's Roll no to delete : ");
            String searchname=sc.next();
            while((name=file1.readLine())!=null){
                String[] line=name.split(" ");
                if(!searchname.equalsIgnoreCase(line[2])){
                    pw.println(name);
                    flag=0;
                }
                else{
                    System.out.println("Record Found !");
                    flag=1;
                }
            }
            file1.close();
            pw.close();
            File delName=new File(namee);
            File oldName=new File("temp.txt");
            File newName=new File(namee);
            if(delName.delete())
                System.out.println("Record Deleted Successfully !");
            else
                System.out.println("Error !");
            if(oldName.renameTo(newName));
            else
                System.out.println("Error !");
            showMenu(namee);
        }
        catch(FileNotFoundException e){
            System.out.println("ERROR : File Not Found !");
        }
    }
    public void updateRecords(String namee) throws IOException{
        try{
            BufferedReader file1=new BufferedReader(new FileReader(namee));
            PrintWriter pw=new PrintWriter(new BufferedWriter(new FileWriter("temp.txt",true)));
            String name;
            int flag=0;
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter Student's Roll number to update : ");
            String searchname=sc.next();
            while((name=file1.readLine())!=null){
                String[] line=name.split(" ");
                if(!searchname.equalsIgnoreCase(line[2])){
                    pw.println(name);
                    flag=0;
                }
                else{
                    System.out.println("Record Found !");
                    System.out.print("Enter Updated Marks : ");
                    marks=Float.parseFloat(br.readLine());
                    pw.println(line[0]+" "+line[1]+" "+line[2]+" "+line[3]+" "+marks);
                    flag=1;
                }
            }
            file1.close();
            pw.close();
            File delName=new File(namee);
            File oldName=new File("temp.txt");
            File newName=new File(namee);
            if(delName.delete())
                System.out.println("Record Updated Successfully !");
            else
                System.out.println("Error !");
            if(oldName.renameTo(newName));
            else
                System.out.println("Error !");
            showMenu(namee);
        }
        catch(FileNotFoundException e){
            System.out.println("ERROR : File Not Found !");
        }
    }
    public void clear(String filename) throws IOException{
        PrintWriter pw=new PrintWriter(new BufferedWriter(new FileWriter(filename)));
        pw.close();
        System.out.println("All Records Cleared Successfully !");
        int i=0;
        while(i<999999999){
            i++;
        }
        showMenu(filename);
    }
    public void showMenu(String name) throws IOException{
        System.out.print("""
                    Enter your choice : 
                    1. Add Records
                    2. Display Records
                    3. Clear All Records
                    4. Search Records
                    5. Delete Records
                    6. Update Records
                    7. Exit
                    """);
        System.out.print("Select Choice : ");
        int choice=Integer.parseInt(br.readLine());
        switch(choice){
            case 1 -> addRecords(name);
            case 2 -> readRecords(name);
            case 3 -> clear(name);
            case 4 -> searchRecords(name);
            case 5 -> deleteRecords(name);
            case 6 -> updateRecords(name);
            case 7 -> System.exit(0);
            default -> System.out.println("Invalid Choice !");
        }
    }
    public static void main(String[] args) throws IOException{
        String name;
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the name for the file : ");
        name = sc.next();
        name +=".txt";
        Main call=new Main();
        call.showMenu(name);
    }
}
