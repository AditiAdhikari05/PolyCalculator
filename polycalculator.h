//============================================================================
// Name         : Polynomial Calculator 
// Author       : Khalid Mengal
// Version      : 1.0
// Date Created : 25-08-2022
// Date Modified: 30-08-2022 
// Description  : Polynomial Calculator in C++ using Singly Linked-List
//============================================================================

#ifndef POLYCALCULATOR_H
#define POLYCALCULATOR_H
#include<iostream>
#include<fstream>
#include<string>
#include "linkedlist.h"
//=======================================
class PolyCalculator
{
	private:
		LinkedList list1;
		LinkedList list2;
        LinkedList list3;
        
	public:
		void input(); //take input the values of polynomial expressions
		void display(std::ostream &os=std::cout); //display both polynomials (list1 and list2)
		void add();  // Adds list1 and list2 and stores the result in list3
		void mul(); // Multiplies list1 and list2 and stores the result in list3
		void evaluate(int expID, int x); //evalutes both polynomials for a given value of x
		int getDegree(int expID);	//returns the degree of a polynomial
		void isEqual(); //checks if both polynomials are identical or not
		void readData(std::string path); //read a file and load the data into the linked lists (list1 and list2)
		void writeData(std::string path); //write the polynomial expressions and the results of addition,subtraction and multiplication to a file
		bool parse(std::string expr,LinkedList& list);	// Parses a string and saves the terms to a linked list. Returns true if valid, false otherwise
    
};
#endif


