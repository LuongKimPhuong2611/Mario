#pragma once
#include <vector>;
#include "Entity.h";
#include "define.h";

class Grid
{
	int map_weight;
	int map_height;
	int cell_weight;
	int cell_height;
	int numberOfRows;
	int numberOfCols;
	vector<vector<vector<LPGAMEENTITY>>> cells;

public:
	Grid(int map_weight, int map_height);
	void PutObjIntoGrid(vector<LPGAMEENTITY> ListObj);
	void GetObj(int Cam_x, int Cam_y, vector<LPGAMEENTITY> &ListObj);
	void ResetGrid(int map_weight, int map_height);
	~Grid();

};

