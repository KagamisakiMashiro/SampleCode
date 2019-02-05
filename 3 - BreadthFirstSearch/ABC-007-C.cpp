#include <utility>
#include <queue>
#include <cstdio>
using namespace std;

bool maze[50][50];
bool visited[50][50];
int pathLength[50][50];

int bfs(pair<int, int> startPos, pair<int, int> endPos, int R, int C)
{
    queue<pair<int, int>> visitNodes;
    visited[startPos.first][startPos.second] = true;
    pathLength[startPos.first][startPos.second] = 0;
    visitNodes.push(startPos);
    while (!visitNodes.empty())
    {
        pair<int, int> current = visitNodes.front();
        visitNodes.pop();
        int currentLength = pathLength[current.first][current.second] + 1;
        pair<int, int> nearbyNodes[4];
        nearbyNodes[0] = pair<int, int>(current.first - 1, current.second);
        nearbyNodes[1] = pair<int, int>(current.first + 1, current.second);
        nearbyNodes[2] = pair<int, int>(current.first, current.second - 1);
        nearbyNodes[3] = pair<int, int>(current.first, current.second + 1);
        for (int i = 0; i < 4; ++i)
        {
            if (nearbyNodes[i].first >= 0 && nearbyNodes[i].first < R
                    && nearbyNodes[i].second >= 0 && nearbyNodes[i].second < C
                    && maze[nearbyNodes[i].first][nearbyNodes[i].second]
                    && !visited[nearbyNodes[i].first][nearbyNodes[i].second])
            {
                visited[nearbyNodes[i].first][nearbyNodes[i].second] = true;
                pathLength[nearbyNodes[i].first][nearbyNodes[i].second] = currentLength;
                visitNodes.push(nearbyNodes[i]);
            }
            if (nearbyNodes[i] == endPos)
            {
                return currentLength;
            }
        }
    }
    return pathLength[endPos.first][endPos.second];
}

int main()
{
    int R, C;
    pair<int, int> startPos;
    pair<int, int> endPos;
    scanf("%d %d\n", &R, &C);
    scanf("%d %d\n", &startPos.first, &startPos.second);
    scanf("%d %d\n", &endPos.first, &endPos.second);
    --startPos.first;
    --startPos.second;
    --endPos.first;
    --endPos.second;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            char temp;
            scanf("%c", &temp);
            if (temp == '.')
            {
                maze[i][j] = true;
            }
            else
            {
                maze[i][j] = false;
            }
            visited[i][j] = false;
        }
        scanf("\n");
    }
    printf("%d\n", bfs(startPos, endPos, R, C));
    return 0;
}
