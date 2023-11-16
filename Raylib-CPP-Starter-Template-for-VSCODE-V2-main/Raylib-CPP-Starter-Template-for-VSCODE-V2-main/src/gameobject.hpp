#pragma once

#include <raylib.h>

#include "gamewindow.hpp"

/**
 * @brief abstract class that describes an object within the game
 * 
 */
class GameObject{
    private:
        
    protected:
        /// @brief width of the object
        float m_width;
        /// @brief height of the object
        float m_height;     
        /// @brief x position of the object
        float m_x_pos;
        /// @brief y position of the object
        float m_y_pos;
        /// @brief filepath of the texture this object uses
        const char * m_texture_path;
        /// @brief Texture that is used by this object
        Texture2D m_texture;
        /// @brief Window that this object is a part of
        GameWindow & m_window;
        /// @brief Rectangle of this object, essentially its collider
        Rectangle m_rect;
        /// @brief is this object colliding
        bool m_is_colliding;
    public:
        /// @brief GameObject constructor
        /// @param width width of the object and its collider
        /// @param height height of the object and its collider
        /// @param x_pos starting x position of the object
        /// @param y_pos starting y position of the object
        /// @param texturename filepath to the texture used by this object
        /// @param window window that this object is a part of
        GameObject(float width, float height,  int x_pos, int y_pos, const char * texturename, GameWindow &window):
            m_width(width), m_height(height), m_x_pos(x_pos), m_y_pos(y_pos), m_texture_path(texturename), m_window(window){
                m_rect = {m_x_pos, m_y_pos, m_width, m_height};
                m_texture = LoadTexture(m_texture_path);
                DrawObject();
            }

        /// @brief virtual destructor
        virtual ~GameObject() = default;
        
        /// @brief Draws the object's texture at its current position
        void DrawObject(){
                DrawTexture(m_texture, m_x_pos, m_y_pos, WHITE);   
        }

        /// @brief Gets height of the object and it's collider
        int GetHeight(){return m_height;}
        /// @brief Gets width of the object and it's collider
        int GetWidth(){return m_width;}

        /// @brief Gets the object's rectangle/collider
        Rectangle GetRect(){return m_rect;}
        /// @brief Sets the bool that it is colliding with another GameObject
        /// @param collision bool that says if it is colliding or not
        void SetCollision(bool collision){m_is_colliding = collision;}

        /// @brief Returns if the object is currently colliding or not
        bool GetCollision(){return m_is_colliding;}

        /// @brief Pure virtual update function, different for each class
        virtual void Update() = 0;

};