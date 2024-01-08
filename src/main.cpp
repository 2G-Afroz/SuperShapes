// main.cpp
#include <raylib.h>
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
std::vector<Vector2> getSuperShapesPoints(Vector2 position, float a, float b, float m, float n1, float n2, float n3, int pi_multiply) {
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
	float m = 1.5f;		// Controls the number of lobes/vertex.
	float n1 = 1.0f;	// Inversly proportional to size of SuperShape.
	float n2 = 1.0f;	// 
	float n3 = 0.0f;
	int pi_multiply = 20;

	// Getting the points of SuperShape.
	std::vector<Vector2> points = getSuperShapesPoints(center, a, b, m, n1, n2, n3, pi_multiply);

 	// Main game loop
 	while (!WindowShouldClose()) {
		ClearBackground(BLACK);

		// Getting the points of SuperShape.
		points = getSuperShapesPoints(center, a, b, m, n1, n2, n3, pi_multiply);

   	// Draw
    BeginDrawing();
    DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

    // Drawing SuperEllipse
    for (size_t i = 0; i < points.size() - 1; i++) {
        DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, WHITE);
    }
    // For the last line
    DrawLine(points[0].x, points[0].y, points.back().x, points.back().y, WHITE);

		// Drawing Values
		DrawText(TextFormat("a:\t%0.2f\nb:\t%0.2f\nm:\t%0.2f\nn1:\t%0.2f\nn2:\t%0.2f\nn3:\t%0.2f\nPI: \t%0.2f\n", a, b, m, n1, n2, n3, pi_multiply), 10, 40, 15, WHITE);

    EndDrawing();

		n3 += 0.001f;

 	}

  // Clean up
	CloseWindow();
	return 0;
}
