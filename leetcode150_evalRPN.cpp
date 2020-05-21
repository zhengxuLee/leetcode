#include "include.h"
int evalRPN(vector<string>& tokens) 
{
	if (tokens.empty())return 0;
	stack<int>operandStack;
	for (int i = 0; i < tokens.size();++i)
	{
		if (tokens[i]=="+" )
		{
			int num1 = operandStack.top();
			operandStack.pop();
			int num2 = operandStack.top();
			operandStack.pop();
			operandStack.push(num1 + num2);
		}
		else if (tokens[i]=="-")
		{
			int num1 = operandStack.top();
			operandStack.pop();
			int num2 = operandStack.top();
			operandStack.pop();
			operandStack.push(num2 - num1);
		}
		else if (tokens[i]=="*")
		{
			int num1 = operandStack.top();
			operandStack.pop();
			int num2 = operandStack.top();
			operandStack.pop();
			operandStack.push(num2 * num1);
		}
		else if (tokens[i]=="/")
		{
			int num1 = operandStack.top();
			operandStack.pop();
			int num2 = operandStack.top();
			operandStack.pop();
			operandStack.push(num2 / num1);
		}
		else
		{
			int num = stoi(tokens[i]);
			operandStack.push(num);
		}
	}
	return operandStack.top();
}