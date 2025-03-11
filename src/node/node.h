//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_NODE_H
#define LUMMAENGINE_NODE_H

#include <string>

class Node{
protected:
    std::string node_address;
    std::string node_port;

    size_t get_current_level();

};

#endif //LUMMAENGINE_NODE_H
