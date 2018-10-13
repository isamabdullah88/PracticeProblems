
/* Problem Description:
https://leetcode.com/problems/largest-number/description/
*/

#include <iostream>
#include<vector>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.size() == 1 && nums[0] == 0)
			return "0";
		vector<string> str_nums;
		for (auto x : nums) {
			str_nums.push_back(to_string(x));
		}
		sort(str_nums.begin(), str_nums.end(), 
			[](const string& a, const string& b) -> bool {
				if ((a + b) > (b + a)) {
					return false;
				}
				else 
					return true;
			});
		string res;
		for (int i = (int)str_nums.size()-1; i >= 0; --i) {
			res += str_nums[i];
		}
		cout << "here" << endl;
		return res;
	}
};


int main(int argc, char const *argv[])
{
	int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));

	Solution sol;
	string res = sol.largestNumber(vec);

	cout << res << endl;

	return 0;
}