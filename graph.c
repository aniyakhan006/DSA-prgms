#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int graph[MAX][MAX]; 
int visited[MAX]; 
int queue[MAX]; 
int front = -1, rear = -1; 
// Create a graph using Adjacency Matrix values..
void createGraph(int n) 
{ 
 int i, j; 
 printf("Enter the adjacency matrix:\n"); 
 for (i = 0; i < n; i++) 
 { 
 printf("Enter row %d: ", i + 1); 
 for (j = 0; j < n; j++) 
 { 
 // Enter 0 if edge not existed otherwise 1 
 scanf("%d", &graph[i][j]); 
 } 
 } 
} 
// Recursive version of DFS
void DFS(int start, int n) 
{ 
 int i; 
 printf("%d ", start); 
 visited[start] = 1; // Put 1 for strating vertex that is visited
 for (i = 0; i < n; i++) 
 { 
 // if vertex is not visted and check if there is edge btween
 // Current vertex to this vertex
 if (!visited[i] && graph[start][i] == 1) 
 { 
 DFS(i, n); // Call DFS recursively to reach next vertex
 } 
 } 
} 
// BFS Implementation using queue ...
void BFS(int start, int n) 
{ 
 int i, vertex; 
 printf("%d ", start); 
 visited[start] = 1; // Put Starting vertex visited
 queue[++rear] = start; // Insert into queue visited first vertex
 while (front <= rear) 
 { 
 vertex = queue[front++]; // Pop the vertex visited
 for (i = 0; i < n; i++) 
 { 
 // if vertex is not visted and check if there is edge btween
 // Current vertex to this vertex
 if (!visited[i] && graph[vertex][i] == 1) 
 { 
 printf("%d ", i); 
 visited[i] = 1; 
 queue[++rear] = i; // Insert all the vertices connected to Current vertex 
 }
 } 
 } 
} 
int main() 
{ 
 int ch,i; 
 int n, start; 
 while (1) 
 { 
 printf("\n1.Create a Graph\n.2.DFS \n 3.BFS \n 4.Exit \n Enter your choice:\n"); 
 scanf("%d", &ch); 
 switch (ch) 
 { 
 case 1: 
 printf("Enter the number of cities: "); 
 scanf("%d", &n); 
 createGraph(n); 
 break; 
 case 2: 
 printf("\nEnter the starting node: "); 
 scanf("%d", &start); 
 printf("\nNodes reachable from node %d using DFS: ", start); 
 DFS(start, n); 
 // Reset visited array for BFS
 for (i = 0; i < n; i++) 
 { 
 visited[i] = 0; 
 } 
 break; 
 case 3:front = rear = -1; // Reset queue for BFS

 printf("\nNodes reachable from node %d using BFS: ", start); 
 BFS(start, n); 
 // Reset visited array for BFS
 for (i = 0; i < n; i++) 
 { 
 visited[i] = 0; 
 } 
 printf("\n"); 
 case 4:exit(0); 
 break; 
 } 
 } 
 return 0; 
}