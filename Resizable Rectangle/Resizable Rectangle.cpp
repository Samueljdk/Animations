#include <SFML/Graphics.hpp> // SFML is a graphics library for 
#include <iostream>

using namespace sf;
using namespace std;

void ResizableRectangle() {
    // Setting the window dimensions
    const float windowWidth = 1000;
    const float windowHeight = 600;

    // Setting the rectangle's initial dimensions
    float rectangleWidth = 50;
    float rectangleHeight = 50;

    // Setting the window dimensions and title
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Resizable Rectangle");
    window.setPosition(Vector2i(0, 0)); // Making the window show up on the top left corner

    // Defining the rectangle's characteristics
    RectangleShape rectangle;
    rectangle.setFillColor(Color::Green);
    rectangle.setOutlineColor(Color::White);
    rectangle.setOutlineThickness(5);

    while (window.isOpen()) { // Continuously checking to see if the window is open
        // Setting the size of the rectangle every iteration to capture the changes in size
        rectangle.setSize(Vector2f(rectangleWidth, rectangleHeight));

        Event event;

        if (Keyboard::isKeyPressed(Keyboard::W)) {
            /* If the W key is pressed and the rectangle is not less than 10 pixels away from the border,
               the width increases by 0.1 */
            if (rectangleWidth < windowWidth - 10) rectangleWidth += 0.1;

            /* If the W key is pressed and the rectangle is not less than 10 pixels away from the bottom of the window,
               the length increases by 0.1 */
            if (rectangleHeight < windowHeight - 10) rectangleHeight += 0.1;
        }

        if (Keyboard::isKeyPressed(Keyboard::N)) {
            /* If the N key is pressed and the rectangle is still bigger than its initial width,
               the width decreases by 0.1 */
            if (rectangleWidth > 50) rectangleWidth -= 0.1;

            /* If the N key is pressed and the rectangle is still bigger than its initial height,
               the height decreases by 0.1 */
            if (rectangleHeight > 50) rectangleHeight -= 0.1;
        }

        while (window.pollEvent(event)) { // Keeps checking to see if the user closed the window
            if (event.type == Event::Closed) {
                window.close(); // Closes the window
            }
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }
}

int main() {
    ResizableRectangle();
    return 0;
}
