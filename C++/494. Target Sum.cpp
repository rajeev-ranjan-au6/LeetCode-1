// Backtracking
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ways = 0;
        backtrack(nums, S, 0, 0, ways);
        return ways;
    }
    
    void backtrack(vector<int>& nums, int S, int sum, int pos, int& ways){
        if(pos == nums.size()){
            if(sum == S) ways++;
            return;
        }
        backtrack(nums, S, sum + nums[pos], pos + 1, ways);
        backtrack(nums, S, sum - nums[pos], pos + 1, ways);
    }
};

// DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto x: nums) sum += x;
        if(sum < S || -sum > S) return 0;
        vector<int>cur(2 * sum + 1);
        vector<int>next(2 * sum + 1);
        cur[sum] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 2 * sum + 1; j++){
                if(cur[j] != 0){
                    next[j + nums[i]] += cur[j];
                    next[j - nums[i]] += cur[j];
                    cur[j] = 0;
                }
            }
            swap(cur, next);
        }
        return cur[sum + S];
    }
};
