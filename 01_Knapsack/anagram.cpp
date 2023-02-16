#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "pavan";
    string t = "napav";

    vector<int> freq(26);
    for(int i=0 ; i<s.size() ; i++){
        freq[s[i] - 'a']++;
    }
    bool flag = true;
    for(int i=0 ; i<t.size() ; i++){
        if(freq[t[i] - 'a'] == 0){
            flag = false;
            break;
        }else{
            freq[t[i]-'a']--;
        }
    }

    if(flag){
        cout << "Strings are anagram" << endl;
    }else{
        cout << "Strings are not an anagram" << endl;
    }
}