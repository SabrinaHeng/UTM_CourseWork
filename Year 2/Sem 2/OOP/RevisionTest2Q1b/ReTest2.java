//Program 1 
import java.util.*; 
 
class Time { 
 private int hour, minute; 
 
 public Time(int h, int m) { 
  hour = h; 
  minute = m; 
 } 
 
 public String dispTime() { 
  if (minute < 10) 
   return hour + ":0" + minute; 
  else 
   return hour + ":" + minute; 
 } 
} 
 
class Passenger { 
 private String name, parentName, job; 
 int age; 
 
 public Passenger(String name, int age) { 
  this.name = name; //add this
  this.age = age; //add this
  parentName = job = null; 
 } 
 
 public void setPName(String pn) { 
  parentName = pn; 
 } 
 
 public void setJob(String j) { 
  job = j; 
 } 
 
 public int getAge() {  //void -> int
  return age; 
 } 
 
 public void dispDetails() { 
  System.out.print("Name: " + name + "\tAge: " + age); 
  if (age < 12) 
   System.out.println("\tParent Name: " + parentName); 
  else 
   System.out.println("\tJob Title: " + job); 
 } 
} 
 
class Flight { 
 private String id, destination; 
 private Time depart, arrival; 
 private Vector <Passenger> passengerList; 
 
 public Flight(String i, String d, Time dp, Time a) { 
  id = i; 
  destination = d; 
  depart = dp; 
  arrival = a;
  passengerList = new Vector<>(); //add <>
 } 
 
 public void addPassenger(Passenger p) { 
  passengerList.add(p); 
 } 
 
 public void dispInfo() { 
  System.out.println("Flight Number: " + id); 
  System.out.println("Destination: " + destination); 
  System.out.println("Departure: " + depart.dispTime()); 
  System.out.println("Arrival: " + arrival.dispTime()); 
  System.out.println("Number of Passengers: " + passengerList.size()); 
  System.out.println("\nPassengers Details:"); 
  
  for (int i = 0; i < passengerList.size(); i++) 
   passengerList.get(i).dispDetails();  //add get(i)
 } 
} 
 
public class ReTest2 { 
 public static void main(String[] args) { 
   ArrayList <Flight> flightList = new ArrayList<>(); //add <>
 
   Flight [] f = {new Flight("MH1037", "Johor Bahru", new Time(19, 5), new Time(20, 0)), // add new for both Time constrcutor
                  new Flight("Z98805", "Kota Kinabalu", new Time(18, 15), new Time(21, 5))}; 

   Passenger [] p = {new Passenger("Abu Jani", 5), 
                     new Passenger("Ana Alif", 35), 
                     new Passenger("Ali Alwi", 23), 
                     new Passenger("Ani Daud", 11), 
                     new Passenger("Lim Chua", 44), 
                     new Passenger("Rin Liew", 48)}; 

  String [] j = {new String("Accountant"), new String("Engineer")}; 
  String [] pn = {new String("Tina Mat"), new String("Adli Aris")}; 
 
  for (int i = 0; i < p.length; i++) //size() -> length
   if (p[i].getAge() < 12) //add [i] (this is array)
    p[i].setPName(pn[i%2]); 
   else 
    p[i].setJob(j[i%2]); 
 
  flightList.add(f[0]); 
  flightList.add(f[1]); 
 
  flightList.get(0).addPassenger(p[0]); 
  flightList.get(1).addPassenger(p[5]); 
  flightList.get(1).addPassenger(p[1]); 
  flightList.get(1).addPassenger(p[3]); 
  flightList.get(0).addPassenger(p[4]); 
  flightList.get(1).addPassenger(p[2]); 
 
  System.out.println("<<<<<< List of flights >>>>>>\n"); 
  for (int i = 0; i < flightList.size(); i++) { //length -> size()
   flightList.get(i).dispInfo(); // add get(i)
   System.out.println(); 
  } 
 } 
}