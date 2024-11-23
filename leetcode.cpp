// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<vector>
#include <iostream>
#include<algorithm>
#include<numeric>

using namespace std;


int findContentChildren(vector<int>& children, vector<int>& cookies) 
{
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child_i = 0, cookie_i = 0;
    int n_children = children.size(), n_cookies = cookies.size();
    while (child_i < n_children && cookie_i < n_cookies) {
        if (children[child_i] <= cookies[cookie_i]) {
            ++child_i;
        }
        ++cookie_i;
    }
    return child_i;
}
void use_findContentChildren()
{
    vector<int> children;
    vector<int> cookies;
   
    children={ 3,4 };
    cookies={ 1,2,3, };

    cout<<findContentChildren(children, cookies);
}


int candy(vector<int>&rating)
{
    int n = rating.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (rating[i] > rating[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if ( rating[i - 1]> rating[i] )
        {
            candies[i - 1] =max(candies[i - 1], candies[i] + 1);     
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}
void use_candy()
{
    vector<int> rating = { 1,0,2 };
    cout << candy(rating);
}


int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });
    int removed = 0, prev_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < prev_end)
        {
            ++removed;
        }
        else
        {
            prev_end = intervals[i][1];
        }
    }
    return removed;
}
void use_eraseOverlapIntervals()
{
    vector<vector<int>> intervals = { {1,2},{2,4},{1,3} };
    cout<<eraseOverlapIntervals(intervals);
}

/*第2 章玩转双指针*/

vector<int> twoSum(vector<int>& number, int target)
{
    int l = 0, r = number.size() - 1,two_sum;
    while (l < r)
    {
        two_sum = number[l] + number[r];
        if (two_sum == target)
        {
            break;
        }
        if (two_sum < target) l++;
        else                   --r;
    }
    return vector<int>{l + 1, r + 1};
}
void use_twoSum()
{
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> val = twoSum(numbers, target);
    cout << "[" << val[0] << "，" << val[1] << "]" << endl;
}


//归并两个有序数组
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    /*Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
      Output: nums1 = [1,2,2,3,5,6]*/
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0)
    {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0)
    {
        nums1[pos--] = nums2[n--];
    }

    for (int n : nums1)
        cout << n << ",";
}
void use_merge()
{
    vector<int>  nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int>  nums2 = { 2, 5, 6 };
    int m = 3, n = 3;
    merge(nums1,m, nums2,n);

}

string minWindow(string s, string t)
{
    /*   
    先统计 t 中字符的频率。
    使用滑动窗口，右指针不断扩展窗口，左指针在条件满足时缩小窗口。
    通过更新最短窗口的起始位置和长度，最终返回包含 t 所有字符的最短子串。*/


}
void use_minWindow()
{
    string s = "ADOBECODEBANC", t = "ABC";
    minWindow(s,t);
    
}

int main()
{
    std::cout << "Hello World!\n";

    /*第1 章贪心算法*/
    //use_findContentChildren();
    //use_candy();
    //use_eraseOverlapIntervals();// 区间问题

    /*第2 章玩转双指针*/
    //use_twoSum();
    //use_merge();

    /*滑动窗口*/
    use_minWindow();


}

