//============================================================================
// Name         : Polynomial Calculator (linkedlist.cpp)
// Author       : Aditi Adhikari
// Version      : 3.0
// Date Created : 25-02-2025
// Date Modified: 3-03-2025
// Description  : Linked List class used for Polynomial Calculagtor
//============================================================================
#include "linkedlist.h"
#include<iostream>

using namespace std;

//constructor
LinkedList::LinkedList(){
	head=NULL;  //creating a linked list with head pointing to Null
}

//method to insert coef and exponent and sort it
void LinkedList::insert(int coef, int expo) {
    Node* tmp = head; // node pointer to save head
    Node* tmp2;
    
    if (head == NULL) { //if there is nothing in the list
        head = new Node(coef, expo);
        return;
    }

    // Insert at the head if new term has a higher degree than what's already there
    if (head->expo < expo) {
        Node* newNode = new Node(coef, expo); //creating new node
        newNode->next = head; // newNode will point to what head was pointing to
        head = newNode; //head will point to new node
        return;
    }

    // Merge if the exponent already exists at the head
    if (head->expo == expo) {
        head->coef += coef;
        return;
    }

    // Traverse the list to find the correct insertion point
    while (tmp->next != NULL && tmp->next->expo > expo) {
        tmp = tmp->next;
    }

    // If the exponent already exists, update the coefficient
    if (tmp->next != NULL && tmp->next->expo == expo) {
        tmp->next->coef += coef;
        return;
    }

    // Insert a new node if none of the condition above is met
    tmp2 = new Node(coef, expo);
    tmp2->next = tmp->next;
    tmp->next = tmp2;
}

//method to print polynomial
void LinkedList::print(ostream& os) const{
    
    if (head==NULL){ //if there is nothing in the linked list printing nothing
        return;
    }
    
	else{
		Node* tmp=head;
		while(tmp!=NULL){ //going through a loop till the end is meet
            if(tmp->coef>0){ //if the coefficeint is positive then this will be printed
                os<<"+"<<tmp->coef<<"x^"<<tmp->expo;
            }
            
            else{ // if the coeff is negative this will be printed
                os<<tmp->coef<<"x^"<<tmp->expo;
            }
		tmp=tmp->next; //moving the pointer to next
        }
	}
}

//method to check if the polynomial are equal or not
bool LinkedList::operator==(const LinkedList &other){

	Node* tmp1=head; //pointer to save self's head
	Node* tmp2=other.head; //pointer to save another linked list head
    
    if(tmp1==NULL || tmp2==NULL){ //if there is nothing in the list then return
        cout<<"Linked list(s) is empty. Can't evaluate"<<endl;
        return false;
    }
    
    while(tmp1!=NULL && tmp2!=NULL){ // to run till one of the linked list reaches to end end
        if(tmp1->expo!= tmp2->expo || tmp1->coef != tmp2->coef){ // check if the expo and coef matches or not
            return false;
        }
        tmp1=tmp1->next; //moving to the next node
        tmp2=tmp2->next; //moving to the next node
    
    }
    
    if (tmp1==NULL && tmp2==NULL){ //checking if they have the same number of nodes or not if not then they are not same
        return true;
    }
    else{
        return false;
    }
}

//method to remove all of the nodes from the linked list
void LinkedList::removeAll(){
    
	if(head==NULL){ // if there is nothing then removing nothing
        return;
	}
	else{
		while(head!=NULL){ //doing a loop till the end
			removeFront(); // removing first element in a loop till everything is cleared

		}
	}
}

//method to remove front node of the linked list
void LinkedList::removeFront(){
		Node* tmp=head; 	//creating temporary pointer of data type node to store the location where head points to
		head= (*head).next; //changing the point where head points to or making head point to the location where 1st node point to
		delete tmp; //deleting the first node
}

//deconstructor
LinkedList::~LinkedList(){
	removeAll();
}


