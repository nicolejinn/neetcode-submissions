class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};

        vector<int> prefix_products(len, 1);
        for (int i = 1; i < len; ++i)
            prefix_products[i] = prefix_products[i-1] * nums[i-1];

        vector<int> suffix_products(len, 1);
        for (int i = len - 2; i >= 0; --i)
            suffix_products[i] = suffix_products[i+1] * nums[i+1];

        vector<int> res(len);
        for (int i = 0; i < len; ++i)
            res[i] = prefix_products[i] * suffix_products[i];
        return res;
    }
};
