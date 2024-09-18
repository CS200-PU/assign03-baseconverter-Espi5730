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
string getNumber (const string& prompt);
char getbase (const string& strNumber);
void decimalOperations ();
void binaryOperations ();
void hexadecmialOperations ();

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
  const char BINARY = 'B';
  const char HEXADECIMAL = 'H';
  const char DECIMAL = 'D';

  //vars
  string userInput;
  char currentBase;
  int inputLength = 0;

  printTitle(HEADING);
  userInput = getNumber(PROMPT);
  inputLength = userInput.length();

  //main block
  
  while (!(QUIT == userInput[0] && 1 == inputLength))
  {

    currentBase = getbase(userInput);

    if (BINARY == currentBase)
    {
      binaryOperations();
    }
    else if (HEXADECIMAL == currentBase) {
      hexadecmialOperations();
    }
    else {
      decimalOperations();
    }  

    cout << endl;  

    userInput = getNumber(PROMPT);
    inputLength = userInput.length();
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

  return userInput;
}

/****************************************************************************
 Function:    	getBase

 Description: 	find which base the input string is

 Parameters:  	strNumber - message displayed to user
 
 Returned:    	string - user inputed string to convert
 ****************************************************************************/

char getbase (const string& strNumber) {
  //consts
  const char INPUT_BINARY = 'b';
  const char INPUT_HEXACDECIMAL = 'x';

  const char RETURN_DECIMAL = 'D';
  const char RETURN_HEXACDECIMAL = 'H';
  const char RETURN_BINARY = 'B';

  char userInput;

  // if length is 1, return decimal

  if (strNumber.length () == 1) {
    return RETURN_DECIMAL;
  } else {
    // if length greater then 2, check at second index
    userInput = strNumber[1];
    if (INPUT_HEXACDECIMAL == userInput)
    {
      return RETURN_HEXACDECIMAL;
    } 
    else if (INPUT_BINARY == userInput) {
      return RETURN_BINARY;
    } 
    else {
      return RETURN_DECIMAL;
    }
  }
}

/****************************************************************************
 Function:    	hexCharToInt

 Description: 	returns Decimal equivalent to Hex Digit Input

 Parameters:  	hexDigit - inputed hex digit
 
 Returned:    	int 
 ****************************************************************************/
int hexCharToInt (char hexDigit) {
  const int LOWER_DECIMAL_ASCII = 48;
  const int UPPER_DECIMAL_ASCII = 57;
  int returnInt = 0;

  if (hexDigit > LOWER_DECIMAL_ASCII && hexDigit < UPPER_DECIMAL_ASCII) {
    cout << "is decimal";
  }

  return returnInt;
}


/****************************************************************************
 Function:    	decimalOperations

 Description: 	runs all relevant operations for a decimal input

 Parameters:  	none
 
 Returned:    	none
 ****************************************************************************/
void decimalOperations () {
  string binaryNum = "BINARY";
  string hexaNum = "HEXA";

  //calc binary and hexadecimals numbers

  //output
  cout << "The binary conversion is: 0b" << binaryNum << endl;
  cout << "The hexadecimal conversion is: 0x" << hexaNum << endl;
  
}

/****************************************************************************
 Function:    	binaryOperations

 Description: 	runs all relevant operations for a binary input

 Parameters:  	none
 
 Returned:    	none
 ****************************************************************************/
void binaryOperations () {
  string decimalNum = "DECIMAL";
  string hexaNum = "HEXA";

  //calc binary and hexadecimals numbers

  //output
  cout << "The decimal conversion is: " << decimalNum << endl;
  cout << "The hexadecimal conversion is: 0x" << hexaNum << endl;
}

/****************************************************************************
 Function:    	hexadecmialOperations

 Description: 	runs all relevant operations for a hexadecmial input

 Parameters:  	none
 
 Returned:    	none
 ****************************************************************************/
void hexadecmialOperations () {
  string decimalNum = "DECIMAL";
  string binaryNum = "BINARY";
  

  //calc binary and hexadecimals numbers

  //output
  cout << "The decimal conversion is: " << decimalNum << endl;
  cout << "The binary conversion is: 0b" << binaryNum << endl;
}