class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> s_freq(26, 0), t_freq(26, 0);
        for (char c : s) s_freq[(c - 'a')]++;
        for (char c : t) t_freq[(c - 'a')]++;
        for (int i = 0; i < s_freq.size(); ++i) {
            if (s_freq[i] != t_freq[i]) return false;
        }
        return true;
    }
};
