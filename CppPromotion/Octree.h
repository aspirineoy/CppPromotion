#pragma once
#include<iostream>
#include <vector>
#include <math.h>

using namespace std;

class Octree {
public:

	Octree() {};
	~Octree() { destory(octree); }
	//八叉树节点结构体
	struct Point {
		double x;
		double y;
		double z;
		void setPoint(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Point() {}
		Point(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};
	typedef struct Octree_Node {
		int count;
		vector<Point> points;
		Octree_Node* nodes[8];
		Octree_Node* parent;

		int level;
		Point centel;
		double length;

		void init(Octree_Node* parent, double length, int level) {
			this->parent = parent;
			for (int i = 0; i < 8; i++) {
				nodes[i] = NULL;
			}
			centel.setPoint(0, 0, 0);
			this->level = level;
			this->length = length;
		}

		void destory() {
			this->parent = NULL;
			for (int i = 0; i < 8; i++) {
				nodes[i] = NULL;
			}
		}
	}Octree_Node, * Octree_Struct;

	Octree_Struct octree;
	double octLength;
	vector<Point> pointCloud;
	double max_x;
	double max_z;
	double max_y;

	void setPoint(vector<Point> points);

	//初始化八叉树
	void CreatOctreeByPointCloud();

	//创建八叉树空节点
	void creat(Octree_Struct octree);

	//添加点云
	void addPointCloud(vector<Point> pointCloud);

	//添加节点
	void addNode(Octree_Struct octree, Point point);

	//所有点添加到八叉树后，释放空节点
	void addNodeEnd(Octree_Struct octree);
	
	//销毁八叉树
	void destory(Octree_Struct octree);
};