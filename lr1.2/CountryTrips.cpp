
#include "CountryTrips.h"

void CountryTrips::setCountry(string value) {
	this->country = value;
}
string CountryTrips::getCountry()
{
	return this->country;
}
// �������������� ������ showInfoPlace ��� ��������� ���������� � ����������� �����
void CountryTrips::showInfoPlace(Place place) {
	cout << "���������� ��� ���� " << place.getTitle() << "\n";
	cout << "��������: " << place.getCategory() << "\n";
	cout << "�����: " << this->getCountry() << "\n";
	cout << "̳��� ������������: " << place.getLocation() << "\n";
	cout << "����: " << place.getDescription() << "\n";
	cout << "ֳ��: " << place.getPrice() << "\n\n";
}