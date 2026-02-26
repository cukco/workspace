package Java;
public class dog {
    String name;
    String breed;
    public void display(){
        System.out.println(name+" "+breed);
    }
    public static void main(String[] args){
        dog mydo=new dog();
        mydo.breed="Female";
        mydo.name="Peter";
        mydo.display();
    }
}
