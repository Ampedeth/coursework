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
// �������������� ������ showInfoPlace ��� ��������� ���������� � ����������� ������
void HotTrips::showInfoPlace(Place place) {
	cout << "���������� ��� ���� " << place.getTitle() << "\n";
	cout << "��������: " << place.getCategory() << "\n";
	cout << "̳��� ������������: " << place.getLocation() << "\n";
	cout << "����: " << place.getDescription() << "\n";
	cout << "����� ����: " << place.getPrice() << "\n";
	cout << "���� ����: " << place.getPrice() * (1 - this->discount / 100) << "\n\n";
}