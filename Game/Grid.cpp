#include "Grid.h"

Grid::Grid(int map_weight, int map_height)
{
	this->map_weight = map_weight;
	this->map_height = map_height;
	this->cell_weight = SCREEN_WIDTH / 2;
	this->cell_height = SCREEN_HEIGHT / 2;
	this->numberOfCols = (int)(map_weight / cell_weight) + 1;
	this->numberOfRows = (int)(map_height / cell_height) + 1;
	cells.resize(numberOfRows);
	for (int i = 0; i < numberOfRows; i++)
		cells[i].resize(numberOfCols);
	for (int i = 0; i < numberOfCols; i++)
		for (int j = 0; j < numberOfRows; j++)
			cells[i][j].clear();
}

void Grid::PutObjIntoGrid(vector<LPGAMEENTITY> ListObj)
{
	
	for (int i = 0; i < ListObj.size(); i++)
	{
		int Obj_Col = ListObj[i]->x / cell_weight;
		int Obj_Row = ListObj[i]->y / cell_height;
		cells[Obj_Col][Obj_Row].push_back(ListObj[i]);
	}

}

void Grid::GetObj(int Cam_x, int Cam_y, vector<LPGAMEENTITY> & ListObj)
{
	int Start_Cell_Col = Cam_x / cell_weight;
	int Start_Cell_Row = Cam_y / cell_height;
	if (Start_Cell_Col > 0)
		Start_Cell_Col -= 1;
	if (Start_Cell_Row > 0)
		Start_Cell_Row -= 1;
	int End_Cell_Col = Start_Cell_Col +2;
	int End_Cell_Row = Start_Cell_Row +2;
	if (End_Cell_Col >= numberOfCols)
		End_Cell_Col = numberOfCols -1;
	if (End_Cell_Row >= numberOfRows)
		End_Cell_Row = numberOfRows - 1;
	for (int i = Start_Cell_Col; i < End_Cell_Col + 1; i++)
		for (int j = Start_Cell_Row; j < End_Cell_Row + 1; j++)
			for (int k = 0; k < cells[i][j].size(); k++)
				ListObj.push_back(cells[i][j][k]);
}

void Grid::ResetGrid(int map_weight, int map_height)
{
	this->map_weight = map_weight;
	this->map_height = map_height;
	this->numberOfRows = (int)(map_weight / cell_weight) + 1;
	this->numberOfCols = (int)(map_height / cell_height) + 1;
	cells.resize(numberOfRows);
	for (int i = 0; i < numberOfRows; i++)
		cells[i].resize(numberOfCols);
	for (int i = 0; i < numberOfCols; i++)
		for (int j = 0; j < numberOfRows; j++)
			cells[i][j].clear();
}
