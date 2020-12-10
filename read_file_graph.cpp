

#include<iostream>
#include<fstream>
#include<string>
#include<exception>

using namespace std;

struct NodeNotFound : public exception {
   const char * what () const throw () {
      return "Not a Valid Node";
   }
};

class Graph
{
public:
    int v,e;
    int **adj;
   void adjmatrix()
     {
        string line;
        ifstream inp("test.txt");
          getline(inp,line);
        this->v = stoi(line);
            adj = new int* [this->v];
        for(int i=0;i<this->v;i++)
            {
                adj[i] = new int[this->v];
                for(int j=0;j<this->v;j++)
                       adj[i][j] = 0;
            }

        while(!inp.eof()){
            getline(inp,line);
            string a[2] = {"",""};
            int k=0;
            for(int i=0;i<line.length();i++)
            {
                if(i==0 && (line[i]==' ')){
                    int j=0;
                    while(line[j] == ' '){
                        j++;
                        i++;
                    }
                    i--;
                }else{
                    if(line[i] != ' '){
                        a[k]+=line[i];
                    }else
                    {
                        k++;
                        if(k>1)
                            k--;
                    }
                }

            }
     try{
          int stnode = stoi(a[0]);
          int ennode = stoi(a[1]);
         if(((stnode < 0) || (ennode >= this->v)) || ((ennode < 0) || (stnode >= this->v)))
            throw NodeNotFound();

        adj[stnode][ennode] = 1;
        adj[ennode][stnode] = 1;

        }
        catch(NodeNotFound& e)
            {
                cout<<"Error : Enter valid nodes between 0 to (number of vertices - 1)\n";
            }
    }

     }
    void display()
    {
        cout<<"Number of vertices is : "<<this->v<<endl;
        cout << "\t";

        for(int i=0;i<this->v;i++)
            cout << i << "\t";
             cout <<endl;
        for(int i=0;i<this->v;i++)
            {
                 cout << i << "\t";
             for(int j=0;j<this->v;j++)
                cout << adj[i][j] << "\t";
               cout << endl;
             }
    }

};

int main()
{
    Graph g;
    g.adjmatrix();
    g.display();

    return 0;
}

