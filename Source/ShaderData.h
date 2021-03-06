#ifndef SHADER_DATA_H
#define SHADER_DATA_H
#include <vector>
#include <map>
#include <string>
enum BaseDataType
{
	Unknown,
	Boolean,
	Int,
	Half,
	Float,
	Double,
	IntArray,
	FloatArray,
	Vector2,
	Vector3,
	Vector4,
	Matrix3,
	Matrix4
};
struct SingleData
{
	BaseDataType type;
	void * buffer;//VK_BUFFER
	uint32_t size;
};

struct UniformBufferMember
{
	BaseDataType type;
	std::string name;
	uint32_t size;
	uint32_t offset;
};

struct UniformBuffer
{
	std::string name;
	void * buffer;//VK_BUFFER
	std::vector<UniformBufferMember> members;
	uint32_t size;
	uint32_t set;
	uint32_t binding;

};

struct Sampler2D
{
	std::string name;
	uint32_t set;
	uint32_t binding;
};
struct StageInput
{
	BaseDataType type;
	std::string name;
	uint32_t size;
	uint32_t offset;
};

struct ProgramInfo
{
	std::vector<UniformBuffer> uniformBuffers;
	std::vector<StageInput> stageInputs;
	std::vector<Sampler2D> sampler2Ds;
	uint32_t stageInputsSize;
	uint32_t setCount;
};
#endif