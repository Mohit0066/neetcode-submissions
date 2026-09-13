class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int n = s.size();
        int low = 0;
        int high = 0;
        int ans = 0;

        while(high < n){

            while(charSet.find(s[high]) != charSet.end()){
                 charSet.erase(s[low]);
                 low++;
            }

            charSet.insert(s[high]);
            int length = high-low+1;
            ans = max(ans,length);
            high++;
        }

        return ans;
    }
};
