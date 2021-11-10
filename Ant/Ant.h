#ifndef ANT_H
#define ANT_H

#include <vector>
#include "../Edge/Edge.h"
class Verticle;
class Ant
{
	std::vector<Verticle*> visited_V;	
	std::vector<Edge*> visited_E; //raczej niepotrzebne
	Verticle* current_verticle;
	double path_length;
	
public:
	Ant() :current_verticle{ nullptr }, path_length{}{}
	void set_current_V(Verticle* v) { visited_V.push_back(current_verticle = v); }
	void put_feromone(double f);
	double get_path_length() { return path_length; }
	void move(const std::vector<Edge*>& edges);
	static Verticle* target;
};
#endif // !1
