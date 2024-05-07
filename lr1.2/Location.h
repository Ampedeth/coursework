#pragma once
#include <string>
#include <iostream>
class Location {
private:
	std::string location;
public:
	Location();
	Location(std::string);
	Location(const Location&);
	~Location() {};
	void setLocation(std::string);
	std::string getLocation();
	

};
