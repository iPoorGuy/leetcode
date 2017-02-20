#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    string multiply(string num1, string num2) {
      const int ascii = 48;
      int i = 0 , count = 0;
      //char result[110];
      vector<char> result;
      for(;!(i>=num1.length() && i>=num2.length());++i)
      {
        int tmp1 = num1[i],tmp2 = num2[i];
        if(i > num1.length())
          tmp1 = ascii;
        if(i > num2.length())
          tmp2 = ascii;

        int tmp = (tmp1 - ascii) + (tmp2 - ascii) + count;
        if(tmp >= 10)
        {
          count = 1;
          tmp -= 10;
        }
        else
        {
          count = 0;
        }
        //result[i] = tmp + ascii;
        result.push_back(tmp + ascii);
        std::cout<<"value : "<<char(tmp + ascii)<<std::endl;
      }
      if(count == 1)
        result.push_back('1');

      string ret_value;
      for(int k=0;k<result.size();++k)
      {
        ret_value += result[result.size()-1-k];
      }
      return ret_value;
      //return string(result.begin(),result.end());
    }
};

int main()
{
  string a = "123",b = "12311111111111111";
  long int a_ = 123,b_ = 12311111111111111;
  Solution solution;
  std::cout<<"solution : "<<solution.multiply(a,b)<<std::endl;
  std::cout<<"solution should be : "<<a_ + b_<<std::endl;
  return 0;
}

