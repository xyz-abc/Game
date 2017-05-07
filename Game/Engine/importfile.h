#pragma once


#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <d3d11.h>
#include <directxmath.h>
#include <vector>
using namespace DirectX;
using namespace std;

struct VertexType
{
	XMFLOAT3 position;
	XMFLOAT4 color;
};

struct triangleType
{
	int index1;
	int index2;
	int index3;
};

struct Model
{
	vector<VertexType> vertices;
	vector<triangleType> indices;
};


int importObj(char* FileName, Model& model);