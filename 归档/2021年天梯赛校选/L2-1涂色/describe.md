# 涂颜色(25分)

### 【题目描述】  
由数字**0**组成的方阵中，有一任意形状闭合圈，闭合圈由数字**1**构成。现要求把闭合圈内的所有空间都填写成**2**.例如：**6**×**6**的方阵（**n=6**），涂色前和涂色后的方阵如下：

```in
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
```
```in
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 2 2 1
1 1 2 2 2 1
1 2 2 2 2 1
1 1 1 1 1 1
```

### 【输入格式】
每组测试数据第一行一个整数n(1**≤**n**≤**30)

接下来**n**行，由**0**和**1**组成的**n×n**的方阵。

方阵内只有一个闭合圈，圈内至少有一个**0**。

### 【输出格式】
已经填好数字**2**的完整方阵。

### 输入样例:


```in
6
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
```

### 输出样例:


```out
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 2 2 1
1 1 2 2 2 1
1 2 2 2 2 1
1 1 1 1 1 1
```

