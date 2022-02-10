/*
	Author: Bailey Nichols
	
	Purpose: To convert numbers from decimal to hex and binary from the cli

	Structure: Take in number, print the number in both hex and binary

	Notes: The program is run on the cli, you say, hexAndBinary <integer>,
				 does not process numbers above 256

*/
#include <stdio.h>
#include <string>
void printBinary(int number);

//
int main(int argc, char** argv){//argument count and vector
	int i =1;
	std::string::size_type size; //function below needs string to send failed data to
	for (i; i < argc; i++){
		int number = std::stoi(argv[i], &size);
		//now that we have our number just a regular old integer
		//first we can print our hex, that is easy
		printf("%i in hexidecimal is %X \n", number, number);
		//now we make a binary string using a function defined below
		printBinary(number);
		return 0;
	}
}

void printBinary(int number){
	int temp = number;
	int binNum[]={0,0,0,0,0,0,0,0,0,0}; //binary string to hold values
	//code for this function from:
	// https://www.tutorialgateway.org/c-program-to-convert-decimal-to-binary/
	//no author listed
	int i = 0;
	for (; number > 0; i++){
		binNum[i] = number % 2;
		number = number / 2;
	}

	//finally we print
	printf("%i in binary is ", number);

	for (int j = i - 1; j >= 0; j--){
		printf("%i", binNum[j]);
	}
	printf("\n");
	return;
}