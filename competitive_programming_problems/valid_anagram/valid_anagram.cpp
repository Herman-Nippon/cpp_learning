class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if (lenS != lenT) return false;
        vector<int> freq(26);
        for (int i {0}; i < lenS; ++i)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int n : freq)
        {
            if (n != 0) return false;
        }
        return true;
    }
};
