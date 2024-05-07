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
	cout << "��'��� �������� ������� ��������\n";
}
void TouristQuide::addPlace() {
	
	string title,category, location, description;
	double price;
	cout << "������ ��� ��� ������ ����:\n";
	cout << "������ �����: ";
	getline(cin, title);
	cout << "������ ��������: ";
	getline(cin, category);
	cout << "������ ���� ������������: ";
	getline(cin, location);
	cout << "������ ����: ";
	getline(cin, description);
	cout << "������ ����: ";
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
	cout << "���������� ��� ���� " << place.getTitle() << "\n";
	cout << "��������: " << place.getCategory() << "\n";
	cout << "̳��� ������������: " << place.getLocation() << "\n";
	cout << "����: " << place.getDescription() << "\n";
	cout << "ֳ��: " << place.getPrice() << "\n\n";
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
	cout << "������ ������ ����\n\n";
	list<Place>::iterator it;
	for (it = this->places.begin(); it != this->places.end(); it++) {
		this->showInfoPlace(*it);


	}
}

// ��������� ����������� ������
// ����� � ������� ����
void TouristQuide::save() {
	ofstream output(this->namefile, std::ios::binary);
	string title, category, location, description;
	double price;
	if (!output.is_open()) {
		cerr << "������� �������� �����\n";

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
