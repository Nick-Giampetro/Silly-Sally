#pragma once

#include<iostream>
#include"Entity.h"
using namespace std;

class Sally : public Entity
{

	static const int sallySizeI = 5;
	static const int sallySizeJ = 4;

public:
	Sally();
	~Sally();

	void sprite();

private:
	char img[sallySizeI][sallySizeJ];

	
};

