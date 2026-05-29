#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
        	cout << "Insert " << newStud->getName() << "\n";
        	if(head == NULL || head->getName() > newStud->getName()){
        		newStud->setNext(head);
        		head = newStud;
        		if(last == NULL)
        		last = newStud;
			}else{
				Student*current = head;
				while(current->getNext() != NULL && current->getNext()->getName() < newStud->getName()){
					current = current->getNext();
				}
				newStud->setNext(current->getNext());
				current->setNext(newStud);
				if(newStud->getNext()==NULL){
					last = newStud;
				}
			}
        }
        
        Student *findNode(string name) {
        	Student *current = head;
        	
        	while(current != NULL){
        		if(current->getName() == name){
        			return current;
				}
				current = current->getNext();
			}
            return NULL;
        }
        
        void deleteNode(string name) {
            Student *stud, *prev;
			stud = head;
			
			if (stud != NULL && stud->getName() == name) {
		        head = stud->getNext(); 
		        if (head == nullptr) last = nullptr; 
		        delete stud;
		        return;
    		}
    		
    		while (stud != NULL && stud->getName() != name) {
		        prev = stud; 
		        stud = stud->getNext(); 
		    }
		    
		    if (stud == NULL) return;
		    
		    prev->setNext(stud->getNext());
		    if (stud == last) last = prev;
		    delete stud;
        }
        
        void displayList() {
        	Student *stud = head;
        	
        	while (stud != NULL) {
        		stud->printResult();
        		stud = stud->getNext();
			}
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
        	Student *stud = head;
        	cout << "Destroy list...\n";
        	while (stud != NULL) {
        		Student *prevStud = stud;
        		stud = stud->getNext();
        		delete prevStud;
			}
		}
};
