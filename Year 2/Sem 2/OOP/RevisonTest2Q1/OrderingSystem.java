// OrderingSystem.java 
import java.util.*; 
import java.io.*;
 
class Customer { 
  private String name, id; 
  private ArrayList<Order> orders; 
 
  public Customer(String name, String id) { 
    this.name = name; 
    this.id = id; 
    orders = new ArrayList<>(); 
  } 
 
  public String getId() { 
    return id; 
  } 
 
  public void addOrder(Order order) { 
    orders.add(order); //set() -> add()
  } 
 
  public void printOrders() { 
    System.out.println("Customer ID: " + id + "\nCustomer Name: " + name); 
    System.out.println("Number of Orders: " + orders.size()); 
    double total = 0; 
    for (int i = 0; i < orders.size(); i++) { //length -> size()
      Order order = orders.get(i); // orders[i] -> orders.get(i) 
      total += order.getQuantity() * order.getMenuItem().getPrice(); 
      System.out.printf("%d) %-15s %8.2f %5d\n", (i+1),  
      order.getMenuItem().getDescription(), order.getMenuItem().getPrice(),  
      order.getQuantity()); 
    } 
    System.out.printf("\nTotal price = RM %.2f\n\n" , total); // change + to , (printf format use comma)
  } 
} 
 
enum MenuItem { 
  BURGER("BURGER", "Burger", 10), 
  FRIES("FRIES", "Fries", 5), 
  COKE("COKE", "Coke", 3); 
 
  private final double price; 
  private final String code, description; 
 
  MenuItem(String code, String description, double price) { // change price and desctiption order
    this.code = code; 
    this.description = description; 
    this.price = price; 
  } 
 
  public double getPrice() { 
    return price; 
  } 
 
  public String getDescription() { 
    return description; 
  } 
} 

class Order { 
    private MenuItem menuItem; 
    private int quantity; 
   
    public Order(MenuItem menuItem, int quantity) { 
      this.menuItem = menuItem; 
      this.quantity = quantity; 
    } 
   
    public MenuItem getMenuItem() { 
      return this.menuItem; 
    } 
   
    public int getQuantity() { 
      return this.quantity; 
    } 
  } 
   
  public class OrderingSystem { 
    public static void main(String[] args) throws Exception { // use 'Exception' not 'exception'
      ArrayList<Customer> customers = new ArrayList<>(); 
      Scanner file = new Scanner(new File("orders.txt")); //add the file name
      while (file.hasNext()) { // use hasNext() instead of next()
        String code = file.next(); 
        int quantity = file.nextInt(); 
        String id = file.next(); 
        String name = file.nextLine(); 
   
        MenuItem menuItem = MenuItem.valueOf(code); 
        Order order = new Order(menuItem, quantity); 
   
        Customer customer = null; 
        for (Customer c: customers) { 
          if (c.getId().equals(id)) { // use equals() for string comparison
            customer = c; 
            break; 
          } 
        } 
        if (customer == null) { 
          customer = new Customer(name, id); // add 'new'
          customers.add(customer); 
        } 
        customer.addOrder(order); 
      } 
   
      file.close(); // close the file scanner


      System.out.println("List of Orders by Customers"); 
      System.out.println("*******************************"); 
      for (Customer customer: customers) { 
        customer.printOrders(); 
        System.out.println("++++++\n"); 
      } 
    } 
  }