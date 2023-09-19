#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);//добавление элемента в конец списка
	void pop_front();//удаление первого элемента в списке
	void clear();// очистить список
	int GetSize()// получить количество элементов в списке
	{
		return Size;
	}

	T& operator[](const int index);// перегруженный оператор [] 

	void push_front(T data); //добавление элемента в начало списка
	
	void removeAt(int index);//удаление элемента в списке по указанному индексу
	void pop_back();//удаление последнего элемента в списке

	bool search(T value);//проверить, есть ли элемент в словаре
	void insert(T data);//добавить элемент
	void remove(T data);//удалить элемент 
	void merge(List<T>& other);// объединение списков
	void deleteList(List<T>& other);//Удалить словарь
	List<T> getIntersection(List<T>& dict1, List<T>& dict2);//Получить пересечение словарей

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext; //следующий эелемент
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node<T>* head;

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	// Проверяем, есть ли элемент уже в списке
	if (search(data)) {
		return; // Если да, то не добавляем его
	}

	if (head == nullptr)// Проверяем, есть ли хоть один элемент в списке
	{
		head = new Node<T>(data);//Создается новый узел и становится головой
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index) //Найти элемент по индексу
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}


template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}


template<typename T>
bool List<T>::search(T value)
{
	for (int i = 0; i < GetSize(); i++)
	{
		if (value == (*this)[i])
		{
			return true;
		}
	}
	return false;
}

template<typename T>
void List<T>::insert(T data)
{
	// Проверяем, есть ли элемент уже в списке
	if (search(data)) {
		return; // Если да, то не добавляем его
	}
	// Если список пуст, добавляем элемент в начало списка
	if (head == nullptr)
	{
		head = new Node<T>(data);
		Size++;
		return;
	}
	if (data < head->data)
	{
		push_front(data);
		return;
	}
	Node<T>* current = head;
	while (current->pNext != nullptr && data > current->pNext->data)
	{
		current = current->pNext;
	}
	if (data != current->data && (current->pNext == nullptr || data < current->pNext->data))
	{
		current->pNext = new Node<T>(data, current->pNext);
		Size++;
	}
}

template<typename T>
void List<T>::remove(T data)
{
	// Если список пуст, удалять нечего
	if (head == nullptr)
	{
		return;
	}

	if (head->data == data)
	{
		pop_front();
		return;
	}
	Node<T>* current = head;
	while (current->pNext != nullptr && current->pNext->data != data)
	{
		current = current->pNext;
	}
	if (current->pNext != nullptr && current->pNext->data == data)
	{
		Node<T>* temp = current->pNext;
		current->pNext = temp->pNext;
		delete temp;
		Size--;
	}
}
template<typename T>
inline void List<T>::merge(List<T>& other)
{
	for (int i = 0; i < other.GetSize(); i++) // перебираем элементы другого списка
	{
		T data = other[i];
		if (!search(data)) // если элемент уже есть в этом списке, то пропускаем его
		{
			insert(data); // иначе добавляем элемент 
		}
	}
	other.clear(); // очищаем другой список
}

template<typename T>
inline void List<T>::deleteList(List<T>& other)
{
	for (int i = 0; i < other.GetSize(); i++) // перебираем элементы другого списка
	{
		T data = other[i];
		if (search(data)) // если элемент уже есть в этом списке, то удаляем его
		{
			remove(data);  
		}
	}
}

template<typename T>
List<T> getIntersection(List<T>& dict1, List<T>& dict2)
{
	List<T> result;
	for (int i = 0; i < dict1.GetSize(); i++) 
	{
		T data = dict1[i];
		if (dict2.search(data)) {
			result.insert(data);
		}
	}
	return result;
}

#endif