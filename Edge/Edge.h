#ifndef EDGE_H
#define EDGE
#include "../Vertex/Vertex.h"
#include <string>
#include <map>

using Edges_map = std::map < std::string, Edge*> ;

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

private:
	static void create_Edges(const Vertexes_vector& vv);
	Edge(Vertex* current, Vertex* previous);
public:
	void add_feromone(double f) { feromones += f; }
	static void reduce_feromoneG(double f);
	void reduce_feromone(double f) { feromones *= f; }
};
#endif // !EDGE_H
