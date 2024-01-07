// main.cpp
#include <raylib.h>
#include <cmath>
	
int main() {
    	// Initialize raylib
    	InitWindow(850, 850, "Super Shapes");
      SetTargetFPS(60);

      // Variables
      int length = 400;
      float angle = 0;
      Vector2 pos = {425, 425};
	
    	// Main game loop
    	while (!WindowShouldClose()) {
        	// Draw
        	BeginDrawing();

        	  ClearBackground(BLACK);
            
            int x = cos(angle)*length;
            int y = sin(angle)*length;

            // Drawing Shapes
            DrawLine(pos.x, pos.y, pos.x+x, pos.y+y, WHITE);
            DrawCircle(pos.x, pos.y, 2, WHITE);
            DrawCircle(pos.x+x, pos.y+y, 2, WHITE);

            // Draw Texts
            DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, WHITE);

        	EndDrawing();
          angle+= 0.01;
          if(angle > 360)
            angle = 0;
    	}
	
    	// Clean up
	CloseWindow();
	return 0;
}
