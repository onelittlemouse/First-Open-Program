#include<iostream>
using namespace std;

template<class T>
class List;

template<class T>
class Node
{
	friend class List<T>;
	template<class Type>
	friend ostream& operator<<(ostream& cout, const List<Type>& L);
public:
	Node();
	Node(const T& data);
	void InsertAfter(Node<T>* p);
	Node<T>* RemoveAfter();

private:
	T info;
	Node<T>* link;
};

template<class T>
Node<T>::Node()
{
	this->info = 0;
	this->link = NULL;
}

template<class T>
Node<T>::Node(const T& data)
{
	this->info = data;
	this->link = NULL;
}

template<class T>
void Node<T>::InsertAfter(Node<T>* p)
{
	p->link = this->link;
	this->link = p;
}

template<class T>
Node<T>* Node<T>::RemoveAfter()
{
	Node<T>* tempP = this->link;
	if (this->link == NULL)
	{
		tempP = NULL;
	}
	else
	{
		this->link = tempP->link;
	}
	return tempP;
}

template<class T>
class List
{
	template<class Type>
	friend ostream& operator<<(ostream& cout, const List<Type>& L);
public:
	List();
	~List();
	void MakeEmpty();
	Node<T>* Find(T data);
	int Length();
	void PrintList();
	void InsertFront(Node<T>* p);
	void InsertRear(Node<T>* p);
	void InsertOrder(Node<T>* p); 
	Node<T>* CreateNode(T data);
	Node<T>* DeleteNode(Node<T>* p);
	void ReverseList();
	T AddListInfo();
	T CalListAvg();
	void SortList();

private:
	Node<T>* head;
	Node<T>* tail;
};

template<class T>
List<T>::List()
{
	this->head = new Node<T>();
	this->tail = this->head;
}

template<class T>
List<T>::~List()
{
	MakeEmpty();
	delete this->head;
}

template<class T>
void List<T>::MakeEmpty()
{
	Node<T>* tempP;
	while (this->head->link != NULL)
	{
		tempP = this->head->link;
		this->head->link = tempP->link;
		delete tempP;
	}
	this->tail = this->head;
}

template<class T>
Node<T>* List<T>::Find(T data)
{
	Node<T>* tempP = this->head->link;
	while (tempP != NULL && tempP->info != data)
	{
		tempP = tempP->link;
	}
	return tempP;
}

template<class T>
int List<T>::Length()
{
	Node<T>* tempP = this->head->link;
	int count = 0;
	while (tempP != NULL)
	{
		tempP = tempP->link;
		count++;
	}
	return count;
}

template<class T>
void List<T>::PrintList()
{
	Node<T>* tempP = this->head->link;
	while (tempP != NULL)
	{
		cout << tempP->info << "\t";
		tempP = tempP->link;
	}
	cout << endl;
}

template<class T>
void List<T>::InsertFront(Node<T>* p)
{
	p->link = this->head->link;
	this->head->link = p;
	if (tail == head)
	{
		tail = p;
	}
}

template<class T>
void List<T>::InsertRear(Node<T>* p)
{
	p->link = this->tail->link;
	this->tail->link = p;
	this->tail = p;
}

template<class T>
void List<T>::InsertOrder(Node<T>* p)
{
	Node<T>* tempP = this->head->link;
	Node<T>* tempQ = this->head;
	while (tempP != NULL)
	{
		if (p->info < tempP->info)
		{
			break;
		}
		tempQ = tempP;
		tempP = tempP->link;
	}
	tempQ->InsertAfter(p);
	if (this->tail == tempQ)
	{
		this->tail = tempQ->link;
	}
}

template<class T>
Node<T>* List<T>::CreateNode(T data)
{
	Node<T>* tempP = new Node<T>(data);
	return tempP;
}

template<class T>
Node<T>* List<T>::DeleteNode(Node<T>* p)
{
	Node<T>* tempP = this->head;
	while (tempP->link != NULL && tempP->link != p)
	{
		tempP = tempP->link;
	}
	if (tempP->link == this->tail)
	{
		this->tail = tempP;
	}
	return tempP->RemoveAfter();
}

template<class T>
void List<T>::ReverseList()
{
	Node<T>* temp;
	Node<T>* tempP = NULL;
	Node<T>* tempQ = this->head->link;
	this->tail = tempQ;
	while (tempQ != NULL)
	{
		temp = tempQ->link;
		tempQ->link = tempP;
		tempP = tempQ;
		tempQ = temp;
	}
	if (tempQ == NULL)
	{
		this->head->link = tempP;
	}
}

template<class T>
T List<T>::AddListInfo()
{
	double sum = 0;
	Node<T>* tempP = this->head->link;
	while (tempP != NULL)
	{
		sum += tempP->info;
		tempP = tempP->link;
	}
	return sum;
}

template<class T>
T List<T>::CalListAvg()
{
	return this->AddListInfo() / this->Length();
}

template<class T>
void List<T>::SortList()
{
	T* tempArr = new T[this->Length()]{ 0 };
	int countNum = 0;
	Node<T>* tempP = this->head->link;
	while (tempP != NULL)
	{
		tempArr[countNum] = tempP->info;
		tempP = tempP->link;
		++countNum;
	}
	for (int i = 0; i < this->Length() - 1; ++i)
	{
		for (int j = 0; j < this->Length() - i - 1; ++j)
		{
			if (tempArr[j] > tempArr[j + 1])
			{
				T t = tempArr[j];
				tempArr[j] = tempArr[j + 1];
				tempArr[j + 1] = t;
			}
		}
	}
	countNum = 0;
	Node<T>* tempQ = this->head->link;
	while (tempQ != NULL)
	{
		tempQ->info = tempArr[countNum];
		tempQ = tempQ->link;
		++countNum;
	}
}

template<class T>
ostream& operator<<(ostream& cout, const List<T>& L)
{
	Node<T>* tempP = L.head->link;
	while (tempP != NULL)
	{
		cout << tempP->info << "\t";
		tempP = tempP->link;
	}
	return cout;
}


int main()
{
	List<double> L;
	Node<double>* pn1 = new Node<double>(1.1);
	Node<double>* pn2 = new Node<double>(3.3);
	Node<double>* pn3 = new Node<double>(2.2);
	Node<double>* pn4 = new Node<double>(5.5);
	Node<double>* pn5 = new Node<double>(4.4);
	L.InsertRear(pn1);
	L.InsertRear(pn2);
	L.InsertRear(pn3);
	L.InsertRear(pn4);
	L.InsertRear(pn5);
	
	cout << "初始时链表：" << endl;
	L.PrintList();
	cout << "翻转后链表：" << endl;
	L.ReverseList();
	cout << "成员函数打印：" << endl;
	L.PrintList();
	cout << "重载运算符打印：" << endl;
	cout << L << endl; 
	cout << "链表数据之和：" << endl;
	cout << L.AddListInfo() << endl;
	cout << "链表数据平均值：" << endl;
	cout << L.CalListAvg() << endl;
	cout << "对链表排序：" << endl;
	L.SortList();
	cout << L << endl;

	system("pause");

	return 0;
}