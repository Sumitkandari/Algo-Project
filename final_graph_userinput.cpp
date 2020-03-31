
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
struct Graph
{
    int V,E,**adj;
};

int u,v,i;
Graph *adjmatrixgraph()
{
    int k;
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    cout<<"enter nodes and edges";

    cin>>k;
    cin>>g->E;
    g->V = k;
    cout<<endl<<"k = "<<k<<endl;
    cout<<endl<<"g-V = "<<g->V<<endl;



    g->adj=new int*[g->V];
    cout<<endl<<"hhh";
     for(k=0;k<g->V;k++)
    {
        g->adj[k]=new int[g->V];
    }
    cout<<endl<<"hhh";


    cout<<"size of = "<<g->V<<endl;

    for(u=0;u < (g->V);u++)
    {
        cout<<" => u = "<<u<<endl;
        for(v=0; v < (g->V); v++)
        {
            g->adj[u][v]=0;
            cout<<"=> u = "<<u<<" v = "<<v<<" adj = "<<g->adj[u][v]<<endl;
        }
    }
    cout<<"enter node no in pair that connected an edge ";
    for(i=0;i<g->E;i++){
        cin>>u>>v;
    g->adj[u][v]=1;
    g->adj[v][u]=1;
    }

    return g;
}

int main()
{
    struct Graph *g = adjmatrixgraph();
    int x,y;
    for(x=0;x<g->V;x++)
        cout<<x<<" ";
    cout<<"/n";
    for(x=0;x<g->V;x++)
    {

        for(y=0;y<g->V;y++)
        {
            cout<<x <<g->adj[x][y];

        }
        cout<<"/n";
    }
    return 0;
}




