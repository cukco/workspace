package Java;
class student{
    String name,major;
    float gpa;
    public student(String name,String major,float gpa){
        this.name=name;
        this.major=major;
        this.gpa=gpa;
    }
    void display(){
        System.out.println(String.format("Name:%s Major:%s GPA:%.2f",name,major,gpa));
    }
}
class BankAccount{
    String accountnum,custname;
    float balance;
    public BankAccount(String accountnum,String custname,float balance){
        this.accountnum=accountnum;
        this.custname=custname;
        this.balance=balance;
    }
    void deposit(double amount){
        balance+=amount;
    }
    void withdraw(double amount){
        if(balance>=amount) balance-=amount;
        else System.out.print("Not enough Balance");
    }
    void displaybalance(){
        System.out.print(balance);
    }
}
class rectangle{
    int width,height;
    public rectangle(int w,int h){
        width=w;
        height=h;
    }
    boolean issquare(){
        if(width==height) return true;
        else return false;
    }
}
public class oop {
    public static void main(String[] args) {
        student hsinh=new student("Hung", "IT", 3.5f);
        hsinh.display();
        BankAccount custom1=new BankAccount("0819989919", "DINH QUANG HUNG", 20000000f);
        custom1.deposit(500000);
        custom1.displaybalance();
        rectangle squr=new rectangle(50, 50);
        System.out.println(squr.issquare());
    }
}
