package Java;
import java.util.Scanner;
public class caseSwitch {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter your object: ");
        String obj=scanner.nextLine();
        System.out.print("Enter your 1st number: ");
        int a=scanner.nextInt();
        System.out.print("Enter your 2nd number: ");
        int b=scanner.nextInt();
        switch(obj){
            case "Add": 
            System.out.println(a+b);
            break;
            case "Subtract": 
            System.out.println(a-b);
            break;
            case "Multiply": 
            System.out.println(a*b);
            break;
            case "Divide": 
            if(b!=0) System.out.println(a/b);
            else System.out.println("Invalid Input");
            break;
            default: System.out.println("Invalid Input");
        }
    }
}
