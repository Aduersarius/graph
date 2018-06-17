#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class graph
{
private:
  size_t nums;
	bool ** matrix;

	void DFS(size_t a, vector<bool> & visited, ostream & stream)
	{
		visited[a] = true;
		stream << a << " ";
		for (int i = 0; i < nums; ++i) {
			if (matrix[a][i] == 1 && !visited[i]) {
				DFS(i, visited, stream);
			}
		}
	}

public:

	graph()
	{
		matrix = nullptr;
		nums = 0;
	}

	~graph()
	{
		if (matrix)
		{
			for (size_t i = 0; i < nums; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	}
 
	void DFS(size_t a, std::ostream & stream)
	{
		if (a < nums) {
			vector<bool> visited(nums);
			DFS(a, visited, stream);
		}
		else {
			ostringstream sstream;
			sstream << "graph consist " << nums << " nums " << a;
			throw out_of_range(sstream.str());
		}
	}

	bool read(istream & stream)
	{
		bool success = true;
		if (stream >> nums)
		{
			bool **elements = new bool *[nums];
			for (size_t i = 0; success && i < nums; ++i) {
				elements[i] = new bool[nums];
				for (size_t j = 0; j < nums; ++j) {
					if (!(stream >> elements[i][j])) {
						success = false;
						break;
					}
					if (elements[i][j] != 1 && elements[i][j] != 0) {
						success = false;
						break;
					}
				}
			}
			if (success)
			{
				matrix = new bool *[nums];
				for (size_t i = 0; i < nums; i++)
				{
					matrix[i] = new bool[nums];
					for (size_t j = 0; j < nums; j++)
					{
						matrix[i][j]= elements[i][j];
					}
				}
				for (size_t i = 0; i < nums; ++i)
				{
					delete[] elements[i];
				}
				delete[] elements;
			}
			else
			{
				success = false;
			}
		}
		else
		{
			success = false;
		}
		return success;
	}
};
