// Created by Mateusz Mieckowski & Rados�aw Mieckowski 
#include "Edge.h"
#include <string>

Edges_map Edge::Edges{};		// mapa <string, Edge*>  np edges["AI"] = adres krawedzi

void Edge::create_Edge(Vertex* v1, Vertex* v2) 
{
			Edges[v1->get_name() + v2->get_name()] = new Edge(v1, v2);
			v1->neighbours.push_back(v2);
			v2->neighbours.push_back(v1);
}

Edge::Edge(Vertex* v1, Vertex* v2) :feromones{1.0}, begin{ v1 }, end{ v2 }
{
	//point begin
	double x_b = begin->get_x();
	double y_b = begin->get_y();

	//point end
	double x_e = end->get_x();
	double y_e = end->get_y();

	//distance - length
	length = sqrt(pow(x_e - x_b, 2) + pow(y_e - y_b, 2) * 1.0);

}

void Edge::reduce_feromoneG(double f)
{
	for (auto & e : Edges)
	{
		e.second->reduce_feromone(f); 
	}

}

Edge::~Edge()
{
	if (!Edges.empty())
		free_Edges();
}
void Edge::free_Edges()
{
	for (auto& e : Edges) delete e.second;
}