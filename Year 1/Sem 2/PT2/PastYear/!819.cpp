#include<iostream>
#include<iomanip>
using namespace std;

class SpeedDistanceTime{
	private :
		int startHours,startMinutes,endHours,endMinutes;
		double timeTaken,distance,speed;
		void calcTimeTaken(){
			double h,m;
			
			h = endHours;
			if(startMinutes > endMinutes){
				endMinutes += 60;
				h--;
			}
			
			h -= startHours;
			m = endMinutes - startMinutes;
			timeTaken = h+(m/60);
		}
		double calcDistance(){
			distance = timeTaken * speed;
		}
		
	public :
		SpeedDistanceTime(double t = 0,double d = 0){
			timeTaken = t;
			distance = d;
		}
		
		double operator+(const SpeedDistanceTime &other){
			return distance + other.distance;
		}
		
		friend ostream &operator<<(ostream &out, const SpeedDistanceTime &obj){
			out << "Time taken = " << fixed << showpoint << setprecision(2) << obj.timeTaken << " hour(s)" << endl;
			out << "Speed      = " << fixed << showpoint << setprecision(2) << obj.speed << " km/h" << endl;
			out << "Distance   = " << fixed << showpoint << setprecision(2) << obj.distance << " km" << endl;
			return out;
		}
		
		friend void readInput(SpeedDistanceTime &obj){
			char opr;
			cout << "Enter start time and end time using 24-hour time format (hh:mm)" << endl;
			cout << "\tStart time = ";
			cin >> obj.startHours;
			cin >> opr;
			cin >> obj.startMinutes;
			
			cout << "\tEnd time   = ";
			cin >> obj.endHours;
			cin >> opr;
			cin >> obj.endMinutes;
			obj.calcTimeTaken();
			cout << endl << endl;	
			cout << "Enter speed in km/h = ";
			cin >> obj.speed;
			obj.calcDistance();
		}
};

int main(){
	SpeedDistanceTime obj1;
	SpeedDistanceTime obj2;
	
	cout << "Input for Object 1" << endl;
	readInput(obj1);
	
	cout << "\nInput for Object 2" << endl;
	readInput(obj2);
	
	cout << endl << endl;
	cout << "** OUTPUT **" << endl;
	cout << "Object 1 :" << endl;
	cout << obj1 << endl << endl;
	cout << "Object 2 :" << endl;
	cout << obj2 << endl << endl;
	
	cout << "Total distance for Object 1 and 2 = " << obj1 + obj2 << " km" << endl;
}

