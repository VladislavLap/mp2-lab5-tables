#include "polinom.h"
#include "cmath"

Monom::Monom()
{
	coef = 0.0;
	deg = 0;
}

Monom::Monom (double _coef, int _deg)
{
	if (_deg < 0 || _deg >= 1000)
		throw "Error: unresolved degree";

	coef = _coef;
	deg = _deg;
}

Monom::~Monom()
{
}

int Monom::RetSum()
{
	int dx = deg / 100;
	int dy = deg % 100 / 10;
	int dz = deg % 10;

	return(dx+dy+dz);
}

bool Monom::operator!= (const Monom& mon)const
{
	if (coef != mon.coef || deg != mon.deg)
	{
		return (true);
	}
	else
		return(false);
}

bool Monom::operator>=(Monom& mon)
{
	if (deg >= mon.deg)
		return (true);
	else
		return (false);
}

bool Monom::operator<(Monom& mon)
{
	if ((*this) >= mon)
		return(false);
	else
		return(true);
}

std::ostream& operator<< (std::ostream& os, const Monom& mon)
{
	int dx = mon.deg / 100;
	int dy = mon.deg % 100 / 10;
	int dz = mon.deg % 10;

	os << mon.coef << "x^" << dx << "y^"<< dy << "z^" << dz;

	return(os);
}

Polinom::Polinom()
{
}

Polinom::~Polinom()
{
}

void Polinom::ToStandartView()
{
	Node<Monom>* cur = head;
	Node<Monom>* temp;
	double eps = 0.00000000001;

	while (cur != NULL)
	{
		if (abs(cur->data.coef) <  eps)
		{
			temp = cur->next;
			Delete(cur);
			cur = temp;
		}
		else
		{
			if (cur->next != NULL && cur->next->data.deg == cur->data.deg)
			{
				cur->data.coef += cur->next->data.coef;
				Delete(cur->next);
			}
			else
			{
				cur = cur->next;
			}
		}
	}
}

Polinom& Polinom::operator= (List<Monom>& pol)
{
	List<Monom>::operator=(pol);
	return(*this);
}

Polinom& Polinom::operator= (Polinom& pol)
{
	List<Monom>::operator=(pol);
	return(*this);
}

Polinom Polinom::operator+ (Polinom& pol)
{
	Polinom res;
	res = Merge(pol);
	res.ToStandartView();
	return(res);
}

Polinom Polinom::operator* (double _const) 
{
	Polinom res;
	Node<Monom>* cur;

	if (_const == 0.0)
		return (res);

	res = (*this);
	cur = res.head;

	while (cur != NULL)
	{
		cur->data.coef *= _const;
		cur = cur->next;
	}

	return(res);
}

Polinom Polinom::operator- (Polinom& pol)
{
	Polinom res;
	res = (*this) + pol * (-1);
	return(res);
}

Polinom Polinom::operator* (Monom& mon)
{
	Polinom res;
	Node<Monom>* cur = head;
	Node<Monom>* last;
	Node<Monom> fk_head;
	last = &fk_head;
	double eps = 0.00000000001;

	if (abs(mon.coef) < eps)
		return(res);

	while (cur != NULL)
	{
		Node<Monom>* temp = new Node<Monom>;
		temp->data.coef = mon.coef * cur->data.coef;
		temp->data.deg = mon.deg + cur->data.deg;

		if (temp->data.RetSum() != (mon.RetSum() + cur->data.RetSum()))
			throw "Error: degree of x/y/z more than 9";

		temp->prev = last;
		last->next = temp;
		last = temp;
		cur = cur->next;
	}

	res.head = fk_head.next;
	res.head->prev = NULL;
	res.end = last;

	return(res);
}

Polinom Polinom::operator* (Polinom& pol)
{
	Polinom res;
	Node<Monom>* cur = pol.head;

	while (cur != NULL)
	{
		res = res.Merge((*this) * cur->data);
		cur = cur->next;
	}

	res.ToStandartView();

	return (res);
}

void Polinom::Print()
{
	if ( (*this).IsEmpty() )
		std::cout << "0";

	Node<Monom>* cur = head;

	while (cur != NULL)
	{
		std::cout << cur->data;

		if (cur->next != NULL)
			std::cout << " + ";

		cur = cur->next;
	}

	std::cout << std::endl;
}








