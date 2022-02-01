class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
vector<int> ret(nums);
vector<int> sum={0};
for(auto num:nums){
sum.push_back(sum.back()+num);
}
for(int len=2;len<=nums.size();++len){
for(int left=0;left+len-1<nums.size();++left){
int right=left+len-1;
if(left==right-1){
ret[left]=max(ret[left],ret[right]);
}else{
int pickleft=nums[left]+sum[right+1]-sum[left+1]-ret[left+1];
int pickright=nums[right]+sum[right]-sum[left]-ret[left];
ret[left]=max(pickleft,pickright);
}
}
}
return ret[0]>=sum.back()/2+sum.back()%2;
}
};