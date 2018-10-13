#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	if (str.size() == 0) {return 0;}
    	bool num = false;
    	int start = -1;
    	string number = "";
    	int minus = -1;
    	bool before = true;
    	bool num_before = true;

        for (int i = 0; i < str.size(); ++i)
        {
        	if (str[i] == ' ' && !num_before) {
    			if (number.size() == 0) {return 0;}
    			if (minus == 1) {number = "-" + number;}
        		long raw_number = stol(number);
		        // cout << number << endl;
		        if (raw_number < -2147483648) {return -2147483648;}
		        if (raw_number > 2147483647) {return 2147483647;}
		        return stoi(number);
        	}
        	else if (str[i] == ' ' && !before) {return 0;}
        	else if (str[i] != ' ') {
	        	if (str[i] == '-' && (before && num_before)) {
	        		int j = i;
	        		minus = 1;
	        		before = false;
	        		if (i+1 < str.size() && str[i+1] == '+') {return 0;}
	        		start = j;
	        		// cout << start << endl;
	        	}
	        	else if (str[i] == '+' && (before && num_before)) {
	        		int j = i;
	        		minus = 0;
	        		before = false;
	        		if (i+1 < str.size() && str[i+1] == '+') {return 0;}
	        	}
	        	else if (isdigit(str.at(i))) {
	        		num = true;
	        		if (str[i] != '0') {number += str[i];}
	        		else if (!num_before && str[i] == '0') {number += str[i];}
	        		if (str[i] == '0' || minus == 0 || minus == 1) {before = false;}
	        		if (str[i] != '0') {num_before = false;}
	        	}
	        	else {
	        		if (num_before) {
	        			return 0;}
	        		else {
	        			if (number.size() == 0) {return 0;}
	        			if (minus == 1) {number = "-" + number;}
		        		long raw_number = stol(number);
				        // cout << number << endl;
				        if (raw_number < -2147483648) {return -2147483648;}
				        if (raw_number > 2147483647) {return 2147483647;}
				        return stoi(number);
				    }
			    }
	        }
        }
        // cout << number << endl;
        if (minus == 1) {number = "-" + number;}
        if (number.size() > 12) {number = number.substr(0, 13);}
        if (number == "-") {return 0;}
        if (number == "") {return 0;}
        long raw_number = stol(number);
        // cout << number << endl;
        if (raw_number < -2147483648) {return -2147483648;}
        if (raw_number > 2147483647) {return 2147483647;}
        return stoi(number);
    }
};


int main(int argc, char const *argv[])
{
	Solution sol;
	// " ++1" and "++++456" cannot produce different results at the same time.
	vector<string> input1 = {" ++1", "123-", "3.14159", "0-1", "- 234", "-000000000000001", " -42", " +0 123", "-0012a42", "010", "+-2", \
	"+0a32", "0000000000012345678", "   -42", "42", "4193 with words",  "words and 987", "-91283472332", \
    "-20000000000000000000", "-", "----2", " -42", "+1", "++++456", "", "+"};

	// int output = sol.myAtoi("123-");
	cout << "Output:" << endl;
	// cout << output << endl;	
    for (int i = 0; i < input1.size(); ++i)
    {
		int output = sol.myAtoi(input1[i]);
		cout << input1[i] + " : " ;
		cout << output << endl;	
    }
	
	return 0;
}