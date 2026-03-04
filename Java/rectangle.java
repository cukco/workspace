package Java;
import java.util.Scanner;
class hinhchunhat{
    private double width;
    private double height;
    public hinhchunhat(double a,double b){
        this.width=a;
        this.height=b;
    }
    public void setWidth(double width){
        this.width=width;
    }
    public void setHeight(double height){
        this.height=height;
    }
    public double Area(){
        return width*height;
    }
    public double Perimeter(){
        return 2*(width+height);
    }

}
public class rectangle {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        hinhchunhat hinh1=new hinhchunhat(0,0);
        System.out.print("Enter width:");
        double a=scanner.nextDouble();
        hinh1.setWidth(a);
        System.out.print("Enter height:");
        double b=scanner.nextDouble();
        hinh1.setHeight(b);
        System.out.print(String.format("Area: %f - - - Perimeter: %f", hinh1.Area(),hinh1.Perimeter()));
        scanner.close();
    }
}
