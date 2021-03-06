/*
Jump Game
Medium

8530

507

Add to List

Share
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

//DP approach 0 O(N^2)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        dp[nums.size()-1] = true;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i]==0)
                dp[i] = false;
            else{
                for(int j = 1; j <= nums[i] && (j+i) < nums.size(); j++){
                    if(dp[i+j]==true){
                        dp[i] = true;
                        break;
                    }
                    else
                        dp[i] = false;
                }
            }
        }
        return dp[0];
    }
};


//Greedy Approach - O(N)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, flag = 0;
        while(r < nums.size()-1){
            int farthest = 0;
            for(int i = l; i <= r; i++)
                farthest = max(farthest,i+nums[i]);
            l = r+1;
            r = farthest;
            if(l>r){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            return false;
        else
            return true;
    }
};
