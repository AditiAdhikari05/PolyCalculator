//============================================================================
// Name         : Polynomial Calculator. cpp 
// Author       : Aditi Adhikari
// Version      : 3.0
// Date Created : 20-02-2025
// Date Modified: 3-03-2025
// Description  : Polynomial Calculator in C++ using Singly Linked-List
//============================================================================
#include "polycalculator.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

//method to input polynomial
void PolyCalculator::input(){
    
    string l1; //taking input as a string
	string l2;
    
// condition to check if input is right or not in a loop
    while(true){
        list1.removeAll(); //removing all the previously return input
        cout<<"Enter first Polynomial expression: ";
        getline(cin, l1);
        
        if(parse(l1,list1)){ //if input is in correct format then the loop will be stopped
            break;
        };
        
    }
    //loop to check if 2nd input is right or not
    while(true){
        list2.removeAll(); //removing all the previously return input
        cout<<"Enter second Polynomial expression: ";
        getline(cin, l2);
        
        
        if(parse(l2,list2)){//if input is in correct format then the loop will be stopped
            break;
        }
    }
}

//method to display input
void PolyCalculator::display(std::ostream &os){
    
    //checking if the linked list are empty or not
    if(list1.head==NULL && list2.head==NULL){
        cout<<"Exp1: "<<endl; //if there is nothing in the linked list printing exmpyt linked list
        cout<<"Exp2: "<<endl;
    }
    else{
        cout<<"Exp1:";
        list1.print(os); //printing what is in 1st polynopmial
        cout<<endl;
        cout<<"Exp2:";
        list2.print(os); //printing what is in 2nd polynopmial
        cout<<endl;
    }
}


//method to adding two polynomials
void PolyCalculator::add(){

	Node* tmp1=list1.head; //assigning or making new pointer tmp1 to store list1's head
	Node* tmp2=list2.head; //assigning or making new pointer tmp1 to store list2's head
	int sum; //integer to save sum
    list3.removeAll(); //removing all the nodes list3 already has

	while(tmp1!=NULL && tmp2!=NULL){ //will run untill one of the pointer reaches null/end of the node
		if(tmp1->expo > tmp2->expo){ //if exponent of 1st linked list is greater than expo of 2nd linked list then 1st component of 1st linked list will be added to the list3
			list3.insert(tmp1->coef,tmp1->expo);
			tmp1=tmp1->next; //moving pointer to next
		}
        
		else if(tmp2->expo > tmp1->expo){ //if exponent of 2nd linked list if greater than 1st then component of 2nd linked list will be added to the lis3
			list3.insert(tmp2->coef,tmp2->expo);
			tmp2=tmp2->next; //moving pointer to the next pointer
		}
        
		else{
			sum=tmp1->coef+ tmp2->coef; //adding the coefficient of like terms
			if(sum!=0){ //deleting  or not adding coefficient in the linked list that is 0 
				list3.insert(sum,tmp1->expo);
				}
            tmp1=tmp1->next;
            tmp2=tmp2->next;

			}

		}
    
    //once one of the linked list reach Null pointer the above loop will break so we still need to add the remaning component is there is any
    while(tmp1!= NULL){ //adding remaning component from list 1 if any
        list3.insert(tmp1->coef,tmp1->expo);
        tmp1=tmp1->next;
    }
    
    while(tmp2!= NULL){ //adding remaning component from list 1 if any
        
        list3.insert(tmp2->coef,tmp2->expo);
        tmp2=tmp2->next;
    }
    
    if (list3.head==NULL){
        cout<<"Nothing in the linked list 3"<<endl;
    }
    else{
        cout<<"Exp1 + Exp2=";
        list3.print(); //printing the addition of list 1 and list 2
        cout<<endl;
        
    }
}

//method to multiply the exponent
void PolyCalculator::mul(){

    Node* tmp1= list1.head; //creating node pointer to save head of list1 and do a loop
    Node* tmp2= list2.head;  //creating node pointer to save head of list1 and do a loop
    int coef_mul; // creating vairable to save coef after multiplying
    int expo_mul; // creating vairable to save exponent after multiplying
    
    list3.removeAll(); //removing everything from list 3 to save new components
    
    if(tmp1==NULL || tmp2==NULL){ //checking if one of the linked list is empty or not
        cout << "Linked list(s) is empty  can't multiply"<< endl;
        
    }
    else{ //if not empty this things will be done
        tmp1 = list1.head;
        
        while(tmp1 !=NULL){
            tmp2 = list2.head; //starting tmp2 from the beginning of the list2
            while(tmp2 !=NULL){
                coef_mul=(tmp1->coef)*(tmp2->coef); //saving new coef
                expo_mul=(tmp1->expo)+(tmp2->expo); //saving new exp
                list3.insert(coef_mul,expo_mul); //inserting multiplied coef and exponent
                tmp2=tmp2->next; //moving the pointer of list2
            }
            tmp1=tmp1->next; //moving the pointer of list 1
        }
    }
    
    if(list3.head==NULL){ //if nothing was saved in the list3 maybe because they canceled each other or some reason then this will be printed
        cout<<"Nothing in the linked list"<<endl;
    }
    else{ //printing the answer after multiplication
        cout<<"Exp1 * Exp2 =";
        list3.print();
        cout<<endl;
        }
    }


//method to evaluate the polynomial at certain value
void PolyCalculator::evaluate(int ExprID, int x){
	int sum=0; //staring sum integer from 0
    
	if(ExprID==1){ //if given polynomial to be evaluted is 1
		cout<<"p(x) = ";
		list1.print(); //printing list 1

		Node* ptr=list1.head;
		while(ptr!=NULL){ //doing loop to evaluate the polynomial at the given value
			sum=(ptr->coef)*pow(x,(ptr->expo));
            ptr=ptr->next;
		}
		cout<<"p("<<x<<") = "<<sum<<endl; //printing the polynomial at the given value
	}
	else if(ExprID==2){ //if given polynomial is 2
        cout<<"p (x) = ";
        list2.print();
        Node* ptr=list1.head;
		while(ptr!=NULL){
			sum=(ptr->coef)*(x)^(ptr->expo);
			ptr=ptr->next;
		}
	cout<<"p("<<x<<") = "<<sum<<endl; //printing the polynomial at the given value

	}
    else{
        cout<<"Invalid input"<<endl; //if the id is not 1 or 2 we don't have poilynomial more than 2
    }
}

// method to get the degree of polynomial
int PolyCalculator::getDegree(int expID){
	int degree; //vairable to store degree

	if (expID==1){
		degree= list1.head->expo; //since we have sorted the linked list in descending order degree will be the expo of node next to head
        return degree;
	}
	else if (expID==2){
		degree= list2.head->expo; //since we have sorted the linked list in descending order degree will be the expo of node next to head
        return degree;

	}
	return -1;  // indicating an error or invalid expID
}

//method to check if two polynnomial are equal or not
void PolyCalculator::isEqual(){
	if(list1==list2){ //this will call equalto method of linked list
		cout<<"Both polynomials are identical"<<endl;
	}
	else{
		 cout<<"The polynomials aren't the same"<<endl;
	}
}

//method to read data from a file
void PolyCalculator::readData(std::string filename){
    bool valid1=false; // boolean vairables to see if the provided file has proper input format or not
    bool valid2=false;

    list1.removeAll();// removing everything from list 1 and list 2 before adding new nodes
    list2.removeAll();

	// Opening the file for reading
    ifstream fin(filename);
    string l1;
    string l2;
    
    // Check if the file is successfully opened
    if(fin.fail()){
        perror("Error opening file");
        return;
    }
   
    // Read line 1 from the file
    if(getline(fin, l1)){
        valid1=parse(l1,list1); //check if the input is in correct format or not
    }
    // Read line 2 from the file
    if(getline(fin, l2)){
        valid2=parse(l2,list2); //check if the input is in correct format or not
    }
    
    if(!(valid1||valid2)){ //if the input are not valid it will remove all the nodes from the list
        cout<<"Invalid inputs"<<endl;
        list1.removeAll();
        list2.removeAll();
    }
    
    // Close the file after reading all the data
    fin.close();

}

//method to write polynomial data to a file
void PolyCalculator::writeData(std::string filename) {
    // Open the file for writing
    string filename_1="./"+filename;
    std::ofstream fout(filename_1);

    // Check if the file is successfully opened
    if (!fout.is_open()) {
        perror("File not found");
        
    }
    else{
        if (list1.head==NULL || list2.head == NULL) {  // Check if the linked list is empty
            cout<<"There is nothing in the linked list to write in the file"<<endl;
        }
        else {
            fout<<"Exp1= ";
            list1.print(fout); //write list 1 in the file
            fout<<"\n"<<"Exp2= ";
            list2.print(fout); //write list 2 in the file
            fout<<"\n"<<"Exp1 + Exp2= ";
            cout.setstate(ios_base::failbit); // to avoid printing in the terminal
            add(); // adds list 1 and list 2 and save it to list 3
            cout.clear();
            list3.print(fout); // //write added value of list 1 and list2 in the file
            fout<<"\n"<<"Exp1 * Exp2= ";
            cout.setstate(ios_base::failbit);
            mul(); //multiply list 1 and list 2 and saves it in list 3
            list3.print(fout); //write multiplied value of list 1 and list2 in the file
            fout<<"\n"<<"The degree of Exp1 is: ";
            fout<<getDegree(1); //write the degree of polynomial 1
            fout<<"\n"<<"The degree of Exp2 is: ";
            fout<<getDegree(2); //write the degree of polynomial 2
            cout.clear();
            cout<<filename<<" has been created sucessfully"<<endl; //indicating that file has beenn created
        }
        
    }

    // Closing the file
    fout.close();
}

//parse function to identify and sent coef and expo of the polynomial to insert function
bool PolyCalculator::parse(std::string str, LinkedList& list){
	stringstream sstr(str); // help us read the string like a file
	int coef; // variable to store coef of the polynomial
	int expo;  // variable to store exponent of the polynomial
	char dummy; // to store garbage
	bool valid=true; //to check if the input is in correct format or not

	while(not sstr.eof()){ //will be true until the end of the line is reached
		sstr>>coef; //to save coefficient
		sstr>>dummy; //for storing x

		if (dummy !='x'){ //checking if it's x or not else invalid input
			valid=false;
		}
        
        sstr>> dummy; // for storing ^ sign

		if(dummy !='^'){ //checking if it's expontent sign or not else invalid input
			valid=false;
		}
		sstr>>expo; //to save exponent

		if(!valid){ // if the input is not valid
            return false;
			break;
		}
        else{
            list.insert(coef,expo); //passing it to insert function
        }
	} 

    return true; //returning true if there is no error
}
