#include "TaskIdGenerator.hpp"

unsigned int TaskIdGenerator::_nextId = 1; // Start with ID 1

unsigned int TaskIdGenerator::GenerateId() 
{
    return _nextId++;
}
