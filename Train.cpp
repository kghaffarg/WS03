#define _CRT_SECURE_NO_WARNINGS_
//Train.cpp
/*********************************************************/
/*Name: Kajhal Ghaffary                                  */
/*Student ID: 149669178                                  */
/*Seneca Email: kghaffarg@myseneca.ca                    */
/*********************************************************/

#include <iostream>
#include "Train.h"
#include "Cargo.h"
#include "cstring"
using namespace std;
namespace sdds {
	
	void Train::setEmpty() {
		t_Name[0] = '\0';
		t_ID = 0;

	}

	bool Train::isValid() const {
		bool value;
		if (t_Name == nullptr || t_Name[0] == '\0' || t_ID <= 0) {
			value = false;
		}
		else {
			value = true;
		}
		return value;

	}



	void Train::initialize(const char* name, int id) {
		cargo = nullptr;
		if (name == nullptr || name[0] == '\0' || id <= 0) {
			setEmpty();
			
		}
		else if(strlen(name) > MAX_NAME){
			strncpy_s(t_Name, name, MAX_NAME);
			t_ID = id;
		}
		else {
			strcpy_s(t_Name, name);
			t_ID = id;
		}
	}


	void Train::loadCargo(Cargo ca) {///question1// I should use a loop may be to add the cargo
		if (cargo) {
			delete cargo;
			cargo = nullptr;
		}

		cargo = new Cargo;
		cargo->setDesc(ca.getDesc());
		cargo->setWeight(ca.getWeight());

	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}


	bool Train::swapCargo(Train& other) {
		bool swap = true;
		if (isValid() && other.isValid() && cargo != nullptr && other.cargo !=nullptr) {
			Cargo* temp;
			temp = other.cargo;
			other.cargo = this->cargo;
			this->cargo = temp;

			swap = true;
		}
		else {
			swap = false;
		}
		return swap;
	}

	bool Train::increaseCargo(double weight) {
		
		bool increase = false;
		if (isValid() && cargo != nullptr) {
			if (cargo->getWeight() != MAX_WEIGHT ){
				increase = true;
				cargo->setWeight(cargo->getWeight() + weight);
				cout.width(10);
				cout.setf(ios::fixed);
				cout.precision(3);
			}
		
			 if(cargo->getWeight() + weight > MAX_WEIGHT) {
					cargo->setWeight(MAX_WEIGHT);
			 }
						
			
		}

		return increase;
	}
					

		

	bool Train::decreaseCargo(double weight) {
		bool decrease = false;
		if (isValid() && cargo != nullptr) {
			if (cargo->getWeight() != MIN_WEIGHT) {
				decrease = true;
				cargo->setWeight(cargo->getWeight() - weight);
			}
		
			if (cargo->getWeight() - weight < MIN_WEIGHT) {
				cargo->setWeight(MIN_WEIGHT);
				cout.width(10);
				cout.setf(ios::fixed);
				cout.precision(4);
			}


		}

		return decrease;
	}

	void Train::display() const {

		cout << "***Train Summary***\n";

		if (isValid())
		{
			cout.width(10);
			cout << "Name: " << t_Name << endl;
			cout.width(10);
			cout << "  ID: "<< t_ID << "\n";
			if (cargo == nullptr || this->cargo->getWeight() < MIN_WEIGHT || this->cargo->getWeight() > MAX_WEIGHT) {

				cout << "No cargo on this train." << endl;
			}
			else {
				cout.width(10);
				cout << "Cargo: " << cargo->getDesc() << endl;
				cout.setf(ios::fixed);
				cout.width(10);
				cout.precision(2);
				cout <<"Weight: " << cargo->getWeight() << endl;
			
				

			}
		}
		else
			cout << "This is an invalid train.\n";

	}







};