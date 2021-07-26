#include <bits/stdc++.h>
using namespace std;

long long BFS(bool visited[], long long i, unordered_map<long long, vector<long long>> graph)
{

    // if noone is friend of the employee
    if (graph[i].size() == 0)
    {
        visited[i - 1] = true;
        return 1;
    }

    queue<long long> que;
    unordered_set<long long> s1;
    s1.clear();

    while (!que.empty())
        que.pop();

    que.push(i);
    visited[i - 1] = true;
    s1.insert(i);

    // BFS
    while (!que.empty())
    {
        for (auto x = graph[que.front()].begin(); x != graph[que.front()].end(); x++)
            if (!visited[(*x) - 1])
            {
                s1.insert((*x));
                que.push(*x);
                visited[(*x) - 1] = true;
            }

        que.pop();
    }

    return s1.size();
}

void find_sol(long long N, unordered_map<long long, vector<long long>> graph)
{
    bool visited[N];
    vector<long long> set_size; // vector to store number of employees using one exit

    bool *begin = visited;
    bool *end = begin + N;

    set_size.clear();

    for (auto i = 0; i < N; i++)
        visited[i] = false;

    // till the time you can find an unvisited node in the visited array, continue traversing diff graphs
    auto x = std::find(begin, end, false);
    while (x != end)
    {
        auto i = x - begin + 1;

        // get number of employees using the current gate
        auto flg = BFS(visited, i, graph);
        // cout << "max = " << flg << endl;
        set_size.push_back(flg);

        x = find(x + 1, end, false);
    }

    // print the answer
    cout << set_size.size() << " " << std::accumulate(std::begin(set_size), std::end(set_size), 1, std::multiplies<>()) % 1000000007 << endl;

    return;
}

int main()
{
    long long test, N, M, a, b;
    cin >> test;

    // storing a graph
    unordered_map<long long, vector<long long>> graph;

    while (test--)
    {
        cin >> N >> M;
        graph.clear();

        while (M--)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        find_sol(N, graph);
    }
}