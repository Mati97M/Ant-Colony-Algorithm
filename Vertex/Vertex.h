#ifndef Vertex_H
#define Vertex_H
#include <string>
#include <array>
#include <vector>
#include "../Edge/Edge.h"			/// zmien nazwe klasy na Vertex

using Vertexes_vector = std::vector<Vertex*>;

class Vertex	//trzeba tworzyc operatorem new
{
	static Vertexes_vector Vertexes;	//klika - kazdy z kazdym
	static int Vertexes_num;
	std::string name;
	double x,y;
	//bool ant_entered;
	int ants;

	public:
	//static Vertex* target;
	Vertex(std::string name, double x, double y) : name{ name },x{x},y{y},ants{0}
	{
		Vertexes_num++;
		Vertexes.push_back(this);
		if (Vertexes_num > 1) { Edge::create_Edges(Vertexes); }
	}
	double get_x() { return x; }
	double get_y() { return y; }
	std::string get_name() { return name; }
	//bool ant_entered() { return ant_entered; }
	int get_ants_num() { return ants; }
	
};
#endif // !Vertex_H

