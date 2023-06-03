#include<iostream>
#include<string>
using namespace std;
#define PI 4 * atan(1)

class Node
{
public:
	Node(Node* left = NULL, Node* right = NULL)
	{
		this->left = left;
		this->right = right;
		cout << "NODE Created" << endl;
	}

	void LinkNode(Node* left = NULL, Node* right = NULL)
	{
		this->left = left;
		this->right = right;
	}

	virtual void Output(ostream& o) const = 0;

	virtual double calRet() = 0;

	Node* left = NULL;
	Node* right = NULL;
};


class Number : public Node
{
public:
	Number(double n)
	{
		num = n;
		cout << "NUMBER Created" << endl;
	}

	void Output(ostream& cout) const
	{
		cout << num;
	}

	double calRet()
	{
		return num;
	}

private:
	double num;
};

class Function : public Node
{
public:
	Function(string n)
	{
		name = n;
		cout << "FUNCTION Created" << endl;
	}

	void Output(ostream& cout) const
	{
		cout << name << "(";
		if (left != NULL)
		{
			left->Output(cout);
		}
		if (right != NULL)
		{
			cout << ",";
			right->Output(cout);
		}
		cout << ")";
	}

	double calRet()
	{
		if (name == "sin")
		{
			if (left != NULL)
			{
				return sin(left->calRet());
			}
			if (right != NULL)
			{
				return sin(right->calRet());
			}
		}
		cout << "Error!" << endl;
		exit(0);
	}
private:
	string name;
};

class Variable : public Node
{
public:
	Variable(string name)
	{
		this->name = name;
		cout << "VARIABLE Created" << endl;
	}

	void Output(ostream& cout) const
	{
		cout << name;
	}

	double calRet()
	{
		if (name == "pi")
		{
			return PI;
		}
		cout << "Error!" << endl;
		exit(0);
	}

private:
	string name;
};

class Operator : public Node
{
public:
	Operator(string name)
	{
		this->name = name;
		cout << "OPERATOR Created" << endl;
	}

	void Output(ostream& cout) const
	{
		if (left != NULL)
		{
			left->Output(cout);
		}
		cout << name;
		if (right != NULL)
		{
			right->Output(cout);
		}
	}

	double calRet()
	{
		if (this->name == "+")
		{
			return left->calRet() + right->calRet();
		}
		if (this->name == "-")
		{
			return left->calRet() - right->calRet();
		}
		if (this->name == "/")
		{
			return left->calRet() / right->calRet();
		}
		if (this->name == "*")
		{
			return left->calRet() * right->calRet();
		}
		cout << "Error!" << endl;
		exit(0);
	}
private:
	string name;
};

ostream& operator<<(ostream& cout, const Node& name)
{
	name.Output(cout);
	return cout;
}

int main()
{
	Function func("sin");
	Variable pi("pi");
	Operator o1("/");
	Operator o2("+");
	Number num1(0.5);
	Number num2(6);

	o2.LinkNode(&func, &num1);
	func.LinkNode(&o1);
	o1.LinkNode(&pi, &num2);

	cout << o2 << "=" << o2.calRet() << endl;

	system("pause");

	return 0;
}