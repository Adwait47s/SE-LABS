package shoppingcart;

import java.util.*;

public class shoppingcart {
    static ArrayList<items> picked = new ArrayList<items>();
    int totolcost;
    shoppingcart(){
        totolcost=0;
    }
    static ArrayList<items> list = new ArrayList<items>();
    public static void addobj (){
        items i1=new items();
        i1.item_name="Pen";
        i1.item_id="s12";
        i1.item_cost=10;
        list.add(i1);
        items i2 =new items();
        i2.item_name="Pencil";
        i2.item_id="s11";
        i2.item_cost=3;
        list.add(i2);
        items i3 =new items();
        i3.item_name="Backpack";
        i3.item_id="s1122";
        i3.item_cost=800;
        list.add(i3);
        items i4 =new items();
        i4.item_name="Paint Box";
        i4.item_id="s11";
        i4.item_cost=400;
        list.add(i4);
    }

    public void displayitems(){
        for(int i=0;i<list.size();i++){
            System.out.println( i +1 +". Item :" + list.get(i).item_name + "Price : " + list.get(i).item_cost);
        }
    }

    public void additems(){
        System.out.println("MENU");
        displayitems();
        System.out.println("Please select any item");
        System.out.println("1.Pen");
        System.out.println("2.Pencil");
        System.out.println("3.Backpack");
        System.out.println("4.Paint Box");
        System.out.println("Please select the item to add");
        int ch;
        Scanner sc = new Scanner(System.in);
        ch = sc.nextInt();
        if(ch==1){
            totolcost+=10;
            picked.add(list.get(0));
        }
        else if(ch==2){
            totolcost+=3;
            picked.add(list.get(1));
        }
        else if(ch==3){
            totolcost+=800;
            picked.add(list.get(2));
        }
        else if(ch==4){
            totolcost+=400;
            picked.add(list.get(3));
        }
        else{
            System.out.println("Please enter correct choice");;
        }
    }

    public void remove(){
        System.out.println("Please enter the thing you want to remove");
        ArrayList<Integer> current = new ArrayList<Integer>();
        for(int i=0;i<4;i++){
            current.add(0);
        }
        for(int i=0;i<picked.size();i++){
            if(Objects.equals(picked.get(i).item_name, "Pen")){
                int a =current.get(0);
                a++;
                current.set(0, a);
            }
            else if(Objects.equals(picked.get(i).item_name, "Pencil")){
                int a =current.get(1);
                a++;
                current.set(1, a);
            }
            else if(Objects.equals(picked.get(i).item_name, "Backpack")){
                int a =current.get(2);
                a++;
                current.set(2, a);
            }
            else if(Objects.equals(picked.get(i).item_name, "Paint Box")){
                int a =current.get(3);
                a++;
                current.set(3, a);
            }
        }
        for(int i=0;i<4;i++){
            if(current.get(i) !=0){
                if(i==0){
                    System.out.println("Pen" + current.get(i));
                }
                else if(i==1){
                    System.out.println("Pencil" + current.get(i));
                }
                else if(i==2){
                    System.out.println("Backpack" + current.get(i));
                }
                else {
                    System.out.println("Paint Box" + current.get(i));
                }
            }
        }

    }
}
