import java.util.Scanner;
class bank{
    private int accountNumber;
    private String accountHolderName;
    private float balance;
    public bank(int accountNumber,String accountHolderName){
        this.accountNumber=accountNumber;
        this.accountHolderName=accountHolderName;
        this.balance=0f;
    }
    public void deposit(float money){
        balance+=money;
        System.out.println("Status: +"+money+" --- Balance: "+balance);
    }
    public void withdraw(float money){
        if(balance<money){
            System.out.println("Not enough money");
        }else{
            balance-=money;
            System.out.println("Status: -"+money+" --- Balance: "+balance);
        }
    }
}
public class bankaccount {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter customer's number: ");
        int num=scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter customer's name: ");
        String name=scanner.nextLine();
        bank cust1=new bank(num, name);
        int option;
        do{
            System.out.print("\nMenu\n1)Deposit\n2)Withdraw\n3)Quit\n---------\n");
            option=scanner.nextInt();
            switch (option) {
                case 1:
                    float money=scanner.nextFloat();
                    cust1.deposit(money);
                    break;
                case 2:
                    float money1=scanner.nextFloat();
                    cust1.withdraw(money1);
                    break;
                case 3:
                    System.out.print("Exit...");
                    break;
                default: break;
            }
        }while(option!=3);
    }
}
