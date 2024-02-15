#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

void grid() {
    float screenWidth = 600;
    float screenHeight = 600;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Circle Pyramid");
    window.setPosition(Vector2i(0, 0));

    const int height=10;
    float xPosition = 0;
    float yPosition = 0;
    CircleShape circles[height][height];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height -i; j++) {
            circles[i][j].setFillColor(Color::Transparent);
            circles[i][j].setRadius(30);

            circles[i][j].setOutlineColor(Color::White);
            circles[i][j].setOutlineThickness(4);
            circles[i][j].setPosition(Vector2f(xPosition, yPosition));
            xPosition += 60;
        }
        xPosition = 0; // Reset xPosition for the next row
        yPosition += 60;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < height; j++) {
                window.draw(circles[i][j]);
            }
        }

        window.display();
    }
}

int main() {
    grid();
    return 0;
}
