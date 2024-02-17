#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

void CirclePyramid() {
    // Setting the screen dimensions
    float screenWidth = 900;
    float screenHeight = 500;

    // Creating the window for grid animation
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Circle Pyramid");
    window.setPosition(Vector2i(0, 0));

    // Constants for grid dimensions
    const int columns = 5;
    const int rows = 9;
    float x, y;
    const float m = -1; // The slope of the line
    float b = 400; // The vertical component in y = mx + b
    
    //two dimensional array of circles
    CircleShape circles[rows][columns];

    /* drawing the circles in the two dimensional array
     the circles we don't care about will be painted black
     only the circles that we want will be shown*/

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          /*setting the x and y components of the circles' position 
           we multiply by 100 to translate the columns and rows into
           actual coordinates*/
            x = i * 100;
            y = j * 100;

            circles[i][j].setPosition(x, y);
            circles[i][j].setRadius(50);
            circles[i][j].setOutlineThickness(1);

            // Assigning colors based on their position relative to lines
            if (y == (m * x) + 400) {
                // Line formula y = -x + 400
                circles[i][j].setFillColor(Color::Red);
                circles[i][j].setOutlineColor(Color::Red);

            }
            else if (y == ((m * x) + 600) && y > 0) {
                // Line formula y = -x + 600, y must be > 0 to limit the length of the second diagonal
                circles[i][j].setFillColor(Color::Yellow);
                circles[i][j].setOutlineColor(Color::Yellow);

            }
            else if (y == ((m * x) + 800) && y > 100) {
                // Line formula y = -x + 800, y must be > 100 to limit the length of the third diagonal
                circles[i][j].setFillColor(Color::Blue);
                circles[i][j].setOutlineColor(Color::Blue);

            }
            else if (y == ((m * x) + 1000) && y > 200) {
                // Line formula y = -x + 1000, y must be > 200 to limit the length of the fourth diagonal
                circles[i][j].setFillColor(Color::Magenta);
                circles[i][j].setOutlineColor(Color::Magenta);

            }
            else if (y == ((m * x) + 1200) && y > 300) {
                // Line formula y = -x + 1200, y must be > 300 to limit the length of the fifth diagonal
                circles[i][j].setFillColor(Color::White);
            }
            else {
            //the circles that we do not care about will be painted black to hide them
                circles[i][j].setFillColor(Color::Black);

                /* the outlinecolor of the hidden circles
                 is set to transparent so that it
                does not mess with the outlines of the other circles.
                */
                circles[i][j].setOutlineColor(Color::Transparent);
            
            }
        }
    }


    while (window.isOpen()) {
        // checking for the close event while the window is open
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Drawing the circles on the window
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                window.draw(circles[i][j]);
            }
        }

        window.display();
    }
}

int main() {
    CirclePyramid();
    return 0;
}
