#pragma once

#include "TouristQuide.h"

class CountryTrips : public TouristQuide {
private:
	string country;
public:
	CountryTrips() :TouristQuide(), country("") {};
	CountryTrips(string country) :TouristQuide(), country(country) {};
	CountryTrips(const CountryTrips& trip) :TouristQuide(), country(trip.country) {};

	void setCountry(string);
	string getCountry();
	void showInfoPlace(Place);
};