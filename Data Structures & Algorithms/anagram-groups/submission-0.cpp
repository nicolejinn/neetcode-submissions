class Solution {
    std::vector<int> getFreq(const string& str) {
        std::vector<int> freq(26, 0);
        for (const char c: str) freq[c-'a']++;
        return freq;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<int>, int> freq_to_idx;
        std::vector<std::vector<string>> group;

        for (const auto& str: strs) {
            const auto& freq = getFreq(str);
            if (freq_to_idx.find(freq) != freq_to_idx.end())
                group[freq_to_idx[freq]].push_back(str);
            else {
                freq_to_idx.emplace(freq, group.size());
                group.push_back({ str });
            }
        }

        return group;
    }
};
