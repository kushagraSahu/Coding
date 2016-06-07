//Undirected,Unweighted Graph
#ifndef Graph_h
#define Graph_h
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    vector<list<int>> adjlist;
    public:
    Graph(int v){
        adjlist.resize(v);
    }
    bool AddEdgeinGraph(int source,int destination){
        int max=source>destination ? source : destination;
        if(max>adjlist.size()){
            adjlist.resize(max+1);
        }
        if(find(adjlist[source].begin()),adjlist[source].end(),destination)!=adjlist[source].end()){
            return false;
        }
        adjlist[src].push_back(destination);
        adjlist[destination].push_back(source);
        return true;
    }
};
#endif // Graph_h
