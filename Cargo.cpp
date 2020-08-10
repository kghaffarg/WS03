#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Cargo.h"
namespace sdds {

	void Cargo::setEmpty() {
		crgo_desc[0] = '\0';
		crgo_wght = 0;
	}


	void Cargo::initialize(const char* desc, double weight) {

			Cargo::setDesc(desc);
			Cargo::setWeight(weight);
		
	}
	const char* Cargo::getDesc() const {// #1 return member variable has no=
		return crgo_desc;
	}
	double Cargo::getWeight() const {//#2 it gives an error// well it should becuse it's empty how to access the value :::I used refrense it does not accept
		return crgo_wght;

	}
	void Cargo::setDesc(const char* description) {

		if (description == nullptr || description[0] == '\0') {
			crgo_desc[0] = '\0';
		}
		else if (strlen(description) > MAX_DESC) {
			strncpy(crgo_desc, description, MAX_DESC);
			crgo_desc[MAX_DESC] = '\0'; // null-terminate

		}
		else
			strcpy(crgo_desc, description);
	}

	void Cargo::setWeight(double weight) {
		if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
			crgo_wght = MIN_WEIGHT;
		}
		else {
			crgo_wght = weight;
		}

	}








}