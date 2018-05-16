#pragma once
#include <string>
#include "Pet.h"
#include <vector>


class ValidateException {
	std::vector<std::string> msgs;
public:
	ValidateException(const std::vector<std::string>& errors) :msgs{ errors } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend std::ostream& operator<<(std::ostream& out, const ValidateException& ex);
};

std::ostream& operator<<(std::ostream& out, const ValidateException& ex);

class PetValidator {
public:
	void validate(const Pet& p);
};