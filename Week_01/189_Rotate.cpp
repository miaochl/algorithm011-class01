// 1.手写顺序表逆序
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 1) {
            return ;
        }

        k = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size()-1);
    }

    void reverseArray(vector<int>& nums, int nStart, int nEnd) {
        while (nStart < nEnd) {
            int nTmp = nums[nStart];
            nums[nStart++] = nums[nEnd];
            nums[nEnd--] = nTmp;
        }
    }
};

// 使用库函数
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 1) {
            return ;
        }

        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
