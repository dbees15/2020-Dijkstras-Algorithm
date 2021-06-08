#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#define INFINITY 214748364
struct Vertex
{
    Vertex()
    :m_number(0),m_distance(0),m_prev(-1)
    {}
    Vertex(int num,int distance=INFINITY,int prev = -1)
    :m_number(num),m_distance(distance),m_prev(prev)
    {}

    int operator>(const Vertex &other) const
    {
        return m_number< other.m_distance;
    }
    int operator<(const Vertex &other) const
    {
        return m_number> other.m_distance;
    }
    int operator==(const Vertex &other) const
    {
        return m_number== other.m_distance;
    }
    void operator=(const Vertex &other)
    {
        m_number = other.m_number;
        m_distance = other.m_distance;
        m_prev = other.m_prev;
    }

    int m_number;
    int m_distance;
    int m_prev;
};

class Graph
{
public:
    Graph();
    Graph(int vertexnum,std::vector<Vertex> vertices,int** adjmatrix);
    Graph(const Graph& other);
    ~Graph();
    int getEdgeCost(int v1, int v2);    //adjacent edges as parameter

    Vertex getVertex(int index);   //
    int getIndex(int s);    //-1 for not found

    void displayMatrix();   //debug display

    void Dijkstra(int source,int destination);  //shortest path from source to destination

private:
    // Helper Methods

    int getLeast(std::vector<Vertex> v)
    {
        int total = v.size();
        int least = 0;
        for(int i=0;i<total;i++)
        {
            if(v[i].m_distance<v[least].m_distance)
            {
                least = i;
            }
        }
        return least;
    }
    int getFromNumber(std::vector<Vertex> v,int n)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].m_number==n)
            {
                return i;
            }
        }
    }

    void eraseNumber(std::vector<Vertex> &v,int num)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].m_number==num)
            {
                v.erase(v.begin()+i);
                break;
            }
        }
    }


    // Members
    std::vector<Vertex> m_vertices;
    int **m_adjacencymatrix;
    int m_vertexcount;

};

#endif // GRAPH_H
