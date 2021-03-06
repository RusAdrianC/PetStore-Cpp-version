#pragma once
#include "Pet.h"

#include <vector>
#include <string>




class PetRepo {
	std::vector<Pet> all;
	/*
	metoda privata verifica daca exista deja p in repository
	*/
	bool exist(const Pet& p);

public:
	//Constructor Privat
	PetRepo() = default;
	//nu permitem copierea de obiecte
	PetRepo(const PetRepo& ot) = delete;

	/*
	Salvare pet
	arunca exceptie daca mai exista un animal cu acelasi tip si specie
	*/
	void store(const Pet& p);

	/*
	Cauta
	arunca exceptie daca nu exista animal
	*/
	Pet find(const std::string& type, const std::string& species) const;

	/*
	returneaza toate animalele salvate
	*/
	const std::vector<Pet>& getAll() const noexcept;

};

/*
Folosit pentru a semnala situatii exceptionale care pot aparea in repo
*/
class PetRepoException {
	std::string msg;
public:
	PetRepoException(std::string m) :msg{ m } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend std:: ostream& operator<<(std::ostream& out, const PetRepoException& ex);
};
std::ostream& operator<<(std::ostream& out, const PetRepoException& ex);

void testeRepo();