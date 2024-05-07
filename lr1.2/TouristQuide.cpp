#include "TouristQuide.h"
using namespace std;

TouristQuide::TouristQuide() {
	this->namefile = "out.txt";
}
TouristQuide::TouristQuide(const TouristQuide& copied) {
	this->places.assign(copied.places.begin(), copied.places.end());
	this->namefile = "out.txt";
}
TouristQuide::~TouristQuide() {
	this->places.clear();
	cout << "Об'єкт Путівника Туриста видалено\n";
}
void TouristQuide::addPlace() {
	
	string title,category, location, description;
	double price;
	cout << "Введіть дані для нового місця:\n";
	cout << "Введіть назву: ";
	getline(cin, title);
	cout << "Введіть категорію: ";
	getline(cin, category);
	cout << "Введіть місце розташування: ";
	getline(cin, location);
	cout << "Введіть опис: ";
	getline(cin, description);
	cout << "Введіть ціну: ";
	cin >> price;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	this->places.push_back(Place(title, category, location, description, price));
	this->save();
}

void TouristQuide::searchPlaceByTitle(string title)  throw (NoSearchedPlace) {
	list<Place> ::iterator it;
	int c = 0;
	for (it = this->places.begin(); it != this->places.end(); it++) {
		if (it->getTitle() == title) {
			this->showInfoPlace(*it);
			c++;
		}
	}
	if (c == 0) {
		throw NoSearchedPlace();
	}
}
void TouristQuide::showInfoPlace(Place place) {
	cout << "Інформація про місце " << place.getTitle() << "\n";
	cout << "Категорія: " << place.getCategory() << "\n";
	cout << "Місце розташування: " << place.getLocation() << "\n";
	cout << "Опис: " << place.getDescription() << "\n";
	cout << "Ціна: " << place.getPrice() << "\n\n";
}
void TouristQuide::searchPlacesByCategory(string category) throw (NoSearchedPlace){
	list<Place> ::iterator it;
	int c = 0;
	for (it = this->places.begin(); it != this->places.end(); it++) {
		if (it->getCategory() == category) {
			this->showInfoPlace(*it);
			c++;
		}
	}
	if (c==0) {
		throw NoSearchedPlace();
	}
}
void TouristQuide::searchPlacesByLocation(string location) throw (NoSearchedPlace) {
	list<Place> ::iterator it;
	int c = 0;
	for (it = this->places.begin(); it != this->places.end(); it++) {
		if (it->getLocation() == location) {
			this->showInfoPlace(*it);
			c++;
		}
	}
	if (c == 0) {
		throw NoSearchedPlace();
	}
}


void TouristQuide::printAllPlaces() {
	cout << "Повний список місць\n\n";
	list<Place>::iterator it;
	for (it = this->places.begin(); it != this->places.end(); it++) {
		this->showInfoPlace(*it);


	}
}

// реалізація віртуального методу
// запис в бінарний файл
void TouristQuide::save() {
	ofstream output(this->namefile, std::ios::binary);
	string title, category, location, description;
	double price;
	if (!output.is_open()) {
		cerr << "Помилка відкриття файлу\n";

	}

	
	list<Place>::iterator it;
	for (it = this->places.begin(); it != this->places.end(); it++) {

		title = it->getTitle();
		category = it->getCategory();
		location = it->getLocation();
		description = it->getDescription();
		price = it->getPrice();
		output.write(reinterpret_cast<const char*>(&title), sizeof(title));
		output.write(reinterpret_cast<const char*>(&category), sizeof(category));
		output.write(reinterpret_cast<const char*>(&location), sizeof(location));
		output.write(reinterpret_cast<const char*>(&description), sizeof(description));
		output.write(reinterpret_cast<const char*>(&price), sizeof(price));
	}

	output.close();

	
}
