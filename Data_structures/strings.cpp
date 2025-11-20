#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;


 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;


        for(string &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
            }


        


        for(auto &item : mp){
            ans.push_back(item.second);
        }


        return ans;
    }


 vector<string> removeAnagrams(vector<string>& words) {
        
           vector<string> ans;

           string last = "";

            for(string &s : words){

                string temp = s;

                sort(temp.begin(), temp.end());

                if(temp != last) {
                    ans.push_back(s);
                }   

                last = temp;
            }

           return ans;



}

int main(){

    vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> res = removeAnagrams(words);

    for(string &s : res){
        cout << s << " ";
    }
}