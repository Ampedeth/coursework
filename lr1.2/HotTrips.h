#pragma once
#include "TouristQuide.h"
class HotTrips : public TouristQuide {
private:
	double discount;
public:
	HotTrips() :TouristQuide(),discount(0) {};
	HotTrips(double discount) :TouristQuide(), discount(discount) {};
	HotTrips(const HotTrips& trips) :TouristQuide(trips), discount(trips.discount) {};

	double getDiscount();
	void setDiscount(double value);

	void showInfoPlace(Place);
};