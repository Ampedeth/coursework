#include <typeinfo>
#include "HotTrips.h"

double HotTrips::getDiscount() {
	return this->discount;
}
void HotTrips::setDiscount(double value) {
	if (typeid(value) == typeid(double)) {
		this->discount = value;
	}
}
// перевизначення методу showInfoPlace для виведення інформації з врахуванням знижки
void HotTrips::showInfoPlace(Place place) {
	cout << "Інформація про місце " << place.getTitle() << "\n";
	cout << "Категорія: " << place.getCategory() << "\n";
	cout << "Місце розташування: " << place.getLocation() << "\n";
	cout << "Опис: " << place.getDescription() << "\n";
	cout << "Стара ціна: " << place.getPrice() << "\n";
	cout << "Нова ціна: " << place.getPrice() * (1 - this->discount / 100) << "\n\n";
}