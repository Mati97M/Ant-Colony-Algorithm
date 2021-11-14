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

//void Ant::move(const std::vector<Edge*> & edges)	//inaczej zrob - niech  mrowka przemieszcza sie po wierzcholkach, ne po krawedziach
//{
//	//find unvisited edge
//	int n = rand() % edges.size();	//inaczej, uzywaj ieratora po wierzcholkach
//	auto it = edges.begin();
//	it += n;
//	while (std::find(visited_E.begin(), visited_E.end(), *it) != visited_E.end()) //jesli znajdzie, to trzeba jeszcze raz losowac n 
//	{
//		//if((*it)->)
//		n = rand() % edges.size();
//	}
//	//found edge wasn`t visited, so ant goes there
//	
//	//funkcja celu? w kazdym razie teraz  ocena edges[n] , jej atrakcyjnosci, funkcja losujaca prog przebicia
//}
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
	if (current_Vertex != target)  //&& !current_Vertex->neighbours.empty()  nie, bo nie da sie wtedy ich zrestartowac
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
			set_current_V(nullptr);
			set_current_V(start);
			reset_candidates();
			reset_visited();
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
	else std::cout << "Ant "<<id << "waiting for company" << std::endl;

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
	double upper_limit = it->second;// górna granica przedzia³u (narastaj¹ca suma prawdopodobieñstw)
	double lower_limit = 0.0;
	while(it != possibility_of_choosing.end())
	{
		if (random_number >= lower_limit && random_number <= upper_limit) //spawdzamy, czy wylosowana liczba znajduje siê w przedziale
		{
			chosen_edge = it->first;//jak tak, to przerywamy
			break;
		}
		else
		{
			lower_limit = upper_limit;//jak nie, to aktualizujemy wartoœci granic
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