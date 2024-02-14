#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

void grid() {
    float screenWidth = 600;
    float screenHeight = 600;
    float xCircle = 75;
    float yCirlce = 255;

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0));

    CircleShape circle(15);
    circle.setFillColor(Color::Green);
    circle.setPosition(xCircle, yCirlce);
    float xChange = 60;

    const int rows = 10;
    const int columns = 10;
    float xPosition = 0;
    float yPosition = 0;

    RectangleShape squares[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i==9 || j==9 || j == 0) {
                squares[i][j].setFillColor(Color::White);

            } 
            else if (i==1 || i==4 || i==8) {
                squares[i][j].setFillColor(Color::Transparent);

            }
            else if (j == 1 || j == 4 || j == 8) {
                squares[i][j].setFillColor(Color::Transparent);

            }

            
            else {
                squares[i][j].setFillColor(Color::White);
            }
            squares[i][j].setSize(Vector2f(60, 60));
            squares[i][j].setOutlineColor(Color::Red);
            squares[i][j].setOutlineThickness(4);
            squares[i][j].setPosition(Vector2f(xPosition, yPosition));
            xPosition += 60;
        }
        xPosition = 0; // Reset xPosition for the next row
        yPosition += 60;
    }

    float speed = 0.1;
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Left) && circle.getPosition().x > 75)
            circle.move(-speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Right) && circle.getPosition().x < 495)
           circle.move(speed, 0);
    
            if (Keyboard::isKeyPressed(Keyboard::Up) && circle.getPosition().y > 75)
            circle.move(0, -speed);
        if (Keyboard::isKeyPressed(Keyboard::Down) && circle.getPosition().y <495)
            circle.move(0, speed);


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

        window.draw(circle);

        window.display();
    }
}

int main() {
    grid();
    return 0;
}
