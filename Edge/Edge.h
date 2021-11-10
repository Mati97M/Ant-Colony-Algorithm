#ifndef EDGE_H
#define EDGE
#include "../Verticle/Verticle.h"
#include <string>

//using Edges_vector = std::vector<Edge*>;
class Edge
{
	friend class Verticle;
	friend class Ant;

	double length;
	double feromones;
	Verticle* begin;
	Verticle* end;
public:
	static std::vector<Edge*> Edges;

private:
	static void create_Edges(const Verticles_vector& vv);

	Edge(Verticle* current, Verticle* previous);
public:
	void add_feromone(double f) { feromones += f; }
	static void reduce_feromoneG(double f);

};
#endif // !EDGE_H
