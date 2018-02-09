#include <iostream>
#include <stdio.h>
#include "Calculator.h"


char operation,choice;
int calculatorVersion;
float leftSide,rightSide;
Calculator calc;

void Algebra() {
	do {
		std::cout << "*****************************************" << std::endl;
		std::cout << "Please provide a math problem (ex. 1 + 2)" << std::endl;
		std::cout << "*****************************************\n" << std::endl;

		std::cin >> leftSide >> operation >> rightSide;

		if (operation == '/' && rightSide == 0) {
			std::cout << "\nDivision by Zero is not possible!!\n" << std::endl;
			std::cout << "please enter a valid second value:\n" << std::endl;
			std::cin >> rightSide;
		}

		switch (operation) {
		case '*':
			std::cout << "\n"<< leftSide <<" Times " << rightSide << " is:\n" << std::endl;
			std::cout << calc.Multiply(leftSide, rightSide) << "\n" << std::endl;
			break;
		case '/':
			std::cout << "\n" << leftSide << " Divided by " << rightSide << " is:\n" << std::endl;
			std::cout << calc.Divide(leftSide, rightSide) << "\n" << std::endl;
			break;
		case '+':
			std::cout << "\n" << leftSide << " Plus " << rightSide << " is:\n" << std::endl;
			std::cout << calc.Add(leftSide, rightSide) << "\n" << std::endl;
			break;
		case '-':
			std::cout << "\n" << leftSide << " Minus " << rightSide << " is:\n" << std::endl;
			std::cout << calc.Subtract(leftSide, rightSide) << "\n" << std::endl;
			break;
		}
		std::cout << "Do you want to find the value of another? (y/n)" << std::endl;
		std::cin >> choice;
	} while (choice != 'n');
}

void Geometry() {
	int issue;
	float base, height, radius, width;
	do {
		std::cout << "*****************************************" << std::endl;
		std::cout << "Please select a geometry problem issue" << std::endl;
		std::cout << "(1) Area of a Circle" << std::endl;
		std::cout << "(2) Area of a Triangle" << std::endl;
		std::cout << "(3) Area of a Rectangle/square" << std::endl;
		std::cout << "*****************************************\n" << std::endl;

		std::cin >> issue;

		switch (issue) {
		case 1:
			std::cout << "Enter the Radius of the Circle:\n" << std::endl;
			std::cin >> radius;
			std::cout << "\nThe Area of your Circle is:\n" << std::endl;
			std::cout << calc.CircleArea(radius) << "\n" << std::endl;
			break;
		case 2:
			std::cout << "Enter the Base and the Height:\n" << std::endl;
			std::cin >> base >> height;
			std::cout << "\nThe Area of your Triangle is:\n" << std::endl;
			std::cout << calc.TriangleArea(base, height) << "\n" << std::endl;
			break;
		case 3:
			std::cout << "Enter the Width and the Height:\n" << std::endl;
			float width, height;
			std::cin >> width >> height;
			std::cout << "\nThe Area of your Rectangle is:\n" << std::endl;
			std::cout << calc.RectangleArea(width, height) << "\n" << std::endl;
			break;
		}
		std::cout << "Do you want to find the value of another? (y/n)" << std::endl;
		std::cin >> choice;
	}
	while (choice != 'n');
}

void run() {
	do {
		std::cout << "Select a Calculator:\n" << std::endl;
		std::cout << "*******************************" << std::endl;
		std::cout << "(1) Algebra Calculator" << std::endl;
		std::cout << "(2) Geometry Calculator" << std::endl;
		std::cout << "*******************************\n" << std::endl;

		std::cin >> calculatorVersion;

		switch (calculatorVersion) {
		case 1:
			Algebra();
			break;
		case 2:
			Geometry();
			break;
		default:
			std::cout << "You did not enter a valid selection" << std::endl;
		break;
		}
		std::cout << "Do you want to continue? (y/n)" << std::endl;
		std::cin >> choice;

	} while (choice != 'n');
}

int main() {

	run();
	return 0;
}

