#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MAXM = 110;
map<string, string>mp;
map<string, string>::iterator it;

int main()
{
	int n, m;
	int csnum, cs;

	string s1, s2;
	string s;

	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d %d", &n, &m);

		mp.clear();
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2;
			mp[s1] = s2;
		}

	//	for (it = mp.begin(); it != mp.end(); it++)
	//	{
	//		cout << "(" << it->first << ") (" << it->second << ")\n";
	//	}
	
		getchar();
		getline(cin, s);
	//	cout << "s=(" << s << ")\n";

		cout << "Case #" << cs << ":";
		for (int i = 0; i < s.length(); i++)
		{
			int j;
			for (j = i; j < s.length() && s[j] != ' '; j++);
			string w = s.substr(i, j - i);
			//cout << "w=(" << w << ")\n";
			i = j;

			for (int k = 0; k < n - 1; k++)
				if (mp.find(w) != mp.end())
				{
			//		cout << "   w=(" << w << ")\n";
					w = mp[w];
			//		cout << "   w=(" << w << ")\n";
				}
				else
					break;

			cout << " " << w;
		//	cout << "w=(" << w << ")\n";
		}
		cout << endl;

	}
	return 0;
}

