#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};

template<class T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	int getlen();
	T getfirst();
	T  pop();

private:
	Node<T>*front;
	Node<T>*r;
};

template<class T>
LinkList<T>::LinkList()
{
	int len;
	cin >> len;
	front = new Node<T>;
	r = front;

	for (int i = 0; i < len ; i++)
	{

		r->next = new Node<T>;
		r = r->next;
		cin >> r->data;

	}
	r->next = front;
	front->data = len;
}

template<class T>
LinkList<T>::~LinkList()
{
	delete r;
}

template<class T>
int LinkList<T>::getlen()
{
	return front->data;
}


template<class T>
T LinkList<T>::getfirst()
{
	if (r != front)
	{
		return front->next->data;
	}
	else
		throw"error";
}

template<class T>
T LinkList<T>::pop()
{
	if (front == r)
	{
		throw"error";
	}
	else
	{
		T temp = front->next->data;
		Node<T>* pt = front->next->next;
		delete front->next;
		front->next = pt;
		pt = NULL;
		front->data -= 1;
		return temp;
	}

}


int main()
{
	LinkList<int> L;

	cout << L.getlen()<< " " ;
	cout << L.getfirst() << " ";
	cout << L.pop() << " ";
	cout << L.getlen()<<endl;
	//system("pause");
	return 0;
}