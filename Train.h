#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__
#include "Cargo.h"
namespace sdds {
	const int MAX_NAME = 30;
	class Train {
		char t_Name[MAX_NAME + 1];
		int t_ID;
		Cargo* cargo;

	public:


	public:
		void setEmpty();
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;
		bool swapCargo(Train& other);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);
	};










}
#endif // !SDDS_TRAIN_H__
