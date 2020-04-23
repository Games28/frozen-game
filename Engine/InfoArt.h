#pragma once
#include "ChiliWin.h"
#include <cassert>
#include <fstream>
#include "colors.h"
#include <string>




class InfoArt
{
public:
	InfoArt() = default;
	InfoArt(const std::string& filename);
	InfoArt(int width, int height);
	InfoArt(const InfoArt& rhs);
	~InfoArt();
	InfoArt& operator=(const InfoArt& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

private:
	Color* pPixels = nullptr;
	int width;
	int height;
};

