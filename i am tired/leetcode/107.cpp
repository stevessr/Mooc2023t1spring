#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> qlast, qnext;
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return {};
        }
        else
        {
            qlast.push(root);
        again:
            vector<int> tempv;
            while (!qlast.empty())
            {
                TreeNode *temp = qlast.front();
                qlast.pop();
                tempv.push_back(((temp)->val));
                if (temp->left != nullptr)
                {
                    qnext.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    qnext.push(temp->right);
                }
            }
            ans.push_back(tempv);
            tempv.clear();
            qlast = qnext;
            qnext = queue<TreeNode *>();
            if (!qlast.empty())
            {
                goto again;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};