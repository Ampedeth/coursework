#pragma once
#include <exception>
using std::exception;

// ����� ��� ��������� ����������, ��� ��������� �������� �� ���������� ������� ����.
class NoSearchedPlace : public exception {
public:
	NoSearchedPlace();

};

