#include "Coordinator.hpp"

void Coordinator::Init()
{
    m_ComponentManager = std::make_unique<ComponentManager>();
    m_SystemManager = std::make_unique<SystemManager>();
    m_EntityManager = std::make_unique<EntityManager>();
}

Entity Coordinator::CreateEntity()
{
}

void Coordinator::DestroyEntity(Entity entity)
{
}

void Coordinator::RegisterComponent()
{
}

template <typename T>
void Coordinator::AddComponent(Entity entity, T component) {}

template <typename T>
void Coordinator::RemoveComponent(Entity entity)
{
}

template <typename T>
T &Coordinator::GetComponent(Entity entity)
{
}

template <typename T>
ComponentType Coordinator::GetComponentType() {}

Systems Coordinator::GetAllSystems()
{
    return m_SystemManager->GetAllSystems();
}
