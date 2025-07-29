2411 
  
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(31, -1);
        vector<int> r(n, 0);

        for(int i=n-1; i>=0; i--){
            
            for(int j=0; j<31; j++){
                if((nums[i] >> j) & 1){
                    bits[j] = i;
                }
            }

            int x = i;
            for(int j=0; j<31; j++){
                x = max(x, bits[j]);
            }

            r[i] = x - i + 1;
        }

        return r;
    }
};
