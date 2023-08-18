#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{

    vector<string> soln{};
    string temp{};

    // void display(vector<vector<char>>& bb){
    //     for(vector<char>& gg:bb){
    //         for(char& c:gg){
    //             cout<<c<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    // void display(vector<char>& gg){
    //     for(auto&c :gg) cout<<c<<" ";
    //     cout<<endl;
    // }

    vector<vector<char>> preprocess_string(const string& s){
        vector<vector<char>> pre;
        int sz = s.size();
        vector<char> gg{};
        for(int i{};i<sz;i++){
            vector<char> gg{};
            char c = s.at(i);
            if(c=='{'){
                i++;
                c = s.at(i);
                while(c!='}'){
                    if(c!=',') gg.push_back(c);
                    ++i;
                    c = s.at(i);
                }
            }
            else{
                gg.push_back(c);
            }
            pre.push_back(gg);
            //display(gg);
            gg.clear();
        }
        return pre;
    }
    void backtrack(vector<vector<char>>& pre,int idx){
        //base
        if(idx == pre.size()){
            string to_push{temp};
            soln.push_back(to_push);
            return;
        }

        //logic
        for(char& c:pre.at(idx)){
            //action
            temp.push_back(c);
            //recurse
            backtrack(pre,idx+1);
            //backtrack
            temp.pop_back();
        }

    }
        
    public:

    void display(vector<string>& gg){
        for(string& s:gg) cout<<s<<" ";
        cout<<endl;
    }

    vector<string> ques(string &s){
        vector<vector<char>> pre = preprocess_string(s);
        //display(pre);
        backtrack(pre,0);
        return soln;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution prob1;
    string s1{"{a,b}cd{e,f}gh"};
    vector<string> sol = prob1.ques(s1);
    prob1.display(sol);
    return 0;
}
