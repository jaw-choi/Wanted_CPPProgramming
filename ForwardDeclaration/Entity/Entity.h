#pragma once

class Vector;
namespace Wanted
{


    //전방 선언(Forward Declaration)
    class Entity
    {
    public:
        Entity() = default;
        Entity(int x, int y);
        Entity(const Entity& other);
        ~Entity();

    private:
        Vector* position = nullptr;

    };
}