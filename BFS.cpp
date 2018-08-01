/****bfs**/
#include <bits/stdc++.h>
using namespace std;
#define  unvisited -1
#define  visited 1
vector <int> node[1005];
int dis[1005];
void bfs (int src)
{
    queue <int> q;
    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i];
            if(dis[v] == unvisited)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int tes;
    cin >> tes;
    while(tes--)
    {
        memset(dis, unvisited , sizeof dis);
        int n, e;
        cout<<"Node and edge" << endl;
        cin >> n >> e;
        for(int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
            node[v].push_back(u);
        }
        int src;
        cin >> src;
        bfs(src);
        for(int i = 1; i <= n; i++)
        {
            cout<< dis[i] << " ";
        }
        for(int i = 0; i <= n; i++)
            node[i].clear();
    }
}
