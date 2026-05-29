#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() { 
  cout << "Test file operation (binary and text)\n";
  
  // open input files "Bignum.txt" and "Bignum.dat" 
  // respectively in text and binary mode 
  fstream outTxt("Bignum.txt",ios::in);
  fstream outBin("Bignum.dat",ios::in|ios::binary);


  // read and print the input from "Bignum.txt"
  while(!outTxt.eof()){
  	char c = outTxt.get();
  	cout << c;
  }

  cout << "\n";
  int num;
  cout << sizeof(num) << "\n";
  
  // read and print the input from "Bignum.dat"
  while(!outBin.eof()){
  	outBin.read((char *)&num,sizeof(num));
  	cout << num <<"\n";
  }
  
  return 0;

}