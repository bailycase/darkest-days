#pragma once
#include <memory>
#include <unordered_map>
#include "ecs/System.hpp"
#include <assert.h>
#include "ecs/Types.hpp"

// ***
// System Manager manages all of the systems
// Systems run through each entities that possess a specific component and excutes on its actions
// ex: render system
// **

class SystemManager
{
public:
    template <typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        const char *typeName = typeid(T).name();

        assert(m_Systems.find(typeName) == m_Systems.end() && "Registering system more than once!");

        auto system = std::make_shared<T>();
        m_Systems.insert({typeName, system});
        return system;
    }

    Systems GetAllSystems()
    {
        return m_Systems;
    }

private:
    Systems m_Systems{};
};