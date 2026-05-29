/*
TEST 2 (PRACTICAL)
SUBJECT CODE    : SECJ2154
SUBJECT NAME    : OBJECT ORIENTED PROGRAMMING
YEAR/COURSE     : 2 (SECB/ SECJ/ SECP/ SECR/ SECV)
TIME            : 08:00 PM– 10:00 PM MYT (2 HOURS)
DATE            : 29th MAY 2024 (WEDNESDAY)

NAME            : SABRINA HENG WEI QI
MATRIC NO       : A23CS0265
YEAR/PROGRAM    : 2/SECPH
SECTION         : 02
LECTURER NAME   : DR. ZURAINI

Objective:
Refer Question Booklet.
*/

import java.util.ArrayList;

class Bank { //Total 15 marks for Bank class
    private String name;
    private Address address;
    private ArrayList<Account> accounts;

    public Bank(String name, Address address){
        this.name = name;
        this.address = address;
        this.accounts = new ArrayList<>();
    }

    public String getName(){
        return name;
    }

    public String getAddress(){
        return address.getFullAddress();
    }

    public void addAccount(Account account){
        accounts.add(account);
    }

    public void removeAccount(Account account){
        accounts.remove(account);
    }

    public void printAllInfo(){
        System.out.println("Bank Name: " + name);
        System.out.println("Bank Address: " + getAddress());
        System.out.println("Number of Account(s) Registered: " + accounts.size());
        System.out.println("List of Account(s): ");
        for(int i=0; i<accounts.size(); i++){
            Account account = accounts.get(i);
            System.out.println((i+1) + ". Account #: " + account.getAccountNumber() + ", Type: " + account.getType());
        }
        System.out.println("\n");
    }
}

class Account { //Total 15 marks
    private String accountNumber;
    private String owner;
    private double balance;
    private String type;
    private ArrayList<Transaction> transactions;

    public Account(String accountNumber, String type){
        this.accountNumber = accountNumber;
        this.type = type;
        this.transactions = new ArrayList<>();
    }

    public void setOwner(String owner){
        this.owner = owner;
    }

    public String getAccountNumber(){
        return accountNumber;
    }

    public double getBalance(){
        return balance;
    }

    public String getType(){
        return type;
    }

    public void deposit(double amount){
        if(amount>=0){
            balance+=amount;
            Transaction transaction = new Transaction("Deposit",amount);
            transactions.add(transaction);
        }else{
            System.out.println("The amount cannot less than zero.");
        }
    }

    public void withdraw(double amount){
        if(amount>=0 && amount<=balance){
            balance-=amount;
            Transaction transaction = new Transaction("Withdraw",amount);
            transactions.add(transaction);
        }else{
            System.out.println("Withdrawal Fail");
        }
    }

    public void printAllInfo(){
        System.out.println("Account #: " + accountNumber);
        System.out.println("Owner: " + owner);
        System.out.println("Type: " + type);
        System.out.println("Balance: " + balance);
        System.out.println("Number of Transaction(s): " + transactions.size());
        System.out.println("List of Transaction(s): ");
        for(int i=0; i<transactions.size(); i++){
            Transaction transaction = transactions.get(i);
            System.out.println((i+1) + ". Type: " + transaction.getTransactionType() + ", Amount: " + transaction.getAmount());  
        }
        System.out.println("\n");
    }
}

class Customer { //Total 15 marks
    private String customerID;
    private String name;
    private Address address;
    private ArrayList<Account> accounts;

    public Customer(String customerID, String name, Address address){
        this.customerID = customerID;
        this.name = name;
        this.address = address;
        this.accounts = new ArrayList<>();
    }

    public String getCustomerID(){
        return customerID;
    }

    public String getName(){
        return name;
    }

    public String getAddress(){
        return address.getFullAddress();
    }

    public void addAccount(Account account, Bank bank){
        accounts.add(account);
        bank.addAccount(account);
        account.setOwner(name);
    }

    public void removeAccount(Account account, Bank bank){
        accounts.remove(account);
        bank.removeAccount(account);
        account.setOwner(name);
    }

    public void printAllInfo(){
        System.out.println("Customer Name: " + name);
        System.out.println("Customer ID: " +  customerID);
        System.out.println("Customer Address: " + getAddress());
        System.out.println("Number of Account(s) Registered: " + accounts.size());
        System.out.println("List of Account(s): ");
        for(int i=0; i<accounts.size(); i++ ){
            Account account = accounts.get(i);
            System.out.println((i+1) + ". Account #: " + account.getAccountNumber() + ", Balance: " + account.getBalance() + ", Type: " + account.getType());
        }
        System.out.println("\n");
    }
}

class Address { //Total 5 marks
    private String roadName;
    private String city;
    private String state;
    private String country;

    public Address(String roadName, String city, String state, String country){
        this.roadName = roadName;
        this.city = city;
        this.state = state;
        this.country = country;
    }

    public String getFullAddress(){
        return roadName + ", " + city + ", " + state + ", " + country;
    }
}

class Transaction { //Total 5 marks
    private String transactionType;
    private double amount;

    public Transaction(String transactionType, double amount){
        this.transactionType = transactionType;
        this.amount = amount;
    }

    public String getTransactionType(){
        return transactionType;
    }

    public double getAmount(){
        return amount;
    }
}

public class BankingSystem { //Total 15 marks
    public static void main(String[] args) {
        // Create TWO (2) address objects, 1 for bank and 1 for customer
        // 1 marks
        Address bankAddress = new Address("Jalan Kebudayaan", "Skudai", "Johor", "Malaysia");
        // 1 marks
        Address customerAddress = new Address("Jalan Pendidikan", "Skudai", "Johor", "Malaysia");

        // Create a bank object
        // 1 marks
        Bank bank = new Bank("Beacon Bank", bankAddress);

        // Create a customer object
        // 1 marks
        Customer customer = new Customer("C001", "John Doe", customerAddress);

        // Create an account object and link it to the customer object
        // 1 marks
        Account account1 = new Account("A001", "Savings");
        // 1 marks
        customer.addAccount(account1, bank);

        // Create another account object and link it to the customer object
        // 1 marks
        Account account2 = new Account("A002", "Current");
        // 1 marks
        customer.addAccount(account2, bank);

        // Deposit and withdraw from the first account
        // 1 marks
        account1.deposit(1000);
        // 1 marks
        account1.withdraw(200);

        // Deposit to the second account
        // 1 marks
        account2.deposit(2000);

        // Print info for bank, account 1 & 2, customer
        // 0.5 marks
        bank.printAllInfo();
        // 0.5 marks
        account1.printAllInfo();
        // 0.5 marks
        account2.printAllInfo();
        // 0.5 marks
        customer.printAllInfo();

        // Remove account 2 from customer
        // 1 marks
        customer.removeAccount(account2, bank);

        // Print info for bank, customer
        // 0.5 marks
        bank.printAllInfo();
        // 0.5 marks
        customer.printAllInfo();
    }
}
