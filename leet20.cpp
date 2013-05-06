/*
   Valid Parentheses
   */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution 
{
	public:
		bool isValid(string s)
		{
			int len = s.length();
			char* sk = new char[len];
			int top = 0;

			for (int i = 0; i < len; i++)
			{
				if (s[i] == '(' || s[i] == '{' || s[i] == '[')
					sk[top++] = s[i];
				else if (top > 0 && isPair(sk[top - 1], s[i]))
					top--;
				else 
					return false;
			}

			return top == 0;
		}

		bool isPair(char x, char y)
		{
			return (x == '(' && y == ')')
				|| (x == '[' && y == ']')
				|| (x == '{' && y == '}');
		}
};

int main()
{
	Solution s;
	cout << s.isValid("()([]){[][]}") << endl;
	cout << s.isValid("()[]}") << endl;

	return 0;
}
