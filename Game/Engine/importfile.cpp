using namespace std;

#include "importfile.h"

int importObj(char* FileName, ModelClass::Model& model) //input empty vector
{
	ifstream file(FileName);
	if (file.is_open())
	{
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
				XMFLOAT4 color;
				model.vertices.push_back(ModelClass::VertexType{ position, color});
			}
			else if(type == "f")
			{
				string s1, s2, s3, split1, split2, split3;
				in >> s1 >> s2 >> s3;

				int i1, i2, i3;
				split1 = s1.substr(0, s1.find("/"));
				split2 = s2.substr(0, s2.find("/"));
				split3 = s3.substr(0, s3.find("/"));
				i1 = stoi(split1);
				i2 = stoi(split2);
				i3 = stoi(split3);
				model.indices.push_back(ModelClass::triangleType{ i1, i2, i3});
			}
		}

		file.close();
		return 0;
	}

	else 
	{
		return -1; //could not open file
	}
	
}
