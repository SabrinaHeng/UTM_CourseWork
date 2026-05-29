// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II
// Semester 2, 2023/2024

// Section: 01
// Member 1's Name: Sabrina Heng Wei Qi    Location: Melaka (i.e. where are you currently located)
// Member 2's Name: Chau Ying Jia    Location: Ipoh
//
// Date and time of pair programming sessions:
//   _________  (Date, time and estimate duration)
//   _________  (Date, time and estimate duration)
// 
// Video link:
//   _________  

// ? Notes: Choose the debug mode "Console Program" to run the program.

#include <iostream>
#include <string>

using namespace std;

class Subject{
	private:
		string name;
		string code;
		double score;
		
	public:
		//parameterized constructor
		Subject(string n, string c, double s){
			name = n;
			code = c;
			score = s;
		}	
		
		//default constructor
		Subject(){
			name = "";
			code = "";
			score = 0.00;
		}
		
		//destructor
		~Subject(){}
		
		//mutator
		void setName(string n){
			name = n;
		}
		
		void setCode(string c){
			code = c;
		}
		
		void setScore(double s){
			score = s;
		}
		
		//accessor
		string getName() const{
			return name;
		}
		
		string getCode() const{
			return code;
		}
		
		double getScore() const{
			return score;
		}
		
		string gradeEarned(){
			if(score>=90 && score<=100){
				return "A+";
			}
			else if (score>=80 && score <= 89){
				return "A";
			}
			else if (score >=75 && score <= 79){
				return "A-";
			}
			else if (score >= 70 && score <= 74){
				return "B+";
			}
			else if (score >= 65 && score <= 69){
				return "B";
			}
			else if(score>=60 && score<=64){
				return "B-";
			}
			else if(score>=55 && score<=59){
				return "C+";
			}
			else if(score>=50 && score<=54){
				return "C";
			}
			else if(score>=45 && score<=49){
				return "C-";
			}
			else if(score>=40 && score<=44){
				return "D+";
			}
			else if(score>=35 && score<=39){
				return "D";
			}
			else if(score>=30 && score<=34){
				return "D-";
			}
			else if(score>=0 && score<=29){
				return "E";
			}
			else{
				return "invalid score!!!";
			}
		}
		
		double pointValue(){
			string grade = gradeEarned();
			if(grade == "A+" || grade == "A"){
				return 4.00;
			} 
			else if(grade == "A-"){
				return 3.67;
			}
			else if(grade == "B+"){
				return 3.33;
			}
			else if(grade == "B"){
				return 3.00;
			}
			else if(grade == "B-"){
				return 2.67;
			}
			else if(grade == "C+"){
				return 2.33;
			}
			else if(grade == "C"){
				return 2.00;
			}
			else if(grade == "C-"){
				return 1.67;
			}
			else if(grade == "D+"){
				return 1.33;
			}
			else if(grade == "D"){
				return 1.00;
			}
			else if(grade == "D-"){
				return 0.67;
			}
			else if(grade == "E"){
				return 0.00;
			}
			else 
				return -1;	//invalid
		}
		
		double pointEarned(){
			char credithr = code[code.length()-1];
			int credit = credithr - '0';			//convert from string to int refer to ASCII table 51-48=3
			return (pointValue()*credit);
		}
};

int main()
{
	Subject s1;
	string name, code;
	double score;
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin, name);;

	cout << "  Subject code => ";
	cin >> code;

	cout << "  Score earned => ";
	cin >> score;

	cout << endl
		 << endl;  
		 
	s1.setName(name);				//set into the mutator in the class
	s1.setCode(code);
	s1.setScore(score);
	

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " << code << endl;
	cout << "Subject Name : " << name << endl;
	cout << "Credit Hour  : " << (s1.pointEarned() / s1.pointValue()) << endl;			//call back all the datas from the class
	cout << "Score Earned : " << score << endl;
	cout << "Grade Earned : " << s1.gradeEarned() << endl;
	cout << "Grade Point  : " << s1.pointValue() << endl;
	cout << "Point Earned : " << s1.pointEarned() << endl;
	cout << endl;

	return 0;
}
