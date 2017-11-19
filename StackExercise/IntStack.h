#pragma once

#include "StackOverflowException.h"
#include "StackUnderflowException.h"

namespace StackExercise
{
	template<typename T,size_t size>
	class IntStack
	{
	public:
		IntStack();
		void Push(T val);
		T Pop();

	private:
		T m_impl[size];
		int m_nextIndex;
	};

	template<typename T, size_t size>
	IntStack<T,size>::IntStack()
		: m_nextIndex(0)
	{}

	template<typename T, size_t size>
	void IntStack<T, size>::Push(T val)
	{
		if (m_nextIndex < size)
		{
			m_impl[m_nextIndex] = val;
			++m_nextIndex;
		}
		else
		{
			throw StackOverflowException();
		}
	}

	template<typename T, size_t size>
	T IntStack<T, size>::Pop()
	{
		if (m_nextIndex > 0)
		{
			--m_nextIndex;
			return m_impl[m_nextIndex];
		}
		else
		{
			throw StackUnderflowException();
		}
	}

}