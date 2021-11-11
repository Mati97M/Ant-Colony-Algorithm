#ifndef EDGE_H
#define EDGE
#include "../Vertex/Vertex.h"
#include <string>

//using Edges_vector = std::vector<Edge*>;
class Edge
{
	friend class Vertex;
	friend class Ant;

	double length;
	double feromones;
	Vertex* begin;
	Vertex* end;
public:
	static std::vector<Edge*> Edges;

private:
	static void create_Edges(const Vertexes_vector& vv);

	Edge(Vertex* current, Vertex* previous);
public:
	void add_feromone(double f) { feromones += f; }
	static void reduce_feromoneG(double f);

};
#endif // !EDGE_H
