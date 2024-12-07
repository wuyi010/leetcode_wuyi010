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
    /*
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 
    Output: nums1 = [1,2,2,3,5,6]
    */
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
  通过更新最短窗口的起始位置和长度，最终返回包含 t 所有字符的最短子串。
 */
    vector<bool> valid(128, false);
    vector<int> freq(128, 0);
    for (int i = 0; i < t.length(); i++)
    {
        valid[t[i]] = true;
        ++freq[t[i]];
    }
    int min_l = -1, min_length = -1;
    int count = 0 ;
    for (int l = 0, r = 0; r < s.length(); ++r)
    {
        if (!valid[s[r]]) 
            continue;
        if (--freq[s[r]] >= 0)
            ++count;
        while (count == t.length())
        {
            if (min_length == -1 || r - l + 1 < min_length)
            {
                min_l = l;
                min_length = r - l + 1;
            }
            if (valid[s[l]] && ++freq[s[l]] > 0)
            {
                --count;
            }
            ++l;
        }
    }
    return min_length == -1 ? "" : s.substr(min_l, min_length);
}


void use_minWindow()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
}

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head, * fast = head;
    bool is_first_cycle = true;
    while (fast != slow || is_first_cycle)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
        is_first_cycle = false;
    }
    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
void use_ListNode()
{
    ListNode* node1 = new ListNode(1); // 创建一个值为1的节点
    ListNode* node2 = new ListNode(2); // 创建一个值为2的节点
    ListNode* node3 = new ListNode(3); // 创建一个值为3的节点
    ListNode* node4 = new ListNode(4); // 创建一个值为3的节点
    ListNode* node5 = new ListNode(5); // 创建一个值为3的节点
    ListNode* node6 = new ListNode(6); // 创建一个值为3的节点
    ListNode* node7 = new ListNode(7); // 创建一个值为3的节点
    ListNode* node8 = new ListNode(8); // 创建一个值为3的节点
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node4;
    ListNode* node = detectCycle(node1);
    int temp = node->val;
    while (node != nullptr)
    {
         cout << node->val << " - ";
         node = node->next;
         int val = node->val;
         if (val == temp)
             break;
    }
}


int mySqrt_1(int x) {
    float t = x;
    while (t * t > x) {
        t = (t + x / t) / 2;
    }
    return t;
}
int mySqrt(int x) {
    int l = 1, r = x, mid, x_div_mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        x_div_mid = x / mid;

        if (mid == x_div_mid)
        {
            return mid;
        }
        if (mid < x_div_mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}
void use_mySqrt()
{
    //cout << mySqrt_1(10);
    cout << mySqrt(10.00);


}
int lowerBound(vector<int>& nums, int target)
{
    int l = 0, r = nums.size(), mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid ;
        }
    }
    return l;
}
int upperBound(vector<int>& nums, int target)
{
    int l = 0, r = nums.size(), mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] <= target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
void use_lowerBound_and_uperBound()
{
    //vector<int> nums = {1,2,3,4,5,7,7,8,8,10,13,15,18};
    vector<int> nums = { 1, 2, 4, 4, 4, 5, 6, 8 };

   int target = 4;
   int lower =  lowerBound(nums, target);
   int upper =  upperBound(nums, target);

   cout <<"(lower:upper) = ["<< lower <<":"<< upper<<")" << endl;
}
int findPeakElement(vector<int> & nums)
{
    int n = nums.size();
    if (n == 1) return 0;
    if (nums[0] > nums[1])return 0;
    if (nums[n - 1] > nums[n - 2])return n - 1; 
    int l = 1, r = n - 2, mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            return mid;
        else if (nums[mid] > nums[mid - 1])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
void use_findPeakElement()
{
    vector<int> nums = { 1, 2, 3, 1 };
    cout<<findPeakElement(nums);
}

void quickSort(vector<int>& nums, int l, int r)
{
    if (l >= r)
        return;
    int pivot = l + (rand() % (r - l + 1));
    int pivot_val = nums[pivot];
    swap(nums[l], nums[pivot]);
    int i = l + 1, j = r;
    while (true)
    {
        while (i < j && nums[j] >= pivot_val) 
        { 
            --j;
        }
        while (i < j && nums[i] <= pivot_val) 
        { 
            ++i;
        }
        if (i==j) 
        { 
            break;
        }
        swap(nums[i], nums[j]);
    }
    // i和j相遇的位置即为新的pivot，我们将pivot与l重新换回来。
    // 此时相遇位置左侧一定比pivot值小，右侧一定比pivot值大。
    int new_pivot = nums[i] <= nums[l] ? i : i - 1;
    swap(nums[l], nums[new_pivot]);
    quickSort(nums, l, new_pivot - 1);
    quickSort(nums, new_pivot+1, r);

}
void use_quickSort()
{
    vector<int>nums = { 5,3,2,8,1,4,0,7,6,9 };
    int r = nums.size() - 1;
    int l = 0;
    quickSort(nums,l, r);
    for (int x : nums) {
        cout << x << " ";
    }
}


vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b)
{
    int i = 0, j = 0;
    vector<int> mergeArray;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            mergeArray.push_back(a[i]);
            i++;
        }
        else
        {
            mergeArray.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        mergeArray.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        mergeArray.push_back(b[j]);
        j++;
    }
    return mergeArray;
}
void use_mergearray()
{
    vector<int> a{ 1,3,5,7,9,11,13,};
    vector<int> b{ 2,4,6,8,10 };
    vector<int> c= mergeSortedArrays(a,b);
    for (int x : c) {
        cout << x << " ";
    }
}
#include<stack>
int maxAreaOfIsland(vector<vector<int>>& grid) {
    //vector<int> direction{ -1, 0, 1, 0, -1 };
    vector<vector<int>> direction{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int m = grid.size(), n = grid[0].size(), max_area = 0;
    cout <<"行" << m << " 列" << n << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                stack<pair<int, int>> island;
                // 初始化第第一个节点。
                int local_area = 1;
                grid[i][j] = 0;
                island.push({ i, j });
                // DFS.
                while (!island.empty()) {
                    auto &[r,c] = island.top();
                    island.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = r + direction[k][0], y = c + direction[k][1];
                        // 放入满足条件的相邻节点。
                        if (x >= 0 && x < m && y >= 0 && y < n &&grid[x][y] == 1)
                        {
                            ++local_area;
                            grid[x][y] = 0;
                            island.push({ x, y });
                            cout << "x = " << x<<" ,y="<<y << "   locala "<< local_area<<endl;
                        }
                    }
                }
                cout <<"local_area:"<< local_area << endl;
                max_area = max(max_area, local_area);
            }
        }
    }

    return max_area;
}

int maxAreaOfIsland_wxl(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int island_num = 0;
    vector<vector<int>> direaction{ {-1,0},{0,1},{1,0},{0,-1} };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({ i,j });
                int islandcount = 1;
                while(!island.empty()) {
                    auto& [r, c] = island.top();
                    island.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = r + direaction[k][0];
                        int y = c + direaction[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                            island.push({ x,y });
                            grid[x][y] = 0;
                            islandcount++;
                        }
                    }
                    
                    island_num = max(island_num, islandcount);
                }
            }
        }
    }
    return island_num;
}
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
        return 0;
    }
    grid[r][c] = 0;
    return (1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c)+ dfs(grid, r, c + 1)+dfs(grid, r, c - 1));
}
int use_dfs_max_areaofIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); ++j) {
            max_area = max(max_area, dfs(grid, i, j));
        }
    }
    return max_area;
}
void use_DFS()
{
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1}
    };
    //int maxArea = maxAreaOfIsland(grid);
    int maxArea = maxAreaOfIsland_wxl(grid);
    cout << "Maximum area of the island is: " << maxArea << endl;

    vector<vector<int>> grid2 = {
       {1, 0, 1, 1, 0, 1, 0, 1},
       {1, 0, 1, 1, 0, 1, 1, 1},
       {0, 0, 0, 0, 0, 0, 0, 1}
    };
    cout << "使用递归方法进行深度搜索" << endl;
    cout<<use_dfs_max_areaofIsland(grid2);

}
void backtracking(vector<int>&nums,int level, vector<vector<int>>& permutations) {
    if (level == nums.size() - 1)
    {
        permutations.push_back(nums);
        return;
    }
    for (int i = level; i < nums.size(); ++i) {
        swap(nums[i], nums[level]);
        backtracking(nums, level + 1, permutations);
        swap(nums[i], nums[level]);

    }

}
vector<vector<int>> permute(vector<int>& num) {
    vector<vector<int>> permutations;
    backtracking(num, 0, permutations);
    return permutations;
}
void use_backtracking() {
   //回溯法，只对原数组进行修改，在递归完成后再修改回来。
    //，一是按引用传状态，二是所有的状态修改在递归完成后回改。
    vector<int> num{ 1,2,3 };
    vector<vector<int>> output = permute(num);

    for ( vector<int>vx : output) {
        cout << "{ ";
        for (int x : vx) {
            cout << x << ",";
        }
        cout << " }" << endl;
    }

}
int main()
{
    /*第5 章 一切皆可搜索*/
   //深度优先搜索 搜索到新节点 对新节点进行搜索 遍历需要用先入后出的stack，递归等价，对于树结构而言，由于总是对新节点调用遍历，因此看起来是向着“深”的方向前进
   // 广度优先搜索
   // 回溯法

   //5.2 use_DFS();
   //5.3 回溯法
    use_backtracking();

    /*************************************************************/
    std::cout << "Hello World!\n";
    /*  第1 章贪心算法  */
    //  use_findContentChildren();
    //  use_candy();
    //  use_eraseOverlapIntervals();// 区间问题
    /*************************************************************/
    /*  第2 章玩转双指针 */
    //  use_twoSum();
    //  use_merge();
    //  滑动窗口 
    //use_minWindow();
    /*2.5快慢指针*/
    /*************************************************************/
    //use_ListNode();
    /*3 居合斩！二分查找*/
    //use_mySqrt();
    /*3.3 查找区间*/
    //use_lowerBound_and_uperBound();
    //查找峰值
    //use_findPeakElement();
    /*************************************************************/
    /*第4 章千奇百怪的排序算法*/
    //use_quickSort();
    //Hungarian_Algorithm();
    //use_mergearray();
   /*************************************************************/
}

