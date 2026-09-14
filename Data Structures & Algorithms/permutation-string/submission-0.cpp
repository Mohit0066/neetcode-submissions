class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()){
            return false;
        }

        unordered_map<char,int> counts1;

        for(int i = 0; i < s1.size(); i++){
            counts1[s1[i]]++;
        }

        unordered_map<char,int> counts2;

        int low = 0;
        int high = 0;

        while(high < s2.size()){

            counts2[s2[high]]++;

            if(high - low + 1 > s1.size()){

                counts2[s2[low]]--;

                if(counts2[s2[low]] == 0){
                    counts2.erase(s2[low]);
                }

                low++;
            }

            if(counts1 == counts2){
                return true;
            }

            high++;
        }

        return false;
    }
};