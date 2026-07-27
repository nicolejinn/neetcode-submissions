class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, std::optional<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (m[num]) 
                return std::vector<int>{ m[num].value(), i };
            m[target - num] = i;
        }
        return std::vector<int>();
    }
};
