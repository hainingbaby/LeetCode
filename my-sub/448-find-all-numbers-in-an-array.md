
#### 448. Find All Numbers Disappeared in an Array.
>Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

>Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
>
Example:
>
Input:
[4,3,2,7,8,2,3,1]
>
Output:
[5,6]

解：在一个整数数组中找出所有未出现过的数并输出，要求时间复杂度O(n),而且不浪费额外的空间。
正常的思路是两个循环解决问题。空间上不多余，但时间复杂度是0(n^2)。
考虑到是一个整数数组，可以利用索引与本身数值的关系。

如果这个数组是顺序排列的那就好了，我只需要判断索引 i 的值是不是 i+1（num[i] == i+1)，就能知道这个数在不在数组里。然后得出结果就行了。

<b>问题的关键就在于</b>，数组不是顺序排列的，这个简单的判断方法不好使了，之前是按照索引找数值，因为本题情况的特殊化，可不可以按照数值找索引呢？

也就是说，一个整数数组[4,3,2,7,8,2,3,1]，有 4 这个数值，就意味着，<b>在顺序排列的数组里</b>，num[3]是可以映射到4的（num[3]==4），有 3 这个数值，那么num[2]可以映射到3（num[2]==3），有 num[i]这个数值，那么 num[ num[i]-1 ] 可以映射到num[i]。所以，是不是遍历一次这个数组，如果有个整数不在这个数组里边，那么我们就无法对他作出处理，使其在顺序数组里索引和数值相对应？

所以，思路有了：

* 遍历一遍数组，对于每一个整数num[i]，把这个整数，在假设的顺序排列数组里的<b>索引</b>，也就是「num[i]-1」（注意，这是一个索引）做上标记，目的是和没有出现在数组里的整数的索引区分开来。

* 再遍历一遍（这个数组或者你自己新建的数组，后边会解释），根据标记，返回最终结果。

怎么做标记区分开出现的和没出现的整数？举两个例子。

1. 新建一个数组a，初始化为1，见到第一个数4，把a[3]改为0，见到3，把a[2]改为0，见到2把a[1]改为0，依次继续。突然，见到了第二个2出现了，这时候改不改都无所谓，因为a[2]已经是0了。<b>注意</b>，这个地方的数字本来应该是缺少的那一个，也就是我们寻找的结果，是几呢，5，所以他本来应该把a[4]改成0，但是现在没有改。
所以，再遍历一次你新建的a数组，哪个索引 i 对应的数值是 1 ，则 i+1 就是我们要找的那个未出现在数组里的整数（因为我们利用了顺序数组的性质进行的改值操作）。

2. 方法1自己开辟了一个数组a，能不能在原数组上改呢？能，改成原来值的负值是一个不错的选择，虽然我们根本不关心它的值为负还是为0，只是需要区分在其中的整数和不在其中的整数的区别罢了。但是在把当前数值转换成索引的时候会变动后边的数值，取负值可以用绝对值函数abs，不影响后边的变换。改成0就不行了。

``` c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0)
                nums[index] = -nums[index];
            }
        for(int j=0; j< nums.size(); j++){
            if(nums[j] > 0)
                res.push_back(j+1);
        }
        return res;
    }
};
```