#include "WInArt.h"

WinArt::WinArt(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);
	BITMAPFILEHEADER BmFIleHeader;
	file.read(reinterpret_cast<char*>(&BmFIleHeader), sizeof(BmFIleHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24);
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	height = bmInfoHeader.biHeight;

	pPixels = new Color[width * height];

	file.seekg(BmFIleHeader.bfOffBits);
	const int padding = (4 - (width * 3) % 4) % 4;

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}
}

WinArt::WinArt(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

WinArt::WinArt(const WinArt& rhs)// deep copy
	:
	WinArt(rhs.width, rhs.height)
{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
}

WinArt::~WinArt()
{
	delete[] pPixels;
	pPixels = nullptr;
}

WinArt& WinArt::operator=(const WinArt& rhs)
{
	width = rhs.width;
	height = rhs.height;

	delete[] pPixels;
	pPixels = new Color[width * height];
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
	return *this;
}

void WinArt::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	pPixels[y * width + x] = c;
}

Color WinArt::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return pPixels[y * width + x];
}



int WinArt::GetWidth() const
{
	return width;
}

int WinArt::GetHeight() const
{
	return height;
}