package Java;
import java.util.Scanner;
class hsinh{
    private String name;
    private int age;
    private int grade;
    public void setname(String name){
        this.name=name;
    }
    public void setage(int age){
        this.age=age;
    }
    public void setGrade(int grade){
        this.grade=grade;
    }
    public boolean check(){
        if(grade>60) return true;
        else return false;
    }
}
public class student {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        hsinh DinhHung=new hsinh();
        System.out.print("Enter your name:");
        DinhHung.setname(scanner.nextLine());
        System.out.print("Enter your age:");
        DinhHung.setage(scanner.nextInt());
        System.out.print("Enter your grade:");
        DinhHung.setGrade(scanner.nextInt());
        System.out.print(DinhHung.check());
        scanner.close();

    }
}
