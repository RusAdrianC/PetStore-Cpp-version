#include "petrepo.h"
#include <assert.h>


void PetRepo::store(const Pet& p)
{
	if (exist(p)) {
		throw PetRepoException("Exista deja animal tip:" + p.getType() + " specie:" + p.getSpecies());
	}
	all.push_back(p);
}

bool PetRepo::exist(const Pet& p) {
	try {
		find(p.getType(), p.getSpecies());
		return true;
	}
	catch (PetRepoException& ) {
		return false;
	}
}
/*
Cauta
arunca exceptie daca nu exista animal
*/
Pet PetRepo::find(const std::string& type, const std::string& species) const {
	for (const Pet& p : all) {
		if (p.getType() == type && p.getSpecies() == species) {
			return p;
		}
	}
	//daca nu exista arunc o exceptie
	throw PetRepoException("Nu exista animal tip:" + type + " specie:" + species);
}

/*
returneaza toate animalele salvate
*/
const std::vector<Pet>& PetRepo::getAll() const noexcept{
	return all;
}


std::ostream& operator<<(std::ostream& out, const PetRepoException& ex) {
	out << ex.msg;
	return out;
}




void testAdauga() {
	PetRepo rep;
	//salvare pet
	rep.store(Pet{ "a","a",4 });
	//verifica daca este doar 1 animal
	assert(rep.getAll().size() == 1);
	//cauta animalu cu specia respectiva 
	assert(rep.find("a", "a").getSpecies() == "a");

	rep.store(Pet{ "b","b",4 });
	assert(rep.getAll().size() == 2);

	//nu pot adauga 2 cu acelasi tip si specie
	try {
		rep.store(Pet{ "a","a",4 });
		assert(false);
	}
	catch (PetRepoException&) {
		assert(true);
	}
}

void testCauta() {
	PetRepo rep;
	//salvam animale
	rep.store(Pet{ "a","a",4 });
	rep.store(Pet{ "b","b",4 });

	auto p = rep.find("a", "a");
	///sau rep.find("a", "a").getSpecies() == "a);
	assert(p.getSpecies() == "a");
	assert(p.getType() == "a");

	//arunca exceptie daca nu gaseste
	try {
		rep.find("a", "b");
		assert(false);
	}
	catch (PetRepoException&) {
		assert(true);
	}
}

void testeRepo() {
	testAdauga();
	testCauta();
}