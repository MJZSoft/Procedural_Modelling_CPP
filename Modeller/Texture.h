/*
 * Texture.h
 *
 *  Created on: Sep 16, 2015
 *  Author: mjz
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <string>
using namespace std;

class Texture {
private:
	string path; // The path to the bitmap file e.g /data/*.bmp
	int width; // width of the picture must be power of 2; e.g 16, 32, 64, 128 , ....
	int height; // height of the picture must be power of 2, and is better to be same as width
	bool valid;
public:
	Texture();
	Texture(string path, int width, int height);
	virtual ~Texture();
	int getWidth();
	int getHeight();
	const char* getPath();
	bool isPowerOfTwo (unsigned int x);
	bool isValid();
	//string to_string();
};

#endif /* TEXTURE_H_ */
