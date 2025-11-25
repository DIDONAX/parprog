#include "DiGraph.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Node.h"
#include <fstream>


DiGraph::DiGraph():next_free_node_id(0){}

DiGraph::~DiGraph(){
    for (auto& [_, node_ptr] : node_map) {
        delete node_ptr;
    }
}

std::int32_t DiGraph::get_node_count() const { 
    return static_cast<std::int32_t>(node_map.size());
}

Node* DiGraph::add_node(){ 
    Node *node = new Node(next_free_node_id);
    next_free_node_id++;
    node_map[node->get_id()] = node;
    return node;
 }

Node* DiGraph::add_node_carelessly(std::int32_t new_node_id){ 
    Node *node = new Node(new_node_id);
    node_map[new_node_id] = node;
    return node;
}

void DiGraph::set_next_free_node_id (std::int32_t value){
    next_free_node_id = value;
}

Node* DiGraph::get_node_by_id(std::int32_t node_id) const {
    auto it = node_map.find(node_id);
    if (it != node_map.end()) {
        return node_map.at(node_id);
    } else {
        throw std::invalid_argument("Invalid Node ID");
    }
}

void DiGraph::add_edge(int32_t source_id, int32_t target_id){
    auto source_it = node_map.find(source_id);
    auto target_it = node_map.find(target_id);
    if (source_it != node_map.end() && target_it != node_map.end()) {
        auto source_node_ptr = get_node_by_id(source_id);
        auto target_node_ptr = get_node_by_id(target_id);
        source_node_ptr->add_out_edge(target_node_ptr);
        target_node_ptr->add_in_edge(source_node_ptr);
    } else {
        throw std::invalid_argument("Invalid Node ID");
    }
}

void DiGraph::export_to_dot_file(std::string file_path) const {
    std::ofstream of(file_path);
    
    if (of.is_open()) {
        of << "digraph {\n";
        for (int node_id = 0; node_id < node_map.size(); ++node_id) {
            auto const source = node_map.at(node_id);
            auto const targets = source->get_out_edges();
            for (auto const& target : targets) {
                of << "\t" << source->get_id() << " -> " << target->get_id() << ";\n";
            }
        }
        of << "}";
        of.close();
    }
}


Matrix<bool> DiGraph::get_adjacency_matrix_from_graph() const { return Matrix<bool>(1, 1); }

/* Do not change the code below here */

/* These functions are used for importing graph from .dot files. */
std::int32_t* DiGraph::get_next_free_node_id_ptr(){
    return &next_free_node_id;
}

std::unordered_map<int32_t, Node*>* DiGraph::get_node_map_ptr(){
    return &node_map;
}
