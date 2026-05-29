#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class WordNumber{
	private :
		string data,other;
		int num;

	public : 
		WordNumber(string d = "zero"){
			data = d;
		}
		
		WordNumber(int n = 0){
			num = n;
			
			switch (num){
				case 0 :  data = "zero";
							break;
							
				case 1 :  data = "one";
							break; 
				
				case 2 :  data = "two";
							break;
						
				case 3 :  data = "three";
							break;
							
				case 4 :  data = "four";
							break;
							
				case 5 :  data = "five";
							break;
							
				case 6 :  data = "six";
							break;
							
				case 7 :  data = "seven";
							break;
							
				case 8 :  data = "eight";
							break;
				
				case 9 :  data = "nine";
							break;
						
				default :  data = "";
							break; 
			}
		}
		
		void setWord(string d){
			data = d;
		}
		
		int toStringint(){
			int n;
			if(data == "zero"){
				n = 0;
			}else if (data == "one"){
				n = 1;
			}else if (data == "two"){
				n = 2;
			}else if (data == "three"){
				n = 3;
			}else if (data == "four"){
				n = 4;;
			}else if (data == "five"){
				n = 5;
			}else if (data == "six"){
				n = 6;
			}else if (data == "seven"){
				n = 7;
			}else if (data == "eight"){
				n = 8;
			}else if (data == "nine"){
				n = 9;
			}else {
				n = 0;
			}
			return n;
		}
		
		bool operator>(WordNumber &obj){
			if(toStringint() > obj.toStringint()){
				return true;
			}else{
				return false;
			}
		}
		
		int operator+(WordNumber &obj){
			return (toStringint(data) + toStringint(obj.data));
		}
		
		string operator+(const WordNumber &obj){
			string str = "";
			str += data + obj.other;
			return str;
		}
		
		WordNumber operator+(const WordNumber &other)const{
			WordNumber temp;
			int n = stringtoint() + other.stringtoint();
            string str;
                if(n==0)
                    str="zero";
                else if(n==1)
                    str="one";
                else if(n==2)
                    str="two";
                else if(n==3)
                    str="three";
                else if(n==4)
                    str="four";
                else if(n==5)
                    str="five";
                else if(n==6)
                    str="six";
                else if(n==7)
                    str="seven";
                else if(n==8)
                    str="eight";
                else if(n==9)
                    str="nine";
                    
                temp.data=str;
                return temp;
            } 
		}
};