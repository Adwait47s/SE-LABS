import java.util.Scanner;
interface Vehical{
    void speedup(int a);
    void changegear(int a);
    void applybreaks();
}
class Bike implements Vehical{
    int speed,gear,currgear;
    Bike(int s,int g){
        this.speed =s;
        this.gear = g;
        currgear =0;
    }
    public void speedup(int a){
        if(a==1){
            speed +=10;
            System.out.println("Speed of the bike is increased by 10 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }
        else if(a==2){
            if(speed<10){
                speed=0;
            }
            else{
                speed-=10;
            }
            System.out.println("Speed of the bike is decrease by 10 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }

    }
    public void changegear(int a){
        if(a==1){
            if(this.speed==0){
                System.out.println("Speed of the vehical 0 km/hr so you can't change gear ");
                return;
            }
            if(currgear==gear){
                System.out.println("Bike is on max gear");
                return;
            }
            currgear++;
            System.out.println("Gear is increased by 1");
            System.out.println("Current Gear : "+currgear);
        }
        else if(a==2){
            if(currgear==0){
                System.out.println("Current gear is 0");
                return;
            }
            currgear--;
            System.out.println("Gear is decreased by 1");
            System.out.println("Current Gear : "+currgear);
        }

    }
    public void applybreaks(){
        System.out.println("Brakes are applied");
        System.out.println("Current Speed : 0");
    }
}
class Car implements Vehical{
    int speed,gear,currgear;
    Car(int s,int g){
        this.speed =s;
        this.gear = g;
        currgear =0;
    }
    public void speedup(int a){
        if(a==1){
            speed +=20;
            System.out.println("Speed of the car is increased by 20 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }
        else if(a==2){
            if(speed<20){
                speed=0;
            }
            else{
                speed-=20;
            }
            System.out.println("Speed of the Car is decrease by 20 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }
    }
    public void changegear(int a) {
        if (a == 1) {
            if(this.speed==0){
                System.out.println("Speed of the vehical 0 km/hr so you can't change gear ");
                return;
            }
            if (currgear == gear) {
                System.out.println("Car is on max gear");
                return;
            }
            currgear++;
            System.out.println("Gear is increased by 1");
            System.out.println("Current Gear : " + currgear);
        } else if (a == 2) {
            if (currgear == 0) {
                System.out.println("Current gear is 0");
                return;
            }
            currgear--;
            System.out.println("Gear is decreased by 1");
            System.out.println("Current Gear : " + currgear);
        }
    }
    public void applybreaks(){
        System.out.println("Brakes are applied");
        System.out.println("Current Speed : 0");
    }
}

class Bicycle implements Vehical{
    int speed,gear,currgear;
    Bicycle(int s,int g){
        this.speed =s;
        this.gear = g;
        currgear =0;
    }
    public void speedup(int a){
        if(a==1){
            speed +=5;
            System.out.println("Speed of the Bicycle is increased by 5 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }
        else if(a==2){
            if(speed<5){
                speed=0;
            }
            else{
                speed-=5;
            }
            System.out.println("Speed of the Bicycle is decrease by 5 km/hr");
            System.out.println("Current Speed : " +speed+" km/hr");
        }
    }
    public void changegear(int a) {
        if (a == 1) {
            if(this.speed==0){
                System.out.println("Speed of the vehical 0 km/hr so you can't change gear ");
                return;
            }
            if (currgear == gear) {
                System.out.println("Bicycle is on max gear");
                return;
            }
            currgear++;
            System.out.println("Gear is increased by 1");
            System.out.println("Current Gear : " + currgear);
        } else if (a == 2) {
            if (currgear == 0) {
                System.out.println("Current gear is 0");
                return;
            }
            currgear--;
            System.out.println("Gear is decreased by 1");
            System.out.println("Current Gear : " + currgear);
        }
    }
    public void applybreaks(){
        System.out.println("Brakes are applied");
        System.out.println("Current Speed : 0");
    }
}
public class vehicle {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        while(true){
            System.out.println("Please select the choice");
            System.out.println("1.Bike");
            System.out.println("2.Car");
            System.out.println("3.Bycycle");
            int ch;
            boolean flag =true;
            ch = s.nextInt();
            if(ch==1){
                System.out.println("Please enter initial speed of bike");
                int speed=s.nextInt();
                System.out.println("Please enter total gears in the bike");
                int gear = s.nextInt();
                Bike b = new Bike(speed,gear);
                while(true){
                    System.out.println("1.Increase Speed");
                    System.out.println("2.Change Gear");
                    System.out.println("3.Apply Brakes");
                    System.out.println("4.Exit");
                    int chh = s.nextInt();
                    if(chh==1){
                        System.out.println("1.Increase Speed");
                        System.out.println("2.Decrease Speed");
                        int c= s.nextInt();
                        b.speedup(c);
                    }
                    else if(chh==2){
                        System.out.println("You want to increase or decrease gear?");
                        System.out.println("1.Increase");
                        System.out.println("2.Decrease");
                        int gg= s.nextInt();
                        if(gg==1){
                            b.changegear(1);
                        }
                        else{
                            b.changegear(2);
                        }
                    }
                    else if(chh==3){
                        b.applybreaks();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            else if(ch==2){
                System.out.println("Please enter initial speed of Car");
                int speed=s.nextInt();
                System.out.println("Please enter total gears in the Car");
                int gear = s.nextInt();
                Car b = new Car(speed,gear);
                while(true){
                    System.out.println("1.Change Speed");
                    System.out.println("2.Change Gear");
                    System.out.println("3.Apply Brakes");
                    System.out.println("4.Exit");
                    int chh = s.nextInt();
                    if(chh==1){
                        System.out.println("1.Increase Speed");
                        System.out.println("2.Decrease Speed");
                        int c= s.nextInt();
                        b.speedup(c);
                    }
                    else if(chh==2){
                        System.out.println("You want to increase or decrease gear?");
                        System.out.println("1.Increase");
                        System.out.println("2.Decrease");
                        int gg= s.nextInt();
                        if(gg==1){
                            b.changegear(1);
                        }
                        else{
                            b.changegear(2);
                        }
                    }
                    else if(chh==3){
                        b.applybreaks();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            else if(ch==3){
                System.out.println("Please enter initial speed of Bicycle");
                int speed=s.nextInt();
                System.out.println("Please enter total gears in the Bicycle");
                int gear = s.nextInt();
                Bicycle b = new Bicycle(speed,gear);
                while(true){
                    System.out.println("1.Increase Speed");
                    System.out.println("2.Change Gear");
                    System.out.println("3.Apply Brakes");
                    System.out.println("4.Exit");
                    int chh = s.nextInt();
                    if(chh==1){
                        System.out.println("1.Increase Speed");
                        System.out.println("2.Decrease Speed");
                        int c= s.nextInt();
                        b.speedup(c);
                    }
                    else if(chh==2){
                        System.out.println("You want to increase or decrease gear?");
                        System.out.println("1.Increase");
                        System.out.println("2.Decrease");
                        int gg= s.nextInt();
                        if(gg==1){
                            b.changegear(1);
                        }
                        else{
                            b.changegear(2);
                        }
                    }
                    else if(chh==3){
                        b.applybreaks();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
    }
}
