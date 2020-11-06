#include<cstdio>
#include<cstdlib>
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

    void push_front(int k)
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
            node* n = start->node;
            start->node = (node*)malloc(sizeof(node));
            Long ++;
            start->node->num = k;
            start->node->node = n;
        }
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
        start = null;
    }
    void printelem()
    {
        for (node* i = start; i != null; i = i->node)
        {
            if (i != start)
                printf("%d ",i->num);
        }
        puts("");
    }
};

int main()
{
    node* null = (node*)malloc(sizeof(node));
    null->node = null;
    LA k;
    k.push_front(20);
    k.push_front(15);
    k.push_front(11);
    k.push_front(9);
    k.push_front(8);
    k.push_front(6);
    k.push_front(2);
    k.push_back(2);
    printf("%d\n",k.length());
    printf("%d\n",k.empty());
    k.printelem();
    k.clear();
    k.printelem();
    printf("%d", k.empty());

    free(null);
    return 0;
}