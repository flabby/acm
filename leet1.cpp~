#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int>mp;
        for (int i = numbers.size() - 1; i >= 0; i--)
        {
            if (mp.find(numbers[i]) == mp.end())
                mp[numbers[i]] = i;
        }
        
        vector<int> ret;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (mp.find (target - numbers[i]) != mp.end())
            {
                ret.push_back(i + 1);
                ret.push_back(mp[target - numbers[i]] + 1);
                break;
            }
        }
        
        return ret;
    }
};
