/*
 * C++ Program to Implement Adjacency Matrix Graph
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
/*
 * Adjacency Matrix Class
 */
class AdjacencyMatrix
{
    private:
        int n;
        bool adj[MAX][MAX];
    public:
        AdjacencyMatrix(int k)
        {
            n = k;
            for (int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
        /*
         * Adding Edge to Graph
         */ 
        void add_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {   
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }
        /*
         * Print the graph
         */ 
        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};
/*
 * Main
 */ 
int main()
{
    int nodes, max_edges, origin, destin;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.add_edge(origin, destin);
    }
    am.display();
    return 0;
}
/*
$ g++ adjacency_matrix.cpp
$ a.out
 
Enter number of nodes: 5
Enter edge (-1 -1 to exit): 1 2
Enter edge (-1 -1 to exit): 1 4
Enter edge (-1 -1 to exit): 1 5
Enter edge (-1 -1 to exit): 2 3
Enter edge (-1 -1 to exit): 2 5
Enter edge (-1 -1 to exit): 3 1
Enter edge (-1 -1 to exit): 5 2
Enter edge (-1 -1 to exit): 4 3
Enter edge (-1 -1 to exit): -1 -1
0  1  0  1  1
0  0  1  0  1
1  0  0  0  0
0  0  1  0  0
0  1  0  0  0
*/
