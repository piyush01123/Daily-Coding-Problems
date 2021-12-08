---
layout: post
title: "First missing positive"
categories: misc
---

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.


My Solution(C++):
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i=0; i< nums.size(); i++){
            mySet.insert(nums[i]);
        }
        int i = 1;
        while (i <= nums.size()){
            if (mySet.find(i) == mySet.end()){
                return i;
            }
            i++;
        }
        return i;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
```


My Solution(Python):
```
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        S = set()
        for num in nums:
            S.add(num)
        for i in range(1, len(nums)+1):
            if i not in S:
                return i
        return len(nums) + 1
```
