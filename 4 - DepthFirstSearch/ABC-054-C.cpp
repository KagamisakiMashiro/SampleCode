#include <cstdio>
#include <array>
using namespace std;

bool graph[8][8];

void dfs(int n, int &result, int root, array<bool, 8> visited)
{
    visited[root] = true;
    bool allVisited = true;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            allVisited = false;
            break;
        }
    }
    if (allVisited)
    {
        ++result;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && graph[root][i])
        {
            dfs(n, result, i, visited);
        }
    }
}

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            graph[i][j] = false;
        }
    }
    int n, m;
    scanf("%d %d", &n, &m);
    array<bool, 8> visited;
    visited.fill(false);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }
    int result = 0;
    dfs(n, result, 0, visited);
    printf("%d", result);
    return 0;
}
