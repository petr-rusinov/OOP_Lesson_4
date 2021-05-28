﻿#include <iostream>
#include "ArrayInt.h"
#include <vector>
#include <algorithm>

using namespace std;

//1.Добавить в контейнерный класс, который был написан в этом уроке, методы:
//	- для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//	- для удаления первого элемента массива(аналог pop_front() в векторах)
//	- для сортировки массива
//	- для вывода на экран элементов.




//2.Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.

int findDifferent(vector<int> vec)
{
	vector<int>::const_iterator iter;
	sort(vec.begin(), vec.end());

	int i = 1; //счетчик различных чисел. в худшем случае - все числа одинаковые, поэтому минимально i==1

	int prev = vec[0]; //для хранения предыдущих значений

	//последовательно сравниваем предыдущее значение с текущим в отсортированном векторе

	for (iter = vec.begin()+1; iter != vec.end(); ++iter)
	{
		if (*iter != prev)
		{
			++i;
		}
		prev = *iter;
	}
	return i;
}

void task_2()
{
	vector<int> v = { 5, 3, 4, 3, 2, 4, 1, 6, 7, 25, 32, 3, 55, 1, 1, 4 };

	cout << "There are " << findDifferent(v) << " different values in vector" << endl;
}

//3.Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : 
//	вектор указателей карт(удобно использовать вектор, т.к.это по сути динамический массив, а тип его 
//	элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
//	- метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//	- метод Clear, который очищает руку от карт
//	- метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).



enum eSuit { CLUBS, SPADES, DIAMONDS, HEARTS }; //крести, пики, буби, черви
enum eRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};


const int cardsOneSuit = 13; //количество карт одной масти

class Card
{
	eSuit m_suit;
	eRank m_rank;
	bool m_isFaceUp;
public:
	Card(eSuit suit, eRank value, bool pos) : m_suit(suit), m_rank(value), m_isFaceUp(pos) {}
	void flip() { m_isFaceUp = !m_isFaceUp; }
	int getValue() { return m_rank; }
};

class Hand
{
private:
	vector<Card*> m_cards; //колода карт
public:
	Hand()
	{
		for (int i = 1; i <= cardsOneSuit; i++)
		{
			Card card(eSuit::CLUBS, static_cast<eRank>(i), true);
			m_cards.push_back(&card);
		}
	}
	void add(Card* pCard) { m_cards.push_back(pCard); }
	void clear() { m_cards.clear(); }
	int getTotal() 
	{
		int s = 0;

		for (Card* c : m_cards)
		{
			s += static_cast<int>(c->getValue());
			int val = c->getValue();
			if (val > ACE && val < JACK)
				s += val;
			else if (val >= JACK)
				s += 10;
			//обработать ситуацию с тузом


		}
		return s;
	}
};


int main()
{
	Hand hand;
	int v = hand.getTotal();
	task_2();

	srand(time(0));

	ArrayInt arr;
	for (int i = 0; i < 10; ++i)
		arr.push_back(rand()%100);
	arr.print();
	arr.sort();
	arr.print();
	//arr.deleteAfter(3);
	//arr.pop_back();
	//arr.deleteBefore(3);
	arr.pop_front();
	arr.print();
}
