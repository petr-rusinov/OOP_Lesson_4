#include "ArrayInt.h"

void ArrayInt::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int ArrayInt::getLength() { return m_length; }

int& ArrayInt::operator[] (int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

void ArrayInt::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLength];

	if (m_length > 0) 
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	data[index] = value;
	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	++m_length;
}

void ArrayInt::push_back(int value)
{
	insertBefore(value, m_length);
}

void ArrayInt::deleteAfter(int index)
{
	assert(index >= 0 && index < m_length);
	int* data = new int[m_length - 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	for (int after = index + 1; after < m_length; ++after)
		data[after - 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	--m_length;

}

void ArrayInt::deleteBefore(int index)
{
	assert(index > 0 && index <= m_length);
	int* data = new int[m_length - 1];
	for (int before = 0; before < index - 1; ++before)
		data[before] = m_data[before];

	for (int after = index; after < m_length; ++after)
		data[after - 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	--m_length;

}

void ArrayInt::pop_back()
{
	deleteAfter(m_length - 1);
}

void ArrayInt::pop_front()
{
	deleteBefore(1);
}

void ArrayInt::print()
{
	for (int i = 0; i < m_length; ++i)
		cout << m_data[i] << " ";
	cout << endl;
}

void ArrayInt::sort()
{
	bool isSwapped = false;
	do
	{
		isSwapped = false;
		for (int i = 0; i < m_length - 1; ++i)
		{
			if (m_data[i + 1] < m_data[i])
			{
				swap(m_data[i + 1], m_data[i]);
				isSwapped = true;
			}
		}
	} while (isSwapped);
}