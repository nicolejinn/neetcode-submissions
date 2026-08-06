class Solution {
    int getConsecutiveLenStartsAt(const unordered_set<int>& nums, int num) {
        int len = 1;
        while(true) {
            if (!nums.contains(num + len))
                return len;
            ++len;
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_consecutive_len = 0;
        for (const auto num : nums_set) {
            if (nums_set.contains(num - 1)) continue;
            int consecutive_len = getConsecutiveLenStartsAt(nums_set, num);
            if (consecutive_len > max_consecutive_len)
                max_consecutive_len = consecutive_len;
        }
        return max_consecutive_len;
    }
};
