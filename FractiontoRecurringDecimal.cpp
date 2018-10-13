
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	string quotient = "";
    	vector<long> orig_numerator;
    	orig_numerator.push_back(long(numerator));
    	helperFractionToDecimal(orig_numerator, long(numerator), long(denominator), quotient);
    	if (numerator*denominator < 0) {quotient.insert(0, "-");}
    	if (quotient[0] == '.') {quotient.insert(0, "0");}
    	return quotient;
    }

    void helperFractionToDecimal(vector<long>& orig_numerator, long numerator, long denominator, string& quotient) {
		if (numerator % denominator == 0)
			quotient += to_string(numerator / denominator);
		else if (numerator > denominator) {
			// cout << "here";
			// cout << numerator << endl;
			quotient += to_string(numerator / denominator);
			numerator = numerator % denominator;
			// check if remainder is equal to dividend [if so, it is repeating]
			bool in_para = false;
			for (int i = 0; i < orig_numerator.size(); ++i) {
				if (orig_numerator[i] == numerator) {
					// cout << orig_numerator[i] << endl;
					quotient.insert(1+i, "(");
					quotient += ")";
					in_para = true;
				}
			}
			if (!in_para) {
				orig_numerator.push_back(numerator);
				helperFractionToDecimal(orig_numerator, numerator, denominator, quotient);
			}
		}
		else {
			numerator *= 10;
			if (quotient[0] == '.') {} else if (quotient.find(".") != string::npos) {quotient += "0";} 
			else {quotient += ".";}
			while (numerator < denominator) {
				numerator *= 10;
				quotient += "0";
			}
			// check if remainder is equal to dividend [if so, it is repeating]
			// for (int i=0; i < orig_numerator.size(); ++i) {cout << orig_numerator[i] << endl;}
			bool in_para2 = false;
			for (int i = 0; i < orig_numerator.size(); ++i) {
				if (orig_numerator[i] == numerator) {
					quotient.insert(1+i, "(");
					quotient += ")";
					in_para2 = true;
				}
			}
			if (!in_para2) {
				orig_numerator.push_back(numerator);
				helperFractionToDecimal(orig_numerator, numerator, denominator, quotient);
			}
		}
	}
};


int main(int argc, char const *argv[])
{
	Solution sol;

	int numerator = 1; int denominator = 6;
	// int numerator = 4; int denominator = 333;
	// int numerator = 1; int denominator = 90;
	string result = sol.fractionToDecimal(numerator, denominator);
	cout << result << endl;

	return 0;
}