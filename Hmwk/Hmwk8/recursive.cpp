#include <iostream>
#include <vector>
using namespace std;

vector<int> getNextNum(vector<int> nums, vector<int> vec, int currentSum, int currentCount, int endNum){
    vector<int> returnVec = vec;
    if(currentCount < nums.size()){
        int returnInt = currentSum;
        int count = currentCount;
        returnInt += nums[count];
        count++;
        if(currentSum > endNum){
            return returnVec;
        } else {
            getNextNum(nums, returnVec, returnInt, count, endNum);
        }
    } else {
        returnVec.push_back(currentSum);
        getNextNum(returnVec, returnVec, 0, 0, endNum);
    }
}

void printElements(vector<int> nums, int count){
    cout << nums[count] << " ";
    int i = count;
    i++;
    printElements(nums, i);
}

void fillCumulativeSumRecursive(int endNum){
    vector<int> vec{1};
    vector<int> printNums = getNextNum(vec, vec, 0, 0, endNum);
    printElements(printNums, 0);
}

int main(){
    fillCumulativeSumRecursive(20);
}