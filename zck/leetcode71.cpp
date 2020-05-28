/*以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path){
    vector<string> paths;
    string temp = "";
    for(int i = 0; i < path.size(); i++){
        if(path[i] == '/' && temp != ""){
            paths.push_back(temp);
            temp = "/";
        }
        else{
            temp += path[i]; 
        }   
    }
    
    paths.push_back(temp);

    vector<string> s;
    for(int i = 0; i < paths.size(); i++){
        if(paths[i] == "/." || paths[i] == "/"){
            continue;
        }
        else if(paths[i] == "/.." && !s.empty()){
            s.pop_back();
        }
        else if(paths[i] == "/.." && s.empty())
            continue;
        else
            s.push_back(paths[i]);
        
    }

    string res = "";
    for(auto t : s)
        res += t;
    if(res.size() == 0)
        res = "/";
    return res;
}

int main(){
    string path = "/a//b////c/d//././/..";
    cout << simplifyPath(path) << endl;

    return 0;
}

//需要注意的是，在stack或者vector为空的时候，进行pop会报错