#include "Node.h"

Node::Node(std::int32_t id){}

Node::~Node(){}

std::int32_t Node::get_id(){ return 0; }

void Node::add_in_edge(Node* source){}

void Node::add_out_edge(Node* target){}

std::vector<Node*> Node::get_in_edges(){ return std::vector<Node*>(); }

std::vector<Node*> Node::get_out_edges(){return std::vector<Node*>(); }