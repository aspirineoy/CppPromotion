#pragma once
#include<iostream>
using namespace std;

struct OctreeNode {
    double x, y, z;
    OctreeNode* children[8];

    OctreeNode(double x, double y, double z);

    ~OctreeNode();
};

class Octree {
private:
    OctreeNode* root;

public:
    Octree();

    ~Octree();

    void insert(double x, double y, double z);

    void insertRecursive(OctreeNode* node, double x, double y, double z);

    void traverse(OctreeNode* node);

    void print();
};

