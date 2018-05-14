#pragma once

#include "Pet.h"
#include "petrepo.h"
#include <string>
#include <vector>

#include <functional>
#include "validator.h"

using namespace std;

typedef bool(*MaiMicF)(const Pet&, const Pet&);

class PetStore {
	PetRepo& rep;
	PetValidator& val;

	/*
	 Functie de sortare generala
	 maiMicF - functie care compara 2 Pet, verifica daca are loc relatia mai mare
	          - poate fi orice functie (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Pet)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
	vector<Pet> generalSort(MaiMicF maiMicF)const;
	/*
	Functie generala de filtrare
	fct - poate fi o functie 
	fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
	returneaza doar animalele care trec de filtru (fct(pet)==true)
	*/
	vector<Pet> filtreaza(function<bool(const Pet&)> fct)const;
public:
	PetStore(PetRepo& rep, PetValidator& val) noexcept:rep{ rep }, val{ val } {
	}
	//nu permitem copierea de obiecte PetStore
	PetStore(const PetStore& ot) = delete;
	/*
	 returneaza toate animalele in ordinea in care au fost adaugate
	*/
	const vector<Pet>& getAll() const noexcept{
		return rep.getAll();
	}
	/*
	Adauga un nou pet
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	void addPet(const string& type, const string& species, int price);

	/*
	Sorteaza dupa tip
	*/
	vector<Pet> sortByType()const;

	/*
	Sorteaza dupa species
	*/
	vector<Pet> sortBySpecies()const;


	/*
	Sorteaza dupa species+price
	*/
	vector<Pet> sortBySpeciesPrice() const;

	/*
	returneaza doar animalele cu pret mai mic decat cel dat
	*/
	vector<Pet> filtrarePretMaiMic(int pret)const;

	/*
	returneaza doar animalele cu pret intre cele doua preturi
	*/
	vector<Pet> filtrarePret(int pretMin, int pretMax)const;

};
void testCtr();
