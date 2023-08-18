#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    int min_dist{INT32_MAX};

    void bfs(vector<vector<int>>& lot,int width,int height){
        vector<vector<bool>> flags(height,vector<bool>(width,false));
        queue<vector<int>> que{};
        for(int i{};i<height;++i){
            for(int j{};j<width;++j){
                if(lot.at(i).at(j) == 0){
                    que.push(vector<int>{i,j});
                    flags.at(i).at(j) = true;
                }
            }
        }
        int dist{};
        vector<vector<int>> dirs{
            {0,-1},
            {0,1},
            {1,0},
            {-1,0}
        };

        while(!que.empty()){
            //cout<<"error";
            int sz = que.size();
            for(int i{};i<sz;++i){
                vector<int> curr_dir = que.front();
                que.pop();
                for(vector<int>& dir: dirs){
                    int nr = curr_dir.at(0)+dir.at(0);
                    int nc = curr_dir.at(1)+dir.at(1);
                    if(nr >= 0 && nr<height && nc>=0 && nc<width && flags.at(nr).at(nc) == false){
                        flags.at(nr).at(nc) = true;
                        que.push(vector<int>{nr,nc});
                    }
                }
            }
            dist++;
        }
        //cout<<dist<<endl;
        min_dist = min(min_dist,dist-1);
    }

    void backtrack(vector<vector<int>>& lot,int pivot,int build_left,int width,int height){
        //base
        if(build_left == 0){
            bfs(lot,width,height);
            return;
        }

        //logic

        int r = pivot/width;
        int c = pivot%width;
        for(int i{pivot};i<height*width;++i){
            //cout<<i<<" ";
            //action
            lot.at(r).at(c) = 0;
            //recurse
            backtrack(lot,i+1,build_left-1,width,height);
            //backtrack
            lot.at(r).at(c) = -1;
        }
    }

    public:

    int ques(int height,int width,int num_builds){
        //cout<<num_builds<<" ";
        vector<vector<int>> empty_lot(height,vector<int>(width,-1));
        backtrack(empty_lot,0,num_builds,width,height);
        return min_dist;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    Solution type1{};
    int res = type1.ques(4,4,3);
    cout<<res<<endl;
    return 0;
}
