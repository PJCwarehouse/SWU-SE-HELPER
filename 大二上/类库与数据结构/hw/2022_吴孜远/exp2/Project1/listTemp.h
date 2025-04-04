#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class ListTemp
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	int size;

public:

	ListTemp(); //constructor

	~ListTemp(); //destructor

	int getLength() const; //get the number of elements

	bool isEmpty() const; //check whether the container is empty

	// Postcondition: A node with newData has been inserted at the
	//                head of the Linked container.
	void addHead(const T& newData);

	void addTail(const T& newData);

	//************************declaration of the inner iterator class****************************
	class Iterator
	{
		friend class ListTemp<T>; //friend class of the iterator class
	private:
		Node* curr;

		// Postcondition: The iterator has been constructed from ptr.
		Iterator(Node* ptr); //constructor with Node parameter, defined as private

	public:

		// Postcondition: The iterator has been constructed.
		Iterator(); //default constructor

		// Precondition: The iterator is positioned at an item.
		// Postcondition: The iterator has been positioned at
		// the next item in the Linked object.
		Iterator operator++(int); //post-increment of ++

		// Postcondition: A reference to the item the iterator
		// is positioned at has been returned.
		T& operator*() const;

		// Postcondition: true has been returned if the
		// iterator is equal to other; otherwise,
		// false has been returned.
		bool operator==(const Iterator other) const;

	};//class Iterator


	// Postcondition: An iterator positioned at the head of
	//                the Linked container has been returned.
	Iterator Begin() const;

	// Postcondition: An iterator positioned just AFTER the
	//                tail of the Linked container has been
	//                returned. NOT the position at the tail!
	Iterator End() const;

};


//************************implementation of the iterator inner class**************************
template<class T>
ListTemp<T>::Iterator::Iterator()
{
	curr = NULL;
}

template<class T>
ListTemp<T>::Iterator::Iterator(Node* ptr)
{
	curr = ptr;
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Iterator::operator++(int)
{
	Iterator temp = *this; //default copy constructor
	this->curr = curr->next;
	return temp; //return iterator object
}

template<class T>
T& ListTemp<T>::Iterator::operator*() const
{
	return curr->data; //return data reference
}

template<class T>
bool ListTemp<T>::Iterator::operator==(const Iterator other) const
{
	return curr == other.curr;
}


//************************implementation of the Begin and End position**************************
template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Begin() const
{
	return Iterator(head); //container class call the private method (constructor) of the Iterator class: 
	//friend class is required
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::End() const
{
	return Iterator(); //NULL pointer
}


//************************implementation of the linked list class template**************************
template<class T>
ListTemp<T>::ListTemp()
{
	head = NULL; //empty list
	size = 0;
}


template<class T>
ListTemp<T>::~ListTemp()
{
	Node* current = head;
	Node* temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp; //release
	}
}


template<class T>
int ListTemp<T>::getLength() const
{
	return size;
}


template<class T>
bool ListTemp<T>::isEmpty() const
{
	return size == 0;
}


template<class T>
void ListTemp<T>::addHead(const T& newData)
{
	Node* temp = new Node;
	temp->next = head;
	temp->data = newData;
	head = temp;

	size++;
}

template<class T>
void ListTemp<T>::addTail(const T& newData)
{
	//please implement this
	Node* temp = new Node; //新节点
	Node* oldTail = head; //oldTail用于指向先前的最后一个结点，初始化为head
	temp->next = NULL; //没有这个就不行？
	temp->data = newData; //先将传入的data存进新节点

	if (head == NULL) {
		head = temp; //如果之前啥也没有，那么存进来的就是第一个结点
	}
	else {
		while (oldTail->next != NULL) { //让oldTail循环到最后一个结点
			oldTail = oldTail->next;
		}
		oldTail->next = temp; //让最后一个节点的next指向新节点
	}
	size++;
}


#endif