class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int pos1=mid/matrix[0].size();
            int pos2=mid%matrix[0].size();
            if(matrix[pos1][pos2]==target){
                return true;
            }
            else if(matrix[pos1][pos2]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};
