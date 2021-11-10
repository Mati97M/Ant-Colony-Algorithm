#ifndef VERTICLE_H
#define VERTICLE_H
#include <string>
#include <array>
#include <vector>
#include "../Edge/Edge.h"

using Verticles_vector = std::vector<Verticle*>;

class Verticle	//trzeba tworzyc operatorem new
{
	static Verticles_vector Verticles;	//klika - kazdy z kazdym
	static int Verticles_num;
	std::string name;
	double x,y;
	//bool ant_entered;
	int ants;

	public:
	//static Verticle* target;
	Verticle(std::string name, double x, double y) : name{ name },x{x},y{y},ants{0}
	{
		Verticles_num++;
		Verticles.push_back(this);
		if (Verticles_num > 1) { Edge::create_Edges(Verticles); }
	}
	double get_x() { return x; }
	double get_y() { return y; }
	std::string get_name() { return name; }
	//bool ant_entered() { return ant_entered; }
	int get_ants_num() { return ants; }
	
};
#endif // !VERTICLE_H

