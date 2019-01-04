#include <iostream>
#include "ShaderReflection.h"
using namespace std;

int main()
{
	ProgramInfo* info = NULL;
	info = getProgramInfo("D:/GearShaderTool/GearShaderTool/Shaders/vert.spv");
	getchar();
	delete info;
	return 0;
}