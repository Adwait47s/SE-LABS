import java.util.ArrayList;

interface matchcondition<T>{
    public boolean match(T t);
}
class primecnt implements matchcondition<Integer>{
    @Override
    public boolean match(Integer curr) {
        for(int i=2;i*i<=curr;i++){
            if(curr%i==0) return false;
        }
        return true;
    }
}
class evennumber implements matchcondition<Integer>{
    @Override
    public boolean match(Integer curr) {
        if(curr%2==0) return true;
        return false;
    }
}
class oddnumber implements matchcondition<Integer>{
    @Override
    public boolean match(Integer curr) {
        if(curr%2!=0)return true;
        return false;
    }
}
class palindrome implements matchcondition<String>{
    @Override
    public boolean match(String s) {
        for(int i=0;i<=s.length()/2;i++){
            if(s.charAt(i)!=s.charAt(s.length()-1-i)) return false;
        }
        return true;
    }
}
class count{
    int cnt;
    count(){
        cnt=0;
    }
    public <T> int countt(ArrayList<T>listt,matchcondition<T> obj){
        for (int i=0;i<listt.size();i++){
            if(obj.match(listt.get(i))){
                cnt++;
            }
        }
        return cnt;
    }
}
public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> lisst = new ArrayList<Integer>();
        for(int i=1;i<=25;i++){
            lisst.add(i);
        }
        System.out.println("Given integer list : "+lisst);
        primecnt pn = new primecnt();
        oddnumber od = new oddnumber();
        evennumber ev = new evennumber();
        palindrome pv = new palindrome();
        count ct = new count();
        System.out.println("The count of prime numbers in the given list is : "+ct.countt(lisst,pn));
        ct.cnt=0;
        System.out.println("The count of even numbers in the given list is : "+ct.countt(lisst,ev));
        ct.cnt=0;
        System.out.println("The count of odd numbers in the given list is : "+ct.countt(lisst,od));
        ct.cnt =0;
        ArrayList<String > liist = new ArrayList<String>();
        liist.add("1001001");
        liist.add("11");
        liist.add("AdwaittiawdA");
        liist.add("NULL");
        liist.add("Pointer");
        liist.add("IOSTREAM");
        System.out.println("Given string list : "+liist);
        System.out.println("The count of palindromes in the given list is : "+ct.countt(liist,pv));
    }
}
