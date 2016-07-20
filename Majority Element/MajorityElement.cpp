#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

vector<int> RemoveDuplicates(vector<int>& nums) 
{
    vector<int> result;

    if (nums.size() == 0)
    {
        return result;
    }

    int majority1 = 0;
    int majority2 = 0;

    int count1 = 0;
    int count2 = 0;

    for (int n : nums)
    {
        if (n == majority1)
        {
            count1++;
        }
        else if (n == majority2)
        {
            count2++;
        }
        else
        {
            if (count1 == 0)
            {
                majority1 = n;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                majority2 = n;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
    }

    count1 = 0;
    count2 = 0;

    for (int n : nums)
    {
        if (n == majority1)
        {
            count1++;
        }
        else if (n == majority2)
        {
            count2++;
        }
    }

    if (count1 > (nums.size() / 3))
    {
        result.push_back(majority1);
    }
    if (count2 > (nums.size() / 3))
    {
        result.push_back(majority2);
    }
    
    return result; 
}