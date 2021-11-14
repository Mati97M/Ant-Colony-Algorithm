#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <array>
#include <vector>
#include "../Edge/Edge.h"			

class Vertex;
using Vertexes_vector = std::vector<Vertex*>;

class Vertex	//nalezy tworzyc operatorem new
{
	friend class Ant;
	friend class Edge;
	Vertexes_vector neighbours;
	static Vertexes_vector Vertexes;	
	static int Vertexes_num;
	std::string name;
	double x,y;
	int ants_num;

	public:
	Vertex(std::string name, double x, double y) : name{ name }, x{ x }, y{ y }, ants_num{ 0 }, neighbours{}
	{
		Vertexes_num++;
		Vertexes.push_back(this);
	}
	double get_x() { return x; }
	double get_y() { return y; }
	std::string get_name() { return name; }
	int get_ants_num() { return ants_num; }
	
};
#endif // !VERTEX_H

