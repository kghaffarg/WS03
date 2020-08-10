#ifndef SDDS_CARGO_H__
#define SDDS_CARGO_H__
namespace sdds {
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	class Cargo {
		char crgo_desc[MAX_DESC + 1];//
		double crgo_wght;

	public:
		void setEmpty();
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);
	};








}
#endif // !SDDS_CARGO_H__
