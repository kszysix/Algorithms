#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

float distance(float x1,float y1,float x2,float y2)
{
  float z;
  z=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
  return z; //distance between (x1,y1) and (x2,y2)
}

void showArray(vector<vector<float>> array)
{
  for(int i=0;i<array.size();i++) //show adjencacy array
  {
    for(int j=0;j<array.size();j++)
    {
      cout<<array[i][j]<<" ";
    }
    cout<<endl;
  }
}

int ary[10][10],completed[10],n,cost=0;

/*void takeInput()
{
    int i,j;

    cout<<"Enter the number of villages: ";
    cin>>n;

    cout<<"\nEnter the Cost Matrix\n";

    for(i=0;i < n;i++)
    {
        cout<<"\nEnter Elements of Row: "<<i+1<<"\n";

        for( j=0;j < n;j++)
            cin>>ary[i][j];

        completed[i]=0;
    }

    cout<<"\n\nThe cost list is:";

    for( i=0;i < n;i++)
    {
        cout<<"\n";

        for(j=0;j < n;j++)
            cout<<"\t"<<ary[i][j];
    }
}*/

int least(int c)
{
    int i,nc=999;
    int min=999,kmin;

    for(i=0;i < n;i++)
    {
        if((ary[c][i]!=0)&&(completed[i]==0))
            if(ary[c][i]+ary[i][c] < min)
            {
                min=ary[i][0]+ary[c][i];
                kmin=ary[c][i];
                nc=i;
            }
    }

    if(min!=999)
        cost+=kmin;

    return nc;
}

void mincost(int city)
{
    int i,ncity;

    completed[city]=1;

    cout<<city+1<<"--->";
    ncity=least(city);

    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];

        return;
    }

    mincost(ncity);
}

int main()
{

// MAIN START
int main() {

    vector<vector<float>> tab;
    vector<float> point;

    cout << "Hello world" << endl;

    float file;  //number of point
    float filex; //coordinate X
    float filey; //coordinate Y
    while (scanf("%f", &file) == 1) {
        point.push_back(file);

        scanf("%f", &filex);
        point.push_back(filex);

        scanf("%f", &filey);
        point.push_back(filey);

        tab.push_back(point);
        point.clear();
    }

    vector<vector<float>> adjcol; //table column
    vector<float> adjrow; //table row
    float dist;

    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab.size(); j++) {
            if (i == j) {
                adjrow.push_back(0);
                continue;
            }
            dist = distance(tab[i][1], tab[i][2], tab[j][1], tab[j][2]);
            adjrow.push_back(dist);
        }
        adjcol.push_back(adjrow);
        adjrow.clear();
    }

    showArray(adjcol);
//-------------------
    takeInput();

    cout<<"\n\nThe Path is:\n";
    mincost(0); //passing 0 because starting vertex

    cout<<"\n\nMinimum cost is "<<cost;

    return 0;
}
