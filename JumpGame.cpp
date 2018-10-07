
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> store(nums.size(),-1);
		return helperCanJump(nums, nums.size()-1, store);
	}
	
	int helperCanJump(vector<int>& nums, int idx, vector<int>& store) {

		if (nums.size() == 1)
			return 1;
		if (idx == 0 && nums[idx] > 0) {
			store[idx] = 1;
			return 1;
		}
		else {
			for (int i = idx-1; i >= 0; --i)
			{
				if (nums[i] >= idx-i) {
					if (store[i] == 1)
						return 1;
					else if (store[i] == 0) {}
					else {
						int res = helperCanJump(nums, idx-1, store);
						store[idx-1] = res;
						if (res == 1)
							return 1;
					} 
				}
			}
			return 0;
		}
	}
};



int main(int argc, char const *argv[])
{
	Solution sol;

	int a[] = {3,2,1,0,4};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));

	bool res = sol.canJump(nums);
	cout << res << endl;

	return 0;
}