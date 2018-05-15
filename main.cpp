#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100

using namespace std;

int main()
{
    vector <int> adjlist[MAXN];//adjacency list of graph
    char visit[MAXN];//array of visited or unvisited vertices
    int dist[MAXN];//array of distance from vertex '0' to others
    int v,e;//number of vertices and edges
    cout<<"Number of vertices: ";
    cin>>v;
    cout<<"Number of edges: ";
    cin>>e;

    cout<<"Give me the Graph! : ";
    for(int i=0; i<e;i++)//loop to create adjacency list
    {
        int a,b;//a=start of e, b=end of e
        cin>>a;
        cin>>b;
        adjlist[a].push_back(b);//a->b and b->a, because there is
        adjlist[b].push_back(a);//undirected graph
    }

    for(int i=0;i<MAXN;i++)
    {
        visit[i]=0;//cause we didn't visit any vertices yet
        dist[i]=-1;//-1 to show that we don't have distance to 'i' yet
    }

    dist[0]=0;//distance from vertex 'a' to vertex 'a' is 0
    visit[0]=1;//we want to start at vertex number '0' so '0' has been visited

    queue<int> bfsq;//create queue FIFO
    bfsq.push(0);//push first vertex to queue

    while(!bfsq.empty())//as long as queue isn't empty, we haven't visited every vertex yet
    {
        int u = bfsq.front();//take the first (oldest) element from queue
        bfsq.pop();//remove the first (oldest) element from queue

        for(int j : adjlist[u])//loop to find neighboring vertices
        {
            if(!visit[j])//if vertex 'j' isn't visited yet
            {
                visit[j]=1;//now 'j' have been visited
                dist[j]=dist[u]+1;  //distance from vertex '0' to 'j' is
                                    //distance from j's parent('u') to '0' + 1 (from 'u' tp 'j')
                bfsq.push(j);//add 'j' to queue to find his neighboring vertices

            }
        }
    }
    int x;
    cout<<endl<<"Distance from '0' to ..."<<endl;
    cin>>x;
    cout<<"Distance from '0' to '"<<x<<"' is "<<dist[x]<<"."<<endl;
    return 0;
}

