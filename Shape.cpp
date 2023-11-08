#include<iostream>
#include"Shape.h"


Shape::Shape(){
	this->color = "red";
};

Shape::Shape(std::string color){
	if (color!="red" || color!="green" || color!="blue")
		throw std::invalid_argument("color no válido");
	else
		this->color=color;
};
std::string Shape::get_color() const{
	return color;
};

void Shape::set_color(std::string c){
	if (color!="red" || color!="green" || color!="blue")
		throw std::invalid_argument("color no válido");
	else
		this->color=c;
};
