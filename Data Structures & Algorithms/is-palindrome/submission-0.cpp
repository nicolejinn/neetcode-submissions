class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());

        int len = s.size();
        int front = len / 2 - 1;
        int back = len % 2 == 0 ? front + 1 : front + 2;
        while (back < len) {
            if (isdigit(s[front]) && s[front] != s[back])
                return false;
            if (tolower(s[front]) != tolower(s[back]))
                return false;
            front--;
            back++;
        }
        return true;
    }
};
