#include "validator.h"

void PetValidator::validate(const Pet& p) {
	std::vector<std::string> msgs;
	if (p.getPrice() < 0) msgs.push_back("Pret negativ!!!");
	if (p.getType().size() == 0) msgs.push_back("Tip vid!!!");
	if (p.getSpecies().size() == 0) msgs.push_back("Specie vid!!!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

std::ostream& operator<<(std::ostream& out, const ValidateException& ex) {
	for (const auto& msg : ex.msgs) {
		out << msg<<" ";
	}
	return out;
}