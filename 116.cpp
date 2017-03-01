#include <iostream>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  public:
      void connect(TreeLinkNode *root) {
        if(root == NULL)
          return;
        fun(root);
      }
  
  private:
      void fun(TreeLinkNode* head)
      {
        TreeLinkNode* first = head;
        if(first->left == NULL)
          return;
        while(first != NULL)
        {
          first->left->next = first->right;
          if(first->next != NULL)
          {
            first->right->next = first->next->left;
          }
          first = first->next;
        }
        head = head->left;
        fun(head);
      }
};

int main()
{
}
