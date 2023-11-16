#pragma once

#include <raylib.h>
#include "gameobject.hpp"

/**
 * @brief class that represents the star object within the game
 * 
 */

class Star: public GameObject{

    private:

    protected:

    public:
    /// @brief Constructor for star
    /// @param width width of the star
    /// @param height height of the star
    /// @param x_pos starting x position of the star
    /// @param y_pos starting y position of the star
    /// @param texturename name of the texture this star uses
    /// @param window window that this star is a part of
    Star(float width, float height,  int x_pos, int y_pos, const char * texturename, GameWindow &window): 
        GameObject(width, height,  x_pos, y_pos, texturename, window){}

    /// @brief Function that handles the star's logic every frame
    void Update() override{
        //Handles the star falling
        m_y_pos += GetFrameTime() * 75;
        m_rect.y += GetFrameTime() * 75;
        
        //If statement will set the star back to top of screen if it leaves the window or if it collides with bucket
        if (m_y_pos >= m_window.GetHeight() + 10 || m_is_colliding){
            m_y_pos = 100;
            m_x_pos = GetRandomValue(100, 700);
            m_rect.y = m_y_pos;
            m_rect.x = m_x_pos;
            //If it collides, we increase the score of the game
            if (m_is_colliding){
                m_window.IncreaseScore();
            }
            //Else we reset the score to 0
            else{
                m_window.ResetScore();
            }
        }
    }
};