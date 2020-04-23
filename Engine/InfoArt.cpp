#include "InfoArt.h"


InfoArt::InfoArt(const std::string& filename)
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

InfoArt::InfoArt(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

InfoArt::InfoArt(const InfoArt& rhs)// deep copy
	:
	InfoArt(rhs.width, rhs.height)
{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
}

InfoArt::~InfoArt()
{
	delete[] pPixels;
	pPixels = nullptr;
}

InfoArt& InfoArt::operator=(const InfoArt& rhs)
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

void InfoArt::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	pPixels[y * width + x] = c;
}

Color InfoArt::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return pPixels[y * width + x];
}



int InfoArt::GetWidth() const
{
	return width;
}

int InfoArt::GetHeight() const
{
	return height;
}
