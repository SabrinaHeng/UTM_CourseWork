#include<iostream>
#include<string>
using namespace std;

class Line{
	private :
		int m,c;
		
	public :
		Line(int _m = 1, int _c = 0){
			m = _m;
			c = _c;
		}
		
		void read(){
			cout << "Enter the slope (m) and y-intercept of a line (c) =>";
			cin >> m;
			cin >> c;
		}
		
		Line operator-(Line &right){
//			return Line(m-right.m,c-right.c);
			
			Line line;
			
			line.m = m - right.m;
			line.c = c - right.c;
			
			return line;
		}
		
		bool operator!=(Line &line){
			if((m*line.m)!= -1){
				return true;
			}else{
				return false;
			}
		}
		
		string toString(){
			string str = "y=";
			
			if(m==1){
				str += "x";
				if(c>0){
					str += ("+" + to_string(c)); 
				} else if(c<0){
					str += to_string(c);
				}
			}else if(m==-1){
				str += "-x";
				if(c>0){
					str += ("+" + to_string(c)); 
				}else if(c<0){
					str += to_string(c);
				}
			}else{
				str += (to_string(m)+"x");
				if(c>0){
					str += ("+" + to_string(c)); 
				}else if(c<0){
					str += to_string(c);
				}
			}
			return str;
		}
		
		friend void printLines(Line obj[]){
			for(int i=0; i<3; i++){
				cout << "Line" << i+1 << "slope(m) = " << obj[i].m << ", y-intercept(c) = " << obj[i].c << ", equation : " << obj[i].toString() << endl;
			}
		}
};

int main(){
	Line line[3] = {Line(1,5)};	//array
	
	cout << "ORIGINAL LINES" << endl;
	printLines(line);
	
	cout << "\nSet the second line from user input" << endl;
	line[1].read();
	line[2] = line[0] - line[1];
	
	cout << "\nUPDATED LINES" << endl;
	printLines(line);
	
	if(line[0] != line[2]){
		cout << "\n\nThe first line is not perpendicular to the last line";
	}else{
		cout << "\n\nThe first line is perpendicular to the last line";
	}
	
	return 0;
}