#pragma once
#include <bitset>
#include <memory>
#include <unordered_map>
#include "ecs/System.hpp"

const int MAX_COMPONENTS = 32;
using Entity = int;
using ComponentType = int;
using Signature = std::bitset<MAX_COMPONENTS>;

using Systems = std::unordered_map<const char *, std::shared_ptr<class System>>;
