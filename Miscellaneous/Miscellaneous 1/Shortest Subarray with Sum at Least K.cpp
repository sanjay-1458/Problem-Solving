class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, long long>> deque;
        long long cumSum = 0;
        long long ans = INT_MAX;
        long long i = 0;

        while (i < nums.size()) {
            cumSum += nums[i];
            if (cumSum >= k) {
                ans = min(ans, (long long)(i) + 1);
            }

            while (!deque.empty() && deque.back().first > cumSum) {
                deque.pop_back();
            }
            while (!deque.empty() && cumSum - deque.front().first >= k) {
                pair<long, long> ds = deque.front();
                deque.pop_front();
                ans = min(ans, i - ds.second);
            }
            deque.push_back(make_pair(cumSum, (long long)(i)));
            i++;
        }

        return ans == INT_MAX ? -1 : (int)(ans);

    }
};
