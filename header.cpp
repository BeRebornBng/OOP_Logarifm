#include "header.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::cerr;
using bng::log;
bng::log temp;


log::log():_coefficient(1), _base(2), _result(0) {}


log::log(double coefficient, double base):_coefficient(coefficient), _base(base)
{
	if (_base < 2 || _coefficient < 1) { cerr << "Ошибка: _base>1,_coefficient>=1"; exit(-1); }
	_result = std::log(_coefficient) / std::log(_base);
}


log::log(const log const& logarithm) :_coefficient(logarithm._coefficient), _base(logarithm._base), _result(logarithm._result) {}

	
void log::set()
{
	double value;

	cout << "Введите основание логарифма: ";
	cin >> value;
	_base = value;

	cout << "Введите аргумент логарифма: ";
	cin >> value;
	_coefficient = value;

	_result = std::log(_coefficient) / std::log(_base);
}
	

double log::get()const
{
	return _result;
}


void log::output() 
{
	cout << "Основание логарифма = " << _base << '\n';
	cout << "Аргумент логарифма = " << _coefficient << '\n';
}


double log::ResultCalculate() 
{
	_result = std::log(_coefficient) / std::log(_base);
	return _result;
}


bng::log& log::operator+(const log const& logarithm) 
{
	if (_base == logarithm._base) {
		temp._base = _base;
		temp._coefficient = (_coefficient * logarithm._coefficient);
		temp._result = temp.ResultCalculate();
		return temp;
	}
	else {
		cerr << "Основания не равны";
		exit(-1);
	}
}


bng::log& log::operator-(const log const& logarithm)
{
	if (_base == logarithm._base) {
		temp._base = _base;
		temp._coefficient = (_coefficient / logarithm._coefficient);
		temp._result = temp.ResultCalculate();
		return temp;
	}
	else {
		cerr << "Основания не равны";
		exit(-1);
	}
}


bng::log log::operator*(log& logarithm)
{
	double tempVal=_base;
	_base = logarithm._base;
	logarithm._base = tempVal;
	temp._base = 2;
	temp._result = logarithm.ResultCalculate()*(this->ResultCalculate());
	temp._coefficient = std::log(temp._result)/std::log(temp._base);
	return temp;
}


bng::log& log::operator*(double multiplier)
{
	temp(*this);
	temp._coefficient = pow(temp._coefficient,multiplier);
	temp.ResultCalculate();
	return temp;
}


bng::log& log::operator=(const log const& logarithm)
{
	_base = logarithm._base;
	_coefficient = logarithm._coefficient;
	_result = logarithm._result;
	return *this;
}


bng::log log::operator()(const log const& logarithm)
{
	_base = logarithm._base;
	_coefficient = logarithm._coefficient;
	_result = logarithm._result;
	return *this;
}


bool log::operator==(const log const& logarithm)const
{
	if (_result==logarithm._result)
		return true;
	return false;
}


bool log::operator!=(const log const& logarithm)const
{
	if (_result != logarithm._result)
		return true;
	return false;
}


bool log::operator>(const log const& logarithm)const
{
	if (_result > logarithm._result)
		return true;
	return false;
}


bool log::operator<(const log const& logarithm)const
{
	if (_result < logarithm._result)
		return true;
	return false;
}