/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
string neighbors(string pattern,int d)
{    
    string chars = "ACGT";
    if(d <= pattern.length())

    {
        if (d == 0)
            return pattern;
        
        string r2 = neighbors(pattern.substr (1,pattern.length()-1), d-1);
        // r = [c + r3 for r3 in r2 for c in chars if c != pattern[0]]
        string r;//lr = [];

            for (int c = 0; c < chars.length(); c++)
            {
                
                for (int r3 = 0; r3 < r2.length(); r3++) 
                {
                    if (c != pattern[0])
                    {
                        r.append(c + r3);
                    }
                }
            }
        

        if (d < pattern.length())
        {
            r2 = neighbors(pattern.substr (1,pattern.length()-1), d);//neighbors(pattern[1:], d);
            r += [pattern[0] + r3 for r3 in r2];
        }
        
        return r;
    }
}
using namespace std;

int main()
{
    cout<<"Hello World";
    string s = neighbors("ACG",1);
    cout<<s;
    return 0;
}
