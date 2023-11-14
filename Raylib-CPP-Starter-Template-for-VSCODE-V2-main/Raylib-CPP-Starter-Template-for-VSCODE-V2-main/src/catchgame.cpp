// /*******************************************************************************************
// *
// *   raylib [core] example - Basic window
// *
// *   Welcome to raylib!
// *
// *   To test examples, just press F6 and execute raylib_compile_execute script
// *   Note that compiled executable is placed in the same folder as .c file
// *
// *   You can find all basic examples on C:\raylib\raylib\examples folder or
// *   raylib official webpage: www.raylib.com
// *
// *   Enjoy using raylib. :)
// *
// *   Example originally created with raylib 1.0, last time updated with raylib 1.0
// *
// *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
// *   BSD-like license that allows static linking with closed source software
// *
// *   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
// *
// ********************************************************************************************/

#include <raylib.h>
#include <iostream>
#include "gamewindow.hpp"
#include "star.hpp"
#include "bucket.hpp"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization of game
    int score = 0;
    GameWindow window = GameWindow(450, 800, "Star Catcher", "src/starrysky.png", score);

    Bucket bucket = Bucket(static_cast<float>(41), static_cast<float>(46), 400, 300, "src/minecraftbucket.png", window);

    Star star = Star(static_cast<float>(20), static_cast<float>(22), GetRandomValue(100, 700), 100, "src/singlestar.png", window);
        
    bool collision;
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //This line calls a Raylib function to see if two Rectangle structs are colliding
        collision = CheckCollisionRecs(bucket.GetRect(), star.GetRect());

        //Making the bucket and star aware of their collisions
        bucket.SetCollision(collision);
        star.SetCollision(collision);

        //Calling the respective update functions 
        bucket.Update();
        star.Update();
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        //Each object has their own draw functions
        window.Draw();
        star.DrawObject();
        bucket.DrawObject();       
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization of game
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}