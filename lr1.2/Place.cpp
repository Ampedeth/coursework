#include <typeinfo>
#include <string>
#include "Place.h"

using namespace std;


// ����������� ��������� 

Place::Place(const Place& place) {
	this->title = place.title;
	this->category = place.category;
	this->location = place.location;
	this->description = place.description;
	this->price = place.price;
}
// ����������
Place::~Place() {
	//cout << "The object place has been deleted\n";
	;
}

string Place::getTitle() {
	return this->title;
}
void Place::setTitle(string title) {
	this->title = title;
}
string Place::getCategory() {
	return this->category;
}
void Place::setCategory(string category) {
	this->category = category;
}
void Place::setLocation(string value) {
	this->location = value;
}
string Place::getLocation() {
	return this->location;
}
string Place::getDescription() {
	return this->description;
}
void Place::setDescription(string description) {
	this->description = description;
}
double Place::getPrice() {
	return this->price;
}
void Place::setPrice(double price) {
	if (typeid(price) == typeid(double)) {
		this->price = price;
	}
	else {
		this->price = 0;
	}
	
}
// �������������� �������� ��������� ++

// �������� ++ ���� 1 �� �������� ���� price
Place Place::operator ++() {
	this->price ++;
	return *this;
}

Place Place::operator ++(int) {
	Place temp = *this;
	++(*this);
	return temp;

}

// �������������� �������� ��������� +
// �������� ���� �������� double �� �������� ���� price
Place Place::operator +(double value) {
	this->price += value;
	return *this;
}
// �������������� �������� ��������� -
// �������� ����� �������� double �� �������� ���� price. �������� �� ���������, ���� � ��������� ���� ��'���� �����
Place Place::operator -(double value) {
	if (this->price >= value) {
		this->price -= value;
	}
	return *this;
}
