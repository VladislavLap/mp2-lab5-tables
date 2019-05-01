#ifndef _POLINOM_H_
#define _POLINOM_H_

#include "list.h"

class Monom
{
public:

	double coef; //коэффициент монома
	int deg;     //степень монома

	Monom();
	Monom(double, int);
	~Monom();
	int RetSum();     //вернуть сумму цифр степени
	bool operator>= (Monom&); //оператор сравнения
	bool operator< (Monom&);  //оператор сравнения
	bool operator!= (const Monom&)const;  //оператор сравнения
	friend std::ostream& operator<< (std::ostream& os, const Monom& v); //перегрузка потокового вывода
};

class Polinom : public List<Monom>
{
public:

	Polinom();  //конструктор по умолчанию
	~Polinom(); //деструктор
	void ToStandartView(); //приведение подобных и удаление мономов с нулевым коэффициентом
	Polinom& operator= (Polinom&);     //присваивание
	Polinom& operator= (List<Monom>&); //присваивание
	Polinom operator+ (Polinom&); //сложение полиномов
	Polinom operator- (Polinom&); //разность полиномов
	Polinom operator* (double);   //умножение полинома на константу
	Polinom operator* (Monom&);   //умножение полинома на моном
	Polinom operator* (Polinom&); //умножение полиномов
	void Print(); //печать полинома
};

#endif // !_POLINOM_H_