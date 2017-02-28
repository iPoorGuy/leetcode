#include <iostream>
#include <vector>
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 */

class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum)
    {
      if(root == NULL)
        return false;
      bool flag = false;
      fun(root,sum,0,flag);
      return flag;
    }

  private:
    void fun(TreeNode* node, int sum, int count, bool& flag)
    {
      count += node->val;
      if(count > sum)
        return;
      if(count == sum && node->left == NULL && node->right == NULL)
      {
        flag = true;
        return;
      }

      if(node->left != NULL)
        fun(node->left,sum,count,flag);
      if(node->right != NULL)
        fun(node->right,sum,count,flag);
    }
};

int main()
{

}
