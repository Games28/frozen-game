#pragma once
#include "ChiliWin.h"
#include <cassert>
#include <fstream>
#include "colors.h"
#include <string>
class FailArt
{
public:
	FailArt() = default;
	FailArt(const std::string& filename);
	FailArt(int width, int height);
	FailArt(const FailArt& rhs);
	~FailArt();
	FailArt& operator=(const FailArt& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;

	int GetWidth() const;
	int GetHeight() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
	
};

