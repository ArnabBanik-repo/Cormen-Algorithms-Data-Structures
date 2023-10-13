//  Created by Arnab Banik on 2023-10-12.
//  Copyright (c) 2023 Arnab Banik. All rights reserved.
//
//  An example of countingSort implementation in C++ using vectors:
//     Worst case performance       O(n + k)
//     Best case performance        O(n)
//     Average case performance     O(n)
//
//  Counting sort works by iterating through each integer element of a list and using the frequency of each element to decide the position of the element in the sorted array.
//

#include <iostream>
#include <vector>

std::vector<int> countingSort(std::vector<int>& numbers){
    int n = numbers.size(), k = 0;
    for(int i = 0; i < n; ++ i)
        k = std::max(k, numbers[i]);
    std::vector<int> freq(k + 1, 0), temp(n);
    for(int i = 0; i < n; ++ i)
        ++ freq[numbers[i]];
    for(int i = 1; i <= k; ++ i)
        freq[i] += freq[i - 1];
    for(int i = n - 1; i >= 0; -- i){
        temp[freq[numbers[i]] - 1] = numbers[i];
        -- freq[numbers[i]];
    }
    return temp;
};

// Testing the countingSort function

int main() {
    std::vector<int> numbers = {44, 9, 237, 1, 5, 44, 534, 17, 21, 819, 1};
    std::vector<int> sortedNumbers = countingSort(numbers);
    for(const auto& x: sortedNumbers)
        std::cout << x <<" ";
    return 0;
}
