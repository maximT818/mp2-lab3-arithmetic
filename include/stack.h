// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыдел€тьс€ пам€ть



#pragma once
#include <iostream>

#include <cmath>

template <typename ValType>
class Stack {
private:
	int Size; //индекс максимального
	int MaxSize; //максимальное кол-во элементов
	ValType* pVector;
	bool IsFull();
public:
	Stack();
	Stack(int maxSize);
	Stack(const Stack& st0);
	~Stack();
	int GetSize() { return (Size + 1); }
	int GetMaxSize() { return MaxSize; }
	bool IsEmpty();
	void push(ValType value);
	ValType pop();
	ValType show();
	bool operator==(const Stack& st0) const;
	Stack& operator=(Stack& st0);
};

template <typename ValType>
Stack<ValType>::Stack() : Size(-1), MaxSize(8), pVector(new ValType[MaxSize]{}) {}

template <typename ValType>
Stack<ValType>::Stack(int maxSize) : Size(-1), MaxSize(maxSize), pVector(new ValType[MaxSize]{}) {}

template <typename ValType>
Stack<ValType>::Stack(const Stack& st0) : Size(-1), MaxSize(st0.MaxSize) 
{
	this->pVector = new ValType[MaxSize];

	for (int i = 0; i < MaxSize; i++)
	{
		this->pVector[i] = 0;
	}

	for (int i = 0; i < Size; i++)
	{
		this->pVector[i] = st0.pVector[i];
	}

}

template<typename ValType>
Stack<ValType>::~Stack()
{
	delete[] pVector;
}

template<typename ValType>
bool Stack<ValType>::IsEmpty()
{
	if (Size == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<typename ValType>
bool Stack<ValType>::IsFull()
{
	if (Size + 1 == MaxSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<typename ValType>
void Stack<ValType>::push(ValType value)
{
	if (this->IsFull())
	{
		ValType* saver = new ValType[MaxSize * 2]{};


		for (int i = 0; i < MaxSize; i++)
		{
			saver[i] = this->pVector[i];
		}

		saver[++Size] = value;


		this->pVector = saver;
	}
	else
	{
		this->pVector[++Size] = value;
	}
}

template<typename ValType>
ValType Stack<ValType>::pop()
{
	if (this->IsEmpty())
	{
		throw "Stack is empty!";
	}
	else
	{
		return this->pVector[Size--];
	}
}

template<typename ValType>
ValType Stack<ValType>::show()
{
	//There is no check for emptiness, since it is easier to implement the check of operations in Postfix this way
	return this->pVector[Size];
}
	

template<typename ValType>
bool Stack<ValType>::operator==(const Stack<ValType>& st0) const
{
	if (this->Size == st0.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (this->pVector[i] != st0.pVector[i])
			{
				return 0;
			}
		}

		return 1;
	}
	else
	{
		return 0;
	}
	
}

template<typename ValType>
Stack<ValType>& Stack<ValType>::operator=(Stack<ValType>& st0)
{
	if (!(* st0 == *this))
	{
		delete this->pVector;
		this->pVector = new ValType[st0.MaxSize];
		this->Size = st0.Size;

		for (int i = 0; i < st0.MaxSize; i++)
		{
			this->pVector[i] = 0;
		}
	}

	return *this;
}