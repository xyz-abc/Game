#include "importfile.h"
#include <time.h> 

int importObj(char* FileName, Model& model) //input empty vector
{
	ifstream file(FileName);
	if (file.is_open())
	{
		float xx = 0.0f;
		float yy = 0.0f;
		float zz = 0.0f;
		for (string line;  getline(file, line); ) //read stream line by line
		{
			istringstream in(line); //make a stream for the line itself

			string type;
			in >> type;	           //and read the first whitespace-separated token

			//start reading vertices
			if (type == "v")       //and check its value
			{
				float x, y, z;
				in >> x >> y >> z; //now read the whitespace-separated floats
				XMFLOAT3 position = { x,y,z };
				xx = xx + 0.1f;
				yy = yy + 0.1f;
				zz = zz + 0.1f;
				XMFLOAT4 color = {xx, yy, zz, 1.0f};
				//XMFLOAT4 color = { (x + 1.0f)/2.0f , (y + 1.0f) / 2.0f, (z + 1.0f) / 2.0f, 1.0f };
				//XMFLOAT4 color = { static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ,static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ,static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ,static_cast <float> (rand()) / static_cast <float> (RAND_MAX) };
				model.vertices.push_back(VertexType{ position, color});
			}
			else if(type == "f")
			{
				string s1, s2, s3, split1, split2, split3;
				in >> s1 >> s2 >> s3;

				int i1, i2, i3;
				split1 = s1.substr(0, s1.find("/"));
				split2 = s2.substr(0, s2.find("/"));
				split3 = s3.substr(0, s3.find("/"));
				i1 = stoi(split1) - 1; //indices start at 1 and start need to be mapped to 0
				i2 = stoi(split2) - 1;
				i3 = stoi(split3) - 1;
				model.indices.push_back(triangleType{ i1, i2, i3});
			}
		}

		file.close();
		return S_OK;
	}

	else 
	{
		return E_FAIL; //could not open file
	}
	
}
