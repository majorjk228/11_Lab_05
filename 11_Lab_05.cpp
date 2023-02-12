// Лабораторная работа №11(5), Вариант 3 (2 семестр).
//

#include "Time.h" 
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;

int main()
{
	Vector<Time>v(3);
	v.Print();

	cout << "Min= " << v.Min() << endl;
	cout << "Max= " << v.Max() << endl;

	cout << "minus max-min-element" << endl;
	v.Razn();
	v.Print();
}

