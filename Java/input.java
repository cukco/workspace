package Java;
import java.util.Scanner;

public class input {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        String chuoi=scanner.nextLine();
        try{
            int x=Integer.parseInt(chuoi);
            System.out.print(x+"\n");
        }catch(NumberFormatException e){
            System.out.println("Error:"+chuoi+" is not right");
        }
        int y=scanner.nextInt();
        boolean z=scanner.nextBoolean();
        System.out.print(String.valueOf(y)+" and "+String.valueOf(z));
    }
}