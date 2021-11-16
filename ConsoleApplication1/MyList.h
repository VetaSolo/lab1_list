#pragma once

#include <iostream>

using namespace std;

class MyList
{
private:
	class Node
	{
	public:
		Node* Next;
		int data;
		Node(int data = 0, Node* Next = nullptr)
		{
			this->data = data;
			this->Next = Next;
		}
	};
public:
	// list is always empty at the beginning
	int Size = 0;
	Node* head = nullptr;

	void push_back(int data)
	{
		if (head == nullptr) //If Head is empty, then just create a new list item
		{
			head = new Node(data);
		}
		else //If Head is not empty, then go through the whole list until we find the last item
		{
			Node* current = this->head;

			while (current->Next != nullptr)
			{
				current = current->Next;
			}
			current->Next = new Node(data);
		}

		Size++;
	}

	void push_front(int data)
	{
		head = new Node(data, head);
		Size++;
	}

	void pop_front()
	{
		//original Head is placed in a temporary variable, next element is new Head
		Node* temp = head;
		head = head->Next;
		Size--;
	}

	int get_size() //Finding the list size
	{
		return Size;
	}

	void insert(int data, int index)
	{
		if (index != 0)
		{
			Node* prev = this->head;
			for (int i = 0; i < index - 1; i++) //search for the previous item in the list
			{
				prev = prev->Next;
			}
			Node* newNode = new Node(data, prev->Next);
			prev->Next = newNode;
		}
		else
		{
			push_front(data);
		}
	}

	void remove(int index)
	{
		if (index != 0)
		{
			Node* prev = this->head;
			for (int i = 0; i < index - 1; i++) //search for the previous item in the list
			{
				prev = prev->Next;
			}
			Node* toDel = prev->Next;
			prev->Next = toDel->Next;
			Size--;
		}
		else
		{
			pop_front();
		}
	}

	void pop_back()
	{
		remove(Size - 1);
	}

	void clear()
	{
		//until the list is empty, delete one item at a time
		while (Size != 0)
		{
			pop_front();
		}
	}

	void set(int data, int index)
	{
		if (Size >= index + 1)
		{
			Node* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->Next;
			}
			current->data = index;
		}
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	int at(int index)
	{
		Node* current = head;
		for (int i = 0; i < index; i++) // go through the list until we find the desired item
		{
			current = current->Next;
		}
		return current->data;
	}

	void reverse()
	{
		Node* prev = nullptr;
		while (head) // swap the two nearby elements one by one 
		{
			Node* Next = head;
			head = head->Next;
			Next->Next = prev;
			prev = Next;
		}
		head = prev;
	}

	friend ostream& operator<< (ostream& out, const MyList& list)
	{
		MyList current; // [1;2;3;4;..]
		current.head = list.head;
		out << "[";
		while (current.head)
		{
			out << current.head->data;
			if (current.head->Next) out << ';';
			current.head = current.head->Next;
		}
		out << "]";
		current.Size = 0;
		return out;
	}
};
