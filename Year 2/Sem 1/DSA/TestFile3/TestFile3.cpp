#include<iostream>
#include<fstream>
using namespace std;

int main() { 
  cout << "Test file operation (binary and text)\n";
  
  // open output files "Bignum.txt" and "Bignum.dat" 
  // respectively in text and binary mode 
    fstream outfile("Bignum.txt",ios::out);
    fstream out("Bignum.dat",ios::out|ios::binary);
	
//	outfile.open("Bignum.txt",ios::out);
//	out.open("Bignum.dat",ios::out|ios::binary);


  // write the numbers 10, 11, ..., 90 million into 
  // "Bignum.txt" and "Bignum.dat" 
  for (int i = 1; i < 10; i++) {
    int num = i * 10000000;
    cout << num << "\n";
    outfile << num << "\n";
    out.write(reinterpret_cast<char *>(&num),sizeof(num));
  }
  
  outfile.close();
  out.close();
  
  return 0;
}