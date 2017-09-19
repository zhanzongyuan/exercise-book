# leetcode
The repository is used to store my code for problems in leetcode

## 015 three sum
> 2017-09-11 08:18

算法accpted！但是运行时间特别慢，只击败1%的cpp代码
算法学习改进中......

> 2017-09-13 08:27

通过网上学习代码，发现我的算法有如下不足：
- 排序使用的是优先队列，这里可以改用algorithm里的sort，方便消重，而2sum则不必要进行排序，因为这里排序至少需要nlogn的时间复杂度，而2sum只需要获得对应的一组目标的位置即可，则可以在n的时间复杂度内完成
- 在对第二，第三个数进行查找的时候，为了迎合大小顺序原则，对后面的序列进行了两次遍历，一次用于map存储下标，一次是逐个搜索；改进是需要放弃原来的2sum思想，因为对于3sum我们需要看到不同的是，这里有出现重复序列的可能；由于从小到大拼，所以可以自然的想到对后面的序列进行两端向中间靠拢的搜索，于是可以设置left，right，对于当前sum=nums[left]+nums[right]比较target，根据大小比适当移动left和right；实现这个的同时还需要进行消重的移动
- 外层循环里加入判断，判断当前位置nums[i]如果大于0，则后面的搜索是找不到新的目标序列的（但是不知道为什么加入这个后反而变慢了）

## 006 ZigZag Conversion
> 2017-09-13 12:16
- bug1: zigzag排列形式理解，以及规律探索
- bug2: s="AB" 1; 当转换行数为1时，出现bug，当作特殊情况处理，临界点bug

## 007 int2str
> 2017-09-18 08:35
- 对越界的判别方法
    - 符号变化
    - long long 范围用INT_MAX和INT_MIN判定

## 009 Palindrome Number
> 2017-09-19 13:00
- bug1 忘了考虑负数 x=INT_MIN=-2147483648 无法abs
- bug2 100021 验证中间变成只有一位的数字 不可用x<10判定
- bug3 k==0 不可k==1
- improve thinking 回文比较方法，数字反向后比较

