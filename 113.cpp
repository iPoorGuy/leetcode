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
    //bool hasPathSum(TreeNode* root, int sum)
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
      vector<vector<int> > ret;
      if(root == NULL)
        return ret;
      vector<int> tmp;
      fun(root,sum,ret,tmp,0);
      return ret;
    }

  private:
    void fun(TreeNode* node, int sum, vector<vector<int> >& ret, vector<int> tmp,int count)
    {
      count += node->val;
      tmp.push_back(node->val);
      if(count == sum && node->left == NULL && node->right == NULL)
      {
        ret.push_back(tmp);
        return;
      }

      if(node->left != NULL)
        fun(node->left,sum,ret,tmp,count);
      if(node->right != NULL)
        fun(node->right,sum,ret,tmp,count);
    }
};

int main()
{
}
