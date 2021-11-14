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
	Vertex* begin;	
	Vertex* end;	
public:
	static Edges_map Edges;
	static void create_Edge(Vertex* v1, Vertex* v2);
	Edge(Vertex* v1, Vertex* v2);
private:
	void free_Edges();

public:
	~Edge();
	void add_feromone(double f) { feromones += f; }
	static void reduce_feromoneG(double f);
	void reduce_feromone(double f) { feromones *= f; }
};

#endif // !EDGE_H
