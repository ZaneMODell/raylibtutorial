#pragma once

#include <raylib.h>
#include "gameobject.hpp"

/// @brief Class representing the bucket object 
class Bucket: public GameObject{

    private:

    protected:

    public:
    /// @brief Bucket constructor
    /// @param width width of the bucket and its collider
    /// @param height height of the bucket and its collider
    /// @param x_pos starting x position of the bucket
    /// @param y_pos starting y position of the bucket
    /// @param texturename filepath of the texture this bucket will use
    /// @param window window that this bucket is a part of
    Bucket(float width, float height,  int x_pos, int y_pos, const char * texturename, GameWindow &window): 
        GameObject(width, height,  x_pos, y_pos, texturename, window){}
    /// @brief Updates the bucket's logic every frame
    void Update() override{
        ///If the player hits the right arrow key, it will move to the right, if they hit the left arrow key it moves to the left
        if (IsKeyDown(KEY_RIGHT)){
            m_x_pos += GetFrameTime() * 150;
            m_rect.x += GetFrameTime() * 150;
        }
        if (IsKeyDown(KEY_LEFT)){
            m_x_pos -= GetFrameTime() * 150;
            m_rect.x -= GetFrameTime() * 150;
        }
    }
};