#include <SFML/Graphics.hpp> // sfml is a graphics libraary for drawing the shapes
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void bouncingBall() {
    /*VideoMode desktopMode = VideoMode::getDesktopMode();
    int screenWidth = desktopMode.width;
    int screenHeight = desktopMode.height;*/

    sf::Font font;
    if (!font.loadFromFile("Aller_It.ttf")) {
        cout << "error loading file";
    }

    int screenWidth = 600;
    int screenHeight = 600;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Bouncing Ball Animation");
    window.setPosition(Vector2i(0, 0)); // sets the position of the window at top left corner

    float horizontalPosition = 0;
    float verticalPosition = 0;
    float hChange = 0;
    float vChange = 0;


    CircleShape circle(50); // radius of 50

    
    bool reachedBottom = false;
    bool reachedRight = false;
    bool reachedTop = false;
    bool reachedLeft = false;


    while (window.isOpen()) {

        //diagonal move to the bottom
        if (horizontalPosition < 250 && verticalPosition < 500 && !reachedBottom) {
            horizontalPosition += 0.1;
            verticalPosition = horizontalPosition * 2;

        }

        else {
            reachedBottom = true;

        }
        // diagonal move to the right
        if (reachedBottom && horizontalPosition < 500 && verticalPosition>250 && !reachedRight) {
            horizontalPosition += 0.1;
            verticalPosition -= 0.1;
            if (horizontalPosition >= 500 && verticalPosition <= 250)reachedRight = true;
        }

        // moving diagonally to the left
        if (reachedBottom && reachedRight && verticalPosition > 0 && !reachedTop) {
            horizontalPosition -= 0.1;
            verticalPosition -= 0.1;
            if (verticalPosition <= 0)reachedTop = true;
        }

        // moving down to left
        if (reachedBottom && reachedRight && reachedTop && horizontalPosition > 0 && !reachedLeft) {
            horizontalPosition -= 0.1;
            verticalPosition += 0.1;
            if (horizontalPosition <= 0)reachedLeft = true;
        }


        if (reachedBottom && reachedLeft && reachedRight && reachedTop && verticalPosition < 500 && horizontalPosition < 500) {

            horizontalPosition += 0.1;
            verticalPosition += 0.1;

            if (horizontalPosition > 250 || verticalPosition >= 500) {
                reachedBottom = false;
                reachedLeft = false;
                reachedTop = false;
                reachedRight = false;

            }
        }







        circle.setPosition(horizontalPosition, verticalPosition);
        Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        String message = "X: " + to_string(horizontalPosition) + " Y: " + to_string(verticalPosition);

        if (reachedBottom)circle.setFillColor(Color::Green);
        if (reachedRight)circle.setFillColor(Color::Yellow);
        if (reachedTop)circle.setFillColor(Color::Red);
        if (reachedLeft)circle.setFillColor(Color::Blue);


        text.setString(message);

        Event event;
        while (window.pollEvent(event)) { // keeps checking to see if the user closed the windo
            if (event.type == Event::Closed) {
                window.close(); // closes the window
            }
        }




        window.clear(); // clears the window to prepare to make the next ball drawing
        window.draw(text);
        window.draw(circle); // draws the ball
        window.display(); // displays the ball
    }

}

int main() {
    bouncingBall();

    return 0;
}

