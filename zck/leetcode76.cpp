/*给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t){
    unordered_map<char, int> m_t;
    for(auto c : t){
        m_t[c]++;
    }

    for(int len = t.size(); len <= s.size(); len++){
        for(int i = 0; i < s.size() - len + 1; i++){
            bool status = true;
            string temp = s.substr(i, len);
            //cout << temp << endl;
            unordered_map<char,int> m_temp;
            for(auto c : temp){
                m_temp[c]++;
            }
            for(auto c : t){
                if(m_t[c] > m_temp[c]){
                    status = false;
                    break;
                }
            }
            if(status)
                return temp; 
        }
    }
    return "";
}


int main(){
    cout << minWindow("cwirwjbfntstplnenpabdttnbiagcnrglbyhnbnavhvmtlqgaqkdmdtnltvpipwuquddvseqabctmsbmllsxrlmegjupyqlpmqsjlyalaegozjbkxtjogxsmgodhgqwsjqeureftknhlwixvdgjjfeyoudvburvdjzxafetqtbdplblrjwcpccdxgyyarvfaxcbciwubzysnzfekeizgledredrvzyyyazakxvlxvfkwlqgpyixjmbargtohrmftngfldskyywwlmccmkzwzayshugontwhicovfhffhbdsphucutatwalfutviorrxvhscoyhvbmntujvofxjbxwispdcexvdscvvtveozresnnpbsmmvjifdxlhdicgchexazcqavusikhlevxaffhkessicwqffuchugyudspncwahuxjzeslll",
                        "ftpejujeztahrwljlao") << endl;
    return 0;
}
