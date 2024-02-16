#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

void grid() {
    float screenWidth = 1000;
    float screenHeight = 600;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0));

    const int columns = 6;
    const int rows = 10;
    float xPosition = 0;
    float yPosition = 0;
    float x,y;
    RectangleShape squares[rows][columns];
    CircleShape circles[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            squares[i][j].setFillColor(Color::Transparent);
            squares[i][j].setSize(Vector2f(100, 100));
            squares[i][j].setOutlineColor(Color::White);
            squares[i][j].setOutlineThickness(1);
            squares[i][j].setPosition(Vector2f(xPosition, yPosition));
            xPosition += 100;

            circles[i][j].setPosition(i*100, j*100);
           
            cout << "(" << i * 100 << "," << j * 100 << ")" << endl;
               circles[i][j].setRadius(50);
               circles[i][j].setOutlineThickness(1);
            circles[i][j].setOutlineColor(Color::White);
            circles[i][j].setFillColor(Color::Green);
       
        }
        xPosition = 0; // Reset xPosition for the next row
        yPosition += 100;
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
