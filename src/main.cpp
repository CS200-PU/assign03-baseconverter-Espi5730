//******************************************************************************
// File name:   main.cpp
// Author:      Matthew Espinoza
// Date:        09/13/2024
// Class:       CS200-01 
// Assignment:  Homework 3
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include "string.h"

using namespace std;



// function prototypes
void printTitle (const string& myTitle);
string getNumber(const string& prompt);
char getbase(const string& strNumber);

/****************************************************************************
 Function:    	main

 Description: 	Base System Converter

 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/

int main () {

  //constants
  const string HEADING = "HEX-DECIMAL-BINARY CONVERTER";
  const string PROMPT = "Enter your string to convert (q to quit): ";
  const char QUIT = 'q';

  //vars

  string userInput;
  int inputLength = 0;

  printTitle(HEADING);

  userInput = getNumber(PROMPT);

  inputLength = userInput.length();
  cout << inputLength;
  
  while (!(QUIT == userInput[0] && 1 == inputLength))
  {
    userInput = getNumber(PROMPT);
    inputLength = userInput.length();
    cout << inputLength;
  }
  
  return EXIT_SUCCESS;
}

/****************************************************************************
 Function:    	printTitle

 Description: 	Displays program title

 Parameters:  	myTitle - title that is being displayed
 
 Returned:    	None
 ****************************************************************************/

void printTitle (const string& myTitle) {
  cout << "**************************************" << endl;
  cout << "*****" << myTitle << "*****" << endl;
  cout << "**************************************" << endl;
}

/****************************************************************************
 Function:    	getNumber

 Description: 	gets user input string

 Parameters:  	prompt - message displayed to user
 
 Returned:    	string - user inputed string to convert
 ****************************************************************************/
string getNumber(const string& prompt) {
  string userInput;

  cout << prompt;
  cin >> userInput;
  cout << endl;

  return userInput;
}

/****************************************************************************
 Function:    	getBase

 Description: 	find which base the input string is

 Parameters:  	strNumber - message displayed to user
 
 Returned:    	string - user inputed string to convert
 ****************************************************************************/

char getbase(const string& strNumber) {

  char tmp = 'a';
  // example code for splicing 
  

  return tmp;
}