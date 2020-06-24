#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 200100
#define INF 2147480000
#define startroot n[0].plea[0]
using namespace std;
int k,head,grank;
struct avl
{
	int plea[2],fath,depth;	
	int num,cnt,recy;
}n[MAXN];

void updata(int root)//更新节点信息
{
    if (root == 0) return ;
    if (n[root].num == 0) return ;
    n[root].depth = max(n[n[root].plea[0]].depth,n[n[root].plea[1]].depth) + 1;
    n[root].cnt = n[n[root].plea[0]].cnt + n[n[root].plea[1]].cnt + n[root].recy;
}

int idt(int x){return n[n[x].fath].plea[0] == x?0:1;}//判断是否为左节点，是则返回0，否则返回1。 

void connect(int son, int fat,int ple){n[son].fath = fat;  n[fat].plea[ple] = son;}   //给两个点建立父子关系 
void rotate(int root)
{
	int up = n[root].fath; // 获得当前节点的父亲。 
	int upfa = n[up].fath; //  获得爷爷节点。 
	int upple = idt(up); // 获得父亲节点是爷爷节点的哪个节点。 
	int xple = idt(root);//  获得当前节点是父亲节点的哪个节点 
	int menext = n[root].plea[xple^1];// 获得自己要替换的节点的位置
    // printf("rotate %d and %d\n",root,up);
	connect(menext,up,xple);// 让自己的子节点与父节点相连接 
	connect(up,root,xple^1);//  让父节点连接自己 
	connect(root,upfa,upple);//  让自己连接爷节点。
	updata(up);
    updata(root); // 更新数据 
}

int putbf(int root)  {return n[n[root].plea[0]].depth - n[n[root].plea[1]].depth;}

void ifbf(int root)//获取自身与父亲的关系
{
    updata(root);
    int bf = putbf(root);
        // printf("int root:%d  the bf =%d\n",root,bf);
    if (bf > 1)
    {
        int son = n[root].plea[0];
        int sonbf = putbf(son);
        // printf("1111int root:%d  the bf =%d\n",root,sonbf);
        if (sonbf >= 0)
            rotate(son);
        else 
            {int acc = n[son].plea[1];rotate(acc);rotate(acc);}
    }
    if (bf < -1)
    {
        int son = n[root].plea[1];
        int sonbf = putbf(son);
        // printf("2222int root:%d  the bf =%d\n",root,sonbf);
	// for (int i = 0; i <= head; i++)
	// {
	// 	printf("root:%d     left:%d   right:%d     num:%d   father:%d     depth: %d \n",i,n[i].plea[0],n[i].plea[1],n[i].num,n[i].fath,n[i].depth);
	// }
        if (sonbf <= 0)
            rotate(son);
        else 
            {int acc = n[son].plea[0];rotate(acc);rotate(acc);}
    }
}

void create(int x,int root) // 创建新节点
{
    // printf("%d is stack in %d\n",x,root);
    if (head == 0)
    {
        // printf("****%d\n",x);
        head ++; n[0].plea[0] = 1;n[1].depth = 1,n[1].recy = 1;
        n[1].num = x;n[1].fath = 0;n[1].cnt = 1;
        return ;
    }
    if (x < n[root].num)
    {
        int k = n[root].plea[0];
        if (k == 0)
        {
            k = ++head;n[k].fath = root;
            // printf("k = %d\n",k);
            n[k].depth = 1;
            n[k].cnt = 1;n[k].recy = 1;
            n[root].plea[0] = k;n[k].num = x;
            // printf("in ");
            updata(root);
            return;
        }
        create(x,n[root].plea[0]);
    }
    if (x == n[root].num)
    {
        n[root].recy ++;
    }
    if (x > n[root].num)
    {
        int k = n[root].plea[1];
        if (k == 0)
        {
            k = ++head;n[k].fath = root;
            // printf("k = %d\n",k);
            n[k].depth = 1;
            n[k].cnt = 1;n[k].recy = 1;
            n[root].plea[1] = k;n[k].num = x;
            // printf("in ");
            updata(root);
            return ;
        }
        create(x,n[root].plea[1]);
    }
    // printf("%d is stack out:%d\n",x,root);
    ifbf(root);
}

void findrank(int x,int root,int rank) // 查找排名为N的点
{
    if (x > head) {printf("-%d\n",INF);return ;};
    int now = root;
    while(1)
    {
        // printf("find %d\n",now);
        int minused = n[now].cnt-n[n[now].plea[1]].cnt;
        if(x > n[n[now].plea[0]].cnt && x <= minused) break;
        if(x < minused) now = n[now].plea[0];
        else
        {
            x = x - minused;
            now = n[now].plea[1];
        }
    }
    printf("%d\n",n[now].num);
    // printf("is finding  %d at %d  count rank  %d",x,root,rank);
    // if (rank == x) 
    // {
    //     printf("%d\n",n[root].num);
    //     return ;
    // }
    // else 
    // {  
	//     if (n[root].plea[0] == 0 && n[root].plea[1] == 0) 
	// 	    return ;
    //     if (rank > x)
    //     {
    //         int son = n[root].plea[0];
    //         // printf("   **go left **\n");
    //         findrank(x,son,rank - n[n[son].plea[1]].cnt-1);
    //     }
    //     else 
    //     {
    //         int son = n[root].plea[1];
    //         // printf("   **go right **\n");
    //         findrank(x,son,rank + n[n[son].plea[0]].cnt+1);
    //     }

    // }
}

// void findNrank(int x,int root,int rank)
// {
//     if (root == 0) return;
// 	if (n[root].plea[0]) findNrank(x,n[root].plea[0],rank);
//     grank ++;
// 	if (x == n[root].num) printf("%d\n",grank);
// 	if (n[root].plea[1]) findNrank(x,n[root].plea[1],rank);
// }
void findNrank(int x,int root,int rank) // 查找为N的点的排名
{
    
    int ans = 0,now = root;
    while(1)
    {
        if (n[now].num == x) {printf("%d\n",ans+n[n[now].plea[0]].cnt + 1);return ;}
        if (now == 0) {printf("0\n");return;}
        if (x < n[now].num) now = n[now].plea[0];
        else 
        {
            ans = ans + n[n[now].plea[0]].cnt + n[now].recy;
            now = n[now].plea[1];
        }
    }
    return ;
    // printf("is finding  %d at %d  count rank  %d\n",x,root,rank);
    // if (x == n[root].num)
    // {
    //     bool bo = true;
    //     if (n[n[root].plea[0]].num == x)
    //     {
    //         int son = n[root].plea[0];
    //         findNrank(x,n[root].plea[0],rank - 1);
    //         bo = false;
    //     }
    //     if (bo) printf("%d\n",rank);
    //     return ;
    // }
    // else 
    // {
	//     if (n[root].plea[0] == 0 && n[root].plea[1] == 0) 
	// 	    return ;
    //     if (x < n[root].num)
    //     {
    //         int son = n[root].plea[0];
    //         // printf("   **go left **\n");
    //         findNrank(x,son,rank - n[n[son].plea[1]].cnt-1);
    //     }
    //     else 
    //     {
    //         int son = n[root].plea[1];
    //         // printf("   **go right **\n");
    //         findNrank(x,son,rank + n[n[son].plea[0]].cnt+1);
    //     }
    // }
}

void findupper(int x)
{
    int ans = INF;
    int now = startroot;
    while(now)
    {
        if(n[now].num > x && n[now].num < ans) ans = n[now].num;
        if(x < n[now].num) now = n[now].plea[0];
            else now = n[now].plea[1];
    }
    printf("%d\n",ans);
}

void findlower(int x)
{
    int ans = -INF;
    int now = startroot;
    while(now)
    {
        if(n[now].num < x && n[now].num > ans) ans = n[now].num;
        if(x > n[now].num) now = n[now].plea[1];
            else now = n[now].plea[0];
    }
    printf("%d\n",ans);
}

int find(int x,int root)
{
	if (n[root].num == x) return root;
	if (n[root].plea[0] == 0 && n[root].plea[1] == 0) 
		return -1;
	if (n[root].num < x)
		return find(x,n[root].plea[1]);
	else 
		return find(x,n[root].plea[0]);
	
}

void del(int x,int root)
{
    // if (x == 415495)    printf(" %d  I DON DELETE IT root %d \n",x,root);
    if (x == n[root].num) 
    {
        if(n[root].recy > 1)
        {
            n[root].recy --;
            n[root].cnt --; 
            updata(root);
            return ;
        }   
        if (n[root].plea[0] == 0 && n[root].plea[1] == 0)
        {
            n[root].recy = n[root].num = n[root].cnt = 0;
            int a = n[root].fath;
            while(a)  {updata(a);a = n[a].fath;}
            updata(n[root].fath);
            n[n[root].fath].plea[idt(root)] = 0;
            n[root].fath = 0;
            return;
        }
        else 
        {
            if (n[n[root].plea[0]].depth >= n[n[root].plea[1]].depth)
            {
                rotate(n[root].plea[0]);
                del(x,root);
            }
            else 
            {
                rotate(n[root].plea[1]);
                del(x,root);
            }
        }
        updata(root);
    }
    else 
    {
        // printf("is del  %d at %d\n",x,root);
        if (n[root].plea[0] == 0 && n[root].plea[1] == 0)
        {
            updata(root);
            int a = n[root].fath;
            while(a)    
            {
                updata(a);
                a = n[a].fath;
            }
            return ;
        }
        if (x > n[root].num)
            del(x,n[root].plea[1]);
        else 
            del(x,n[root].plea[0]); 
    }
        updata(root);
} 

void midfind(int x)
{
    if (x == 0) return;
	if (n[x].plea[0]) midfind(n[x].plea[0]);
	printf("%d ",n[x].num);
	if (n[x].plea[1]) midfind(n[x].plea[1]);
}

int main()
{
	int q;
	scanf("%d",&q);
	head = 0;
	for (int i = 1; i <= q; i++)
	{
        grank = 0;
        int q,w;
		scanf("%d%d",&q,&w);
        if (q == 1)
        {
		    if (head != 0) create(w,startroot);
                else create(w,1);
        }
        if (q == 2) del(w,startroot);
        if (q == 3) findNrank(w,startroot,n[startroot].cnt - n[n[startroot].plea[1]].cnt);
        if (q == 4) findrank(w,startroot,n[startroot].cnt - n[n[startroot].plea[1]].cnt);
        if (q == 5) findlower(w);
        if (q == 6) findupper(w);
        // printf("\n%d %d:\n",q,w);
        // updata(7);
        // if (w == 415495)
            
        // if (w == 632641)
        //     for (int i = 0; i <= head; i++)
	    //     {
		//         printf("root:%d      num:%d   left:%d   right:%d    father:%d     depth: %d all have %d\n",i,n[i].num,n[i].plea[0],n[i].plea[1],n[i].fath,n[i].depth,n[i].cnt);
	    //     }
	    // printf("root:%d      num:%d   left:%d   right:%d    father:%d     depth: %d all have %d\n",7,n[7].num,n[7].plea[0],n[7].plea[1],n[7].fath,n[7].depth,n[7].cnt);
        // puts("");
        // puts("");
        // puts("");
    //     puts("");
        
		// printf("root:%d     left:%d   right:%d     num:%d   father:%d     depth: %d \n",1,n[1].plea[0],n[1].plea[1],n[1].num,n[1].fath,n[1].depth);
	}
    // printf("****%d****",find(30,n[0].plea[0]));
	// for (int i = 0; i <= head; i++)
	// {
	// 	printf("root:%d      num:%d   left:%d   right:%d    father:%d     depth: %d cnt %d  recy:%d\n",i,n[i].num,n[i].plea[0],n[i].plea[1],n[i].fath,n[i].depth,n[i].cnt,n[i].recy);
	// }
    // midfind(startroot);
    
            for (int i = 0; i <= head; i++)
	        {
		        printf("root:%d      num:%d   left:%d   right:%d    father:%d     depth: %d all have %d\n",i,n[i].num,n[i].plea[0],n[i].plea[1],n[i].fath,n[i].depth,n[i].cnt);
	        }
}