//******************************************************************************
// File name:   main.cpp
// Author:      Matthew Espinoza
// Date:        09/13/2024
// Class:       CS200-01 
// Assignment:  Homework 3
// Hours:       0.25
//******************************************************************************

#include <algorithm>
#include <cmath>
#include <iostream>
#include "string.h"

using namespace std;



// function prototypes
void printTitle (const string& myTitle);
string getNumber (const string& prompt);
char getbase (const string& strNumber);
void decimalOperations (const string& strNumber);
void binaryOperations (const string& strNumber);
void hexadecmialOperations (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string binaryToDecimal (const string& strNumber);
string binaryToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);

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
  //const char DECIMAL = 'D';

  //vars
  string userInput;
  char currentBase;
  int inputLength = 0;

  printTitle (HEADING);
  userInput = getNumber (PROMPT);
  inputLength = userInput.length ();

  //main block

  while (!(QUIT == userInput[0] && 1 == inputLength)) {

    currentBase = getbase (userInput);

    if (BINARY == currentBase) {
      binaryOperations (userInput);
    }
    else if (HEXADECIMAL == currentBase) {
      hexadecmialOperations (userInput);
    }
    else {
      decimalOperations (userInput);
    }

    cout << endl;

    userInput = getNumber (PROMPT);
    inputLength = userInput.length ();
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
string getNumber (const string& prompt) {
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
  }
  else {
    // if length greater then 2, check at second index
    userInput = strNumber[1];
    if (INPUT_HEXACDECIMAL == userInput) {
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
  const char LOWER_DECIMAL = '0';
  const char UPPER_DECIMAL = '9';
  const char LOWER_DECIMAL_ALPHA = 'A';

  if (hexDigit >= LOWER_DECIMAL && hexDigit <= UPPER_DECIMAL) {
    return hexDigit % LOWER_DECIMAL;
  }
  else {
    return (hexDigit % LOWER_DECIMAL_ALPHA) + 10;
  }

}


/****************************************************************************
 Function:    	decimalOperations

 Description: 	runs all relevant operations for a decimal input

 Parameters:  	num - the number to convert

 Returned:    	none
 ****************************************************************************/
void decimalOperations (const string& strNumber) {
  string binaryNum = decimalToBinary (strNumber);
  string hexaNum = decimalToHex (strNumber);

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
void binaryOperations (const string& strNumber) {
  string decimalNum = binaryToDecimal(strNumber);
  string hexaNum = binaryToHex(strNumber);

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
void hexadecmialOperations (const string& strNumber) {
  string decimalNum = hexToDecimal(strNumber);
  string binaryNum = hexToBinary(strNumber);


  //calc binary and hexadecimals numbers

  //output
  cout << "The decimal conversion is: " << decimalNum << endl;
  cout << "The binary conversion is: 0b" << binaryNum << endl;
}

/****************************************************************************
 Function:    	decimalToBinary

 Description: 	takes a base 10 number and converts it to base 2

 Parameters:  	strNumber - the base 10 number

 Returned:    	the base 2 number
 ****************************************************************************/
string decimalToBinary (const string& strNumber) {
  const int BASE_2 = 2;
  //vars
  int decimalNum = stoi (strNumber);
  string binaryNum = "";

  //base case
  if (decimalNum == 0) {
    return "0";
  }
  else {
    while (decimalNum > 0) {
      binaryNum = to_string (decimalNum % BASE_2) + binaryNum;
      decimalNum /= BASE_2;
    }
  }

  return binaryNum;
}


/****************************************************************************
 Function:    	decimalToHex

 Description: 	takes a base 10 number and converts it to base 16

 Parameters:  	strNumber - the base 10 number

 Returned:    	the base 16 number
 ****************************************************************************/
string decimalToHex (const string& strNumber) {
  //consts
  const int BASE_16 = 16;
  const int BASE_10 = 10;

  //vars
  int decimalNum = stoi (strNumber);
  int leftover = 0;
  string hexNum = "";

  //base case
  if (decimalNum == 0) {
    return "0";
  }
  else {
    while (decimalNum > 0) {
      leftover = decimalNum % BASE_16;

      if(leftover >= BASE_10) {
        hexNum = static_cast<char>('A' + (leftover - BASE_10)) + hexNum;
      } else {
        hexNum = to_string (decimalNum % BASE_16) + hexNum;
      }
      decimalNum /= BASE_16;
    }
  }

  return hexNum;
}

/****************************************************************************
 Function:    	binaryToDecimal

 Description: 	takes a base 2 number and converts it to base 10

 Parameters:  	strNumber - the base 2 number

 Returned:    	the base 10 number
 ****************************************************************************/
string binaryToDecimal (const string& strNumber) {
  string parseString;
 
  int length = strNumber.length ();
  int decimalNum = 0;

  parseString = strNumber.substr(2, length - 2);
  length -= 2;
  //reverse string
  reverse ( parseString.begin (),  parseString.end ());

  for (int i = 0 ; i < length; i++ ){
    decimalNum = decimalNum + ( pow(2, i) * (parseString[i] % 48));
  }

  return to_string (decimalNum);
}

/****************************************************************************
 Function:    	binaryToHex

 Description: 	takes a base 2 number and converts it to base 16

 Parameters:  	strNumber - the base 2 number

 Returned:    	the base 16 number
 ****************************************************************************/
string binaryToHex (const string& strNumber) {
  string decimalNum;

  decimalNum = binaryToDecimal(strNumber);

  return decimalToHex(decimalNum);
}


/****************************************************************************
 Function:    	hexToDecimal

 Description: 	takes a base 16 number and converts it to base 10

 Parameters:  	strNumber - the base 16 number

 Returned:    	the base 10 number
 ****************************************************************************/
string hexToDecimal (const string& strNumber) {
  string parseString;
 
  int length = strNumber.length ();
  int decimalNum = 0;

  //remove front 2 of string
  parseString = strNumber.substr(2, length - 2);
  length -= 2;
  //reverse string
  reverse (parseString.begin (),  parseString.end ());

  for (int i = 0 ; i < length; i++ ){
    decimalNum = decimalNum + ( pow(16, i) * hexCharToInt(parseString[i]));
  }

  return to_string (decimalNum);
}

/****************************************************************************
 Function:    	hexToBinary

 Description: 	takes a base 16 number and converts it to base 2

 Parameters:  	strNumber - the base 16 number

 Returned:    	the base 2 number
 ****************************************************************************/
string hexToBinary (const string& strNumber) {
  string decimalNum;

  decimalNum = hexToDecimal(strNumber);

  return decimalToBinary(decimalNum);
}