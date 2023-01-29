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
	cout << "Min=" << v.Min() << endl;
	v.Add();//добавление элемента
	v.Print();

	cout << "pos for del?";
	int pos;
	cin >> pos;//вводим позицию для удаления
	v.Del(pos);//удаление элемента
	v.Print();

	cout << "plusuem max+min+element" << endl;
	v.Summa();
	v.Print();
}

