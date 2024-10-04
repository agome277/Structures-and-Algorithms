#include <iostream>
#include <vector>

using namespace std;

//receives sorted vector and target int value
//returns index of target if found, otherwise returns -1
int BinarySearch(const vector<int> &data, const int target) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {//loop ends and returns -1 when low is larger than high
        int mid = (low + high) / 2;

        if (data[mid] == target) { //returns index/mid when target found
            return mid;
        }

        //low adjusted to upper half of array when data[mid] is less than target
        else if (data[mid] < target) {
            low = mid + 1;
        }

        //high adjusted to lower half of array when data[mid] is more than target
        else {
            high = mid - 1;
        }
    }

    return -1;
}

//recursive implementation of binary search
//receives sorted vector, low (initially 0), high (initially vector size -1), and the target value
//returns index of vector where target is, -1 if target not in vector
int BinarySearchRecursive(const vector<int> &data, const int low, const int high, const int target) {
    if (low > high) {return -1;} //return -1 when low is larger than high

    int mid = (low + high) / 2;

    if (data[mid] == target) { //returns mid (index) when target is found
        return mid;
    }

    //target is in upper half of vector if data's value at mid is less than target
    else if (data[mid] < target) {
        return BinarySearchRecursive(data, mid + 1, high, target);
    }

    //target is in lower half of vector if data's value at mid is more than target
    else {
        return BinarySearchRecursive(data, low, mid - 1, target);
    }
}
