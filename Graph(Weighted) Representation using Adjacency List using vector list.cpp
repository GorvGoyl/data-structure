// Weighted Graph(undirected/directed) Representation using Adjacency List USING VECTOR STL of LIST STL
#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
WEIGHTED UNDIRECTED GRAPH (code will be same for DIRECTED WEIGHTED GRAPH, just use LIST of type 'class' to store vertex no. and wt.)
			   (4)
			0-------1
			  \     -
			   \    -
			    \   -
			 (2) \  -(5)
				  \ -
				   \-
			3-------2
			  (1)
*/

class edge{   //class for storing vertex number and its weight
	double wt;
	int vertex_id;
	public:
		edge(double w, int id){
			wt=w;
			vertex_id=id;
		}
	double getweight() const{
	return wt;
	}
	int getvertex_id() const{
	return vertex_id;
	}
	
};



int main()
{
vector <list <edge> > a(4);	//LIST is of type 'class'
									
a[0].push_back(edge(4,1));			//a[0] --(4)-->1
a[0].push_back(edge(2,2));			//a[0] --(4)-->1 --(2)--->2

a[1].push_back(edge(4,0));			//a[1] --(4)-->0
a[1].push_back(edge(5,2));			//a[1] --(4)-->0 ---(5)-->2

a[2].push_back(edge(2,0));			//a[2] --(2)--->0
a[2].push_back(edge(5,1));			//a[2] --(2)--->0 ---(5)-->1
a[2].push_back(edge(1,3));			//a[2] --(2)--->0 ---(5)-->1 --(1)-->3

a[3].push_back(edge(1,2));			//a[3] --(1)--->2

int c=0;   // for printing 0,1,2,3 of a[0],a[2]....
vector <list<edge> >::iterator i;
for(i=a.begin();i!=a.end();i++){
	cout<<"vertices connected to node "<<c <<" are ";
	
	std::list<edge> tmp;
	 tmp = *i;    //list pointing to a[0]
	list <edge>::iterator itr;
	
	for(itr=tmp.begin();itr!=tmp.end();itr++)
		 cout<<"(Vertex no.= "<<(*itr).getvertex_id()<<" Weight= "<<(*itr).getweight()<<") "; //printing 'vertex' and 'weight' of a[0]--(4)->1
	cout<<"\n";
	c++;
}



}

