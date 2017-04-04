// LR4b.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <future>
#include <mutex> 
#include <condition_variable>
#include <iostream>

using namespace std;
mutex mut1;
condition_variable con_var;


class Area
{
protected:
	double first_side;
	double second_side;
public:
	Area(double x, double y);
	double Get_x() { return first_side; }
	double Get_y() { return second_side; }
	virtual void show_area() = 0;

	Area & operator = (Area & op2)
	{
		first_side = op2.Get_x();
		second_side = op2.Get_y();
		return*this;
	}
};
Area::Area(double x, double y)
{
	first_side = x;
	second_side = y;
}
class triangle :public Area {
public:
	triangle(double x, double y);
	void show_area() {
		cout << "The triangle with height ";
		cout << first_side << " and the base " << second_side;
		cout << " have an area of ";
		cout << first_side*0.5*second_side << ".\n";
		cout << endl;
		
	}
};
triangle::triangle(double x, double y) :Area(x, y) {}

class circle :public Area {
public:
	circle(double x, double y);
	void show_area() {
		cout << "A circle with radius ";
		cout << first_side;
		cout << " have an area of ";
		cout << first_side*first_side*3.14 << ".\n";
		
	}
};
circle::circle(double x, double y) :Area(x, y) {}
void thread1()
{
	Area*p;
	triangle t(7.0, 13.0);
	p = &t;
	p->show_area();
	cout <<endl;
	con_var.notify_one();

}

void thread2()
{
	Area*p;
	circle c(8.0, 0.0);
	p = &c;
	p->show_area();
	unique_lock<mutex> lock(mut1);
	con_var.wait(lock);


}
void main()
{
	auto f1 = async(launch::async, thread1);
	auto f2 = async(launch::async, thread2);
	system("pause");
}

