// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 8 - Problem #1

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums;
    int input = 0;
    int length = 0;
    while(input != -1){
        cout << "Please enter a number:" << endl;
        cin >> input;
        bool insert = true;
        if(input > 0){
            if(length == 0){
                nums.push_back(input);
                length++;
            } else {
                if(input % 3 == 0){
                    nums.pop_back();
                    insert = false;
                    length--;
                }
                if(input % 5 == 0 && length > 0){
                    nums.erase(nums.begin());
                    insert = false;
                    length--;
                }
                if(insert){
                    nums.push_back(input);
                    length++;
                }

            }
        } else if(input != -1){
            cout << "The number should be a positive integer or -1." << endl;
        }
    }
    if(length > 0){
        cout << "The elements in the vector are: ";
        for(int i = 0; i < length; i++){
            cout << nums[i] << " ";
        }
        int max = 0;
        int min = 9999999;
        for(int i = 0; i < length; i++){
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i] < min){
                min = nums[i];
            }
        }
        cout << endl;
        cout << "Min = " << min << endl;
        cout << "Max = " << max << endl;
    } else {
        cout << "The vector is empty." << endl;
    }
    return 0;
}