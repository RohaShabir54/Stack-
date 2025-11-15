#include<iostream>;
using namespace std;
class Node
{
public:
	int data;
	Node* next_ptr;
public:
	Node(int val = 0, Node* n = nullptr)
	{
		data = val;
		next_ptr = n;
	}
public:
	int retreive()
	{
		return data;
	}
public:
	Node* next()
	{
		return next_ptr;
	}

};

class List

{
public:
	Node* list_head;
public:
	List()
	{
		list_head = nullptr;
	}
public:
	bool empty()
	{
		return list_head == nullptr;
	}

public:
	int front()const
	{
		return list_head->retreive();
	}
public:
	int back()const
	{
		Node* temp = list_head;
		while (temp->next_ptr != nullptr)
		{

			temp = temp->next_ptr;
		}
		return temp->retreive();
	}
public:
	void push_front(int val)
	{
		list_head = new Node(val, list_head);
	}
public:
	int pop_front()
	{
		if (empty())
		{
			cout << "List is already empty" << endl;
		}
		else
		{
			Node* temp = list_head;
			int val = list_head->retreive();
			list_head = list_head->next_ptr;
			delete temp;
			return val;
		}
	}

	



};

class Stack
{ private:
	List s1;
public:
	bool empty()
	{
		return s1.empty();
	}
public:
	int front()
	{
		if (empty())
		{
			cout << "List is empty";
			return 0;
		}
		else
		{
			return s1.front();
		}
	}
public:
	void push(int val)
	{
		s1.push_front(val);
	}
public:
	int pop()
	{ if(empty())
	{
		cout << "List is empty";
		return 0;
	}
	else
	{
		int ele= s1.pop_front();
		return ele;
	}
	}

};
int main()
{
	Stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	int topele = s1.front();
	cout << "The top element of stack is:" << topele << endl;
	int popele = s1.pop();
	cout << "The popped element from the stack is :" << popele;
	return 0;
}