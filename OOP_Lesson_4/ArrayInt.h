#pragma once
#include <cassert>

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
		//надо массив обнулить
		else
			m_data = nullptr;
	}

	~ArrayInt()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	int getLength() { return m_length; }

	int& operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	void resize(int newLength)
	{
		if (newLength == m_length)
			return;
		if (newLength <= 0)
		{
			erase();
			return;
		}
		int* data = new int[newLength];
		//надо массив обнулить
		if (m_length > 0) // вот это условие не нужно. m_length в этой точке всегда будет > 0, другие случаи обработаны выше
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}
};

