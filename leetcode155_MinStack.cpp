#include "include.h"
class MinStack {
public:
	MinStack()
	{
	
	}
	void push(int x)
	{
		m_stack.push(x);
		if (m_stack.size() == 1)m_minValue = x;
		else m_minValue = min(m_minValue, x);
	}
	void pop()
	{
		int top = m_stack.top();
		m_stack.pop();
		if (top == m_minValue)
		{
			m_minValue = INT_MAX;
			stack<int>help_stack;
			while (!m_stack.empty())
			{
				int top = m_stack.top();
				m_minValue = min(m_minValue, top);
				m_stack.pop();
				help_stack.push(top);
			}
			while (!help_stack.empty())
			{
				int top = help_stack.top();
				m_stack.push(top);
				help_stack.pop();
			}
		}
	}
	int top()
	{
		return m_stack.top();
	}

	int getMin()
	{
		return m_minValue;
	}
private:
	stack<int>m_stack;
	int m_minValue;
};