#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace sf;
using namespace std;

/*
std::string getRandomDirection(std::mt19937& gen, std::uniform_int_distribution<>& distrib, int exclude) {
    int randomChoice;
    do {
        randomChoice = distrib(gen);
    } while (randomChoice == exclude);

    if (randomChoice == 0) return "up";
    else if (randomChoice == 1) return "right";
    else if (randomChoice == 2) return "down";
    else return "left";
}

std::string decide(float x, float y) {
    x = round(x);
    y = round(y);

    std::random_device rd;
    std::mt19937 gen(rd());

    // Common random distribution for 0 to N-1 choices
    std::uniform_int_distribution<> distrib(0, 3);

    // U, R, D, L
    // 255, 75 down only 1
    if (x == 255 && y == 75) return "down";
    // 495, 75 down only 1
    else if (x == 495 && y == 75) return "down";
    // 75, 75 right or down, exclude right and left
    else if (x == 75 && y == 75) return getRandomDirection(gen, distrib, 1);
    // 75, 495 up or right 2, exclude left and down
    else if (x == 75 && y == 495) return getRandomDirection(gen, distrib, 2);
    // 495, 495 up or left 2, exclude right and down
    else if (x == 495 && y == 495) return getRandomDirection(gen, distrib, 1);
    // 75, 255 up, down, right 3, exclude left
    else if (x == 75 && y == 255) return getRandomDirection(gen, distrib, 3);
    // 495, 255 left, up or down 3, exclude right
    else if (x == 495 && y == 255) return getRandomDirection(gen, distrib, 1);
    // 255, 495 up, left, right 3, exclude down
    else if (x == 255 && y == 495) return getRandomDirection(gen, distrib, 2);
    // 255, 255 all directions 4
    else if (x == 255 && y == 495) return getRandomDirection(gen, distrib, 3);
    else return "right";
}
*/
int randomChoice(int lowerBound, int upperBound) {
    srand(time(0)); // uses the current time to generate a random number

    // Generate a random number within the specified range
    int randomNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;

    cout << "random called \n";
    return randomNumber;
}
string decide(float x, float y, string previousDecision) {
    string randomDecision = previousDecision;
    // intersections
    int choice = 0;
    if ((60 < x && x < 120) && (60 < y && y < 120)) {

        randomDecision = "right";
        cout << "Random chose " << randomDecision;
        cout << "here at number 1" << endl;
        return randomDecision;
    }

    if ((60 < x && x < 120) && (240 < y && y < 300)) {

        randomDecision = "up";
        cout << "Random chose " << randomDecision;
        cout << "here at number 2" << endl;
        return randomDecision;
    }

    if ((60 < x && x < 120) && (480 < y && y < 540)) {
        randomDecision = "up";
        cout << "Random chose " << randomDecision;
        cout << "here at number 3" << endl;
        return randomDecision;
    }

    if ((240 < x && x < 300) && (60 < y && y < 120)) {

        randomDecision = "right";
        cout << "Random chose " << randomDecision;
        cout << "here at number 4" << endl;
        return randomDecision;
    }

    if ((240 < x && x < 300) && (240 < y && y < 300)) {
        choice == randomChoice(0, 3);
        if (choice == 0)randomDecision = "up";
        else if (choice == 1)randomDecision = "right";
        else if (choice == 2)randomDecision = "down";
        else randomDecision = "left";
        cout << "Random chose " << randomDecision;
        cout << "here at number 5" << endl;
        return randomDecision;
    }
    
    if ((240 < x && x < 300) && (480 < y && y < 540)) {
            choice = randomChoice(0, 1);
            if (choice == 0)randomDecision = "up";
            else randomDecision = "left";

            cout << "Random chose " << randomDecision;
            cout << "here at number 6" << endl;
            return randomDecision;
        }
        
    if ((480 < x && x < 540) && (60 < y && y < 120)) {

                randomDecision = "down";
                cout << "Random chose " << randomDecision;
                cout << "here at number 7" << endl;
                return randomDecision;
            }
            
     if ((480 < x && x < 540) && (480 < y && y < 540)) {

                    randomDecision = "left";
                    cout << "Random chose " << randomDecision;
                    cout << "here at number 9" << endl;
                    return randomDecision;
                }


    return randomDecision;

}

void grid() {

    float screenWidth = 600;
    float screenHeight = 600;

    CircleShape circle(15);
    circle.setFillColor(Color::Green);
    float xCircle = 75;
    float yCirlce = 255;
    circle.setPosition(xCircle, yCirlce);


    // setting the font
    Font font;
    if (!font.loadFromFile("Aller_It.ttf")) {
        cout << "error loading file";
    }
    Text text;
    text.setFont(font);
    text.setFillColor(Color::Black);
    text.setCharacterSize(24);

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0));



    float xChange = 1;
    float yChange = 1;
    const int rows = 10;
    const int columns = 10;
    float xPosition = 0;
    float yPosition = 0;

    RectangleShape squares[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == 9 || j == 9 || j == 0) {
                squares[i][j].setFillColor(Color::White);

            }
            else if (i == 1 || i == 4 || i == 8) {
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



    string decision = "";
    string previousDecision = "";
    float speed = 10;
    while (window.isOpen()) {
        Event event;
        try {


            decision = decide(circle.getPosition().x, circle.getPosition().y, previousDecision);
            previousDecision = decision;



            if (decision == "right" && circle.getPosition().x < 495) {

                xPosition = circle.getPosition().x + xChange;
                yPosition = circle.getPosition().y;
                circle.setPosition(Vector2f(xPosition, yPosition));
                //  circle.move(speed, 0);
                  // decision = decide(circle.getPosition().x, circle.getPosition().y);



            }


            if (decision == "left" && circle.getPosition().x > 75) {

                xPosition = circle.getPosition().x - xChange;
                yPosition = circle.getPosition().y;
                circle.setPosition(Vector2f(xPosition, yPosition));
                   // circle.move(-speed, 0);
                    // decision = decide(circle.getPosition().x, circle.getPosition().y);

            }



            if (decision == "up" && circle.getPosition().y > 75) {

                xPosition = circle.getPosition().x;
                yPosition = circle.getPosition().y - yChange;  //reduce the vertical position to move up

                circle.setPosition(Vector2f(xPosition, yPosition));
                 // circle.move(0, -speed);

                  //  decision = decide(circle.getPosition().x, circle.getPosition().y);

            }



            if (decision == "down" && circle.getPosition().y < 495) {

                xPosition = circle.getPosition().x;
                yPosition = circle.getPosition().y + yChange; // increase the vertical position to move down
               circle.setPosition(Vector2f(xPosition, yPosition));

               //  circle.move(0, speed);
              //  decision = decide(circle.getPosition().x, circle.getPosition().y);


            }



        }
        catch (exception& e) {
            cout << "Error " << e.what() << endl;

        }



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


        String message = "X: " + to_string(circle.getPosition().x) + " Y: " + to_string(circle.getPosition().y);
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
