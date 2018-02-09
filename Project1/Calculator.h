#pragma once
class Calculator
{
private:
	float leftSide;
	float rightSide;
	float radius;
	float pi;

public:
	Calculator();
	float Add(float, float);
	float Subtract(float, float);
	float Divide(float, float);
	float Multiply(float, float);

public:
	float RectangleArea(float, float);
	float TriangleArea(float, float);
	float CircleArea(float);

};

