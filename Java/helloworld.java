package Java;

import java.util.Scanner;

public class helloworld {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.print("Nhập tên: ");
        String name=scanner.nextLine();
        System.out.print("Nhập tuổi của bạn: ");
        int age = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Nhập quê: ");
        String city=scanner.nextLine();
        System.out.print(String.format("Tên: %s\nTuổi: %d\nQuê quán:%s",name,age,city));
    }
}