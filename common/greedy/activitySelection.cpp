#include<iostream>
#include<vector>

using namespace std;
//created by ailias
/**
*【算法导论p237的活动选择问题】
*活动选择问题可以使用贪心算法来进行求解，因为该问题满足最优子结构性质。
*贪心选择的依据是：每次选择起始时间不小于上一个活动完成时间的第一个活动。
*
*/


//方案1：活动选择问题的贪心的递归算法
int recursiveActivitySelection(vector<int>start, vector<int>finish, int k, int num){
  if(k == num) return 0;
  int next = k + 1;//寻找下一个起始时间不小于上一个任务的完成时间的活动下标
  while(next < num && start[next] < finish[k]) ++next;
  if(next <= num)//第0个任务必定会选择，所以放在k == num尽心统计正好。
    return 1 + recursiveActivitySelection(start, finish, next, num);
}

//方案2：活动选择问题的贪心的非递归算法。
int iterationActivitySelection(vector<int>start, vector<int>finish){
  int res = 0;//结果
  int istart = 0;//start数组的下标
  int ifinish = 0;//finish的下标
  int len = start.size();
  while(istart < len && ifinish < len){
  	//查找下一个起始时间不小于上一个任务的完成时间的活动下标
    while(istart < len && start[istart] < finish[ifinish]) ++istart;
    ifinish = istart;//更新可满足任务的下标
    ++res;
  }
  return res;
}

int main(int argc, char**argv){
  //your code here
  vector<int> start = {1,3,0,5,3,5,6,8,8,2,12};
  vector<int> finish = {4,5,6,7,9,9,10,11,12,14,16};
  int res1 = recursiveActivitySelection(start, finish, 0, start.size());
  cout<<res1<<endl;
  int res2 = iterationActivitySelection(start, finish);
  cout<<res2<<endl;
  return 0;
}
