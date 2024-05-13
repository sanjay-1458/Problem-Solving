class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> minDeque;
        deque<int> maxDeque;
        int start = 0;
        int end = 0;
        int maxLength = 0;
        
        while (end < n) {
            int currentNum = nums[end];
            
            while (!minDeque.empty() && nums[minDeque.back()] >= currentNum) {
                minDeque.pop_back();
            }
            
            while (!maxDeque.empty() && nums[maxDeque.back()] <= currentNum) {
                maxDeque.pop_back();
            }
            
            minDeque.push_back(end);
            maxDeque.push_back(end);
            
            int diff = nums[maxDeque.front()] - nums[minDeque.front()];
            if (diff > limit) {
                start++;
                while (!minDeque.empty() && minDeque.front() < start) {
                    minDeque.pop_front();
                }
                while (!maxDeque.empty() && maxDeque.front() < start) {
                    maxDeque.pop_front();
                }
            } else {
                maxLength = max(maxLength, end - start + 1);
                end++;
            }
        }
        return maxLength;
    }
};
