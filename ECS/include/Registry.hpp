/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Registry.hpp
*/

#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <unordered_map>
    #include <typeindex>
    #include <functional>
    #include <any>

    #include "SparseArray.hpp"
    #include "Entity.hpp"

namespace ECS {

class Registry {
    public:
        template <typename Component>
        SparseArray<Component>& registerComponent() {
            _component_array.insert_or_assign(std::type_index(typeid(Component)), SparseArray<Component>());
            _remover.push_back([](Registry& reg, const Entity& e){
                auto& cmpt = reg.getComponents<Component>();
                if (cmpt.size() >= e && cmpt[e].has_value()) {
                    cmpt[e].reset();
                }
            });
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        template <typename Component>
        SparseArray<Component>& getComponents() {
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        template <typename Component>
        SparseArray<Component> const & getComponents() const {
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        void addSystem(const std::function<void(Registry&)>& f) {
            _systems.push_back(f);
        }

        void runSystems(void);

        void killEntity(const Entity& e);

        template <typename Component>
        void addComponent(const Entity& e, const Component& c) {
            std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component)))).insert_at(e, c);
        }

        template <typename Component>
        void addComponent(const Entity& e, Component&& c) {
            std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component)))).insert_at(e, std::forward<Component>(c));
        }

        template <typename Component>
        void removeComponent(const Entity& e) {
            std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component)))).erase(e);
        }

    private:
        std::unordered_map<std::type_index, std::any> _component_array;
        std::vector<std::function<void(Registry&, const Entity&)>> _remover;

        std::vector<std::function<void(Registry&)>> _systems;
};

} // namespace ECS

#endif
