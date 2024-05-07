#pragma once
#include <exception>
using std::exception;

// класс для створення виключення, при відсутності елементів що відповідають вказаній умові.
class NoSearchedPlace : public exception {
public:
	NoSearchedPlace();

};

