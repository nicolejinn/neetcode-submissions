class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;
        for (const auto num : nums) {
            if (counts.contains(num))
                counts[num]++;
            else
                counts.emplace(num, 1);
        }

        multimap<int, int> count_to_num;
        for (const auto& [num, count] : counts) {
            count_to_num.emplace(count, num);
        }

        vector<int> top_k_nums;
        auto rit = count_to_num.rbegin();
        for (int i = 0; i < k; ++i, ++rit) {
            int num = (*rit).second;
            top_k_nums.push_back(num);
        }
        return top_k_nums;
    }
};
