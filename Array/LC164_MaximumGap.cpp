// bucket sort
class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	if(nums.size()<2) return 0;
        int mini=INT_MAX, maxi=-1;
        for(auto n : nums){
        	mini = min(mini, n);
        	maxi = max(maxi, n);
        }
        int diff = maxi-mini;
        int gap = (int)ceil((double)diff/(num.size() - 1));		// ceil() ATTENTION
        if(gap==0) return 0;
        gap++;
        vector<vector<int>> dp(nums.size()-1, vector<int>(2, -1));
        for(auto n : nums){
        	int index = (n-mini)/gap;
        	if(dp[index][0]==-1){
        		dp[index][0] = n;
        		dp[index][1] = n;
        	}
        	else{
        		dp[index][0] = min(dp[index][0], n);
        		dp[index][1] = max(dp[index][1], n);
        	}
        }
        maxi = dp[0][1]-dp[0][0];
        pair<int,int> pre;
        pre.first = dp[0][0];
        pre.second = dp[0][1];
        for(int i=1; i<dp.size(); i++){
        	if(dp[i][0]==-1) continue;
        	maxi = max(maxi, dp[i][0]-pre.second);
        	pre.first = dp[i][0];
        	pre.second = dp[i][1];
        }
        return maxi;
    }
};
// int[] bucketsMIN = new int[num.length - 1]; // store the min value in that bucket
// int gap = (int)Math.ceil((double)(max - min)/(num.length - 1));
// int idx = (i - min) / gap; // index of the right position in the buckets


// Explain for radix sort http://www.geeksforgeeks.org/radix-sort/
// Radix Sort
public class Solution {
public int maximumGap(int[] nums) {
    if (nums == null || nums.length < 2) {
        return 0;
    }
    
    // m is the maximal number in nums
    int m = nums[0];
    for (int i = 1; i < nums.length; i++) {
        m = Math.max(m, nums[i]);
    }
    
    int exp = 1; // 1, 10, 100, 1000 ...
    int R = 10; // 10 digits

    int[] aux = new int[nums.length];
    
    while (m / exp > 0) { // Go through all digits from LSB to MSB
        int[] count = new int[R];
        
        for (int i = 0; i < nums.length; i++) {
            count[(nums[i] / exp) % 10]++;
        }
        
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = nums.length - 1; i >= 0; i--) {
            aux[--count[(nums[i] / exp) % 10]] = nums[i];
        }
        
        for (int i = 0; i < nums.length; i++) {
            nums[i] = aux[i];
        }
        exp *= 10;
    }
    
    int max = 0;
    for (int i = 1; i < aux.length; i++) {
        max = Math.max(max, aux[i] - aux[i - 1]);
    }
     
    return max;
}

// Answer
class Solution {
public:
	int maximumGap(vector<int> &num) {
		int sSize = num.size();
		int i, res =0;
		int minV, maxV;
		int bucket_size, bucket_num, bucket_id;
		int maxGap = INT_MIN;
		int last_max;
	    if(sSize>1)
	    {
	        minV =  maxV = num[0];
	        for(i=1; i<sSize; i++)
	        {
	            if(minV > num[i]) minV = num[i];
	            else if(maxV < num[i]) maxV = num[i];
	        }
	        
	        bucket_size = max(1, (maxV - minV )/ (sSize - 1)));
	        bucket_num  = (maxV - minV)/bucket_size + 1;

	        if(bucket_num <=1) return (maxV - minV); 
	        vector<int> bucket_max(bucket_num, INT_MIN);
	        vector<int> bucket_min(bucket_num, INT_MAX);
	        vector<int> bucket_count(bucket_num, 0);
	        
	        for(i=0; i<sSize; i++)
	        {
	            bucket_id = (num[i] - minV)/bucket_size;
	            bucket_count[bucket_id]++;
	            bucket_min[bucket_id] = bucket_min[bucket_id] > num[i]? num[i]:bucket_min[bucket_id];
	            bucket_max[bucket_id] = bucket_max[bucket_id] < num[i]? num[i]:bucket_max[bucket_id];
	        }
	        
	        last_max = minV;
	        for(i=0; i<bucket_num; i++)
	        {
	            if(bucket_count[i]>0)
	            {
	                maxGap = max(maxGap, bucket_min[i]- last_max);
	                last_max = bucket_max[i];
	            }
	        }
	        return maxGap;
	    }
	    return 0;
	}
};