// main.cpp
#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 850
#include <cmath>
#include <vector>

/**
 * @brief	This function is uded to generate points for SuperShapes.
 * 
 * @param	position	The center position of SuperShape.
 * @param a					The width of SuperShape.
 * @param b					The height of SuperShape.
 * @param m					The number of 'lobes' or 'vertex' in the SuperShape.
 * @param n1, n2, n3	Exponents to controll the shape of SuperShape.
 * 
 * @return A vector of Vector2 points representing the SuperShape.
*/
std::vector<Vector2> getSuperShapesPoints(Vector2 position, float a, float b, float m, float n1, float n2, float n3, float pi_multiply) {
    std::vector<Vector2> points;

    for (float angle = 0; angle <= PI * pi_multiply; angle += 0.01) {
        float mAngleDiv4 = m * angle / 4;
        float part1 = pow(std::abs(cos(mAngleDiv4) / a), n2);
        float part2 = pow(std::abs(sin(mAngleDiv4) / b), n3);
        float r = 1 / pow(part1 + part2, 1 / n1);

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
  SetTargetFPS(30);
	
  // Variables
	Vector2 center = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
	float a = 400.0f;
	float b = 400.0f;
	float m = 2.0f;		// Controls the number of lobes/vertex.
	float n1 = 1.0f;	// Inversly proportional to size of SuperShape.
	float n2 = 1.0f;	// 
	float n3 = 1.0f;
	float pi_multiply = 20;

	// Getting the points of SuperShape.
	std::vector<Vector2> points = getSuperShapesPoints(center, a, b, m, n1, n2, n3, pi_multiply);

 	// Main game loop
 	while (!WindowShouldClose()) {
		ClearBackground(BLACK);

		// Getting the points of SuperShape.
		points = getSuperShapesPoints(center, a, b, m, n1, n2, n3, pi_multiply);

   	// Draw
    BeginDrawing();

    // Drawing SuperEllipse
    for (size_t i = 0; i < points.size() - 1; i++) {
        DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, WHITE);
    }
    // For the last line
    DrawLine(points[0].x, points[0].y, points.back().x, points.back().y, WHITE);

    // Adding GUI Controls
    GuiSlider({20, 5, 790, 10}, "a: ", TextFormat("%0.2f", a), &a, 0, 400);   //  Height
    GuiSlider({20, 20, 790, 10}, "b: ", TextFormat("%0.2f", b), &b, 0, 400);  // Width
    GuiSlider({20, 35, 790, 10}, "m: ", TextFormat("%0.2f", m), &m, 0, 50);  // Lobes
    m = std::floor(m);
    GuiSlider({20, 50, 790, 10}, "n1: ", TextFormat("%0.2f", n1), &n1, 0, 2);  // n1
    GuiSlider({20, 65, 790, 10}, "n2: ", TextFormat("%0.2f", n2), &n2, 0, 2);  // n2
    GuiSlider({20, 80, 790, 10}, "n3: ", TextFormat("%0.2f", n3), &n3, 0, 2);  // n3
    GuiSlider({20, 95, 790, 10}, "m: ", TextFormat("%0.2f", pi_multiply), &pi_multiply, 0, 50);  // pi_m
    pi_multiply = std::floor(pi_multiply);

    EndDrawing();
 	}

  // Clean up
	CloseWindow();
	return 0;
}
