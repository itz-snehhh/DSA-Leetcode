class Solution {
public:
    int countarray(vector<int>& nums, int goal){
      int n= nums.size();
        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;

        while(r<n){
            sum += nums[r];
            while(sum>goal){
                sum = sum -nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2 ==0){
                nums[i]= 0;
            }else{
                nums[i]= 1;
            }
        }
        int cnt1 = countarray(nums, k);
        int cnt2= countarray(nums, k-1);

        return cnt1 - cnt2;
        
    }
};


