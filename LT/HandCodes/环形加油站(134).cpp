class Solution {
public:
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int tank=0;//当前站出发后Δ装油量
    //     int start=0;//出发站点
    //     int total=0;//循环总Δ油量
    //     for(int i=0;i<gas.size();i++){
    //         int delta=gas[i]-cost[i];
    //         tank+=delta;
    //         total+=delta;
    //         if(tank<0){
    //             tank=0;
    //             start=i+1;
    //             //站点i出发为负，必然只能从下一站点出发
    //         }
    //     }
    //     return total<0?-1:start;
    // }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while(start > end){
            if(sum >= 0){
                sum += gas[end] - cost[end];
                ++end;
            }else{
                --start;
                sum += gas[start] - cost[start];
            }
        }
        return sum >=0 ? start : -1;
    }
};