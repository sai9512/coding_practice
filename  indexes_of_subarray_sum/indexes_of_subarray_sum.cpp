#include <iostream>
#include "indexes_of_subarray_sum.h"
using namespace std;


/*

Given an unsorted array arr of size n that contains only non negative integers, 
find a sub-array (continuous elements) that has sum equal to s. You mainly need 
to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. 
If no such subarray exists return an array consisting of element -1.

Examples:

Input: arr[] = [1,2,3,7,5], n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.
Input: arr[] = [1,2,3,4,5,6,7,8,9,10], n = 10, s = 15,
Output: 1 5
Explanation: The sum of elements from 1st to 5th position is 15.
Input: arr[] = [7,2,1], n = 3, s = 2
Output: 2 2
Explanation: The sum of elements from 2nd to 2nd position is 2.
Input: arr[] = [5,3,4], n = 3, s = 2
Output: -1
Explanation: There is no subarray with sum 2
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:

0 <= arr[i] <= 109
1 <= n <= 105
0 <= s <= 109

*/





int main() {

int size;
int total_sum;
int current_sum =0;
int start_index=0;
const int MAX_SIZE = 105;
const int MIN_SIZE = 1;
const int MAX_SUM = 109;
const int MIN_SUM = 1;
const int MAX_VALUE = 109;
const int MIN_VALUE = 0;
cout<<"Enter size of the array"<<endl ;
get_input_values_with_limit(MIN_SIZE, MAX_SIZE, size);

cout<<"Enter total_sum"<<endl ;
get_input_values_with_limit(MIN_SUM, MAX_SUM, total_sum);
int arr[size];

cout<<"Enter the array of size:"<< size<<endl;

for (int i = 0; i < size; i++) {
        cout<<"index:"<<i<<endl;
        get_input_values_with_limit(MIN_VALUE, MAX_VALUE, arr[i]);
        if (arr[i] == total_sum){cout<< "result:"<< i+1 << "," << i+1 <<endl;break;} 
        if (current_sum + arr[i] < total_sum){current_sum = current_sum+arr[i];continue;} 
        if (current_sum + arr[i] > total_sum){current_sum = abs(current_sum + arr[i] - arr[start_index]); start_index=start_index+1; if (current_sum==total_sum){cout<< "result:"<< start_index+1 << "," << i+1 <<endl;break;}continue;} 
        if (current_sum + arr[i] == total_sum){cout<< "result:"<< start_index+1 << "," << i+1 <<endl;break;} 

        cout<<-1<<endl;

    }


return 0;
}

void get_input_values_with_limit(const int MIN_SUM, const int MAX_SUM, int &total_sum)
{
while (true) {
            int value;
            cin >> value;
            if (value >= MIN_SUM && value <= MAX_SUM) {
                total_sum = value;
                break; // Break the loop if the value is within the limit
            } else {
                cout << "Invalid input. Please enter a number between " << MIN_SUM << " and " << MAX_SUM << ": ";
            }
        }
}