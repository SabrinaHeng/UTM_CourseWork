#include <iostream>
#include <string>
using namespace std;

//create a base class
class Student{
	protected:
		string name;
		string matric;
		string program;
		
	public:
		Student(string name,string matric,string program):name(name),matric(matric),program(program){}
		
	//accessor
	string getName() const { return name; }
    string getMatric() const { return matric; }
    string getProgram() const { return program; }
    
    //mutator
    void setName(string name) { this->name = name; }
    void setMatric(string matric) { this->matric = matric; }
    void setProgram(string program) { this->program = program; }
};

class Undergraduate: public Student
{
private:
    double cgpa;

public:
    Undergraduate(string name, string matric, string program, double cgpa):Student(name,matric,program),cgpa(cgpa){}

    double getCGPA() const { return cgpa; }

    void setCGPA(double cgpa) { this->cgpa = cgpa; }

    void print() const
    {
        cout << "UNDERGRADUATE STUDENT INFORMATION:" << endl;
        cout << "Name       : " << name << endl;
        cout << "Matric     : " << matric << endl;
        cout << "Program    : " << program << endl;
        cout << "CGPA       : " << cgpa << endl;
        cout << endl;
    }
};

class Postgraduate: public Student
{
private:
    string project;
    string supervisor;

public:
    Postgraduate(string name, string matric, string program, string project,string supervisor):Student(name,matric,program),project(project),supervisor(supervisor){}

    string getProject() const { return project; }
    string getSupervisor() const { return supervisor; }

    void setProject(string project) { this->project = project; }
    void setSupervisor(string supervisor) { this->supervisor = supervisor; }

    void print() const
    {
        cout << "POSTGRADUATE STUDENT INFORMATION:" << endl;
        cout << "Name       : " << name << endl;
        cout << "Matric     : " << matric << endl;
        cout << "Program    : " << program << endl;
        cout << "Project    : " << project << endl;
        cout << "Supervisor : " << supervisor << endl;
        cout << endl;
    }
};

//? The main function is provided only for testing the classes.
//? Do nothing on this funciton.

int main()
{
    Undergraduate ug("Razali Hamzah", "A22CS1234", "Bachelor of Computer Science", 3.80);
    Postgraduate pg("Siti Nurhazila", "PCS20124",  "Master of Education Engineering", "Futuristic T&L in Metaverse", "Prof. Dr. Kamarul");

    ug.print();

    cout << endl;
    pg.print();

    cin.get();
    return 0;
}