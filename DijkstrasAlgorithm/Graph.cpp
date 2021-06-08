#include "Graph.h"

Graph::Graph()
: m_vertexcount(0),m_adjacencymatrix(nullptr)
{
}

Graph::Graph(int vertexnum,std::vector<Vertex> vertices,int** adjmatrix)
: m_vertexcount(vertexnum)
{
    for(int i=0;i<vertexnum;i++)    //Fill name vector
    {
        m_vertices.push_back(vertices[i]);
    }
    m_adjacencymatrix = new int*[vertexnum];
    for(int i=0;i<vertexnum;i++)  //create and fill adj matrix
    {
        m_adjacencymatrix[i] = new int[vertexnum];
        for(int j=0;j<vertexnum;j++)
        {
            m_adjacencymatrix[i][j] = adjmatrix[i][j];
        }
    }
}

Graph::Graph(const Graph& other)
: m_vertexcount(other.m_vertexcount)
{
    m_vertices = other.m_vertices;
    m_adjacencymatrix = new int*[other.m_vertexcount];
    for(int i=0;i<m_vertexcount;i++)  //create and fill adj matrix
    {
        m_adjacencymatrix[i] = new int[m_vertexcount];
        for(int j=0;j<m_vertexcount;j++)
        {
            m_adjacencymatrix[i][j] = other.m_adjacencymatrix[i][j];
        }
    }
}

Graph::~Graph()
{
}


int Graph::getEdgeCost(int v1, int v2)
{
    if(m_adjacencymatrix)
    {
        return m_adjacencymatrix[v1][v2];
    }
}


void Graph::displayMatrix()
{
	for(int i=0; i<m_vertexcount; i++)
	{
		for(int j=0; j<m_vertexcount; j++)
		{
			std::cout<<"["<<i<<"]["<<j<<"]="<<m_adjacencymatrix[i][j]<<" , ";
		}
		std::cout<<std::endl;
	}
}


void Graph::Dijkstra(int source,int destination)
{
    int distance[m_vertexcount];
    for(int i=0;i<m_vertexcount;i++)
    {
        distance[i] = INFINITY;
    }
    distance[source] = 0;
    std::vector<Vertex> vertexq;
    std::vector<Vertex> visited;
    for(int i=0;i<m_vertexcount;i++)
    {
        vertexq.push_back(m_vertices[i]);
    }
    while(!vertexq.empty())
    {
        Vertex lowest= vertexq[0]; //get lowest distance from distance[], the index of that distance is the vertex number
        for(int i = 0;i<vertexq.size();i++)
        {
            if(distance[vertexq[i].m_number]<distance[lowest.m_number])
            {
                lowest = vertexq[i];
            }
        }
        eraseNumber(vertexq,lowest.m_number);
        for(int i=0;i<m_vertexcount;i++)   //for each of lowest neighbors i is number of neighbor
        {
            if(m_adjacencymatrix[lowest.m_number][i]<INFINITY)  //check if a connection exists
            {
                int dist = distance[lowest.m_number] + m_adjacencymatrix[lowest.m_number][i];   //get distance
                if(dist<distance[i])
                {
                    distance[i] = dist;
                    m_vertices[i].m_prev = lowest.m_number;     //update shortest path in graph vector
                    m_vertices[i].m_distance = dist;            //update distance in graph vector
                }
            }
        }
    }
    std::cout<<"\n";
    for(int i=0;i<21;i++)
    {
        std::cout<<"Vertex "<<char(97+i)<<" Distance: "<<distance[i]<<"\n";
    }
    int prev = destination;
    std::list<int> output;  //Since the path can only be read backwards, a list is used to output it forwards
    while(prev != -1)   //fill up output list with vertex values
    {
        output.push_front(prev);
        prev = m_vertices[prev].m_prev;
    }
    std::cout<<"Shortest path: ";
    int listsize = output.size();
    for(int i=0;i<listsize;i++)
    {
        char c = 97+output.front();
        if(c == 'u')
        {
            std::cout<<'z'<<" ";
        }
        else
        {
            std::cout<<c<<" ";
        }
        output.pop_front();
    }
    std::cout<<"\nShortest path distance: "<<m_vertices[destination].m_distance;


}

int Graph::getIndex(int number)
{
    for(int i=0;i<m_vertexcount;i++)
    {
        if(m_vertices[i].m_number==number)
        {
            return i;
        }
    }
    return -1;
}

Vertex Graph::getVertex(int index)
{
    return m_vertices[index];
}
