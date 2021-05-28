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

	void add(Card* pCard) { m_cards.push_back(pCard); }
	void clear() { m_cards.clear(); }
	int getTotal() 
	{
		int s = 0;
		int acesNum = 0;
		for (Card* c : m_cards)
		{
			int val = c->getValue();
			if (val >= ACE && val < JACK)
			{
				if (val == ACE) acesNum++;
				s += val;
			}
			else if (val >= JACK)
				s += 10;
		}
		if (acesNum < 2) //Если вдруг тузов больше 1, нет смысла их считать как 11
		{
			if ((s + 10) <= 21) //Пробуем считать туз как 11, поэтому добавляем к общей сумме 10
				s += 10;
		}
		return s;
	}
};


int main()
{
	Hand hand;
	Card c1(SPADES, NINE, true);
	Card c2(SPADES, TWO, true);
	Card c3(SPADES, ACE, true);

	hand.add(&c1);
	hand.add(&c2);
	hand.add(&c3);

	int v = hand.getTotal();
	cout << "Hand total score: " << v << endl;
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
