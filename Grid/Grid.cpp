#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace sf;
using namespace std;
/*String decide(float x, float y) {
    x = round(x); // approximate to the nearest whole number value
    y = round(y); // approximate to the nearest whole number value

    
    //255, 75 down only 1
    if (x == 255 && y == 75)return "down";
    //495, 75 down only 1
    if (x == 495 && y == 75)return "down";
    //75,75  right or down  2
    if (x == 75 && y == 75) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "right";
        else return "down";
    }
    //75, 495 up or right 2
    if (x == 75 && y == 495) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else return "right";
    }
    //495, 495 up or left   2
    if (x == 495 && y == 495) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else return "left";
    }
    //75, 255 up, down, right  3
    if (x == 75 && y == 255) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "down";
        else return "right";
    }
    //495, 255 left, up or down 3
    if (x == 495 && y == 255) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "down";
        else return "left";
    }
   // 255, 495 up, left, right 3
    if (x == 255 && y == 495) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "right";
        else return "left";
    }
//255, 255 all directions 4
    if (x == 255 && y == 495) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 3);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "right";
        else if (randomChoice == 2) return "down";
        else return "left";
    }
  


}
*/
String decide(float x, float y) {
    x = round(x); // approximate to the nearest whole number value
    y = round(y); // approximate to the nearest whole number value
    random_device rd;
    mt19937 gen(rd());
    
    //255, 75 down only 1
    if (x == 255 && y == 75)return "down";
    //495, 75 down only 1
    if (x == 495 && y == 75)return "down";
    //75,75  right or down  2
    if (x == 75 && y == 75) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "right";
        else return "down";
    }
    //75, 495 up or right 2
    if (x == 75 && y == 495) {
        
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else return "right";
    }
    //495, 495 up or left   2
    if (x == 495 && y == 495) {
        uniform_int_distribution<> distrib(0, 1);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else return "left";
    }
    //75, 255 up, down, right  3
    if (x == 75 && y == 255) {
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "down";
        else return "right";
    }
    //495, 255 left, up or down 3
    if (x == 495 && y == 255) {
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "down";
        else return "left";
    }
   // 255, 495 up, left, right 3
    if (x == 255 && y == 495) {
        uniform_int_distribution<> distrib(0, 2);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "right";
        else return "left";
    }
//255, 255 all directions 4
    if (x == 255 && y == 495) {
        uniform_int_distribution<> distrib(0, 3);
        int randomChoice = distrib(gen);
        if (randomChoice == 0)return "up";
        else if (randomChoice == 1) return "right";
        else if (randomChoice == 2) return "down";
        else return "left";
    }
  

    return "not intersection";
}
void grid() {
    sf::Font font;
    if (!font.loadFromFile("Aller_It.ttf")) {
        cout << "error loading file";
    }


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
        if (Keyboard::isKeyPressed(Keyboard::Left) &&circle.getPosition().x > 75) {
            circle.move(-speed, 0);
            string x = decide(circle.getPosition().x, circle.getPosition().y);
            if (x != "not intersection")cout << x;

        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && circle.getPosition().x < 495)
        {
            circle.move(speed, 0);
            string x = decide(circle.getPosition().x, circle.getPosition().y);
            if (x != "not intersection")cout << x;

        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && circle.getPosition().y > 75)
        {
            circle.move(0, -speed);
            string x = decide(circle.getPosition().x, circle.getPosition().y);
            if(x!="not intersection")cout << x;

        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && circle.getPosition().y < 495)
        {
            circle.move(0, speed);
            string x = decide(circle.getPosition().x, circle.getPosition().y);
            if (x != "not intersection")cout << x;

        }

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

        Text text;
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(24);
        String message = "X: " + to_string(circle.getPosition().x)+ " Y: " + to_string(circle.getPosition().y);
        text.setString(message);

        window.draw(circle);
        window.draw(text);
        window.display();
    }
}

int main() {
    grid();
    return 0;
}
