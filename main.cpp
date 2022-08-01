// Travis Cassell
// 02/15/2022
// CS 413_05
// Professor Derakhshandeh
// HW2

#include <iostream>
using namespace std;

int main() {
    // Struct to hold array values and their quantities
    struct Number
    {
        int value = 0;
        int quantity = 0;
    };
    
    const int SIZE = 20;
    int currentIndex = 0;
    int totalDuplicates = 0;
    Number nums[SIZE];     // Array of structs to find duplicates
    
    int arr[SIZE] = {2,6,5,9,2,5,2,6,3,1,4,3,4,0,2,6,4,8,2,1};

    // Algorithm to search array and find duplicates
    // Duplicates are stored in separate array of structs
    // Struct holds the value and corresponding quantities
    
    for(int i = 0; i < SIZE; i++) {         // FIRST LOOP N
        int temp = arr[i];
        bool found = false;
        for(int j = 0; j < SIZE; j++) {     // NESTED SECOND LOOP N (N*N = O(N^2))
            if(temp == nums[j].value) {
                found = true;
                nums[j].quantity += 1;
            }
        }
        if(found == false) {
            nums[currentIndex].value = temp;
            nums[currentIndex].quantity += 1;
            currentIndex++;
        }
    }
    
    // Display results
    for(int x = 0; x < SIZE; x++) {
        if(nums[x].quantity > 1) {
            cout << nums[x].value << " has " << nums[x].quantity - 1 << " duplicates \n";
            totalDuplicates += (nums[x].quantity - 1);
        }
    }
    
    // Display accumulative duplicates
    cout << endl << "Total combined duplicates: " << totalDuplicates << endl;
    
    return 0;
}


// C * N * N = CN^2 = O(N^2)
