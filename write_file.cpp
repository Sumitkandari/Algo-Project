#include<iostream>
#include<string>
#include<fstream>
#include<exception>
using namespace std;
 struct NodeNotFound : public exception {
   const char * what () const throw () {
      return "Not a Valid Node";
   }
};

class graph
{
  public:
      int v,e,stn,enn,**adj;
      void inputs()
      {
          cout<<"enter number of vertics";
          cin>>this->v;
          adj=new int*[this->v];
          for(int i=0;i<this->v;i++)
          {
              adj[i]=new int[this->v];
          }
          for(int i=0;i<this->v;i++)
          {
              for(int j=0;j<this->v;j++)
              {
                  adj[i][j]=NULL;
              }
          }
          cout<<"enter number of edges";
          cin>>this->e;
          cout<<"enter nodes you want to connect";
          for(int i=0;i<this->e;i++)
          {
              cin>>this->stn>>this->enn;
              try
              {
                  if(this->stn<0||this->stn>v||this->enn<0||this->enn>v)
                     throw NodeNotFound();
                     adj[stn][enn]=1;
                     adj[enn][stn]=1;
              }
              catch(NodeNotFound& e)
              {
                  cout<<"Error : Enter valid nodes between 0 to (number of vertices - 1)\n";
                    i--;
              }
        }

      }
      void writefile()
    {

        ofstream fout;
        fout.open("test.txt");
        for(int i=0;i<this->v;i++)
        {
            fout<<"\t";
            fout<<i;
        }
        fout<<endl;
        for(int i=0;i<this->v;i++)
        {
            fout<<i;
          for(int j=0;j<this->v;j++)
          {
              fout<<"\t";
            fout<< adj[i][j];
          }
          fout<<endl;
        }
        fout.close();
    }
};
int main()
{

    graph g;
    g.inputs();
  g.writefile();

    return 0;

}
