#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

class Person{
	private :
		string name,ic;
		int activityLevel;
		double height,weight,bmr,calorie;
		
	public :
		Person(string n = "",double h = 0.0,double w = 0,int al = 0){
			name = n;
			height = h;
			weight = w;
			activityLevel = al;
			ic = "";
		}
		
		string getName()const{
			return name;
		}
		
		string getGender(){
			string gender;
			
			if(stoi(ic.substr(11,1))%2 ==0){
				gender = "female";
			}else{
				gender = "male";
			}
			return gender;
		}
		
		int getAge(){
			int age;
			
			age = stoi(ic.substr(0,2));
			
			if(age>19){
				age += 1900;
			}else{
				age += 2000;
			}
			
			age = 2020 - age;
			return age;
		}
		
		void calcCalorie(string gender,int age){
			if(gender == "male"){
				bmr = (10*weight)+(6.25*height)-(5*age)+5;
			}else{
				bmr = (10*weight)+(6.25*height)-(5*age)-161;
			}
			
			switch (activityLevel){
				case 1 : calorie = bmr*1.2;
							break;
							
				case 2 : calorie = bmr*1.375;
							break;
							
				case 3 : calorie = bmr*1.55;
							break;
							
				case 4 : calorie = bmr*1.725;
							break;
							
				case 5 : calorie = bmr*1.9;
							break;
			}
		}
		
		void readInput(){
			cout << "Name : ";
			getline(cin,name);
			cout << "NRIC Number (without hyphen '-' :";
			cin >> ic;
			cout << "Height (in meter) : ";
			cin >> height;
			cout << "Weight (in kg) : ";
			cin >> weight;
			cout << "Choose the activity level : 1-Sedentary, 2-Ligthly Active, 3-Moderately Active, 4-Very Active, 5-Extra Active";
			cout << "\nActivity level (1-5) :";
			cin >> activityLevel;
			
			string g = getGender();
			int a = getAge();
			
			calcCalorie(g,a);
		}
		
		bool operator==(const Person &obj){
			if(activityLevel == obj.activityLevel){
				return true;
			}else{
				return false;
			}
		}
		
		friend void dispInfo(Person &obj){
			cout << "Your gender is " << obj.getGender() << endl;
			cout << "Your age is " << obj.getAge() << " year old" << endl;
		}
		
		friend ostream& operator<<(ostream &out, Person &obj){
			out << "Hello, " << obj.name << endl;
			dispInfo(obj);
			out << "Your height is " << fixed << showpoint << setprecision (2) << obj.height << " cm" << endl;
			out << "Your weight is " << fixed << showpoint << setprecision (2) << obj.weight << " kg" << endl;
			out << "Your BMR is " << fixed << showpoint << setprecision (2) << obj.bmr << "kcal/day" << endl;
			out << "Your calorie based on activity level is " << fixed << showpoint << setprecision (2) << obj.calorie << "kcal/day";
			return out;
		}
		
};

int main(){
	Person p1;
	Person p2("Alisa Hashim",150,50,2);
	
	cout << "Calorie Calculator" << endl << endl;
	cout << "<<< Input >>>" << endl;
	p1.readInput();
	
	cout << "\n<<< Output >>>" << endl;
	cout << p1 << endl;
	
	
	if(p1==p2){
		cout << "\n\n**Note : " << p1.getName() << " and " << p2.getName() << "have same activity level.";
	}else{
		cout << "\n\n**Note : " << p1.getName() << " and " << p2.getName() << "have different activity level.";
	}
	
	return 0;
}
