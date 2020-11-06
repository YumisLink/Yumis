#include<cstdio>
#include<cstdlib>
struct node
{
    int num;
    node* node;
};

class stack
{
private:
    node* top = NULL;
    int size = 0;
public:
    void push(int i)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->num = i;
        newnode->node = top;
        top = newnode;
        size ++;
    }
    int pop()
    {
        int k = top->num;
        node* del = top;
        top = top->node;
        free(del);
        size --;
        return k;
    }
    int size()
    {
        return size;
    }
    int top()
    {
        return top->num;
    }
    bool empty()
    {
        if (top == NULL)
            return 1;
        else 
            return 0
    }
};

int main ()
{

}