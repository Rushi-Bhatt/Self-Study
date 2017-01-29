//Dijkstra's shortest path algorithm for 6 nodes and starting vertice 0.
//Rushi K.Bhatt
//11bce128
//Copy folder C_PROG in C:\ and run this program.

#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#define MAX 6
#define INFINITY 999


class Dijkstra{
    private:
	int adjMatrix[MAX][MAX];
	int predecessor[MAX],distance[MAX];
	int mark[15]; //keep track of visited node
	int source;
	int numOfVertices;
    public:
    /*
    * Function read() reads No of vertices, Adjacency Matrix and source
    * Matrix from the user. The number of vertices must be greather than
    * zero, all members of Adjacency Matrix must be postive as distances
    * are always positive. The source vertex must also be positive from 0
    * to noOfVertices - 1
    */

	void read();

   /*
    * Function initialize initializes all the data members at the begining of
    * the execution. The distance between source to source is zero and all other
    * distances between source and vertices are infinity. The mark is initialized
    * to false and predecessor is initialized to -1
    */

	void initialize();

    /*
    * Function getClosestUnmarkedNode returns the node which is nearest from the
    * Predecessor marked node. If the node is already marked as visited, then it search
    * for another node.
    */

	int getClosestUnmarkedNode();

    /*
    * Function calculateDistance calculates the minimum distances from the source node to
    * Other node.
    */

	void calculateDistance();
    /*
    * Function output prints the results
    */

	void output();
	void printPath(int);
};



void Dijkstra::read(){

    ifstream inFile;
int temps[MAX][MAX];
int col;
int row;
//int count=MAX;
	inFile.open("C:\\C_PROG\\UNITS.txt");

for (row = 0; row<MAX; row++)
{
    for (col = 0; col<MAX; col++)
    {
    inFile >> temps[row][col];
    adjMatrix[row][col]=temps[row][col];
    }
}
inFile.close();
  numOfVertices=MAX;
     source=0;
}


void Dijkstra::initialize(){
    for(int i=0;i<numOfVertices;i++) {
	mark[i] = 0;
	predecessor[i] = -1;
	distance[i] = INFINITY;
    }
    distance[source]= 0;
}


int Dijkstra::getClosestUnmarkedNode(){
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++) {
	if((!mark[i]) && ( minDistance >= distance[i])) {
	    minDistance = distance[i];
	    closestUnmarkedNode = i;
	}
    }
    return closestUnmarkedNode;
}

void Dijkstra::calculateDistance(){
    initialize();
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices) {
	closestUnmarkedNode = getClosestUnmarkedNode();
	mark[closestUnmarkedNode] = 1;
	for(int i=0;i<numOfVertices;i++) {
	    if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
		if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
		    distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
		    predecessor[i] = closestUnmarkedNode;
		}

            }

        }

	count++;

    }

}


void Dijkstra::printPath(int node){
    if(node == source)
	cout<<(char)(node + 97)<<"..";
    else if(predecessor[node] == -1)
	cout<<"No path from "<<source<<" "<< (char)(node + 97)<<endl;
    else {
	printPath(predecessor[node]);
	cout<<(char)(node + 97)<<"..";
    }
}


void Dijkstra::output(){
    for(int i=0;i<numOfVertices;i++) {
	if(i == source)               {
	    cout<<(char)(source + 97)<<".."<<source;  }
	else        {
	    printPath(i);}
	cout<<"->"<<distance[i]<<endl;
    }
}


void main(){
clrscr();
    Dijkstra G;
    G.read();
    G.calculateDistance();
    G.output();

    getch();
}

