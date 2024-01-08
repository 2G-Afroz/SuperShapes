// main.cpp
#include <raylib.h>
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 850
#include <cmath>
#include <vector>
#include <iostream>

std::vector<Vector2> getSuperShapesPoints(Vector2 position, float a, float b, float m, float n1, float n2, float n3){
  std::vector<Vector2> points;

  for(float angle = 0; angle <= PI * 12; angle+=0.01){
    float part1 = pow(abs(cos(m*angle/4)/a), n2);
    float part2 = pow(abs(sin(m*angle/4)/b), n3);
    float r = 1/pow(part1+part2, 1/n1);

    float x = cos(angle) * r + position.x;
    float y = sin(angle) * r + position.y;

    points.push_back(Vector2{x, y});
  }

  return points;
}
	
int main() {
  // Initialize raylib
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Super Shapes");
  ClearBackground(BLACK);
  SetTargetFPS(60);
	
  // Variables
	Vector2 centre = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
	std::vector<Vector2> points;
	float a = 200.0f;
	float b = 200.0f;
	float m = 1/6.0f;
	float n1 = 0.3;
	float n2 = 0.3;
	float n3 = 0.3;

	points = getSuperShapesPoints(centre, a, b, m, n1, n2, n3);
	std::cout<<points.size();

 	// Main game loop
 	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
   	// Draw
   	BeginDrawing();
   	DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

		// Gettin SuperEllipse points

		// Drawing SuperEllipse
		for (size_t i = 0; i < points.size()-1; i++) {
			DrawLine(points.at(i).x, points.at(i).y, points.at(i+1).x, points.at(i+1).y, WHITE);
		}
		// For the last line
		DrawLine(points.at(0).x, points.at(0).y, points.at(points.size()-1).x, points.at(points.size()-1).y, WHITE);

		// Drawing values
		// DrawText(TextFormat("a: %0.2f\nb: %0.2f\nn: %0.2f", a, b, points.size()), 10, 40, 15, WHITE);

   	EndDrawing();
 	}

  // Clean up
	CloseWindow();
	return 0;
}
