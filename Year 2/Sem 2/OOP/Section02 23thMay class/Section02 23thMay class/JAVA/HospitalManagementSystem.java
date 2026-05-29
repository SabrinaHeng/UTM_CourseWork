//Refer class 22th May - incomplete.pdf for UML class diagram

import java.util.ArrayList;

class Name {
    private String firstName;
    private String lastName;

    public Name(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFullName(){
        return firstName + lastName;
    }


}

class Address {
    private String street;
    private String city;
    private String postcode;
    
    public Address(String street, String city, String postcode) {
        this.street = street;
        this.city = city;
        this.postcode = postcode;
    }

    public String getFullAddress(){
        return street + city + postcode;
    }

    public String toString() {
        return street + ", " + city + ", " + postcode;
    }
}

class Patient {
    private Name name;
    private Address address;

    public Patient(String first, String last, Address address){
        // Assuming Name is a class with appropriate constructor
        this.name = new Name(first, last);
        // Assuming Address is a class with appropriate constructor
        this.address = address;
    }

    public void display(){
        System.out.println("Patient Name: " + name.getFullName());
        System.out.println("Address: " + address.toString());
    }


}

class Hospital {
    private String name;
    private ArrayList<Patient> patients;

    public Hospital(String name){
        this.name = name;
        this.patients = new ArrayList<>();
    }

    public void addPatient(Patient p){
        patients.add(p);
    }

    public void displayInfo(){
        System.out.println("Hospital Name: " + name);
        System.out.println("Patients:");
        for (Patient p : patients) {
            p.display();
        }
    }


}

// Main class
public class HospitalManagementSystem {
    public static void main(String[] args) {
        
        // Create Address objects 
        Address a = new Address("123 Main St", "Springfield", "12345");

        // Create Patient objects 
        Patient p = new Patient("Sabrina", "Heng", a);

        // Create Hospital object
        Hospital h = new  Hospital("ABC");

        // Association: Add patients to hospital
        h.addPatient(p);

        // Output
        h.displayInfo();

    }
}

