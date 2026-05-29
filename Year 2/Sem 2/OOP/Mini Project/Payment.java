import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Date;

import javax.swing.JOptionPane;


//Payment class
public class Payment extends Entity implements SaveToFile {
    private int billID;
    private double amount;
    private LocalDate paymentDate;
    private String paymentMethod;

    private static int nextPaymentID = 1;

    // Constructor
    public Payment(int billID, double amount, String paymentMethod) {
        this.id = nextPaymentID++;
        this.billID = billID;
        this.amount = amount;
        this.paymentDate = LocalDate.now();
        this.paymentMethod = paymentMethod;
    }

    // Getter methods
    public int getPaymentID() { return id; }
    public int getBillID() { return billID; }
    public double getAmount() { return amount; }
    public LocalDate getPaymentDate() { return paymentDate; }
    public String getPaymentMethod() { return paymentMethod; }

    // Method 1: Process Payment (simple version)
    public boolean processPayment() {
        return amount > 0;
    }

    // Method 2: Generate Receipt
    public String generateReceipt() {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        return "Payment Receipt\n" +
               "Payment ID: " + id + "\n" +
               "Bill ID: " + billID + "\n" +
               "Date: " + dtf.format(paymentDate) + "\n" +
               "Method: " + paymentMethod + "\n" +
               "Amount: RM" + String.format("%.2f", amount);
    }

    // Save to file (implements SaveToFile)
    @Override
    public void saveToFile() {
        try {
            FileWriter writer = new FileWriter("payment.txt", true);
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");

            writer.write("Payment ID: " + id + "\n");
            writer.write("Bill ID: " + billID + "\n");
            writer.write("Payment Date: " + dtf.format(paymentDate) + "\n");
            writer.write("Method: " + paymentMethod + "\n");
            writer.write("Amount: RM" + String.format("%.2f", amount) + "\n");
            writer.write("===================================\n");
            writer.close();

            JOptionPane.showMessageDialog(null, "Payment saved successfully!");

        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Error saving payment: " + e.getMessage());
        }
    }

    // Override displayDetails from Entity
    @Override
    public void displayDetails() {
        System.out.println(generateReceipt());
    }
} 