package Java;
import java.util.Scanner;
public class ifelse {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter one number: ");
        int x=scanner.nextInt();
        if(x%4==0){
            if(x%100 != 0 || x%400==0){
                System.out.print("True");
            }else System.out.print("False");
        }else System.out.print("False");

    }
}
