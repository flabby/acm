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
			int flg = 0;
			while ((token = getNext(path, i)) != "")
			{
				if (token == "../" || token == "..")
					moveBack(ret);
				else if (token != "./" && token != ".")
				{
					if (flg && token[0] == '/')
						continue;
					flg = 1;
					ret.append(token);
				}
			}

			if (ret.length() > 1 && ret[ret.length() - 1] == '/')
				ret.erase(ret.end() - 1);

			return ret;
//			return ret.substr(0, ret.length());
		}

		void moveBack(string &ret)
		{
			if (ret == "/" || ret.empty())
				return;

			int len = ret.length(); 
			int i;
			for (i = len - 2; i >= 0; i--)
				if (ret[i] == '/')
					break;
			ret.erase(ret.begin() + i + 1, ret.end());
//			cout << "ret=(" << ret << ")\n";
		}

		string getNext(string &path, int &id)
		{
			int ed = id;
			if (id >= path.length())
				return "";

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
//	cout << s.simplifyPath("/..") << endl;
	cout << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << s.simplifyPath("/ac/") << endl;
	cout << s.simplifyPath("/a//c/") << endl;
	cout << s.simplifyPath("///") << endl;

	return 0;
}

