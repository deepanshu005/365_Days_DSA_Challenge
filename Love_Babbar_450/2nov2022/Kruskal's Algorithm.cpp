// CPP DSA CN Lec 21 Love Babbar 450
#include <iostream>
#include <algorithm>
using namespace std;
class Edge { // Class that store values for each vertex
public:
int source;
int dest;
int weight;
};
bool compare(Edge e1, Edge e2) { // Comparator function used to sort edges
return e1.weight < e2.weight; // Edges will sorted in order of their weights
}
int findParent(int v, int *parent) { // Function to find the parent of a vertex
if (parent[v] == v) { // Base case, when a vertex is parent of itself
return v;
}
// Recursively called to find the topmost parent of the vertex.
return findParent(parent[v], parent);
}
void kruskals(Edge *input, int n, int E) {
sort(input, input + E, compare); // In-built sort function: Sorts the edges in
// increasing order of their weights
Edge *output = new Edge[n-1]; // Array to store final edges of MST
int *parent = new int[n]; // Parent array initialized with their indexes
for (int i = 0; i < n; i++) {
parent[i] = i;
}
int count = 0; // To maintain the count of number of edges in the MST


int i = 0; // Index to traverse over the input array
while (count != n - 1) { // As the MST contains n-1 edges.
Edge currentEdge = input[i];
// Figuring out the parent of each edge’s vertices
int sourceParent = findParent(currentEdge.source, parent);
int destParent = findParent(currentEdge.dest, parent);
// If their parents are not equal, then we added that edge to output
if(sourceParent != destParent) {
output[count] = currentEdge;
count++; // Increased the count
parent[sourceParent] = destParent;// Updated the parent array
}
i++;
}
// Finally, printing the MST obtained.
for (int i = 0; i < n-1; i++) {
if(output[i].source < output[i].dest) {
cout << output[i].source << " " << output[i].dest << " " <<
output[i].weight << endl;
}
else {
cout<< output[i].dest << " " <<output[i].source << " " <<
output[i].weight << endl;
}
}
}
int main() {
int n, E;
cin >> n;
cin >> E;
Edge *input = new Edge[E];
for (int i = 0; i < E; i++) {
int s, d, w;
cin >> s >> d >> w;
input[i].source = s;
input[i].dest = d;
input[i].weight = w;
}
kruskals(input, n, E);
return 0;
}
