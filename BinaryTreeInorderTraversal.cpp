
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;

		while (root != NULL || s.size() != 0) {
			while (root != NULL) {
				s.push(root);
				root = root->left;
			}

			root = s.top();
			s.pop();
			res.push_back(root->val);
			root = root->right;

		}

		return res;
	}
};


int main(int argc, char const *argv[]) {
	cout << "main()!" << endl;
	Solution sol;

	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(2);
	tree->left->left = new TreeNode(3);
	tree->left->right = new TreeNode(4);
	tree->right = new TreeNode(5);
	vector<int> res = sol.inorderTraversal(tree);

	for (vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
		cout << *i;
	
	return 0;
}