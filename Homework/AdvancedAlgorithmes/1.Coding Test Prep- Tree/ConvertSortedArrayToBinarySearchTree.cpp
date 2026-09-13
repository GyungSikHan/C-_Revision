#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;



struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.size() == 0)
			return nullptr;
		int half = nums.size() / 2;
		TreeNode* node = new TreeNode(nums[half]);

		vector<int> temp(half, 0);
		std::copy(nums.begin(), nums.begin() + half, temp.begin());
		node->left = sortedArrayToBST(temp);

		vector<int> temp2(nums.size() - (half+1), 0);
		std::copy(nums.begin()+half+1, nums.end(), temp2.begin());
		node->right = sortedArrayToBST(temp2);

		return node;
	}

	void PrintNode(TreeNode* node)
	{
		queue<TreeNode*> qu;
		qu.push(node);

		while (!qu.empty())
		{
			TreeNode* now = qu.front();
			qu.pop();

			cout << now->val << " ";

			if (now->left)
				qu.push(now->left);
			if (now->right)
				qu.push(now->right);
		}
	}

	TreeNode* DeleteAll(TreeNode* node)
	{
		if (node->left)
			node->left = DeleteAll(node->left);
		if (node->right)
			node->right = DeleteAll(node->right);

		delete node;
		node = nullptr;
		return node;
	}

};

int main()
{
	int n{};
	cin >> n;
	vector<int >num(n,0);
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num.begin(), num.end());

	TreeNode* node;
	Solution solution;
	node = solution.sortedArrayToBST(num);
	solution.PrintNode(node);
	node = solution.DeleteAll(node);
}