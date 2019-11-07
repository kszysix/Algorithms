
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

clock_t timex;

//int to_print[10000];
float adj[10000][10000];
float tab[10000][3];
int existing_route[10000];
int new_route[10000];

float route_length(int route[10000],const int memory)
{
    float length = 0;
    int i=0;
    for(i=0;i<memory-1;i++)
    {
        length = length + adj[route[i]][route[i+1]];
    }
    length = length + adj[route[i]][0];

    return length;
}

void first_route(const int memory)
{
    int i;
    for(i=0;i<memory;i++)
    {
        //to_print[i]=i;
        existing_route[i]=i;
    }
    //to_print[i+1]=0;
    existing_route[i+1]=0;
}

void signal_end(const int memory)
{
    int out;
    for (int i=0; i<memory; i++)
    {
        out = static_cast<int>(tab[existing_route[i]][0]);
        printf("%d\n",out);
    }
    exit(0);
}

float distance(float x1,float y1,float x2,float y2)
{
    float z;
    z=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    return z;
}


void to_swap(int route[10000], const int memory, int i, int k)
{
    //cout<<endl<<"int i = "<<i<<"   int k = "<<k;
    //cout<<endl<<"route: ";
    for (int j = 0; j <= i-1; ++j)
    {
        new_route[j]=route[j];
        //cout<<new_route[j]<<" ";
    }
    int n=0;
    for (int m = i; m <= k; ++m)
    {
        new_route[m]=route[k-n];
        //cout<<new_route[m]<<" ";
        n++;
    }
    for (int p = k+1; p < memory; ++p)
    {
        new_route[p] = route[p];
        //cout<<new_route[p]<<" ";
    }
    new_route[memory]=new_route[0];
    //cout<<new_route[memory]<<endl;
}


void tsp_ls(const int memory)
{
    bool improvement = true;
    float shortest_length;
    float new_length=0;
    while (improvement)
    {
        again:
        improvement = false;
        shortest_length = route_length(existing_route,memory);
        //cout<<endl<<"shortest = "<<shortest_length;

        for (int i = 1; i < memory-1; ++i)
        {
            for (int j = i+1; j < memory; ++j)
            {

                if (((clock() - timex) / (double) CLOCKS_PER_SEC) > 58)
                {
                    signal_end(memory);
                    exit(0);
                }

                //cout<<endl<<"old route = ";
                for (int k = 0; k < memory; ++k)
                {
                    //cout<<existing_route[k]<<" ";
                }
                //cout<<endl<<"old length = "<<shortest_length<<endl;

                to_swap(existing_route,memory,i,j);

                new_length = route_length(new_route,memory);

                //cout<<endl<<"new route = ";
                for (int k = 0; k <= memory; ++k)
                {
                    //cout<<new_route[k]<<" ";
                }
                //cout<<endl<<"new length = "<<new_length<<endl;
                if (new_length < shortest_length)
                {
                    shortest_length = new_length;
                    for (int k = 0; k < memory; ++k)
                    {
                        existing_route[k] = new_route[k];
                        //to_print[k] = existing_route[k];
                    }
                    existing_route[memory] = new_route[0];
                    //to_print[memory] = existing_route[0];
                    //cout<<endl<<"best route = ";
                    for (int k = 0; k < memory; ++k)
                    {
                        //cout<<existing_route[k]<<" ";
                    }
                    //cout<<endl<<"best length = "<<new_length<<endl;
                    improvement = true;
                    goto again;
                }
            }
        }
    }
}



int main(){
    timex = clock();

    int memory;

    float file;
    float filex;
    float filey;
    memory = 0;
    while(scanf("%f",&file)==1)
    {
        tab[memory][0]=file;

        scanf("%f",&filex);

        tab[memory][1]=filex;

        scanf("%f",&filey);

        tab[memory][2]=filey;

        memory=memory+1;
    }

    float dist;

    for(int i=0;i<memory;i++)
    {
        for(int j=0;j<memory;j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
                //cout<<"0 ";
                continue;
            }
            dist = distance(tab[i][1],tab[i][2],tab[j][1],tab[j][2]);
            adj[i][j]=dist;
            //cout<<dist<<" ";
        }
        //cout<<endl;
    }

    first_route(memory);

    //float temp = route_length(existing_route,memory);
    //printf("%f",temp);
    //----------------------
    tsp_ls(memory); // START
    //----------------------
    //cout<<endl;

    //to_print[memory] = existing_route[0];
    //cout<<endl;
    //cout<<"last length = "<<route_length(existing_route,memory);
    //cout<<endl;
    int out;
    //cout<<"memory = "<<memory<<endl;
    for (int i=0; i<memory; i++) {
        //cout<<tab[to_print[i]][0]<<endl;
        out = static_cast<int>(tab[existing_route[i]][0]);
        printf("%d\n",out);
    }

    return 0;
}
