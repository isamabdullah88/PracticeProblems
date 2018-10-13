#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> mults1(nums.size());
		vector<int> mults2(nums.size());

		vector<int> mults(nums.size());
		
		int pre_product = 1;

		for (int i = 0; i < nums.size(); ++i)
		{
			mults1[i] = pre_product;
			pre_product *= nums[i];
		}

		int post_product = 1;
		for (int i = nums.size()-1; i >= 0; --i)
		{
			mults2[i] = post_product;
			post_product *= nums[i];
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			mults[i] = mults1[i]*mults2[i];
		}

		return mults;
	}
};



int main(int argc, char const *argv[])
{
	Solution sol;

	vector<int> nums = {1,2,3,4};
	vector<int> product = sol.productExceptSelf(nums);

	for (int i = 0; i < product.size(); ++i)
	{
		cout << product[i] ;
	}
	cout << endl;

	return 0;
}