/* Author: Shanmukh Challa
 * Description:
 * References Used:
 *    https://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
 *    https://www.geeksforgeeks.org/bipartite-graph/
 *    https://stackoverflow.com/questions/26872327/breaking-out-of-nested-loops-in-c
 * NOTES:
 */

#include<iostream>
#include <list>

using namespace std;

struct PlayerInfo { //Struct to store names of the wrestlers
  string name;

};

class Graph
{
    int vertices;
    list<int> *adj;

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int s, int * playerNum, int max);
};

Graph::Graph(int vertices) //Constructor
{
    this->vertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int w) //Add an edge to the graph
{
    adj[v].push_back(w);
}

void Graph::BFS(int s, int * playerNum, int max)
{
    int team[6]; //Initialize array to store the teams

    bool *visited = new bool[vertices];
    for(int i = 0; i < vertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    //Check if impossible
    for (int j = 0; j < max; j++)
    {
        for (i = adj[j].begin(); i != adj[j].end(); j++)
        {
            if (team[j] == team[*i])
            {
              cout << "Impossible" << endl;
              goto finish;

            }
        }
     }
     finish:
     return;
}

//Output whether the wrestler is a babyface or heel
void output(int * playerNum, int max, int name[], int team[])
{
  for (int i = 0; i < max; i++)
  {
    if((playerNum[i] % 2 == 0) || playerNum[i] == 0)
    {
      team[i] = 0;
      cout << "Babyface: " << name[i] << " ";
      cout << endl;
    } else {
      team[i] = 1;
      cout << "Heel: " << name[i] << " ";
      cout << endl;
    }
  }
}

int main()
{
    int playerNum[6];
    Graph g(6);
    int max = 6;

    //Testing with hardcoded Wrestler1.txt info
    g.addEdge(0, 5);
    g.addEdge(5, 0);
    g.addEdge(0, 4);
    g.addEdge(4, 0);
    g.addEdge(5, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 1);

    g.BFS(0, playerNum, max);
    g.BFS(1, playerNum, max);
    g.BFS(2, playerNum, max);
    g.BFS(3, playerNum, max);
    g.BFS(4, playerNum, max);
    g.BFS(5, playerNum, max);

    return 0;
}
