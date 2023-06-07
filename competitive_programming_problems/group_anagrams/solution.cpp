#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(begin(strs[i]), end(strs[i]));
            map[strs[i]].push_back(s);
        }

        for (auto i : map)
        {
            result.push_back(i.second);
        }

        return result;
    }
};
