#pragma once
#include <iostream>
#include <string>

using namespace std;
 
class Place
{
private:
	string title;
	string category;
	string location;
	string description;
	double price;

public:
	// Визначення конструкторів
	// Конструктор за замовчуванням
	Place() :title(""), category(""), location(""), description(""), price(0) {}; 
	// Конструктор ініціалізації
	Place(string title, string category, string location, string decsription, double price) :
		title(title), category(category), location(location), description(decsription), price(price) {};
	Place(const Place&); // Конструктор копіювання
	~Place(); // Деструктор об'єкта
	string getTitle();
	void setTitle(string);
	string getCategory();
	void setCategory(string);
	void setLocation(string);
	string getLocation();
	string getDescription();
	void setDescription(string);
	double getPrice();
	void setPrice(double);
	// перевантаження операторів
	Place operator ++();
	Place operator ++(int);
	Place operator +(double);
	Place operator -(double);
};