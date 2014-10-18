// Graph(unweighted & undirected) Representation using Adjacency List USING VECTOR STL of LIST STL
#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
UNWEIGHTED UNDIRECTED GRAPH
0-----1
 -    -
  -   -
   -  -
    - -
3-----2

*/
int main()
{
vector <list <int> > a(4);		//LIST is of type int

a[0].push_back(1);			//a[0] -->1
a[0].push_back(2);			//a[0] -->1 -->2

a[1].push_back(0);			//a[1] -->0
a[1].push_back(2);			//a[1] -->0 -->2

a[2].push_back(0);			//a[2] -->0
a[2].push_back(1);			//a[2] -->0 -->1
a[2].push_back(3);			//a[2] -->0 -->1 -->3

a[3].push_back(2);			//a[3] -->2

int c=0;   // for printing 0,1,2,3 of a[0],a[2]....
vector <list<int> >::iterator i;
for(i=a.begin();i!=a.end();i++){
	cout<<"vertices connected to node "<<c <<" are ";
	
	list<int> tmp;
	 tmp = *i;    //list pointing to a[0]
	list <int>::iterator itr;
	
	for(itr=tmp.begin();itr!=tmp.end();itr++)
		 cout<<*itr<<" ";  //printing 1 and 2 of a[0]-->1 --->2
	cout<<"\n";
	c++;
}








}

