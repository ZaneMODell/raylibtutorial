#pragma once

#include <raylib.h>

class GameWindow {
    private:
        /// @brief Height of the window
        int m_height;
        /// @brief Width of the window
        int m_width;
        /// @brief Title of the window
        const char * m_title;
        /// @brief filepath to the background texture
        const char * m_background_path;
        /// @brief Background texture
        Texture2D m_background_texture;
        /// @brief reference to the score in the window
        int &m_score;

    protected:

    public:
        /// @brief Constructor of GameWindow
        /// @param height height of the window
        /// @param width width of the window
        /// @param title window title
        /// @param texturename filepath to the background texture
        /// @param score reference to the score
        GameWindow(int height, int width, const char * title, const char * texturename, int &score):
            m_height(height), m_width(width), m_title(title), 
            m_background_path(texturename), m_score(score){
                InitWindow(m_width, m_height, title);
                m_background_texture = LoadTexture(m_background_path);
            }

        /// @brief Destructor
        ~GameWindow() = default;
        /// @brief Draws the background and score
        void Draw(){
                DrawTexture(m_background_texture, 0, 0, WHITE);
                DrawText(TextFormat("Score: %d", m_score), 650, 30, 20, WHITE);
        }

        /// @brief Gets the height of the window
        /// @return the height of the window as an integer in pixels
        int GetHeight(){return m_height;}

        /// @brief Gets the width of the window
        /// @return the width of the window as an integeger in pixels
        int GetWidth(){return m_width;}

        /// @brief Increases the score by 1
        void IncreaseScore(){m_score++;}
        /// @brief Reset the score
        void ResetScore(){m_score = 0;}

};