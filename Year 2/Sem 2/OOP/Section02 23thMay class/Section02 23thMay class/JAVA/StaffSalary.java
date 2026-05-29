import java.util.ArrayList;
import java.util.Scanner;

public class StaffSalary {

    static ArrayList<Staff> staffList = new ArrayList<>(); // add <Staff>

    static final int fulltimeBonus = 500; // remove double quote ""

    public static void main(String[] args) {

        StaffSalary obj = new StaffSalary();
        obj.populateData();

        obj.calculateSalary(staffList); //add obj.
    }

    public void populateData() {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of staff: ");
        int total = input.nextInt(); //nextDouble() -> nextInt()
        input.nextLine();

        for (int i = 0; i < total; i++) {
            System.out.print("Enter Staff ID: ");
            String id = input.nextLine();

            System.out.print("Enter Name: ");
            String name = input.nextLine();

            System.out.print("Enter Staff Type (F/P): ");
            char type = input.nextLine().charAt(0);

            if (type == 'F') {
                System.out.print("Enter Basic Salary: ");
                double salary = input.nextDouble(); //nextDouble()
                input.nextLine();

                Staff s = new Staff(id, name, salary, 0, 0, "FullTime"); 
                staffList.add(s);
            } else if (type == 'P') {
                System.out.print("Enter rate/hour: ");
                double rate = input.nextDouble(); //is double not string

                System.out.print("Enter total hours: ");
                int hrs = input.nextInt();

                Staff s = new Staff(id, name, 0, rate, hrs, "PartTime"); 
                staffList.add(s);
            }
        }
        input.close();
    }

    public void calculateSalary(ArrayList<Staff> list) { 
        for (int i = 0; i < list.size(); i++) {
            Staff s = list.get(i); // remove object

            double salary = s.getSalary(s.type); //pass type
            display(s, salary);
        }
    }

    public void display(Staff s, double amount) {
        System.out.println("Staff ID: " + s.staffID);
        System.out.println("Name: " + s.name);
        System.out.println("Salary: " + amount);
    }
}

class Staff {
    String staffID;
    String name;
    double basicSalary;
    double ratePerHour;
    int totalHours;
    String type;

    public Staff(String id, String name, double salary, double rate, int hours, String t) {
        staffID = id;
        this.name = name;
        basicSalary = salary;
        ratePerHour = rate;
        totalHours = hours;
        type = t;
    }

    public double getSalary(String type) { 
        if (type.equals("FullTime")) { // equal -> equals
            return basicSalary + StaffSalary.fulltimeBonus; 
        } else if (type.equals("PartTime")) {
            return ratePerHour * totalHours;
        } else {
            return 0.0;
        }
    }
}
