#pragma once

class AbstractGuide {
public:
	string namefile;
	// ������� ���������� ����
	virtual void save() = 0;
};