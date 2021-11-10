#include "Edge.h"

std::vector<Edge*> Edge::Edges{};

void Edge::create_Edges(const Verticles_vector& vv)
{
	auto it_begin = vv.begin();
	auto it_current = vv.end();
	while (it_current != it_begin)
	{
		auto e = new Edge(*vv.end(), *(--it_current));
		Edges.push_back(e);
	}
}

Edge::Edge(Verticle* current, Verticle* previous) :feromones{}, begin{ previous }, end{ current }
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
	for (auto& e : Edges)
	{
		e->feromones *= f;
	}
}
