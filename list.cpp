#include <iostream>
using namespace std;

typedef struct node
{
    int number;
    struct node *next;

}node;

int main(int argc,char *argv[])
{

    node *list = NULL;

    for(int i=1;i<argc;i++)
    {
        int number = atoi(argv[i]);
        
        node *n = new node;

        if(n == NULL)
        {
            delete n;
            return 1;
        }

        n->number = number;
        n->next = list;
        list = n;
    }

    node *ptr = list;

    while (ptr != NULL)
    {
        cout<<ptr->number<<endl;
        ptr = ptr->next;
    }    

    return 0;
}