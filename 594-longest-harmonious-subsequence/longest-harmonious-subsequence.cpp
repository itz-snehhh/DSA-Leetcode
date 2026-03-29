class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num:nums){
            freq[num]++;
        }
        int maxlen =0;
        for(auto & it: freq){
            int x = it.first;
            if(freq.count(x+1)){
                maxlen= max(maxlen, it.second + freq[x+1]);
            }
        }
        return maxlen;
        
    }
};