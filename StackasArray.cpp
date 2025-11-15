#include<iostream>
using namespace std;
class Stack {
private:
	int array_capacity;
	int stack_size;
	int* array;
public:
	Stack(int n)
	{
		stack_size = 0;
		array_capacity = max(1, n);
		array = new int[array_capacity];
	}
public:
	bool empty()
	{
		return (stack_size == 0);
	}
public:
	int top()
	{
		if (empty())
		{
			cout << "Stack is empty";
			return 0;
		}
	else
		{
			return array[stack_size-1];
			
		}
	
	}
public:
	int pop()
	{ if(empty())
	{
		cout << "Stack is already empty";
		return 0;
	}
	else
	{
		--stack_size;
		return array[stack_size];
	
	}

	}
public:
	void push(int val)
	{
		if (stack_size == array_capacity)
		{
			double_capacity();
		}
		
			array[stack_size] = val;
			stack_size++;
		
	}
public:
	void double_capacity()
	{
		int* newarray = new int[2 * array_capacity];
		for(int i=0;i<stack_size;i++)
		{
			newarray[i] = array[i];
		}
		delete[]array;
		array = newarray;
		array_capacity *= 2;
	}
public:
	~Stack()
	{
		delete[]array;
	}

};
int main()
{
	Stack s1(5);
	s1.push(5);
	s1.push(10);
	s1.push(15);
	int popele = s1.pop();
	cout << "Popped element of stack is :" << popele << endl;
	int topele = s1.top();
	cout << "THE Top element of stack is :" << topele;
	return 0;
}