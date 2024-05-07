
#include "Location.h"

Location::Location() {
	this->location = "";
}
Location::Location(std::string location) {
	this->location = location;
}
Location::Location(const Location& loc) {
	this->location = loc.location;
}
void Location::setLocation(std::string value) {
	this->location = value;
}
std::string Location::getLocation() {
	return this->location;
}