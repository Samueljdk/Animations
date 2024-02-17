#include <SFML/Graphics.hpp> // sfml library
#include <iostream>
#include <random> // library to create the random choices
using namespace sf;
using namespace std;

static random_device rd;
static mt19937 gen(rd());
int randomChoice(int lowerBound, int upperBound) {
    
    
    uniform_int_distribution<> distrib(lowerBound, upperBound);

    int randomNumber =distrib(gen);
    return randomNumber;
}
string decide(float x, float y, string previousDecision) {
    string randomDecision = previousDecision;
    // intersections
    int choice = 0;
    if (x==75 && y==75) {
        choice = randomChoice(0, 1);
        if (choice == 0 && previousDecision!="left") { randomDecision = "right"; }
        else if (choice==1 && previousDecision!="up") { randomDecision = "down"; }
        
       // randomDecision = "right";
            
        cout << "Random chose " << randomDecision;
        cout << "here at number 1" << endl;
        return randomDecision;
    }

    if (x==75 && y==255) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision != "left")randomDecision = "right";
        else if (choice == 1 && previousDecision != "down")randomDecision = "up";
        else if (choice == 2 && previousDecision != "up")randomDecision = "down";
        cout << "Random chose " << randomDecision;
        cout << "here at number 2" << endl;
        return randomDecision;
    }

    if (x==75 && y==495) {
        choice = randomChoice(0, 1);
        if (choice == 0 && previousDecision != "left") { randomDecision = "right"; }
        else if (choice == 1 && previousDecision != "down") { randomDecision = "up"; }

        //randomDecision = "up";
        cout << "Random chose " << randomDecision;
        cout << "here at number 3" << endl;
        return randomDecision;
    }

    if (x==255 && y==75) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision!="left") { randomDecision = "right"; }
        else if(choice == 2 && previousDecision != "right") { randomDecision = "left"; }
        else if (choice == 1 && previousDecision!="up") { randomDecision = "down"; }
        
        cout << "Random chose " << randomDecision;
        cout << "here at number 4" << endl;
        return randomDecision;
    }

    if (x==255 && y==255) {
        choice == randomChoice(0, 3);
        if (choice == 0 && previousDecision != "down")randomDecision = "up";
        else if (choice == 1 && previousDecision != "left")randomDecision = "right";
        else if (choice == 2 && previousDecision != "up")randomDecision = "down";
        else randomDecision = "left";
        cout << "Random chose " << randomDecision;
        cout << "here at number 5" << endl;
        return randomDecision;
    }
    
    if (x==255 && y==495) {
            choice = randomChoice(0, 2);
            if (choice == 0 && previousDecision != "down")randomDecision = "up";
            else if (choice == 1 && previousDecision != "right") randomDecision = "left";
            else if(choice==2 && previousDecision!="left")randomDecision = "right";

            cout << "Random chose " << randomDecision;
            cout << "here at number 6" << endl;
            return randomDecision;
        }
        
    if (x==495 && y==75) {
        choice = randomChoice(0, 1);
        if (choice == 0 && previousDecision != "right") { randomDecision = "left"; }
        else if (choice == 1 && previousDecision != "up") { randomDecision = "down"; }

      //  randomDecision = "down";
                cout << "Random chose " << randomDecision;
                cout << "here at number 7" << endl;
                return randomDecision;
            }
            
    if (x == 495 && y == 255) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision!="up")randomDecision = "down";
        else if (choice == 1 && previousDecision != "right") randomDecision = "left";
        else if(choice==2 && previousDecision!="down") randomDecision = "up";

        cout << "Random chose " << randomDecision;
        cout << "here at number 6" << endl;
        return randomDecision;
    }
   
   if (x==495 && y==495) {
       choice = randomChoice(0, 1);
       if (choice == 0 && previousDecision != "right") { randomDecision = "left"; }
       else if (choice == 1 && previousDecision != "down") { randomDecision = "up"; }

       //randomDecision = "left";
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



    float xChange = 0.5;
    float yChange = 0.5;
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
