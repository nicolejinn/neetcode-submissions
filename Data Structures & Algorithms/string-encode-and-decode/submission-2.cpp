class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (const auto& str : strs) {
            int len = str.size();
            encoded_str += to_string(len);
            encoded_str += '#';
            encoded_str += str;
            encoded_str += ' ';
        }
        cout << encoded_str << endl;
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                len = len * 10 + (c - '0');
            } else if (c == '#') {
                string str = s.substr(++i, len);
                decoded_strs.push_back(str);
                i += len;
                len = 0;
            }
        }
        return decoded_strs;
    }
};
