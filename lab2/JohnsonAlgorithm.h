#include <stdio.h>
#include <vector>
#include <iostream>
#include "graph.h"

using distanceVector = std::vector<int>;

distanceVector belmanFord(GraphFunctionality& graph, size_t fromVertex) throw(std::runtime_error);

void relax(distanceVector& dist, GraphFunctionality& graph, size_t u, size_t v); 

void relax(distanceVector& dist, edgesContainer& edgesWeight, size_t u, size_t v); 

std::vector<distanceVector> johnsonAlgorithm(GraphFunctionality& g);

void initDistanceVector(distanceVector& distance, size_t fromVertex);

std::pair<size_t, int> findMin(std::vector<bool>& in, edgesContainer& edgesWeight);

distanceVector dijkstra(GraphFunctionality& graph, edgesContainer newEdgesWeight, size_t fromVertex);

void initDistanceVector(distanceVector& distance, size_t fromVertex);
