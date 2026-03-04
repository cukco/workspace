import java.util.Scanner;
class car{
    private int currentspeed;
    public car(int speed){
        currentspeed=speed;
    }
    public void startengine(){
        if(currentspeed==0){
            System.out.print("Engine started.");
            currentspeed=1;
        }
        else System.out.print("Car is already running.");
    }
    public void stopEngine(){
        currentspeed=0;
        System.out.print("Engine stopped.");
    }
    public void acclerate(){
        if(currentspeed==0) System.out.print("Cannot accelerate. Engine is off.");
        else{
            currentspeed=currentspeed*2;
            System.out.printf("Current Spped: %d\n",currentspeed);
        }
    }
}
public class EnhanceCar {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        car porsche=new car(0);
        int option;
        do{
            System.out.println("\nPorsche 911 GT3RS --- MENU\n1)Start Engine\n2)Stop Engine\n3)Acclerate\n4)Quit\n----------------");
            option=scanner.nextInt();
            switch(option){
                case 1: porsche.startengine(); break;
                case 2: porsche.stopEngine(); break;
                case 3: porsche.acclerate(); break;
                case 4: System.out.println("Exit..."); break;
                default: System.out.println("Invalid Number");
            }
        }while(option!=4);
    }
}
