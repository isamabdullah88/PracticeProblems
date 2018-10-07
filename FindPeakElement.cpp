
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int peak = 0;

        for (int i = 1; i < nums.size()-1; ++i)
        {
        	if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
        		return i;
        }

        if (nums[0] > nums[1])
        	return 0;
        else if (nums.back() > nums[nums.size()-2])
        	return nums.size()-1;
        return peak;
    }
};



int main(int argc, char const *argv[])
{
	cout << "main()" << endl;

	Solution sol;

	static const int s[7] = {1,2};
	vector<int> nums(s, s + sizeof(s) / sizeof(s[0]));
	
	int res = sol.findPeakElement(nums);
	cout << res << endl;

	return 0;
}