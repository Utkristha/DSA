#include <iostream>
#include <string>
using namespace std;

struct node
{
    string cha;
    node *next;
};

int hash_func(const string temp)
{
    return tolower(temp[0]) - 'a';
}

int main()
{
    int hash_value;
    node *table[26] = {nullptr};
    
    while(true)
    {
        node *new_data = new node;
        cin>>new_data->cha;

        if(new_data->cha == ";")
        {
            break;
        }

        hash_value = hash_func(new_data->cha);
        new_data->next = table[hash_value];
        table[hash_value] = new_data;
    }

    for(int j=0;j<26;j++)
    {
        node *current  = table[j];
        if(table[j] != nullptr)
        {
            while(current != nullptr)
            {
                cout<<current->cha <<"->";
                current = current->next;
            }
            cout<<"nullptr"<<endl;

        }

    }   

}