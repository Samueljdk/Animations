#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

void grid() {
    float screenWidth = 600;
    float screenHeight = 600;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0));

    const int rows = 10;
    const int columns = 10;
    float xPosition = 0;
    float yPosition = 0;
    RectangleShape squares[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            squares[i][j].setFillColor(Color::Transparent);
            squares[i][j].setSize(Vector2f(60, 60));
            squares[i][j].setOutlineColor(Color::White);
            squares[i][j].setOutlineThickness(4);
            squares[i][j].setPosition(Vector2f(xPosition, yPosition));
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

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                window.draw(squares[i][j]);
            }
        }

        window.display();
    }
}

int main() {
    grid();
    return 0;
}
