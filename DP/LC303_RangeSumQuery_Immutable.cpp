// my solution
class NumArray {
vector<int> dp;
public:
    NumArray(vector<int> nums) {
        for(int i=0; i<nums.size(); i++){
        	if(dp.empty()) dp.push_back(nums[i]);
        	else dp.push_back(dp[dp.size()-1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if(i<0 || j>=dp.size()) return 0;
        if(i==0) return dp[j];
        return dp[j] - dp[i-1];
    }
};

// Answer
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);								// insert 0 first
        for (int num : nums)
            accu.push_back(accu.back() + num);			// use vector.back() to get the last element
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:												// initialzie as private
    vector<int> accu;
};


// Answer 2
class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {			// ????
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);		// Important partial_sum() !!!
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};