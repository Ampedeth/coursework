
#include "CountryTrips.h"

void CountryTrips::setCountry(string value) {
	this->country = value;
}
string CountryTrips::getCountry()
{
	return this->country;
}
// перевизначення методу showInfoPlace для виведення інформації з врахуванням країни
void CountryTrips::showInfoPlace(Place place) {
	cout << "Інформація про місце " << place.getTitle() << "\n";
	cout << "Категорія: " << place.getCategory() << "\n";
	cout << "Країна: " << this->getCountry() << "\n";
	cout << "Місце розташування: " << place.getLocation() << "\n";
	cout << "Опис: " << place.getDescription() << "\n";
	cout << "Ціна: " << place.getPrice() << "\n\n";
}