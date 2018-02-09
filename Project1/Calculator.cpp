#include "Calculator.h"


Calculator::Calculator() {
	leftSide= 0;
	rightSide= 0;
	pi = 3.14f;
}

float Calculator::Add(float leftSide,float rightSide) {
	return leftSide + rightSide;
}

float Calculator::Subtract(float leftSide, float rightSide) {

	return leftSide - rightSide;
}

float Calculator::Divide(float leftSide, float rightSide) {
	return leftSide / rightSide;
}

float Calculator::Multiply(float leftSide, float rightSide) {
	return leftSide * rightSide;
}

//GEOMETRY

float Calculator::CircleArea(float radius) {
	return pi * radius * radius;
}

float Calculator::RectangleArea(float length, float width) {
	return length * width;
}

float Calculator::TriangleArea(float base, float height) {
	return ((base * height) / 2);
}
