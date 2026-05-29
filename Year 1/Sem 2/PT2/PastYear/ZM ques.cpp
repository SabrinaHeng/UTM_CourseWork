#include<iostream>
using namespace std;

class Point{
	private :
		int x,y;
	
	public :
		Point(int _x=0,int _y=0){
			x = _x;
			y = _y;
		}
		
		void setX(double _x){
			x = _x;
		}
		
		void setX(double _y){
			y = _y;
		}
		
		void getX()const{
			return x;
		}
		
		void getY()const{
			return y;
		}
		
		int operator+(Point &c){
			
			Point temp;
			temp.x = x + c.x;
			temp.y = y + c.y;
			
			return temp;
		}
		
		string toString(){
			string str = "(";
			
			str += (to_string(x) + ",")
			str += (to_string(y) + ")")
			
			return str;
		}
		
		//Copy Constructor
		Point(const Point &other){
			x = other.x;
			y = other.y;
		}
		
		friend class Calculation;
};

class Calculation{
	
};