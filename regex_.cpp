#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string str;
    
    while(true)
    {
        cout<<"Enter a string:";
        cin>>str;

        regex e("ab\\[[^\\]]*\\]");
        
        bool match = regex_match(str,e);

        cout<<(match ? "Matched":"Not matched")<<endl;
    }

    return 0;

}