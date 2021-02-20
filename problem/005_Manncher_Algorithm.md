---
export_on_save:
html: true
---
# Manacher Algorithm 马拉车算法

## 1. 预处理
在最长回文子串问题中，比较常见的解法包括动态规划和扩散法，两种方法的复杂度都是$O(n^2)$, 而Manacher算法结合两种算法的优点，从而可以在$O(n)$的线性复杂度下对这一问题进行求解。

首先回顾一下扩散法，就是尝试字符串中每一个可能的回文核，遍历出所有可能的回文子串，并从中找到最长的。基于这一算法，并利用回文字符串的对称特性，我们就可以利用动态规划空间换时间的思想：*利用之前的计算结果，快速找到当前回文核的边界*。扩散法中有一个比较头疼的问题，即奇数回文串和偶数回文串的回文核不一致，为此，我们将原始字符串进行插空加入特殊字符（如下图），这样，字符串中所有的回文串就都是奇数串。

![预处理](https://raw.githubusercontent.com/Frees0u1/ImageBase/main/img/20210220111552.png)
不难得出以下一些基本结论：

$$
i^{'} = i / 2 \\
预处理串中回文子串长度 = (原始串中对应回文串长度 - 1)/2 = 预处理回文串回文核向右扩散的步数
$$
从现在开始，我们都只关心预处理后的字符串，待找到预处理字符串的中的最长回文子串后，再mapping回原始字符串。

## 2. 核心算法

### 变量定义
马拉车算法的核心是利用之前的计算结果，快速找到当前回文核的边界。对于预处理字符串，我们**定义$P[i]$为以下标$i$为回文核的回文半径，也即向右扩散的最大长度**。在这里，我们定义如下几个核心变量：
![核心变量](https://raw.githubusercontent.com/Frees0u1/ImageBase/main/img/20210220164524.png)

1. i是当前循环变量，$P[0]...P[i-1]$以计算完毕
2. $[m, minRight]$是之前所有出现过的回文子串中, 右边界最右的那一个
3. $center$是$[m, minRight]$的回文核，也即对称中心
4. $mirror$是$i$关于center的对称点

上文所说的是$i < maxRight$中的一种情况，对于$i >= maxRight$的case, 老老实实尝试扩散法得到$P[i]$就行。如果下文介绍算法时有任何疑惑，可以回过头来再品一品这几个核心变量的定义。

### 分类讨论
在上节所定义的一般情况中，考虑到回文串的对称性，$P[i]$的值可以利用$P[mirror]$进行求解，根据$P[mirror]$的大小，可以分为以下三种case
#### case 1: $P[mirror] < maxRight - i$
![case1](https://raw.githubusercontent.com/Frees0u1/ImageBase/main/img/20210220123403.png)

这种case下，i和mirror严格对称，mirror的回文串是什么样的，i的回文串就是什么样的，可以得出：$P[i] = P[mirror]$


#### case 2: $P[mirror] > maxRight - i$
![case2](https://raw.githubusercontent.com/Frees0u1/ImageBase/main/img/20210220164332.png)
左边的两个绿色框之间是以mirror为核的回文串，[m, maxRight]为当前最右端的回文串，不难看出 $s[maxRight+1] \ne s[m-1]$, 也即图示中的红框与黑框，根据对称性，我们也不难得出： $P[i] = maxRight - i$


#### case 3: $P[mirror] == maxRight - i$
这是最复杂的一种case
![case3](https://raw.githubusercontent.com/Frees0u1/ImageBase/main/img/20210220165403.png)
这种case下，mirror为核的回文串恰好到了左边界上。我们发现，以i为回文核向右扩散，我们可以发现到maxRight时，根据center的对称性，都依然是回文的。不过到$maxRight+1$时，情况发生了变化，我们不知道这里是否仍然合法，那么怎么办，只能老老实实尝试一个一个扩散。
因此，我们也不难得出，$P[i] 至少为 maxRight - i$, 然后再尝试扩散。

#### 总结
以上三种case我们可以进行归一，即 $P[i] = min(maxRight - i, P[mirror]), 然后尝试扩散$。这就是状态转移方程。
而如果我们得到了一个最长的回文子串其长度是$maxLen$, 回文核是$i$, 则我们也可以推导出其在原始字符串上所对应的子串
$$
对应原始子串长度 = P[i] \\
对应原始子串初始位置begin = (i - P[i]) / 2
$$


## 3. 复杂度分析
在推导每一个$P[i]$时，$P[i]$都可以从当前扩散到的最右端开始，因此哪怕每一个i都需要尝试扩散（即 $i >= maxRight$）,每个位置也只需要尝试扩散一次。因此有最坏时间复杂度为$O(n)$

## 4. Sample Code(C++)
```cpp
string longestPalindrome(string s) {
        int n = s.size(); 
        if(n == 0) return "";

        // 预处理
        string ps = "#";
        for(int i = 0; i < n; i++) {
            ps += s[i];
            ps += "#";
        }

        int center = 0, maxRight = 0;
        int maxLen = 0, begin = 0; 
        vector<int> p(2 * n + 1, 0);
        p[0] = 0;

        for(int i = 0; i < ps.size(); i++) {
            int mirror = 2 * center - i;
            
            if(i < maxRight) {
                p[i] = min(maxRight - i, p[mirror]);
            }

            // 尝试扩散
            int j = i + p[i] + 1;
            while(j < ps.size()) {
                int k = 2 * i - j;
                if(k < 0 || ps[j] != ps[k]) break;
                p[i]++;
                j++;
            }

            if(i + p[i] > maxRight) {
                maxRight = i + p[i];
                center = i;
            }

            if(p[i] > maxLen) {
                maxLen = p[i];
                begin = (i - maxLen) / 2;
            }
        }

        return s.substr(begin, maxLen);
    }
```
