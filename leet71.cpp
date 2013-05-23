/*
   Simplify Path
   */
#include "header.h"

class Solution
{
	public:
		string simplifyPath(string path)
		{
			string ret;

			int len = path.length();

			string token;
			int i = 0;
			while ((token = getNext(path, i)) != "")
			{
				if (token[1] == '.')
				{
					if (token.length() > 2 && token[2] == '.')
						moveBack(ret);
				}
				else
					ret.append(token);
			}

			return ret;
//			return ret.substr(0, ret.length());
		}

		void moveBack(string &ret)
		{
			if (ret == "/" || ret.empty())
				return;

			int len = ret.length(); 
			int i;
			for (i = len - 1; i >= 0; i--)
				if (ret[i] == '/')
					break;
			ret.erase(ret.begin() + i, ret.end());
//			cout << "ret=(" << ret << ")\n";
		}

		string getNext(string &path, int &id)
		{
			int ed = id;
			for (; ed < path.length(); ed++)
				if (path[ed] == '/')
					break;

			string ret(path.substr(id, ed - id + 1));
			id = ed + 1;
			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.simplifyPath("/..") << endl;
	cout << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << s.simplifyPath("/ac/") << endl;

	return 0;
}

