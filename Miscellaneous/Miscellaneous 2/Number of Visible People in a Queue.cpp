class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(heights[i]);
                heights[i] = 0;
                continue;
            }

            int count = 0;
            while (!s.empty() && heights[i] > s.top()) {
                s.pop();
                count++;
            }

            if (!s.empty()) {
                count++;
            }

            s.push(heights[i]);
            heights[i] = count;
        }

        return heights;
    }
};
