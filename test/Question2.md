# 东方之旅-2
## **本题目背景较长，如果没有充足的时间请直接跳到题目描述**
### 【题目背景】  
埃斯蒂尼安整理好了战斗用品准备上路了，他尾随了一艘正经的贸易船和小龙一起前往东方，到达黄金港之后，埃斯蒂尼安和小龙感叹着东方地域的地貌以及建筑风格与艾欧泽亚的区别很大。高耸的塔楼、漫长的海岸线，停泊的商船，以及东方风格满满的建筑，令他们应接不暇。  
他们十分愉悦，当夜幕降临，灯火阑珊，黄金港繁华的小金街的老板们摆上了各色各样的食品，埃斯蒂尼安才发现自己和小龙的肚子已经饿了，他们来到了潮风亭，点了一些食物，正打算享受的时候，埃斯蒂尼安惊讶的发现一个问题。  
因为之前行李只带了战斗用品，而 忘了带钱了！！！！     
“什么！你竟然没有钱！”小龙大惊，这一声引来了潮风亭的老板，老板看到了他们一人一龙体魄惊奇，点了点头，询问他们，是否愿意在潮风亭这里工作，不仅这里吃饭不用花钱，而且还可以赚钱。    
埃斯蒂尼安大喜，说“那就勉为其难的在这里工作把。”    
于是埃斯蒂尼安开始在潮风亭端盘子，当起了服务员，而小龙也跟着没事的时候喷火帮忙烤一下鱼干。


### 【题目描述】  
在工作的期间埃斯蒂尼安总能遇到很多顾客，顾客之间是有关系的，埃斯蒂尼安为了能够询问到他们关于青龙所在地的信息，对他们的关系做了调查。   
对于熟人的定义 满足以下的情况  
- 如果A和B是熟人同时B和C也是熟人 **那么A和C也是熟人** 。
- 对于都是熟人的一群人计算为 **<font size = 4>1个</font>** 顾客团体。
- 如果A和B是熟人，那么A所在的顾客团体和B所在的顾客团体 **每个人** 之间都是熟人,这样只能计算为只有 **一个** 顾客团体。

所以“光之战士，帮帮大师兄！”
### 【输入格式】
第一行给出两个**正整数** **_N_**  和 **_M_**  两个正整数之间用空格隔开,**_N_**  代表顾客总数量 **_M_** 代表要调查中得到的信息，以及想要得到的信息。
接下来 **_M_** 行 每行的格式为下述之一：   
**_1 u v_** ————表示顾客 **_u_** 和顾客 **_v_** 是认识的熟人。  
**_2 x y_** ————表示埃斯蒂尼安想要知道 **_x_** 和顾客 **_y_** 是不是认识的熟人  
**_3 z_** ————表示埃斯蒂尼安想要知道 **_z_** 顾客他们一个整个顾客团体的人有多少人。  
**_4_** ————表示埃斯蒂尼安想要知道现在一共有几个顾客团体。  

### 【输出格式】


### 输入样例:


```in
3 7
1 1 2
2 2 3
3 2
1 2 3
2 2 3
3 2
4
```

### 输出样例:


```out
No
2
Yes
3
1
```


### 数据约定


|  | N | M | 特殊性质 |
| -----------: | -----------: | -----------: | -----------: |
| 1~2 | ≤5e4 | ≤1e5 | √ |
| 3~5 | ≤5e4 | ≤1e5 | × |
特殊性质：不存在3和4操作的情况。
