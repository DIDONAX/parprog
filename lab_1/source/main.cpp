#include <cstdint>
#include <iostream>
#include "Node.h"
#include "DiGraph.h"
#include <typeinfo>
int main(int argc, char** argv) {
	DiGraph graph;
	graph.add_node();
	graph.add_node();
	graph.add_node();
	graph.add_node();
	graph.add_node();
	graph.add_node();
	graph.add_edge(1,2);
	graph.add_edge(2,3);
	graph.add_edge(3,4);
	graph.add_edge(4,1);
	graph.add_edge(1,3);
	graph.add_edge(1,4);
	graph.add_edge(1,5);
	graph.export_to_dot_file("mohamed.dot");
	return 0;
}
