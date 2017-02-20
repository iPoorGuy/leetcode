#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    string multiply(string num1, string num2) {
      const int ASCII = 48;
      vector<vector<char> > vec;
      int len = num2.length() + num1.length() - 1;
      for(int i=num2.length()-1;i >= 0;--i)
      {
        vector<char> tmp_vec(len,'0');
        int count = 0;
        for(int j=num1.length()-1;j >= 0;--j)
        {
          int index_i = num2.length()-1-i;
          int index_j = num1.length()-1-j;
          int tmp = (num2[i]-ASCII)*(num1[j]-ASCII) + count;
          count = tmp/10;
          tmp_vec[index_i+index_j] = (tmp%10 + ASCII);//未分配内存不能直接访问
        }
        vec.push_back(tmp_vec);
      }
      
      vector<char> ret_value;
      int con = 0;
      for(int i=0;i<len;++i)
      {
        int sum = 0;
        for(int j=0;j<num2.length();++j)
        {
          sum += (vec[j][i] -ASCII);
        }
        sum += con;
        con = sum/10;
        ret_value.push_back(sum%10 + ASCII);
      }
      if(con != 0)
      {
        ret_value.push_back(con + ASCII);
      }

      string ret_str;
      for(int i=0;i<ret_value.size();++i)
      {
        ret_str += ret_value[ret_value.size()-1-i];
      }
      return ret_str;
    }
};

int main()
{
  string a = "1233",b = "112134";
  long int a_ = 1233,b_ = 112134;
  Solution solution;
  std::cout<<"solution : "<<solution.multiply(a,b)<<std::endl;
  std::cout<<"solution should be : "<<a_ * b_<<std::endl;
  return 0;
}

