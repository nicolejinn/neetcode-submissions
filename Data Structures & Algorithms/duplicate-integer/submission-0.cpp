class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> freq;
        for (int num : nums) {
            if (freq[num] > 0) return true;
            freq[num]++;
        }
        return false;
    }
};