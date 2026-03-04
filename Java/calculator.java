import java.util.Scanner;
class math{
    private double result=0;
    public math add(double num){
        this.result+=num;
        return this;
    }
    public math subtract(double num){
        this.result-=num;
        return this;
    }
    public math multiply(double num){
        this.result*=num;
        return this;
    }
    public math divide(double num){
        this.result/=num;
        return this;
    }
    public double ketqua(){
        return this.result;
    }
}
public class calculator {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter your function: ");
        String function=scanner.nextLine();
        math fun1=new math();
        String[] doiso = function.split("\\s*[+\\-x:]\\s*");
        fun1.add(Double.parseDouble(doiso[0]));
        String toantu = function.replaceAll("[0-9\\s]", "");
        String[] toantu1=toantu.split("");
        for(int i=0;i<toantu1.length;i++){
            String x=toantu1[i];
            switch(x){
                case "+":
                    fun1.add(Double.parseDouble(doiso[i+1]));
                    break;
                case "-":
                    fun1.subtract(Double.parseDouble(doiso[i+1]));
                    break;
                case "x":
                    fun1.multiply(Double.parseDouble(doiso[i+1]));
                    break;
                case ":":
                    fun1.divide(Double.parseDouble(doiso[i+1]));
                    break;
            }
        }
        System.out.print(fun1.ketqua());
    }
}
