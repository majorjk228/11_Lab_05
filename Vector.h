#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<class T>
class Vector
{
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	void Print();
	void Add();
	void Razn();
	T Max();
	T Min();
	void Del(int pos);
	void Summa();
};


//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}


//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}

 
//печать
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}


//добавление элемента в стек
template <class T>
void Vector<T>::Add()
{
	T m = Min();
	s.push(m);
}


//Разница между объектами
template <class T>
void Vector<T>::Razn()
{
	T min = Min();
	T max = Max();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(max - min);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}


//поиск максимального элемента
template <class T>
T Vector<T>::Max()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if (s.top() > m)m = s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}


//поиск минимального элемента
template <class T>
T Vector<T>::Min()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if (s.top() < m)m = s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}

//удаление элемента из вектора
template <class T>
void Vector<T>::Del(int pos)
{

	vector<T> v;
	T t;
	int i = 1;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если t не равен максимальному, то добавить его в вектор
		if (i != pos)v.push_back(t);
		s.pop();//удалить элемент из стека
		i++;
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}


//деление всех элементов на минимальный
template <class T>
void Vector<T>::Summa()
{
	T m = Min();
	T ma = Max();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t + m + ma);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
