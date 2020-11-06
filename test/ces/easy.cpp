#include <cstdio>
#include <iostream>
#include <cstdlib>
#define MAXN 100010
using namespace std;
template <typename T1>
struct node
{
    node<T1> *son[2];
    node<T1> *fat;
    int all;
    T1 val;
};
template <typename T1>
class Splay
{
private:
    node<T1> start;
    node<T1> *vis;
    int idt(node<T1> *root)
    {
        return (root->fat->son[0] == root) ? (0) : (1);
    }
    void update(node<T1> *root)
    {
        if (root != start)
            root->all = root->son[0]->all + root->son[1]->all + 1;
    }
    void connect(node<T1> *so, node<T1> *fa, int ple)
    {
        so->fat = fa;
        fa->son[ple] = so;
    }
    void rotate(node<T1> *root)
    {
        node<T1> *fa = root->fat;
        node<T1> *gfa = fa->fat;
        int rfa = idt(root);
        int sonr = rfa ^ 1;
        node<T1> *son = root->son[sonr];
        int fagfa = idt(fa);
        connect(son, fa, sonr ^ 1);
        connect(fa, root, sonr);
        connect(root, gfa, fagfa);
        update(fa);
        update(root);
    }
    void splay(node<T1> *root)
    {
        for (; root->fat != start;)
        {
            rotate(root);
        }
    }
    void initNode(node<T1> *root)
    {
        root->son[1] = start;
        root->son[0] = start;
        root->fat = start;
    }
    void findm(node<T1> *root)
    {
        if (root != start)
        {
            findm(root->son[0]);
            cout << root->val << " ";
            findm(root->son[1]);
        }
    }

public:
    Splay(T1 A)
    {
        node<T1> *k = (node<T1> *)malloc(sizeof(node<T1>));
        initNode(k);
        start->son[0] = k;
        k->fat = start;
    }
    void Push(T1 value)
    {
        node<T1> *k = (node<T1> *)malloc(sizeof(node<T1>));
        initNode(k);
        k->val = value;
        node<T1> *fd = start->son[0];
        int flag = -1;
        while (1)
        {
            if (value <= fd->val)
            {
                if (fd->son[0] != start)
                    fd = fd->son[0];
                else 
                    flag = 0;
            }
            else
            {
                if (fd->son[1] != start)
                    fd = fd->son[1];
                else 
                    flag = 1;
            }
            if (flag != -1)
            {
                fd->son[flag] = k;
                k->fat = fd;
                break;
            }
        }
        splay(k);
    }
    void FindMid()
    {
        findm(root->son[0]);
        puts();
    }
    void FindFront()
    {
    }
    void FindBack()
    {
    }
    void FindPerFl()
    {
    }
};
Splay<char> s('a');
int main()
{
    s.Push('b');
    s.FindMid();
}