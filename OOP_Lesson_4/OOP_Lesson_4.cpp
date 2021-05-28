#include <iostream>
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



enum class eSuit { CLUBS, SPADES, DIAMONDS, HEARTS }; //крести, пики, буби, черви
enum eValue { ACE = 1, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO, ONE };

const int cardsOneSuit = 14; //количество карт одной масти

class Card
{
	eSuit m_suit;
	eValue m_value;
	bool m_position;
public:
	Card(eSuit suit, eValue value, bool pos) : m_suit(suit), m_value(value), m_position(pos) {}
	void flip() { m_position = !m_position; }
	eValue getValue() { return m_value; }
};

class Hand
{
private:
	vector<Card> m_deck; //колода карт
public:
	Hand()
	{
		for (int i = 1; i <= cardsOneSuit; i++)
		{
			Card card(eSuit::CLUBS, static_cast<eValue>(i), true);
			m_deck.push_back(card);
		}
	}
	void add(Card& card) { m_deck.push_back(card); }
	void clear() { m_deck.clear(); }
	int getValue() 
	{
		int s = 0;

		for (Card c : m_deck)
		{
			s += static_cast<int>(c.getValue());
		}
		return s;
	}
};


int main()
{
	Hand hand;
	int v = hand.getValue();
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
