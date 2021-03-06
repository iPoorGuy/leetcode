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
 * 主要是树的广度遍历。
 * 给出的结构中没有parent指针，不能用深度遍历!
 */

class Solution {
  public:
      int minDepth(TreeNode* root) {
//        if(root->left == NULL && root->right == NULL)
//          return 1;
        if(root == NULL)
          return 0;
        vector<TreeNode*> tree_ptr;
        int deep = 1, offset = 0;
        tree_ptr.push_back(root);
        while(1)
        {
          int size = tree_ptr.size();
          for(int i = offset;i < size;++i)
          {
            if(tree_ptr[i]->left==NULL && tree_ptr[i]->right==NULL)
              return deep;
            if(tree_ptr[i]->left != NULL)
              tree_ptr.push_back(tree_ptr[i]->left);
            if(tree_ptr[i]->right != NULL)
              tree_ptr.push_back(tree_ptr[i]->right);
          }
          ++deep;
          offset = size;
        }
      }
};

int main()
{

}
