#pragma once
#include <cassert>
#include <iostream>
using namespace std;

//1.Добавить в контейнерный класс, который был написан в этом уроке, методы:
//	- для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//	- для удаления первого элемента массива(аналог pop_front() в векторах)
//	- для сортировки массива
//	- для вывода на экран элементов.

class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr) { }
	ArrayInt(int length) : m_length(length)
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt()
	{
		delete[] m_data;
	}
	void erase();
	int getLength();
	int& operator[] (int index);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void push_back(int value);
	void deleteAfter(int index);
	void deleteBefore(int index);
	void pop_back();
	void pop_front();
	void print();
	void sort();
};
