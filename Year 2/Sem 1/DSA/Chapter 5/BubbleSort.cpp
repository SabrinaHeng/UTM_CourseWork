#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void listItem(int d[], int listSize) {
    for (int x = 0; x < listSize; x++) {
        cout << d[x] << " ";
    }
    cout << "\n";
}

void BubbleSort(int d[], int listSize) {
    for (int x = 0; x < listSize; x++) {
    	if(d[x]>d[x+1]){
    		int temp = d[x];
    		d[x] = d[x+1];
    		d[x+1] = temp;
    		
    		listItem(d,4);
		}

//       cout << x << "\n";
       
    }
}

// Main function section
int main() {
  int data[4] = {12, 8, 3, 21}; // average case
  //int data[4] = {21, 12, 8, 3}; // worst case
  //int data[4] = {3, 8, 12, 21}; // best case
  
  listItem(data, 4);
  BubbleSort(data, 4);
  //listItem(data, 4);
  
  return 0;
}
