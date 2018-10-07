
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> word;
		string letter;
		bool div_by_3;
		bool div_by_5;

		for (int i = 1; i <= n; ++i)
		{
			div_by_3 = i%3 == 0;
			div_by_5 = i%5 == 0;
			if (div_by_3 && div_by_5)
				letter = "FizzBuzz";
			else if (div_by_3)
				letter = "Fizz";
			else if (div_by_5)
				letter = "Buzz";
			else
				letter = to_string(i);

			word.push_back(letter);
		}

		return word;
	}
};


int main(int argc, char const *argv[]) {
	cout << "Main called!" << endl;
	Solution sol;
	vector<string> word = sol.fizzBuzz(15);
	for (vector<string>::const_iterator i = word.begin(); i != word.end(); ++i)
		cout << *i << endl;
	return 0;
}