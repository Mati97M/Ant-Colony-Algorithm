#ifndef EDGE_H
#define EDGE_H
#include "../Vertex/Vertex.h"
#include <string>
#include <map>
class Edge;
using Edges_map = std::map < std::string, Edge* > ;

class Edge
{
	friend class Vertex;
	friend class Ant;

	double length;
	double feromones;
	Vertex* begin;	//niepotrzebne
	Vertex* end;	//niepotrzebne
public:
	static Edges_map Edges;
	static void create_Edge(Vertex* v1, Vertex* v2);
	Edge(Vertex* v1, Vertex* v2);
private:
	//static void create_Edges(const Vertexes_vector & vv);

public:
	void add_feromone(double f) { feromones += f; }
	static void reduce_feromoneG(double f);
	void reduce_feromone(double f) { feromones *= f; }
};

#endif // !EDGE_H
