class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int st=0, en=n-1, mid=0;

        while(mid<=en) {
            if(nums[mid]==1) {
                mid++;
            } else if(nums[mid]==0) {
                swap(nums[st], nums[mid]);
                st++;
                mid++;
            } else if(nums[mid]==2) {
                swap(nums[mid], nums[en]);
                en--;
            }
        }
    }
};