#ifndef _MY_DLIST
#define _MY_DLIST


template<class TYPE>
void SWAP(TYPE& a, TYPE& b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

template <class TYPE>
class Dnode
{
public:
	TYPE data;
	Dnode<TYPE>* next = nullptr;
	Dnode<TYPE>* prev = nullptr;
	Dnode(const TYPE& data) :data(data)
	{}
};




template <class TYPE>
class DList
{
public:
	Dnode<TYPE>* first = nullptr;
public:

	bool empty()const
	{
		return (first == nullptr);
	}
	unsigned int size()const
	{
		unsigned int size = 0;
		Dnode<TYPE>* temp = first;


		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}



		return size;
	}
	Dnode<TYPE>* end()const
	{
		Dnode<TYPE>* temp = first;
		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}

		return temp;
	}


	void push_back(const TYPE& ref)
	{
		Dnode<TYPE>* temp = first;
		Dnode<TYPE>* previous = first;
		Dnode<TYPE>* newnode = new Dnode<TYPE>(ref);
		if (temp == nullptr)
		{
			first = newnode;

		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = newnode;
			newnode->prev = temp;
		}

	}
	void push_front(const TYPE& ref)
	{
		Dnode<TYPE> *temp = first;
		first = new Dnode<TYPE>(ref);
		first->next = temp;
		if (temp != nullptr)
		{
			temp->prev = first;
		}



	}

	bool pop_back()//revise
	{
		Dnode<TYPE> *del = end();
		Dnode<TYPE> *temp = end();
		if (first->next != nullptr)
		{
			temp = temp->prev;
			temp->next = nullptr;
			delete del;
			return true;

		}
		else
		{
			delete first;
			return false;
		}


	}
	bool pop_front()
	{
		if (first != nullptr)
		{
			if (first->next != nullptr)
			{
				Dnode <TYPE> * temp = first;
				first = first->next;
				first->prev = nullptr;
				delete temp;
				return true;
			}
			else
			{
				Dnode <TYPE> * temp = first;
				first = nullptr;
				delete temp;
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	void erase(Dnode<TYPE>* ref)
	{
		if (ref != nullptr)
		{
			if (ref != first)
			{

				if (ref->prev == nullptr)
				{
					ref->next->prev = nullptr;
				}
				else if (ref->next == nullptr)
				{
					ref->prev->next = nullptr;
				}


				else
				{
					ref->prev->next = ref->next;
					ref->next->prev = ref->prev;

				}
				delete ref;
			}
			else
			{
				first = first->next;
				delete ref;
			}

		}

	}
	void insert(Dnode<TYPE>* ref, TYPE data)
	{

		Dnode<TYPE> *temp = new Dnode<TYPE>(data);

		if (first != nullptr)
		{
			if (ref->prev == nullptr)
			{
				ref->prev = temp;
				temp->next = ref;
				first = temp;

			}

			else
			{
				temp->next = ref;
				temp->prev = ref->prev;
				ref->prev->next = temp;
				ref->prev = temp;
			}

		}
		else
		{
			first = temp;
		}
	}

	void Flip()
	{
		Dnode<TYPE>*begin = first;
		Dnode<TYPE>*finale = end();
		TYPE temp = first->data;
		int u = size() / 2;
		for (int i = 0; i < size() / 2; i++)
		{/*
		 begin->data = finale->data;
		 finale->data = temp;
		 begin = begin->next;
		 temp = begin->data;
		 finale = finale->prev;
		 */
			SWAP(begin->data, finale->data);
			begin = begin->next;
			finale = finale->prev;
		}
	}
	unsigned int delnodes(unsigned int pos, unsigned int ammount)
	{
		Dnode<TYPE>*temp = first;
		Dnode<TYPE>*position;
		unsigned int counter = 0;
		for (unsigned int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		position = temp;
		for (unsigned int i = 0; i < ammount; i++)
		{
			if (temp->next != nullptr)
			{
				temp = temp->next;
				counter++;
			}
			else
			{
				break;
			}
		}
		if (temp->next != nullptr)
		{
			temp->next->prev = position;
			position->next = temp->next;
			temp = position->next;
		}
		else
		{
			temp = position->next;
			position->next = nullptr;
			//return counter;
		}
		//DELETE THEM

		for (unsigned int i = 0; i < ammount; i++)
		{
			if (temp->next != nullptr)
			{
				Dnode<TYPE>* del = temp;
				temp = temp->next;
				delete del;
			}
			else
			{
				delete temp;
				break;
			}
		}
		return counter;
	}








	/*

	unsigned int DelNodes(unsigned int pos, unsigned int ammount)
	{
	Dnode<TYPE>*temp = first;
	Dnode<TYPE>*element;
	Dnode<TYPE>* last ;
	unsigned int counter = 0;
	for (unsigned int i = 0; i < pos-1; i++)
	{
	temp = temp->next;
	}
	element = temp;
	last = temp->next;
	for (unsigned int i = 0; i < ammount; i++)
	{


	if (temp->next != nullptr)
	{
	temp = temp->next;
	temp->next->prev = element;
	element->next = temp;
	counter++;
	}
	else
	{
	element->next = nullptr;
	return counter;
	}
	}

	//DELETE THEM
	temp = first;
	for (unsigned int i = 0; i < ammount ; i++)
	{
	if (last->next != nullptr)
	{
	Dnode<TYPE>* extra = last;
	last = last->next;
	delete extra;
	}
	else
	return counter;

	}
	return counter;
	}
	*/

};
#endif