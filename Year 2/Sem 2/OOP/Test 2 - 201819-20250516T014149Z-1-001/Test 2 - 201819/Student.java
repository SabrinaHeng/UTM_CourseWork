public class Student {
    private String name;
    private String matricsNo;
    private double GPA;
    private static double totalCredit;

    public Student() {
        totalCredit = 0;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setMatricNo(String matricsNo){
        this.matricsNo = matricsNo;
    }

    public String getName(){
        return name;
    }

    public String getMatricNo(){
        return matricsNo;
    }

    public double getGPA(){
        return GPA;
    }
}
