#include <iostream>
#include "ShaderReflection.h"
using namespace std;

int main()
{
	ProgramInfo* info = NULL;
	info = getProgramInfo("E:/dev/GearShaderTool/Shaders/vert.spv");
	delete info;
	return 0;
}