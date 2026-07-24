class Solution {
public:
    bool isPalindrome(string s) {
        auto left{0}, right{(int)s.size() - 1};

        while (left < right) {
            while (left < right && !std::isalnum(s[left])) ++left;
            while (right > left && !std::isalnum(s[right])) --right;
            if (std::tolower(s[left]) != std::tolower(s[right])) return false;
//            if (left == right) break;
            ++left; --right;
        }
        return true;
    }
};
