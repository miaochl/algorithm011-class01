//
// Created by miaochl on 2020-06-26.
//

// 1.总个数减去重复个数
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nCount = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                nCount++;
            } else {
                nums[i-nCount] = nums[i];
            }
        }
        return nums.size() - nCount;
    }
};

// 2.如果出现不等情况目标数组有效长度+1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nValidLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[nValidLen++] = nums[i];
            }
        }

        return nValidLen > nums.size() ? nums.size() : nValidLen;
    }
};

// 3.modern C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = !nums.empty();
        for (int n : nums) {
            if (n > nums[i - 1]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};
