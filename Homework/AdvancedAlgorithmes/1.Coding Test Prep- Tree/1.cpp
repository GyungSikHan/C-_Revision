#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n{};
string s{};
vector<int> root;

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
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = 1;
    	left += maxDepth(root->left);
        int right = 1;
    	right += maxDepth(root->right);

        return max(left, right);
    }

    TreeNode* Push(const vector<int>& root, int idx)
    {
        if (idx < 0 || root.size() <= idx || root[idx] == -1)
            return nullptr;

        TreeNode* node = new TreeNode;
    	node->val = root[idx];
	    
        node->left = Push(root, idx * 2);
        node->right = Push(root, idx * 2 + 1);

        return node;
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
    cin >> n;
    root.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        
        if (s == "null")
            root[i] = -1;
        else
            root[i] = stoi(s);
    }
    TreeNode* node;
    Solution solution;

    node = solution.Push(root, 1);
    cout<<solution.maxDepth(node);
    node = solution.DeleteAll(node);

}