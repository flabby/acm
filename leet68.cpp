/*
   Text Justification
   */
#include "header.h"

class Solution
{
	public:
		vector<string> fullJustify(vector<string> &words, int L)
		{
			vector<string> ret;
			int n = words.size();
			if (n == 0)
				return ret;
			if (L == 0)
			{
				ret.push_back("");
				return ret;
			}

			int i = 0;
			while (i < n)
			{
				int len = 0;
				int cnt = getNextLine(words, i, n, L, len);

				string line;
				if (cnt == 1 || i + cnt >= n)
				{
					line.append(words[i]);
					for (int j = 1; j < cnt; j++)
					{
						line.append(1, ' ');
						line.append(words[j + i]);
					}
					if (len < L)
						line.append(L - len, ' ');
				}
				else 
				{
					int tot = L - len + (cnt - 1);
					int avrg = tot / (cnt - 1);
					int rem = tot % (cnt - 1);

					line.append(words[i]);
					for (int j = 1; j < cnt; j++)
					{
						int t = avrg;
						if (j - 1 < rem)
							t++;
						line.append(t, ' ');
						line.append(words[i + j]);
					}
				}

				ret.push_back(line);
				i += cnt;
			}
			return ret;
		}

		int getNextLine(vector<string> &words, int id, int n, int L, int &len)
		{
			int ret = 1;
			len += words[id].length();

			for (int i = id + 1; i < n; i++)
			{
				if (1 + len + words[i].length() > L)
					break;
				len += 1 + words[i].length();
				ret++;
			}

			return ret;
		}
};

int main()
{
	vector<string> a;
	a.push_back("This");
	a.push_back("is");
	a.push_back("an");
	a.push_back("example");
	a.push_back("of");
	a.push_back("text");
	a.push_back("justification.");

	Solution s;
	vector<string> ret;
	ret = s.fullJustify(a, 16);

	for (int i = 0; i < ret.size(); i++)
		cout << "(" << ret[i] << ")\n";

	return 0;
}
