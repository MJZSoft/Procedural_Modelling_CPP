/*
 * Texture.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Texture.h"
Texture::Texture(){
	this->width =0;
	this->height = 0;
	this->path="";
	this->valid = false;
};
Texture::Texture(string path, int width, int height) {
	if(this->isPowerOfTwo(width) && this->isPowerOfTwo(height))
	{
		this->width = width;
		this->height = height;
		this->path=path;
		this->valid=true;
	}
	else
	{
		this->width =0;
		this->height = 0;
		this->path="";
		this->valid = false;
	}
};
Texture::~Texture() {
	// TODO Auto-generated destructor stub
};
bool Texture::isPowerOfTwo (unsigned int x)
{
 return(
   x == 1 || x == 2 || x == 4 || x == 8 || x == 16 || x == 32 ||
   x == 64 || x == 128 || x == 256 || x == 512 || x == 1024 ||
   x == 2048 || x == 4096 || x == 8192 || x == 16384 ||
   x == 32768 || x == 65536 || x == 131072 || x == 262144 ||
   x == 524288 || x == 1048576 || x == 2097152 ||
   x == 4194304 || x == 8388608 || x == 16777216 ||
   x == 33554432 || x == 67108864 || x == 134217728 ||
   x == 268435456 || x == 536870912 || x == 1073741824 ||
   x == 2147483648);
};
int Texture::getWidth(){
	return this->width;
};
int Texture::getHeight(){
	return this->height;
};
const char* Texture::getPath(){
	return this->path.c_str();
};
bool Texture::isValid(){
	return this->valid;
};
