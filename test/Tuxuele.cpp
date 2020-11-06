#include<cstdio>
#include<cstdlib>
#define INF 0x3f3f3f3f
int k;
struct node
{
    int num;
    node* node;
};
node* null;

class LA
{
private:
    node* start = null;
    int Long = 0;
    node* Head = null;
    void LetHeadToTheEnd()
    {
        while (Head->node != null)
        {
            Head = Head->node;
        }
    }

public:
    ~LA()
    {
        clear();
    }


    void push_back(int k)
    {
        if (Long == 0)
        {
            start = (node*)malloc(sizeof(node));
            Head = start->node = (node*)malloc(sizeof(node));
            Long++;
            Head->num = k;
            Head->node = null;
        }
        else
        {
            Head->node = (node*)malloc(sizeof(node));
            Head = Head->node;
            Head->num = k;
            Head->node = null;
            Long++;
        }
    }

    node* find_element(int k)
    {
        for (node* i = start; i->node != null; i = i->node)
        {
            if (i->num == k)
                return i;
        }
    }
    int find_please(int k)
    {
        if (Long < k)
        {
            return -1;
        }
        int j = 0;
        node* i = start;
        while (k != j)
        {
            j++;
            i = i->node;
        }
        return (i->num);
    }
    void insert(int k, int please)
    {
        if (Long + 1 < please)
        {
            return;
        }
        int j = 1;
        node* i = start;
        while (please != j)
        {
            j++;
            i = i->node;
        }
        node* n = (node*)malloc(sizeof(node));
        Long++;
        n->node = i->node;
        i->node = n;
        n->num = k;
        LetHeadToTheEnd();
    }
    int erase(int k)
    {
        if (Long < k)
        {
            return -1;
        }
        int j = 1;
        node* i = start;
        while (k != j)
        {
            j++;
            i = i->node;
        }
        Long--;
        node* del = i->node;
        i->node = del->node;
        int ret = del->num;
        free(del);
        return ret;
    }

    int length()
    {
        return Long;
    }

    bool empty()
    {
        return Long == 0 ? 1 : 0;
    }

    void clear()
    {
        node* t = start;
        while (t != null)
        {
            node* tt = t;
            t = t->node;
            free(tt);
        }
    }
};

int main()
{
    node* null = (node*)malloc(sizeof(node));
    LA k;
    k.push_back(5);
    k.insert(15252, 2);
    k.erase(2);
    printf("%d", k.empty());
    free(null);
    return 0;
}