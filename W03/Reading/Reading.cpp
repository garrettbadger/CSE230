// Reading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*
* Simple class
*/
class Complex
{
public:
	void display() 
	{
		cout << real << " + " << imaginary << endl;
	}
	void set(double r, double i) 
	{
		this->real = r;
		this->imaginary = i;
	}
	double getReal() 
	{
		return real;
	}
	double getImaginary()
	{
		return imaginary;
	}
private:
	double real;
	double imaginary;
};

int main() {
	Complex cx;
	cx.set(7.3, 4.6);
	double r;
	r = cx.getReal();
	cx.set(34.1, -7);
	cx.display();
}