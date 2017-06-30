class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                res.push_back(map[nums[i]]);
                res.push_back(i);
                return res;
            }
            map[target-nums[i]] = i;
        }
        return res;
    }
};