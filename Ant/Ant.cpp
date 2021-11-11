#include "Ant.h"
#include <iostream>

Vertex* Ant::target{};

void Ant::put_feromone(double f)
{
	for (auto &e : visited_E) e->add_feromone(1.0/path_length);
}

void Ant::move(const std::vector<Edge*> & edges)	//inaczej zrob - niech  mrowka przemieszcza sie po wierzcholkach, ne po krawedziach
{
	//find unvisited edge
	int n = rand() % edges.size();	//inaczej, uzywaj ieratora po wierzcholkach
	auto it = edges.begin();
	it += n;
	while (std::find(visited_E.begin(), visited_E.end(), it) != visited_E.end()) //jesli znajdzie, to trzeba jeszcze raz losowac n 
	{
		if((*it)->)
		n = rand() % edges.size();
	}
	//found edge wasn`t visited, so ant goes there
	
	//funkcja celu? w kazdym razie teraz  ocena edges[n] , jej atrakcyjnosci, funkcja losujaca prog przebicia
}

void Ant::move_to_next_V(const std::vector<Edge*>& edges, const Vertexes_vector& Vertexes)
{
	//chose vertex to visit - creating candidates
	auto it_V = Vertexes.begin();
	while (it_V != Vertexes.end())
	{
		while (std::find(visited_V.begin(), visited_V.end(), *it_V) != visited_V.end()) //jesli znaleziono dany wierzch w wekt odwiedzonych, to przypatrujemy sie nast. wierzch.
		{
			it_V++;
		}
		candidates_V.push_back(*it_V);
	}
	//dla kazdego z kandydatow ustalamy atrakcyjnosc sciezki. Te bez feromonow beda mialy losowane wartosci
	//ruletka - wybor lub odrzucenie wierzcholka (krawedzi do wierzcholka)
	///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wybor konkretnej krawedzi, mamy przeciez current_V oraz wierzcholek docelowy
	// zobacz, edge.cpp map
}