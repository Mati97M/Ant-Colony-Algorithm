#include "Ant.h"
#include <iostream>
#include "../tools.h"


Vertex* Ant::target{};
Vertex* Ant::start{};
int Ant::number{};

void Ant::put_feromone()
{
	if (path_length != 0)
	{
		for (auto& e : visited_E) e->add_feromone(1.0 / path_length);
		std::cout << "putting feromone..."<<std::endl;
	}
	else std::cout << "Warning! path_length = 0 Can not put feromone yet!" << std::endl;
}


void Ant::set_current_V(Vertex* v) 
{ 
	if (current_Vertex) current_Vertex->ants_num = current_Vertex->ants_num - 1;
	if (v)
	{
		visited_V.push_back(current_Vertex = v);
		current_Vertex->ants_num = current_Vertex->ants_num + 1;
	}
}


void Ant::move_to_next_V()
{
	if (current_Vertex != target) 
	{
		//chose vertex to visit - creating candidates
		for (const auto& n : current_Vertex->neighbours)
		{
			if (std::find(visited_V.begin(), visited_V.end(), n) == visited_V.end())
			{
				candidates_V.push_back(n);
			}
		}
		//no candidates -> try again (cycle)
		if (candidates_V.empty())
		{
			reset_candidates();
			reset_visited();
			set_current_V(nullptr);
			set_current_V(start);

			std::cout << "ant "<<id<< "got lost.Tries againg" << std::endl;
			return;
		}
		// finding matcihng edges
		for (const auto& v : candidates_V)
		{
			std::string temp_key = current_Vertex->get_name() + v->get_name();
			std::cout <<"Ant nr "<<id<<": temp_key = "<<temp_key;
			std::string key = ( (Edge::Edges.find(temp_key) == Edge::Edges.end()) ? std::string(1, temp_key.back()) + std::string(1, temp_key.front()) : temp_key);
			std::cout << "\tkey =  " << key << std::endl;
			candidates_E.push_back(Edge::Edges[key]);
		}
		//wybieramy krawedz i idziemy do wierzcholka, wydluzamy przebyta droge
		set_current_V(which_way());
		reset_candidates();
		
	}
	else std::cout << "Ant "<<id << " waiting for company" << std::endl;

}

Vertex* Ant::which_way()
{
	double feromones_sum{};
	Edge* chosen_edge{};
	for (const auto& e : candidates_E) { feromones_sum += e->feromones; }
	
	std::vector<std::pair<Edge*,double>> possibility_of_choosing;
	
	for (const auto& e : candidates_E)
	{
		possibility_of_choosing.push_back(std::make_pair(e, e->feromones / feromones_sum));
	}

	double random_number = random();
	//creat ranges & pick one edge 
	auto it = possibility_of_choosing.begin();
	double upper_limit = it->second;// g�rna granica przedzia�u (narastaj�ca suma prawdopodobie�stw)
	double lower_limit = 0.0;
	while(it != possibility_of_choosing.end())
	{
		if (random_number >= lower_limit && random_number <= upper_limit) //spawdzamy, czy wylosowana liczba znajduje si� w przedziale
		{
			chosen_edge = it->first;//jak tak, to przerywamy
			break;
		}
		else
		{
			lower_limit = upper_limit;//jak nie, to aktualizujemy warto�ci granic
			upper_limit += (++it)->second;
		}
	}
	reset_candidates();
	if (chosen_edge != nullptr)
	{
		visited_E.push_back(chosen_edge);
		path_length += chosen_edge->length;
		return chosen_edge->begin == current_Vertex ? chosen_edge->end : chosen_edge->begin;
	}
	else
	{
		std::cout << "Warning! Didn`t choose edge. Returns nullprt as Vertex*" << std::endl;
		return nullptr;
	}
}

void Ant::reset_candidates()
{
	//candidates_V.erase(candidates_V.begin(),candidates_V.end());
	//candidates_E.erase(candidates_E.begin(), candidates_E.end());
	candidates_V.clear();
	candidates_V.shrink_to_fit();
	
	candidates_E.clear();
	candidates_E.shrink_to_fit();
}

void Ant::reset_visited()
{
	/*visited_V.erase(candidates_V.begin(), candidates_V.end());
	visited_E.erase(candidates_E.begin(), candidates_E.end());*/
	visited_V.clear();
	visited_V.shrink_to_fit();

	visited_E.clear();
	visited_E.shrink_to_fit();

	path_length = 0.0;
}

std::string Ant::get_path_name()
{
	std::string path;
	for (const auto& v : visited_V) path.append(v->get_name());
	return path;
}