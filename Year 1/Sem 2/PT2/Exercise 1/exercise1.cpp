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

class Data {
	private :
	string name;						//Attribute
	string code;						//Attribute
	int score;							//Attribute

	public :
	Data(string n,string c,int s){		//Constructor
		name = n;
		code = c;
		score = s;
	}
	Data(){							//Default Constructor
		name = "";
		code = "";
		score = 0;
	};							

	~Data(){};							//Destructor

	//Mutator
	void setName(string n){
		name = n;
	}
	void setCode(string c){
		code = c;
		
	}
	void setScore(int s){
		score = s;
	}
	//Accessor(In constant) 
	string getName()const {
		return name;
	}
	string getCode()const {
		return code;
	}
	int getScore()const {
		return score;
	}

	//Three more accessor
	string displayGrade ()const{
		if (score>=90){
			return "A+";
		}else if(score>=80){
			return "A";
		}else if(score>=75){
			return "A-";
		}else if(score>=70){
			return "B+";
		}else if(score>=65){
			return "B";
		}else if(score>=60){
			return "B-";
		}else if(score>=55){
			return "C+";
		}else if(score>=50){
			return "C";
		}else if(score>=45){
			return "C-";
		}else if(score>=40){
			return "D+";
		}else if(score>=35){
			return "D";
		}else if(score>=30){
			return "D-";
		}else{
			return "E";
		}
	}

	double calculatePointValue (){
		if(score>=80){
			return 4.00;
		}else if(score>=75){
			return 3.67;
		}else if(score>=70){
			return 3.33;
		}else if(score>=65){
			return 3.00;
		}else if(score>=60){
			return 2.67;
		}else if(score>=55){
			return 2.33;
		}else if(score>=50){
			return 2.00;
		}else if(score>=45){
			return 1.67;
		}else if(score>=40){
			return 1.33;
		}else if(score>=35){
			return 1.00;
		}else if(score>=30){
			return 0.67;
		}else{
			return 0.00;
		}
	}

	double calculatePointEarned(int creditHours){
		return calculatePointValue() * creditHours; 
	}

};

int main()
{
	string subjectName,code;
	int score,creditHours;
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin,subjectName);

	cout << "  Subject code => ";
	getline(cin,code);

	cout << "  Score earned => ";
	cin >> score;

	creditHours = code[code.length()-1]-'0';	//"-0" is to convert from string to int

	Data subject(subjectName,code,score);
	cout << endl <<endl;
	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " << subject.getCode() << endl;
	cout << "Subject Name : " << subject.getName() << endl;
	cout << "Credit Hour  : " << creditHours << endl;
	cout << "Score Earned : " << subject.getScore() << endl;
	cout << "Grade Earned : " << subject.displayGrade() << endl;
	cout << "Grade Point  : " << subject.calculatePointValue() << endl;
	cout << "Point Earned : " << subject.calculatePointEarned(creditHours) << endl;

	system("pause");

	return 0;
}

