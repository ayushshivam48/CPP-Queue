#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> res;
    
    // Initial processing for the first window
    for (int i = 0; i < k; i++) {
        // Remove elements from the back if they are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    // Add the maximum for the first window
    res.push_back(arr[dq.front()]);
    
    // Process the rest of the array
    for (int i = k; i < arr.size(); i++) {
        // Remove the element that is out of the current window
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements from the back if they are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(arr, k);
    cout << "Maximum in each sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
