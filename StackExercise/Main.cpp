#include <iostream>
#include "IntStack.h"
using namespace std;
void main()
{
	//StackExercise::IntStack<int, 20> s;
	StackExercise::IntStack<int, 10> s;
	try {
		for (int i = 0; i < 20; i++) {
			s.Push(i);
			cout << "pushed " << i << endl;
		}
	}
	catch (StackExercise::StackOverflowException ex)
	{
		cout << ex.what() << endl;
	}
	try {
		while (true) {
			cout << "poped " << s.Pop() << endl;
		}
	}
	catch (StackExercise::StackUnderflowException ex)
	{
		cout << ex.what() << endl;

	}
}