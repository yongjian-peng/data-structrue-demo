#include "../stdc++.h"

using namespace std;
  // 给出一串字符串，要求找出字符串内连续出现次数最高的字母，
  // 如果存在多个字母并列出现次数最高，则需要把全部都列举出来
  // dasdfdsdfgdeeeeffffggf

  // 先求出最高出現的次數 再依次去查詢等於 次數的字母
class MaxFreq {
    public:
        int main() {
            string str = "dasdfdsdfgdeeeeffffggf";
            vector<string> ans;
            ans = maxFreq(str);

            for (string &s : ans)
            {
                cout << s << endl;
            }
            return 0;
        }
        

    private:
        vector<string> maxFreq(string &str)
        {

            cout << str.length() << endl;
            ans = vector<string>();
            ans.push_back("e");
            ans.push_back("f");
            return ans;
        }
        //vector<string, int> strnum;
        vector<string> ans;
        //string ps;

};