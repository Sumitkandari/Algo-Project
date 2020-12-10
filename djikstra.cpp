#include<cstdlib>
#include<iostream>
#include<vector>
#include<dos.h>
#include<windows.h>
#include<bits/stdc++.h>
#define INFINITY 99;
using namespace std;
class graph
{
    public:
         static int v;
        int x,y;
    static int **adj;
    static void adjm(int ver)
    {
        v=ver;
        adj=new int*[ver];
        for(int i=0;i<ver;i++)
        {
            adj[i]=new int[ver];
            for(int j=0;j<ver;j++)
                adj[i][j]=0;

        }
    }
    void init(int st,int ed,graph g[])
    {
        int weit;
        weit=abs(((g[ed].x-g[st].x)+(g[ed].y-g[st].y)));

                adj[st][ed]=weit;
                adj[ed][st]=weit;
    }

};
int **graph::adj;
int graph::v;
 void djk(int stnode,int enode)
    {
        vector<int> dit;
        int cost[graph::v][graph::v],path[graph::v],visited[graph::v],coun=1,nxtnode,j,minel;
        for(int i=0;i<graph::v;i++)
        {
            for(int j=0;j<graph::v;j++)
            {
                if(graph::adj[i][j]==0)
                {
                    cost[i][j]=INFINITY;
                }
                else{
                    cost[i][j]=graph::adj[i][j];
                }
            }
        }
        for(int i=0;i<graph::v;i++)
        {
            dit.push_back(cost[stnode][i]);
            path[i]=stnode;
            visited[i]=0;

        }
        vector<int> di=dit;
        dit[stnode]=INFINITY;
        visited[stnode]=1;
        di[stnode]=INFINITY;

        while(coun<graph::v-1)
        {

            minel=*min_element(di.begin(),di.end());

            vector<int>::iterator it=find(di.begin(),di.end(),minel);
            nxtnode=distance(di.begin(),it);

            visited[nxtnode]=1;
            di[nxtnode]=INFINITY;
            for(int i=0;i<graph::v;i++)

                if(minel+cost[nxtnode][i]<di[i]&&!visited[i])
                {
                     path[i]=nxtnode;
                    dit[i]=minel+cost[nxtnode][i];
                    di[i]=minel+cost[nxtnode][i];



                }
                coun++;

            }

             cout<<endl<<"distance from starting node is "<<dit[enode];
             j=enode;
             cout<<endl<<"->"<<j;
             while(j!=stnode)
             {
                 j=path[j];
                 Sleep(2000);
                 cout<<"->"<<j;
             }
                return;


    }

int main()
{
    int ver,enod,snod,edge,st,en;

    cout<<"enter no of vertices";
    cin>>ver;
    graph::adjm(ver);
    graph g[ver];

   for(int i=0;i<ver;i++)
    {
        cout<<"enter coordinate of->"<< i;
        cin>>g[i].x>>g[i].y;
    }
    cout<<"enter no of edges";
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        cout<<"enter edges connected";
        cin>>st>>en;
        g[i].init(st,en,g);
    }
    cout<<"enter starting node and ending node";
    cin>>snod>>enod;
    djk(snod,enod);
    return 0;
}

