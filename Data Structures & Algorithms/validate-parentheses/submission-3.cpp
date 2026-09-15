class Solution {
 public:
  bool isValid(string s) {
    std::unordered_map<char, char> close_to_open = {{')', '('}, {'}', '{'}, {']', '['}};
    int n{static_cast<int>(s.size())};
    std::stack<char> stac;

    for (const char& c : s) {
        if (close_to_open.contains(c)) {
            if (!stac.empty() && stac.top() == close_to_open[c]) {
                stac.pop();
            } else {
                return false;
            }
        } else {
            stac.push(c);
        }
    }

    return stac.empty();
  }
};
