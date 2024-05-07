#pragma once

class AbstractGuide {
public:
	string namefile;
	// повністю віртуальний мето
	virtual void save() = 0;
};