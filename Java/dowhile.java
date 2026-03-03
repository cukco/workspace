package Java;
import java.util.Scanner;
public class dowhile {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        String pass;
        int x=0,a=0,b=0;
        do{
            System.out.println("Menu:\n1: Add\n2:Abtract\n3:Multiply\n4:Divide\n5:Quit\nChoose your object?...\n");
            x=scanner.nextInt();
            switch(x){
                case 1:
                    a=scanner.nextInt();
                    b=scanner.nextInt();
                    System.out.println(a+b);
                    break;
                case 2:
                    a=scanner.nextInt();
                    b=scanner.nextInt();
                    System.out.println(a-b);
                    break;
                case 3:
                    a=scanner.nextInt();
                    b=scanner.nextInt();
                    System.out.println(a*b);
                    break;
                case 4:
                    a=scanner.nextInt();
                    b=scanner.nextInt();
                    if(b==0) System.out.println("Invalid number");
                    else System.out.println((float)a/b);
                    break;
                case 5: break;
                default: System.out.println("Invalid number"); break;
            }
        }while(x!=5);
    }

}
