package Java;

import java.util.Scanner;

public class breakAndContinue {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int[][] array=new int[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                array[i][j]=scanner.nextInt();
            }
        }
        System.out.print("\nEnter the goal number:");
        int x=scanner.nextInt();
        int flag=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(array[i][j]==x){
                    System.out.println("\nFound");
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==0){
            System.out.println("\nNo such number bitch");
        }
    }
}
