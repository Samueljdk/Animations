#include <SFML/Graphics.hpp> // SFML is a graphics library for drawing shapes
#include <iostream>
using namespace sf;
using namespace std;

void bouncingBall() {
    // Loading a TTF file to determine the font for the text
    Font font;
    if (!font.loadFromFile("Aller_It.ttf")) {
        cout << "Error loading file"; // Message for me if loading fails
    }

    const int windowWidth = 600; // Window width constant
    const int windowHeight = 600; // Window height constant

    // The circle starts at the top-left corner of the window
    float xPosition = 0; // X-component of the circle's coordinates
    float yPosition = 0; // Y-component of the circle's coordinates

    // Boolean flags used to indicate that the ball has touched different corners
    bool reachedBottom = false;
    bool reachedRight = false;
    bool reachedTop = false;
    bool reachedLeft = false;

    // Creating the window with the specified width, height, and title
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Bouncing Ball Animation");
    // Setting the position of the window at the top-left corner of the screen    
    window.setPosition(Vector2i(0, 0));

    // Creating the circle shape object
    CircleShape circle(50); // Radius of 50

    while (window.isOpen()) { // Constantly checking if the window is open

        // Diagonal move to the bottom from the top-left corner
        // xPosition must be less than 250 to ensure the ball hits the middle of the bottom edge
        // reachedBottom is false before the ball reaches bottom 
        // and true after it hits bottom
        if (xPosition < 250 && !reachedBottom) {
            xPosition += 0.1;  // X-position increments by 0.1 while less than 250
            yPosition = xPosition * 2; // The drop down happens at twice the speed of the lateral move
            // The yPosition has to increase at double the xPosition
            // to ensure the ball hits the middle of the bottom edge
        }
        else {
            reachedBottom = true; // Once the ball hits bottom, we make this flag true
        }

        // Diagonal move to the right
        if (reachedBottom && !reachedRight) {
            xPosition += 0.1; // X-position increments after hitting bottom but before hitting the right edge
            yPosition -= 0.1; // Y-position decrements so that the ball can move up

            // When the ball's xPosition passes 500, we can be sure it is on its way to hit the right edge
            if (xPosition >= 500) reachedRight = true;
        }

        // Moving diagonally to the left
        // If the ball has hit bottom and right, but not top yet
        if (reachedBottom && reachedRight && !reachedTop) {
            xPosition -= 0.1; // We decrement the xPosition to make it go left
            yPosition -= 0.1;  // We decrement the yPosition to make it go up

            // When the ball is close to hitting the upper edge, we turn the flag to true
            if (yPosition <= 0) reachedTop = true;
        }

        // Moving down to the left
        // If the ball has hit all the edges except for the left edge
        if (reachedBottom && reachedRight && reachedTop && !reachedLeft) {
            xPosition -= 0.1; // We decrement the xPosition to make it go left
            yPosition += 0.1; // We increment the yPosition to make it go down

            // When the ball is close to hitting the lower edge, we turn the reachedBottom flag to true
            if (xPosition <= 0) reachedLeft = true;
        }

        // Once all edges have been hit, we start to make the ball go down again
        // It follows the same path
        if (reachedBottom && reachedLeft && reachedRight && reachedTop) {
            xPosition += 0.1; //
            yPosition += 0.1;

            // When the ball is back on the left side of the window and starts to go down again, we turn the flags false
            // Thus starting the cycle again
            if (xPosition > 250 || yPosition >= 500) {
                reachedBottom = false;
                reachedLeft = false;
                reachedTop = false;
                reachedRight = false;
            }
        }

        // Setting the position of the ball
        circle.setPosition(xPosition, yPosition);

        // Defining a text object that takes the font, which will
        // keep track of the ball's location
        Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        String message = "X: " + to_string(xPosition) + " Y: " + to_string(yPosition);

        // Setting fill color based on the reached edge
        if (reachedBottom) circle.setFillColor(Color::Green);
        if (reachedRight) circle.setFillColor(Color::Yellow);
        if (reachedTop) circle.setFillColor(Color::Red);
        if (reachedLeft) circle.setFillColor(Color::Blue);

        text.setString(message);

        Event event;
        while (window.pollEvent(event)) { // Keeps checking to see if the user closed the window
            if (event.type == Event::Closed) {
                window.close(); // Closes the window
            }
        }

        window.clear(); // Clears the window to prepare for the next ball drawing
        window.draw(text);
        window.draw(circle); // Draws the ball
        window.display(); // Displays the ball
    }
}

int main() {
    bouncingBall();
    return 0;
}
