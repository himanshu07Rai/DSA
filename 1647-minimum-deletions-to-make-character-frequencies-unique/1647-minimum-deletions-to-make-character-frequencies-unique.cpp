class Solution {
public:
    int minDeletions(string s) {
      int ans = 0;
      unordered_map<char, int> char_counts;
      for (const char& c : s) char_counts[c]++;
      unordered_set<int> seen;
      for (auto[k, v] : char_counts) {
        while (seen.find(v) != seen.end()) {
          v--;
          ans++;
        }
        if (v > 0) seen.insert(v);
      }

      return ans;
    }
};