package shoppingcart;

import java.util.ArrayList;
import java.util.Scanner;
public class shoppingcart {
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
    }
}
