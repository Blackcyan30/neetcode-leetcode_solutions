
class Solution {
public:
    int characterReplacement(string s, int k) {
          // FIXED: Changed types to signed int to prevent underflow
        std::array<int, 26> freq_map{}; 
        int N = static_cast<int>(s.size());
        int left = 0, max_len = 0;

        for (int right = 0; right < N; ++right) {
            ++freq_map[s[right] - 'A'];
            
            // Math can safely handle negative bounds if max value drops temporarily
            int replacements_needed = (right - left + 1) - std::ranges::max(freq_map);

            while (replacements_needed > k) {
                --freq_map[s[left] - 'A'];
                left++;
                
                replacements_needed = (right - left + 1) - std::ranges::max(freq_map);
            }
            max_len = std::max(right - left + 1, max_len);
        }

        return max_len;;
    }
};
