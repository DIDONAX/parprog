#include "utils.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>


DiGraph get_graph_from_adjacency_matrix(const Matrix<bool>& adjacency_matrix){
    DiGraph graph;
    int d = adjacency_matrix.get_columns();
    for (int i = 0; i < d; ++i) {
        graph.add_node();
    }
    for (int row = 0; row < d; ++row) {
        for (int col = 0; col < d; ++col) {
            if (adjacency_matrix.get_content(row,col) != 0) {
                graph.add_edge(row,col);
            }
        }
    } 
    return graph;
}

Matrix<bool> get_reachability_matrix(const DiGraph& graph) {
    auto N = graph.get_node_count();
    auto reachability_matrix = graph.get_adjacency_matrix_from_graph();
    for (int i = 0; i < N; ++i) {
        reachability_matrix.set_content(i, i, 2);
    }
    for (int i = 0; i < N;++i) {
        reachability_matrix = reachability_matrix + reachability_matrix * reachability_matrix;
    }
    return reachability_matrix;
}


