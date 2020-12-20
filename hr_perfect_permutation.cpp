#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the absolutePermutation function below.
vector<int> absolutePermutation(int n, int k) {
    vector<int> nos;
    int fl;
    nos.clear();
    for(int i=0;i<n;i++)
    {    
        nos.push_back(i+1);
        if(nos[i]-1==k)
            fl=i;
    }
    if(k==0)
    {
        std::rotate(nos.begin(), nos.begin()+fl, nos.end());   
        // for(int o=0;o<n;o++)
        //     cout<<nos[o]<<" ";  
        // cout<<endl;    
        for(fl=0;fl<n;fl++)
            if(abs(nos[fl]-(fl+1))!=k)
                break;
        if(fl==(n))
            return nos;
        else
        {
            nos.clear();
            nos.push_back(-1);
            return nos;           
        }
    }
    if(n%k!=0)
    {
        std::rotate(nos.begin(), nos.begin()+fl, nos.end());   
        for(int o=0;o<n;o++)
            cout<<nos[o]<<" ";  
        // cout<<endl;    
        for(fl=0;fl<n;fl++)
            if(abs(nos[fl]-(fl+1))!=k)
                break;
        if(fl==(n))
            return nos;
        else
        {
            nos.clear();
            nos.push_back(-1);
            return nos;           
        }
    }
    else
    {
        unordered_map<int,int> amap;
        amap.clear();
        int i;
        for(i=0;i<n;i++)
        {
            if(amap.find(nos[i])==amap.end())
            {
                
                if(i+1+k<=n)
                {
                    amap[nos[i+k]]=nos[i];
                    continue;
                }
                else 
                    break;
            }
        }
        //  for(auto p =amap.begin();p!=amap.end();p++)
        //     {
        //        cout<<p->first<<"->"<<p->second<<" ";
        //     }
        // // cout<<amap.size();
        if(amap.size()!=n/2)
        {
            nos.clear();
            nos.push_back(-1);
            return nos;
        }          
        else
        {
            for(auto p =amap.begin();p!=amap.end();p++)
            {
                int temp = nos[(p->first)-1];
                nos[(p->first) -1] = nos[(p->second) -1];
                nos[(p->second) -1] = temp;
            }
            return nos;
        }
        
    }    
     

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        vector<int> result = absolutePermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}