#include <iostream>

class Solution {
  public:
    int climbStairs(int n) {
      int count = 0;
      fun(n,count);
      return count;
    }

  private:
    void fun(int n,int& count)
    {
      if(n-1 == 0 || n-2 == 0)
      {
        ++count;
      }
      if(n-1 > 0)
        fun(n-1,count);
      if(n-2 > 0)
        fun(n-2,count);
    }
};

int main()
{
  int n = 3;
  Solution solution;
  std::cout<<"count : "<<solution.climbStairs(n)<<std::endl;
}
