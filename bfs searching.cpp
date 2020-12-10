#include<iostream>
#include<vector>
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
                adj[i][j]=-1;

        }
    }
    void init(int st,int ed,graph g[])
    {
        int weit;


        weit=((g[ed].x-g[st].x)+(g[ed].y-g[st].y));

                adj[st][ed]=weit;
                adj[ed][st]=weit;
    }
    void bfs(int node,int ednod)
    {
        int vis;
        int dit=0;
        vector <bool> visited(this->v,false);
        vector <int> q;
        visited[node]=true;
        q.push_back(node);
        while(q.size())
        {
            vis=q.front();
            cout<<" "<<vis<<" ";
           // q.pop_back();
           q.erase(q.begin());
            for(int i=0;i<v;i++)
            {
                if(adj[vis][i]!=-1&&(!visited[i]))
                {

                    dit+=adj[vis][i];

                    q.push_back(i);
                    visited[i]=true;
                    if(visited[ednod]==true)
                    {
                    cout<<ednod<<endl;
                    cout<<"weight is"<<dit;
                        exit(0);
                    }
                }

             }

         }
    }

};
int **graph::adj;
int graph::v;

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
    cout<<"enter staring and ending node";
    cin>>snod>>enod;

    g[0].bfs(snod,enod);
    return 0;
}
