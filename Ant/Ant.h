// Created by Mateusz Mieckowski & Rados?aw Mieckowski 
#ifndef ANT_H
#define ANT_H

#include <vector>
#include "../Edge/Edge.h"
#include "../Vertex/Vertex.h"

class Ant
{
	static int number;
	int id;
	Vertexes_vector visited_V;
	std::vector<Edge*> visited_E; 
	Vertex* current_Vertex;
	double path_length;
	Vertexes_vector candidates_V;
	std::vector<Edge*> candidates_E;
	
	Vertex* which_way();
	void reset_candidates();
	void reset_visited();
public:
	static void reset_target() { target->ants_num = 0; }
	Ant() :current_Vertex{ nullptr }, path_length{}, id{}{ id = ++number;}
	~Ant() { --number; }
	void set_current_V(Vertex* v);
	void put_feromone();
	double get_path_length() { return path_length; }
	void move_to_next_V();

	static Vertex* target;
	static Vertex* start;
	std::string get_path_name();
};
#endif // !ANT_H
