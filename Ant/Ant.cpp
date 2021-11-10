#include "Ant.h"

Verticle* Ant::target{};

void Ant::put_feromone(double f)
{
	for (auto e : visited_E) e->add_feromone(1.0/path_length);
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