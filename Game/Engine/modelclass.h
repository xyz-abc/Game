#pragma once


#include <d3d11.h>
#include <directxmath.h>
#include <vector>
#include "importfile.h"
using namespace DirectX;


class ModelClass
{
private:

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

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

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
};