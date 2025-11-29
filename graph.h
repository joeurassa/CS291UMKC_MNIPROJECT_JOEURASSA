/*

 AUTHOR: JOSEPH URASSA
 FILE NAME: "Graph.h"
 DATE: NOV 28, 2025

// This is a header file declaring the graph class used to model directed 
// graph of airports and flights

*/

#ifndef GRAPH_H
#define GRAPH_

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>  // for std: pair.

// The graph class models a weighted, directed graph where:
// - Nodes: Airports(represented by their IATA code, ie. "JFK")
// - Edges: One-way flights from one airport to another.
// - Weights: cost of the flights ( could be sistance for some users)
//
// Public Operations include:
// addFlight            : Add a directed flight with given cost
// shortestPath         : Find minimum-cost path between two airports (Dijkstra Algorithm)
// printHubs            : Show airports wih most outgoin or incoming flights.
// unreachableFrom      : List  unreachable airports from a given starting airport.
// printAdjacencyList   : Show all flights in adjancency-list format.

class Graph{
    private: 
        // List of airport codes: airports[i] gives the code at index i.
        std::vector<std::string> airport;

        // Map from airport code to index in 'airport' vector
        std::unordered_map<std::string, int> id;

        //Adjacency list: adj[u] = vector of (v weight) for flights u --> v
        std::vector<std::pair<int, double>> adj;

        // Add an airport if not already present, and return its index
        int addAirport(const std::string& code);

        // Look up index of airport code; throws std::runtime_error if not found.
        int indexOf( const std::string& code) const;

        // Dijkstra's algorithm from source 's' (index in airports).
        // Rertuns:
        //      - dist: shortest distance from s to every vertex
        //      - prev: predecessor index for each vertex on the shortest path tree
        std::pair<std::vector<double>, std::vector<int>>dijkstra(int s) const;


    ///********************************************************************************************///

    public:
        // Add a directed flight 'from' to 'to' with the given cost.
        void addFlight(const std::string& from, const std::string& to, double cost);
        
        // 1
        // Computing shortest path (by cost) from 'from' to 'to' using Dijkstras algorithm.
        // Returns:
        //      -1st: vector of airport codes representing the path  (empty if unreachable)
        //      -2nd: total cost of that path

        std::pair<std::vector<std::string>,double>
        shortestPath(const std::string& from, const std::string& to) const;

        // 2
        // Computing and Prints hubs (airports with the most outgoing / incoming flights)
        void printHubs()const;

        //3
        // From a given starting airport, return a list of airport that are unreachable
        std::vector<std::string>unreachableFrom(const std::string& start) const;


        //4
        // Printing adjancency list of the graph: for each airport, list outgoing flights
        void printAdjacencyList() const;
     

};


#endif //  GRAPH_H