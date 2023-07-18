#include "Octree.h"


void Octree::setPoint(vector<Point> points)
{
	int size = points.size();
	for (int i = 0; i < size; i++) {
		pointCloud.push_back(points[i]);
	}
}

void Octree::CreatOctreeByPointCloud()
{
	this->max_x = pointCloud.at(0).x;
	this->max_y = pointCloud.at(0).y;
	this->max_z = pointCloud.at(0).z;

	//计算八叉树深度和宽度
	std::vector<Point>::iterator it = pointCloud.begin();
	for (; it != pointCloud.end(); it++) {
		this->max_x = this->max_x < (*it).x ? (*it).x : this->max_x;
		this->max_y = this->max_y < (*it).y ? (*it).y : this->max_y;
		this->max_z = this->max_z < (*it).z ? (*it).z : this->max_z;
	}
	double length = octLength;
	double maxLength;
	int level = 1;
	maxLength = max_x > max_y ? max_x : max_y;
	maxLength = maxLength > max_z ? maxLength : max_z;
	while (length < maxLength) {
		length *= 2;
		level++;
	}

	//初始化八叉树
	octree = new Octree_Node();
	octree->init(NULL, length, level);

	creat(octree);

	addPointCloud(pointCloud);
}

void Octree::creat(Octree_Struct octree)
{
	if (octree->level == 1) {
		return;
	}
	for (int i = 0; i < 8; i++) {
		octree->nodes[i] = new Octree_Node();
		octree->nodes[i]->init(octree, octree->length / 2, octree->level - 1);

		if (i == 0 || i == 1 || i == 4 || i == 5)
			octree->nodes[i]->centel.y = octree->centel.y + octree->length / 2;
		if (i == 2 || i == 3 || i == 6 || i == 7)
			octree->nodes[i]->centel.y = octree->centel.y - octree->length / 2;
		if (i == 0 || i == 2 || i == 4 || i == 6)
			octree->nodes[i]->centel.x = octree->centel.x + octree->length / 2;
		if (i == 1 || i == 3 || i == 5 || i == 7)
			octree->nodes[i]->centel.x = octree->centel.x - octree->length / 2;
		if (i == 0 || i == 1 || i == 2 || i == 3)
			octree->nodes[i]->centel.z = octree->centel.z + octree->length / 2;
		if (i == 4 || i == 5 || i == 6 || i == 7)
			octree->nodes[i]->centel.z = octree->centel.z - octree->length / 2;

		creat(octree->nodes[i]);
	}
}

void Octree::addPointCloud(vector<Point> pointCloud)
{
	vector<Point>::iterator it = pointCloud.begin();
	for (; it != pointCloud.end(); it++) {
		octree->count++;
		addNode(octree, *it);
	}
	addNodeEnd(octree);
}

void Octree::addNode(Octree_Struct octree, Point point)
{
	if (octree->level == 1) {
		octree->points.push_back(point);
		return;
	}
	if (point.x >= octree->centel.x && point.y >= octree->centel.y && point.z >= octree->centel.z) {
		octree->nodes[0]->count++;
		addNode(octree->nodes[0], point);
	}
	else if (point.x < octree->centel.x && point.y >= octree->centel.y && point.z >= octree->centel.z) {
		octree->nodes[1]->count++;
		addNode(octree->nodes[1], point);
	}
	else if (point.x >= octree->centel.x && point.y < octree->centel.y && point.z >= octree->centel.z) {
		octree->nodes[2]->count++;
		addNode(octree->nodes[2], point);
	}
	else if (point.x < octree->centel.x && point.y < octree->centel.y && point.z >= octree->centel.z) {
		octree->nodes[3]->count++;
		addNode(octree->nodes[3], point);
	}
	else if (point.x >= octree->centel.x && point.y >= octree->centel.y && point.z < octree->centel.z) {
		octree->nodes[4]->count++;
		addNode(octree->nodes[4], point);
	}
	else if (point.x < octree->centel.x && point.y >= octree->centel.y && point.z < octree->centel.z) {
		octree->nodes[5]->count++;
		addNode(octree->nodes[5], point);
	}
	else if (point.x >= octree->centel.x && point.y < octree->centel.y && point.z < octree->centel.z) {
		octree->nodes[6]->count++;
		addNode(octree->nodes[6], point);
	}
	else if (point.x < octree->centel.x && point.y < octree->centel.y && point.z < octree->centel.z) {
		octree->nodes[7]->count++;
		addNode(octree->nodes[7], point);
	}
}

void Octree::addNodeEnd(Octree_Struct octree)
{
	for (int i = 0; i < 8; i++) {
		if (octree->nodes[i] != NULL) {
			addNodeEnd(octree->nodes[i]);
			if (octree->nodes[i]->count == 0) {
				octree->nodes[i]->parent = NULL;
				delete octree->nodes[i];
				octree->nodes[i] = NULL;
			}
		}
	}
}

void Octree::destory(Octree_Struct octree)
{
	for (int i = 0; i < 8; i++) {
		if (octree->nodes[i] != NULL) {
			destory(octree->nodes[i]);
			octree->nodes[i]->parent = NULL;
			octree->nodes[i]->points.clear();
			delete octree->nodes[i];
		}
	}
	if (octree->parent == NULL) {
		pointCloud.clear();
		delete octree;
	}
}
