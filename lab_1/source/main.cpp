#include <iostream>
#include "Node.h"
#include "DiGraph.h"
#include "utils.h"
#include "Matrix.h"

int main() {
	DiGraph graph;
	graph.add_node();
	graph.add_node();
	graph.add_node();
	graph.add_edge(0,1);
	graph.add_edge(1,2);
	graph.add_edge(2,0);
	auto r = graph.get_adjacency_matrix_from_graph();
	auto m = get_reachability_matrix(graph);
	for (int i = 0; i < r.get_columns();++i) {
		for (int j = 0; j < r.get_columns();++j) {
			std::cout << r.get_content(i,j) << " ";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < m.get_columns();++i) {
		for (int j = 0; j < m.get_columns();++j) {
			std::cout << m.get_content(i,j) << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
