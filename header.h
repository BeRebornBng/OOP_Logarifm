#pragma once
namespace bng {
	class log{
	public:

		log();
		log(double coefficient, double base);
		log(const log const& logarithm);

		void set();
		double get()const;
		void output();

		log& operator+(const log const&logarithm);
		log& operator-(const log const& logarithm);
		log operator*(log& logarithm);
		log& operator*(double multiplier);
		log& operator=(const log const& logarithm);
		log operator()(const log const& logarithm);

		bool operator==(const log const& logarithm)const;
		bool operator!=(const log const& logarithm)const;
		bool operator>(const log const& logarithm)const;
		bool operator<(const log const& logarithm)const;

	protected:
		double ResultCalculate();
	private:

		long double _coefficient;
		double _base;
		double _result;

	};
}