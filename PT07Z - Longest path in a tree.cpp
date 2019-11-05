#include <iostream>
#include <vector>
#include <queue>

#define MAXN 10001

using namespace std;

pair<int,int> bfs(vector<int> adjlist[MAXN], int x, int v)
{
    queue<int> bfsq;
    int visit[MAXN];
    int dist[MAXN];
    for(int j=0;j<=v;j++)
    {
        visit[j]=0;
        dist[j]=-1;
    }

    int score1=0;//
    int score2=0;//

    bfsq.push(x);
    dist[x]=0;
    visit[x]=1;//!!!

    while(!bfsq.empty())
    {
        int k=bfsq.front();
        bfsq.pop();

        for(int i : adjlist[k])
        {
            if(visit[i]!=1)
            {
                visit[i]=1;
                dist[i]=dist[k]+1;
                bfsq.push(i);
            }
        }
    }

    for(int i=0;i<=v;i++)
    {
        if(score2<dist[i])
        {
            score1=i;
            score2=dist[i];
        }
    }

    return make_pair(score1,score2);//score1 = number of node, score2 = length of road to the node
}

int main()
{
    int x=1;//vertex where BFS starts
    int v;//number of vertices
    int score3=0;
    cin>>v;

    vector<int> adjlist[MAXN];//adjacency list to describe the graph

    int a,b;
    cin>>a>>b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
    x=a;
    for(int i=0;i<v-2;i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    pair<int,int> p1 = bfs(adjlist,x,v);
    pair<int,int> p2 = bfs(adjlist,p1.first,v);
    score3=p2.second;

    cout<<score3;

    return 0;
}
