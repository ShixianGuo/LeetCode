#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> split(string version){

    vector<int> res;
    string temp = "";
    for(int i = 0; i < version.size(); i++){
        if(version[i] != '.')
            temp += version[i];
        else{
            res.push_back(stoi(temp));
            temp = "";
        }
    }
    if(temp != "")
        res.push_back(stoi(temp));

    return res;
} 

int compareVersion(string version1, string version2){
    vector<int> v1 = split(version1);
    vector<int> v2 = split(version2);

    if(v1.size() > v2.size()){
        int dif = v1.size() - v2.size();
        while(dif > 0){
            v2.push_back(0);
            dif--;
        }
    }
    else{
        int dif = v2.size() - v1.size();
        while(dif > 0){
            v1.push_back(0);
            dif--;
        }
    }
    

    for(int i = 0; i < v1.size(); i++){
        if(v1[i] > v2[i])
            return 1;
        else if(v1[i] < v2[i])
            return -1;
        else
            continue;    
    }
    return 0;
}

int main(){
    string version1 =  "1.0";
    string version2 = "1.00";

    cout << compareVersion(version1, version2) << endl;

    return 0;
}