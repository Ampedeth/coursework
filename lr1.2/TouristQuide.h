#pragma once
#include <list>

#include <iterator>
#include <fstream>
#include "Place.h"
#include "AstractGuide.h"
#include "NoSearchedPlace.h"
class TouristQuide:public AbstractGuide {
	
public:
	list<Place> places;
	TouristQuide();
	TouristQuide(const TouristQuide&);
	~TouristQuide();
	void addPlace();
	void searchPlaceByTitle(string) throw (NoSearchedPlace);
	
	void searchPlacesByCategory(string) throw (NoSearchedPlace);
	void searchPlacesByLocation(string) throw (NoSearchedPlace);
	// метод визначається як віртуальний для перевизначення в дочірніх класах (поліморфізм) 
	virtual void showInfoPlace(Place);

	// повністю віртуальний метод
	virtual void save();

	void printAllPlaces();


};