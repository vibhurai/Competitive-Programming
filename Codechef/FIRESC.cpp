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

    long long q_max = 1; // store the maximum size of the queue thus the number of employees using this exit
    queue<long long> que;
    que.push(i);
    visited[i - 1] = true;

    // BFS
    while (!que.empty())
    {
        for (auto x = graph[que.front()].begin(); x != graph[que.front()].end(); x++)
            if (!visited[(*x) - 1])
            {
                que.push(*x);
                visited[(*x) - 1] = true;
            }

        // cout << "qs = " << que.size();

        if (que.size() > q_max)
            q_max = que.size();

        cout << "q_max = " << q_max;
        que.pop();
    }

    return q_max;
}

void find_sol(long long N, unordered_map<long long, vector<long long>> graph)
{
    bool visited[N];
    vector<long long> set_size; // vector to store number of employees using one exit

    bool *begin = visited;
    bool *end = begin + N;

    set_size.clear();

    for (auto i = 0; i < N; i++)
        visited[i] = 0;

    // till the time you can find an unvisited node in the visited array, continue traversing diff graphs
    while (std::find(begin, end, false) != end)
    {
        auto x = find(begin, end, false);
        auto i = x - begin + 1;

        // get number of employees using the current gate
        auto flg = BFS(visited, i, graph);
        cout << "max = " << flg << endl;
        set_size.push_back(flg);
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
        }

        find_sol(N, graph);
    }
}