#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);//���������� �������� � ����� ������
	void pop_front();//�������� ������� �������� � ������
	void clear();// �������� ������
	int GetSize()// �������� ���������� ��������� � ������
	{
		return Size;
	}

	T& operator[](const int index);// ������������� �������� [] 

	void push_front(T data); //���������� �������� � ������ ������
	
	void removeAt(int index);//�������� �������� � ������ �� ���������� �������
	void pop_back();//�������� ���������� �������� � ������

	bool search(T value);//���������, ���� �� ������� � �������
	void insert(T data);//�������� �������
	void remove(T data);//������� ������� 
	void merge(List<T>& other);// ����������� �������
	void deleteList(List<T>& other);//������� �������
	List<T> getIntersection(List<T>& dict1, List<T>& dict2);//�������� ����������� ��������

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext; //��������� ��������
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
	// ���������, ���� �� ������� ��� � ������
	if (search(data)) {
		return; // ���� ��, �� �� ��������� ���
	}

	if (head == nullptr)// ���������, ���� �� ���� ���� ������� � ������
	{
		head = new Node<T>(data);//��������� ����� ���� � ���������� �������
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
T& List<T>::operator[](const int index) //����� ������� �� �������
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
	// ���������, ���� �� ������� ��� � ������
	if (search(data)) {
		return; // ���� ��, �� �� ��������� ���
	}
	// ���� ������ ����, ��������� ������� � ������ ������
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
	// ���� ������ ����, ������� ������
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
	for (int i = 0; i < other.GetSize(); i++) // ���������� �������� ������� ������
	{
		T data = other[i];
		if (!search(data)) // ���� ������� ��� ���� � ���� ������, �� ���������� ���
		{
			insert(data); // ����� ��������� ������� 
		}
	}
	other.clear(); // ������� ������ ������
}

template<typename T>
inline void List<T>::deleteList(List<T>& other)
{
	for (int i = 0; i < other.GetSize(); i++) // ���������� �������� ������� ������
	{
		T data = other[i];
		if (search(data)) // ���� ������� ��� ���� � ���� ������, �� ������� ���
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