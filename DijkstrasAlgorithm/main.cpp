#include <iostream>
#include "Graph.h"

using namespace std;


void initializeMatrix(int **matrix);

int main()
{
    int **adjmatrix;    //create adjacency matrix
    adjmatrix = new int*[21];
    for(int i=0;i<21;i++)
    {
        adjmatrix[i] = new int[21];
    }
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
        {
            adjmatrix[i][j] = INFINITY; //fill adjacency matrix with no connections
        }
    }
    initializeMatrix(adjmatrix);    //apply question 4 graph format
    std::vector<Vertex> v;
    for(int i=0;i<21;i++)
    {
        v.push_back(Vertex(i));
    }
    Graph g(21,v,adjmatrix);    //create graph
    g.Dijkstra(0,20);   //run Dijkstra's algorithm from vertex a to z


    return 0;
}

void initializeMatrix(int **matrix) //question 4 graph
{
    matrix[0][1] = 2; matrix[0][2] = 4; matrix[0][3] = 1;   //A
    matrix[1][0] = 2; matrix[1][2] = 3; matrix[1][4] = 1;   //B
    matrix[2][0] = 4; matrix[2][1] = 3; matrix[2][5] = 2; matrix[2][4] = 2; //C
    matrix[3][0] = 1; matrix[3][5] = 5; matrix[3][6] = 4;   //D
    matrix[4][1] = 1; matrix[4][7] = 3; matrix[4][2] = 2; //E
    matrix[5][2] = 2; matrix[5][3] = 5; matrix[5][6] = 3; matrix[5][7]=3; matrix[5][8]=2;matrix[5][9]=4; //F
    matrix[6][3] = 4; matrix[6][5] = 3; matrix[6][10] = 2; //G
    matrix[7][4] = 3; matrix[7][5] = 3; matrix[7][14] = 8; matrix[7][11] = 1; //H
    matrix[8][5] = 2; matrix[8][9] = 3; matrix[8][11] = 3; matrix[8][12] = 2; //I
    matrix[9][5] = 4; matrix[9][8] = 3; matrix[9][10] = 6; matrix[9][12] = 6; matrix[9][13] = 3;   //J
    matrix[10][6] = 2; matrix[10][9] = 6; matrix[10][13] = 4; matrix[10][17] = 2;  //K
    matrix[11][7] = 1; matrix[11][8] = 3; matrix[11][12] = 3; matrix[11][14] = 6;  //L
    matrix[12][11] = 3; matrix[12][8] = 2; matrix[12][9] = 6; matrix[12][13] = 5; matrix[12][15] = 2; matrix[12][14] = 4;  //M
    matrix[13][12] = 5; matrix[13][9] = 3; matrix[13][10] = 4; matrix[13][17] = 1; matrix[13][16] = 2;  //N
    matrix[14][7] = 8; matrix[14][11] = 6; matrix[14][12] = 4; matrix[14][15] = 2; matrix[14][18] = 6;  //O
    matrix[15][14] = 2; matrix[15][12] = 2; matrix[15][16] = 1; matrix[15][19] = 1; matrix[15][18] = 2;  //P
    matrix[16][15] = 1; matrix[16][13] = 2; matrix[16][17] = 8; matrix[16][19] = 3;  //Q
    matrix[17][10] = 2; matrix[17][13] = 1; matrix[17][16] = 8; matrix[17][19] = 5;  //R
    matrix[18][14] = 6; matrix[18][15] = 2; matrix[18][20] = 2;  //S
    matrix[19][15] = 1; matrix[19][16] = 3; matrix[19][17] = 5; matrix[19][20] = 8;  //T
    matrix[20][18] = 2; matrix[20][19] = 8;  //Z
}
