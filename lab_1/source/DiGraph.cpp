#include "DiGraph.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <fstream>


DiGraph::DiGraph(){}

DiGraph::~DiGraph(){}

std::int32_t DiGraph::get_node_count() const { return 0; }

Node* DiGraph::add_node(){ return nullptr; }

Node* DiGraph::add_node_carelessly(std::int32_t new_node_id){ return nullptr; }

void DiGraph::set_next_free_node_id(std::int32_t value){}

Node* DiGraph::get_node_by_id(std::int32_t node_id) const { return nullptr; }

void DiGraph::add_edge(int32_t source_id, int32_t target_id){}

void DiGraph::export_to_dot_file(std::string file_path) const {}

Matrix<bool> DiGraph::get_adjacency_matrix_from_graph() const { return Matrix<bool>(1, 1); }

/* Do not change the code below here */

/* These functions are used for importing graph from .dot files. */
std::int32_t* DiGraph::get_next_free_node_id_ptr(){
    return &next_free_node_id;
}

std::unordered_map<int32_t, Node*>* DiGraph::get_node_map_ptr(){
    return &node_map;
}
