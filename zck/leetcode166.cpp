#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

string fractionToDecimal(int numerator, int denominator){
    if(denominator == 0)
        return "";
    if(numerator == 0)
        return 0;
    
    numerator = llabs(static_cast<long long>(numerator));
    denominator = llabs(static_cast<long long>(denominator));

    string result = "";
    if((numerator > 0)^(denominator > 0)){
        result += '-';
    } 
   
    result += to_string(numerator / denominator);

    numerator %= denominator;
    if(numerator == 0)
        return result;

    result += '.';
    int index = result.size() - 1;

    map<int, int> m;    
    while(numerator != 0 && m.count(numerator) == 0){
        m[numerator] = ++index;
        numerator *= 10;
        result += to_string(numerator / denominator);
        numerator %= denominator;
    }
    if(m.count(numerator) == 1){
        result.insert(m[numerator], "(");
        result.push_back(')');
    }
    return result;
}

int main(){
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(1, 3) << endl;
    cout << fractionToDecimal(1, 7) << endl;
    return 0;
}