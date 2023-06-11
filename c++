👉 Optimal Approach
use vector of vector of pair type to store the snap history with index history

class SnapshotArray {
public:
vector<vector<pair<int,int>>>vec;
int cnt;
    SnapshotArray(int length) {
        vec.resize(length);
        cnt=0;
        for(int i=0;i<length;i++){
            vec[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        // vec[index].first=cnt;
        // vec[index].second=val;
        vec[index].push_back({cnt,val});
    }
    
    int snap() {
        return cnt++;
    }
    int binary(int snap_id,int index){
        int s=0;
        int e=vec[index].size()-1;
        int value=0;
        int mid =s+(e-s)/2;
        while(s<=e){
           
            if(vec[index][mid].first<=snap_id){
                value=vec[index][mid].second;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return value;
    }
    int get(int index, int snap_id) {
        int ans=binary(snap_id,index);
        return ans;
    }
};
