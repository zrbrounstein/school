#include <iostream>
#include <cmath>
#include "inheritance.h"
using namespace std;

Rectangle::Rectangle(float l,float w){
	length = l;
	width = w;
	isThreeDimensional = false;
}

float Rectangle::calculateAreaOrVolume(){
	return length*width;
}

float Rectangle::calculatePerimeterOrSurfaceArea(){
	return 2*(length+width);
}

void Rectangle::print(){
	cout <<  endl << "The Perimeter of a Rectangle with length: " << length << " and width: " << width << " is: ";
	cout << calculatePerimeterOrSurfaceArea();
	cout <<  endl << "The Area of a Rectangle with length: " << length << " and width: " << width << " is: ";
	cout << calculateAreaOrVolume() << endl;
}

RectangularPrism::RectangularPrism(float l,float w,float h){
	length = l;
	width = w;
	height = h;
	isThreeDimensional = true;
}

float RectangularPrism::calculateAreaOrVolume(){
	return length*width*height;
}

float RectangularPrism::calculatePerimeterOrSurfaceArea(){
	return 2*((length*width)+(length*height)+(width*height));
}

void RectangularPrism::print(){
	cout <<  endl << "The Surface Area of a Rectangular Prism with length: " << length << ", width: " << width  << ", and height: " << height << " is: ";
	cout << calculatePerimeterOrSurfaceArea();
	cout <<  endl << "The Volume of a Rectangular Prism with length: " << length << " and width: " << width << ", and height: " << height << " is: ";
	cout << calculateAreaOrVolume() << endl;
}

Circle::Circle(float r){
	radius = r;
	isThreeDimensional = false;
}

float Circle::calculateAreaOrVolume(){
	return M_PI*radius*radius;
}

float Circle::calculatePerimeterOrSurfaceArea(){
	return 2*M_PI*radius;
}

void Circle::print(){
	cout <<  endl << "The Perimeter of a Circle with radius: " << radius << " is: ";
	cout << calculatePerimeterOrSurfaceArea();
	cout <<  endl << "The Area of a Circle with radius: " << radius << " is: ";
	cout << calculateAreaOrVolume() << endl;
}

Cylinder::Cylinder(float r,float h){
	radius = r;
	height = h;
	isThreeDimensional = true;
}

float Cylinder::calculateAreaOrVolume(){
	return M_PI*height*radius*radius;	
}

float Cylinder::calculatePerimeterOrSurfaceArea(){
	return 2*M_PI*radius*height + 2*M_PI*radius*radius;
}

void Cylinder::print(){
	cout <<  endl << "The Surface Area of a Cylinder with radius: " << radius << " and height: " << height << " is: ";
	cout << calculatePerimeterOrSurfaceArea();
	cout <<  endl << "The Volume of a Cylinder with radius: " << radius << " and height: " << height << " is: ";
	cout << calculateAreaOrVolume() << endl;
}