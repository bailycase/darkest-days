#pragma once
#include <set>
#include "ecs/Types.hpp"

class System
{
public:
    std::set<Entity> m_Entities;
};