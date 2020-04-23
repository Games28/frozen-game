#pragma once
#include "ChiliWin.h"
#include <cassert>
#include <fstream>
#include "colors.h"
#include <string>


class WinArt
{
public:
	WinArt() = default;
	WinArt(const std::string& filename);
	WinArt(int width, int height);
	WinArt(const WinArt& rhs);
	~WinArt();
	WinArt& operator=(const WinArt& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;

	int GetWidth() const;
	int GetHeight() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
	
};

