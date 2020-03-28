#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include <exception>

using namespace std;

struct NodeNotFound : public exception {
   const char * what () const throw () {
      return "Not a Valid Node";
   }
};

static int PI = 3.14;
class Graph{
private:
    int e;
    int v;
    int **adj;
public:

    Graph(){
        this->e = 0;
        this->v = 0;
        this->adj = NULL;
    }

    Graph(int edges, int vertices)
    {
        this->e = edges;
        this->v = vertices;

        this->adj = new int*[this->e]; // Pointer of Pointers, Array of rows

         for(int row=0; row < this->v; row++)
        {
            this->adj[row]=new int[this->v];
        }

        for(int u=0; u < this->v; u++)
        {
            for(int v=0; v < this->v; v++)
            {
                this->adj[u][v]=0;
            }
        }

        this->display_graph();

        for(int i=0; i < this->e; i++)
        {
            try{
                int start,node_end;
                cout<<"Enter the "<<(i+1)<<" Edge : \n";
                cout<<"Start At : ";
                cin>>start;
                cout<<"End At : ";
                cin>>node_end;
                if(((start < 0) || (start >= this->v)) || ((node_end < 0) || (node_end >= this->v)))
                    throw NodeNotFound();

                this->adj[start][node_end]=1;
                this->adj[node_end][start]=1;
            }
            catch(NodeNotFound& e)
            {
                cout<<"Error : Enter valid nodes between 0 to (number of vertices - 1)\n";
            }
        }
    }

    void display_graph(){
        cout<<"Adjacency Matrix\n";
        for(int i = 0 ; i < this->v; i++)
        {
            for(int j = 0 ; j < this->v; j++)
                cout<<this->adj[i][j]<<"\t";
            cout<<endl;
        }
    }

    void save_in_file(char *filename){
    }

    void create_from_file(char *filename)
    {
    }
};

int main()
{
    int e,v;
    cout<<"Enter number of Vertices : ";
    cin>>v;
    cout<<"Enter number of Edges : ";
    cin>>e;
    graph g;
    g.v=9;
    Graph g(e,v);

    g.display_graph();


    return 0;
}
