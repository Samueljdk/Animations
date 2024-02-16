#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

void grid() {
    float screenWidth = 900;
    float screenHeight = 500;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0));

    const int columns = 5;
    const int rows = 9;
    float xPosition = 0;
    float yPosition = 0;
    float x,y;
    const float m = -1; // the slope of line
    float b = 400; // the vertical component in y=mx+b
    CircleShape circles[rows][columns];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            x = i * 100;
            y = j * 100;
            circles[i][j].setPosition(x, y);

            circles[i][j].setRadius(50);
            circles[i][j].setOutlineThickness(1);

            if (y == (m * x) + 400) {
    //line formula y= -x + 400
                circles[i][j].setFillColor(Color::Red);
                cout << i << " turned into x: " << x << endl;
                cout << j << "turned into y: " << y << endl;
            }
            else if (y == ((m * x) + 600) && y > 0) {
                //line formula y= -x + 600 , y must be > 0 to limit the length of the second diagonal
                circles[i][j].setFillColor(Color::Yellow);

            }
            else if (y == ((m * x) + 800) && y > 100) {
                //line formula y= -x + 800 , y must be > 1000 to limit the length of the third diagonal
                circles[i][j].setFillColor(Color::Blue);

            }
            else if (y == ((m * x) + 1000) && y > 200) {
                //line formula y= -x + 1000 , y must be > 200 to limit the length of the fourth diagonal
                circles[i][j].setFillColor(Color::Magenta);

            }
            else if (y == ((m * x) + 1200) && y > 300) {
                //line formula y= -x + 1200 , y must be > 300 to limit the length of the fifth diagonal
                circles[i][j].setFillColor(Color::White);

            }
            else {
                circles[i][j].setFillColor(Color::Black);
                circles[i][j].setOutlineColor(Color::Black);

            }
        }
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
       //         window.draw(squares[i][j]);
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
