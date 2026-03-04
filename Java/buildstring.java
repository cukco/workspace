import java.util.Scanner;
class build{
    private String chuoi="";
    public build append(String chuoinoi){
        if(chuoinoi!=null){
            chuoi+=chuoinoi;
        }
        return this;
    }
    public String tostring(){
        return this.chuoi;
    }
}
public class buildstring {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        build chuoi=new build();
        int index=1;
        String word;
        do{
            System.out.printf("Enter word number %d: ",index);
            word=scanner.nextLine();
            chuoi.append(word);
            index++;
        }while(!word.equals(""));
        System.out.println(chuoi.tostring());
    }
}
