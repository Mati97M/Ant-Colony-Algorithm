#ifndef TOOLS_H
#define TOOLS_H
#include "Edge/Edge.h"
#include "Vertex/Vertex.h"
#include<iostream>


double random()
{
    return static_cast<double>(rand() % 1001) / 1000.0;
}

void create_graph()
{
//    //prepearing Vertexes
//    auto A = new Vertex("A", 185, 245);
//    auto B = new Vertex("B", 35, 235);
//    auto C = new Vertex("C", 135, 215);
//    auto D = new Vertex("D", 205, 205);
//    auto E = new Vertex("E", 45, 195);
//    auto F = new Vertex("F", 155, 185);
//    auto G = new Vertex("G", 105, 155);
//    auto H = new Vertex("H", 185, 155);
//    auto I = new Vertex("I", 45, 125);
//    auto J = new Vertex("J", 175, 115);
//    auto K = new Vertex("K", 95, 105);
//    auto L = new Vertex("L", 225, 105);
//    auto M = new Vertex("M", 45, 65);
//    auto N = new Vertex("N", 125, 65);
//    auto O = new Vertex("O", 195, 45);
//
//    //preaparing Edges 
//    Edge::create_Edge(B, E);
//    Edge::create_Edge(B, C);
//    Edge::create_Edge(B, A);
//
//    Edge::create_Edge(E, C);
//    Edge::create_Edge(E, G);
//    Edge::create_Edge(E, I);
//
//    Edge::create_Edge(I, G);
//    Edge::create_Edge(I, M);
//
//    Edge::create_Edge(M, K);
//
//    Edge::create_Edge(K, J);
//    Edge::create_Edge(K, N);
//
//    Edge::create_Edge(N, O);
//
//    Edge::create_Edge(O, L);
//
//    Edge::create_Edge(L, J);
//
//    Edge::create_Edge(J, H);
//
//    Edge::create_Edge(H, G);
//    Edge::create_Edge(H, D);
//
//    Edge::create_Edge(D, A);
//    Edge::create_Edge(D, C);
//
//    Edge::create_Edge(A, C);
//
//    Edge::create_Edge(C, F);
//
//    Edge::create_Edge(F, G);
//    std::cout << "Graph created successully!" << std::endl;
}

#endif // !TOOLS_H

