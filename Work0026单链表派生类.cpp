#include<iostream>
using namespace std;
#include<string>

class Object
{
public:
	Object() {};
	virtual bool operator > (Object&) = 0;
	virtual bool operator != (Object&) = 0;
	virtual void Print() = 0;
	virtual ~Object() {}
};

class Node
{
public:
	Node();
	~Node();
	void InsertAfter(Node* p);
	Node* RemoveAfter();
	void Linkinfo(Object* obj);
	friend class List;

private:
	Object* info;
	Node* link;
};

Node::Node()
{
	this->info = NULL;
	this->link = NULL;
}

Node::~Node()
{
	cout << "Delete Node" << endl;
	delete this->info;
}

void Node::InsertAfter(Node* p)
{
	p->link = this->link;
	this->link = p;
}

Node* Node::RemoveAfter()
{
	Node* tempP = this->link;
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

void Node::Linkinfo(Object* obj)
{
	this->info = obj;
}

class List
{
public:
	List();
	~List();
	void MakeEmpty();
	Node* Find(Object& obj);
	int Length();
	void PrintList();
	void InsertFront(Node* p);
	void InsertRear(Node* p);
	void InsertOrder(Node* p);
	Node* CreateNode();
	Node* DeleteNode(Node* p);

private:
	Node* head;
	Node* tail;
};

List::List()
{
	this->head = this->tail = new Node();
}

List::~List()
{
	MakeEmpty();
	delete this->head;
}

void List::MakeEmpty()
{
	Node* tempP;
	while (this->head->link != NULL)
	{
		tempP = this->head->link;
		this->head->link = tempP->link;
		delete tempP;
	}
	this->tail = this->head;
}

Node* List::Find(Object& obj)
{
	Node* tempP = this->head->link;
	while (tempP != NULL && *(tempP->info) != obj)
	{
		tempP = tempP->link;
	}
	return tempP;
}

int List::Length()
{
	Node* tempP = this->head->link;
	int count = 0;
	while (tempP != NULL)
	{
		tempP = tempP->link;
		count++;
	}
	return count;
}

void List::PrintList()
{
	Node* tempP = this->head->link;
	while (tempP != NULL)
	{
		tempP->info->Print();
		tempP = tempP->link;
	}
	cout << endl;
}

void List::InsertFront(Node* p)
{
	p->link = this->head->link;
	this->head->link = p;
	if (this->tail == this->head)
	{
		this->tail = p;
	}
}

void List::InsertRear(Node* p)
{
	p->link = this->tail->link;
	this->tail->link = p;
	this->tail = p;
}

void List::InsertOrder(Node* p)
{
	Node* tempP = this->head->link;
	Node* tempQ = this->head;
	while (tempP != NULL)
	{
		if (*(tempP->info) > *(p->info))
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

Node* List::CreateNode()
{
	Node* tempP = new Node();
	return tempP;
}

Node* List::DeleteNode(Node* p)
{
	Node* tempP = this->head;
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

class StringObject :public Object
{
public:
	StringObject();
	StringObject(string);
	~StringObject();
	bool operator>(Object&);
	bool operator!=(Object&);
	void Print();

private:
	string sptr;
};

StringObject::StringObject()
{
	this->sptr = "";
}

StringObject::StringObject(string s)
{
	this->sptr = s;
}

StringObject::~StringObject()
{

}

bool StringObject::operator>(Object& obj)
{
	StringObject& temp = (StringObject&)obj;
	return this->sptr > temp.sptr;
}

bool StringObject::operator!=(Object& obj)
{
	StringObject& temp = (StringObject&)obj;
	return this->sptr != temp.sptr;
}

void StringObject::Print()
{
	cout << this->sptr << "\t";
}


int main()
{
	List list1, list2, list3;
	const char* a[5] = { "dog","cat","bear","sheep","ox" };
	const char* sp = "cat";
	for (int i = 0; i < 5; ++i)
	{
		StringObject* p = new StringObject(a[i]);
		Node* P1 = list1.CreateNode();
		P1->Linkinfo(p);
		list1.InsertFront(P1);
		p = new StringObject(a[i]);
		P1 = list2.CreateNode();
		P1->Linkinfo(p);
		list2.InsertRear(P1);
	}
	list1.PrintList();
	cout << "list1 length:" << list1.Length() << endl;


	system("pause");

	return 0;
}