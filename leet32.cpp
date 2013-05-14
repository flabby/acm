/*
   Longest Valid Parentheses
   */

#include "header.h"

class Solution {  
	public:
		int longestValidParentheses(string s)
		{
			int len = s.length();
			int mx = 0;

			cout << "len=" << len << " [" << s << "]\n";

			int *dp = new int[len + 1];
			for (int i = 0; i < len; i++)
				dp[i] = 0;

			for (int i = 1; i < len; i++)
			{
				if (s[i] == ')')
				{
					int j = i - 1 - dp[i - 1];
					if (j >= 0 && s[j] == '(')
						dp[i] = 2 + dp[i - 1] + (j > 0 ? dp[j - 1] : 0);
				}

				mx = max(mx, dp[i]);
			}

			delete[] dp;
			return mx;
		}
/*
		int longestValidParentheses(String s) {  
			// Start typing your Java solution below  
			// DO NOT write main() function  
			if(s==null||s.length()==0) return 0;  
			int l=s.length();  
			int dp[]=new int[l];  
			int max=0,j;  

			for(int i=1;i<l;i++){  
				if(s.charAt(i)==')')
				{ 
					j=i-1-dp[i-1];  
					if(j>=0&&s.charAt(j)=='(') 
						dp[i]=i-j+1+((j>0)?dp[j-1]:0);
				}  

				if(dp[i]>max) max=dp[i];        
			}  
			return max;  
		}  */
};

int main()
{
	Solution s;

	cout << s.longestValidParentheses("(()()") << endl;
	cout << s.longestValidParentheses("()()()") << endl;
	cout << s.longestValidParentheses("(((()))") << endl;
	cout << s.longestValidParentheses(")()())") << endl;

	return 0;
}

