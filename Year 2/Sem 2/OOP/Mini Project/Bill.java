import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import javax.swing.JOptionPane;


public class Bill extends Entity {
    private int customerId;
    private int units;
    private double amount;
    private LocalDate issueDate;
    private LocalDate dueDate;
    private BillStatus status;
    private Payment payment;
    private static int nextBillId = 1;

    public Bill(int customerId, int units, Tariff tariff) {
        this.id = nextBillId++;
        this.customerId = customerId;
        this.units = units;
        this.issueDate = LocalDate.now();
        this.dueDate = issueDate.plusDays(30);
        this.status = BillStatus.PENDING;
        calculateAmount(tariff);
    }

    public int getCustomerId() { return customerId; }
    public int getUnits() { return units; }
    public double getAmount() { return amount; }
    public LocalDate getIssueDate() { return issueDate; }
    public LocalDate getDueDate() { return dueDate; }
    public BillStatus getStatus() { return status; }
    public Payment getPayment() { return payment; }

    public void calculateAmount(Tariff tariff) {
        double rate = tariff.getCurrentRate();
        this.amount = units * rate;
    }

    public void generateBill() {
        System.out.println("Bill ID: " + id);
        System.out.println("Customer ID: " + customerId);
        System.out.println("Units Consumed: " + units);
        System.out.println("Amount Due: RM" + String.format("%.2f", amount));
        System.out.println("Issue Date: " + issueDate);
        System.out.println("Due Date: " + dueDate);
        System.out.println("Status: " + status);
    }
    
    public void updateStatus() {
        if (payment != null) {
            status = BillStatus.PAID;
        } else if (LocalDate.now().isAfter(dueDate)) {
            status = BillStatus.OVERDUE;
        } else {
            status = BillStatus.PENDING;
        }
    }

    public void displayDetails() { 
        generateBill(); 
    }

    public static int getNextBillId() {
        return nextBillId;
    }

    public static void setNextBillId(int nextBillId) {
        Bill.nextBillId = nextBillId;
    }
    
    // Save to File 

}
