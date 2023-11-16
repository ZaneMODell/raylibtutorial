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
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    GameWindow window = GameWindow(450, 800, "Star Catcher", "src/starrysky.png");

    Bucket bucket = Bucket(static_cast<float>(41), static_cast<float>(46), 400, 300, "src/minecraftbucket.png", window);

    Star star = Star(static_cast<float>(20), static_cast<float>(22), GetRandomValue(100, 700), 100, "src/singlestar.png", window);
        
    bool collision;
        
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
