#ifndef ANT_H
#define ANT_H

#include <vector>
#include "../Edge/Edge.h"
class Vertex;
class Ant
{
	std::vector<Vertex*> visited_V;	
	std::vector<Edge*> visited_E; //raczej niepotrzebne
	Vertex* current_Vertex;
	double path_length;
	
public:
	Ant() :current_Vertex{ nullptr }, path_length{}{}
	void set_current_V(Vertex* v) { visited_V.push_back(current_Vertex = v); }
	void put_feromone(double f);
	double get_path_length() { return path_length; }
	void move_to_next_V(const std::vector<Edge*>& edges, const Vertexes_vector& Vertexes);
	void move(const std::vector<Edge*>& edges);
	static Vertex* target;
};
#endif // !1
