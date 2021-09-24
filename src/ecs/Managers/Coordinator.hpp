#pragma once
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "ecs/Types.hpp"
#include <memory>

// Coordinator acts as a middleman between all managers

class Coordinator
{
public:
    void Init();
    Entity CreateEntity();
    void DestroyEntity(Entity entity);

    void RegisterComponent();

    template <typename T>
    void AddComponent(Entity entity, T component);

    template <typename T>
    void RemoveComponent(Entity entity);

    template <typename T>
    T &GetComponent(Entity entity);

    template <typename T>
    ComponentType GetComponentType();

    template <typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        return m_SystemManager->RegisterSystem<T>();
    }

    Systems GetAllSystems();

    // template<typename T>
    // void SetSystemSignature()

private:
    std::unique_ptr<ComponentManager> m_ComponentManager;
    std::unique_ptr<EntityManager> m_EntityManager;
    std::unique_ptr<SystemManager> m_SystemManager;
};