// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Sabrina Heng Wei Qi
// 2. Tan Zhi Ming
// 3. Woo Cheng Shuan

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// function headers
void listStudent(Student* [], int);
void listByName(Student* [], int);
void listByGrade(Student* [], int);

// main function
int main() {
    const int LIST_SIZE = 10;
    string name;
    int cw, fe, idx = 0;
    Student* studList[LIST_SIZE];

    fstream fileIn("Marks.txt", ios::in);

    if (!fileIn) {
        cout << "File input/output error!\n";
        return 1;

    } else {
        while (fileIn >> name >> cw >> fe) {
            studList[idx] = new Student(name, cw, fe);
            idx++;
        }
        
        int opt = 0;

        while (opt != 4) {
            cout << "\n1. List results (original list)";
            cout << "\n2. List results (sort by name)";
            cout << "\n3. List results (sort by grade)";
            cout << "\n4. Exit\n\n";
            
            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;
            
            if (opt == 1) {
                listStudent(studList, idx);
            }
			
			if (opt == 2){
            	listByName(studList, idx);
			}
            
            if (opt == 3){
            	listByGrade(studList, idx);
			}
            
            if (opt != 4) system("pause");
        }

        fileIn.close();
    }

    return 0;
}

// function implementation
void listStudent(Student* sl[], int size) {
    for (int i = 0; i < size; i++) {
        sl[i]->printResult();
    }
}

void listByName(Student* sl[], int size){
	int insertIndex;
	Student* item;
	
	for(int i = 1; i< size; i++){
		insertIndex = i;
		item = sl[i];
		while((insertIndex > 0) && (sl[insertIndex-1]->getName() > item->getName())){
			sl[insertIndex] = sl[insertIndex-1];
			insertIndex--;
		}
		sl[insertIndex] = item;
	}
	
	for(int i=0; i<size; i++){
		sl[i]->printResult();
	}
}

void listByGrade(Student* sl[], int size){
	int insertIndex;
	Student* item;
	
	for(int i = 1; i< size; i++){
		insertIndex = i;
		item = sl[i];
		while((insertIndex > 0) && (sl[insertIndex-1]->getGrade() > item->getGrade())){
			sl[insertIndex] = sl[insertIndex-1];
			insertIndex--;
		}
		sl[insertIndex] = item;
	}
	
	for(int i=0; i<size; i++){
		sl[i]->printResult();
	}
}
