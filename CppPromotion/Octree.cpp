#include "Octree.h"

OctreeNode::OctreeNode(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    for (int i = 0; i < 8; i++) {
        children[i] = nullptr;
    }
}

OctreeNode::~OctreeNode() {
    for (int i = 0; i < 8; i++) {
        delete children[i];
    }
}

Octree::Octree() {
    root = nullptr;
}

Octree::~Octree() {
    delete root;
}

void Octree::insert(double x, double y, double z) {
    if (root == nullptr) {
        root = new OctreeNode(x, y, z);
        return;
    }
    insertRecursive(root, x, y, z);
}

void Octree::insertRecursive(OctreeNode* node, double x, double y, double z) {
    int index = (x < node->x ? 0 : 1) + (y < node->y ? 0 : 2) + (z < node->z ? 0 : 4);

    if (node->children[index] == nullptr) {
        node->children[index] = new OctreeNode(x, y, z);
    }
    else {
        insertRecursive(node->children[index], x, y, z);
    }
}

void Octree::traverse(OctreeNode* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << "(" << node->x << ", " << node->y << ", " << node->z << ")" << std::endl;

    for (int i = 0; i < 8; i++) {
        traverse(node->children[i]);
    }
}

void Octree::print() {
    traverse(root);
}