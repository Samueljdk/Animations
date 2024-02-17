#include <SFML/Graphics.hpp> // sfml library
#include <iostream>
#include <random> // library to create the random choices
using namespace sf;
using namespace std;

/* randomizing objects that generate random numbers
 I made them static so as not to create them from scratch every single time a random
 decision has to be made*/ 
static random_device rd;
static mt19937 gen(rd());

/*function that generates random number between
the lower and upper bound (inclusive)*/
int randomChoice(int lowerBound, int upperBound) {
    
    /*object that tries to distribute the randomness uniformly
     this reduces the number of times a random decision is repeated*/
    uniform_int_distribution<> distrib(lowerBound, upperBound);

    int randomNumber =distrib(gen);
    return randomNumber;
}

// function that is called at every intersection and corner to decide the next move
string decide(float x, float y, string previousDecision) {
    string randomDecision = previousDecision; // by default, the previous move will the current move
    // intersections
    int choice = 0;

// if we're at corner 1
    if (x==75 && y==75) {
        choice = randomChoice(0, 1); // gives out either zero or one

        // the previous decision is checked so as to prevent 
        // the ping pong effect where the ball moves up and down
        // or right and left between two intersections
        if (choice == 0 && previousDecision!="left") { randomDecision = "right"; }
        else if (choice==1 && previousDecision!="up") { randomDecision = "down"; }
        
        //message for me
        cout << "Random chose " << randomDecision;
        cout << "  here at number 1" << endl;
        return randomDecision;
    }
    // the rest of the corners and intersections follow a similar logic to the
    // the first corner
    //intersection 2
    if (x==75 && y==255) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision != "left")randomDecision = "right";
        else if (choice == 1 && previousDecision != "down")randomDecision = "up";
        else if (choice == 2 && previousDecision != "up")randomDecision = "down";
        cout << "Random chose " << randomDecision;
        cout << " here at number 2" << endl;
        return randomDecision;
    }
    //corner 3
    if (x==75 && y==495) {
        choice = randomChoice(0, 1);
        if (choice == 0 && previousDecision != "left") { randomDecision = "right"; }
        else if (choice == 1 && previousDecision != "down") { randomDecision = "up"; }

        cout << "Random chose " << randomDecision;
        cout << " here at number 3" << endl;
        return randomDecision;
    }
    //intersection 4
    if (x==255 && y==75) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision!="left") { randomDecision = "right"; }
        else if(choice == 2 && previousDecision != "right") { randomDecision = "left"; }
        else if (previousDecision!="up") { randomDecision = "down"; }
        
        cout << "Random chose " << randomDecision;
        cout << " here at number 4" << endl;
        return randomDecision;
    }
    //intersection 5
    if (x==255 && y==255) {
        choice == randomChoice(0, 3);
        if (choice == 0 && previousDecision != "up")randomDecision = "down";
        else if (choice == 1 && previousDecision != "left")randomDecision = "right";
        else if (choice == 2 && previousDecision != "down")randomDecision = "up";
        else  randomDecision = "left";
        cout << "Random chose " << randomDecision;
        cout << " here at number 5" << endl;
        return randomDecision;
    }
    //intersection 6
    if (x==255 && y==495) {
            choice = randomChoice(0, 2);
            if (choice == 0 && previousDecision != "down")randomDecision = "up";
            else if (choice == 1 && previousDecision != "right") randomDecision = "left";
            else if(choice==2 && previousDecision!="left")randomDecision = "right";

            cout << "Random chose " << randomDecision;
            cout << " here at number 6" << endl;
            return randomDecision;
        }
    // corner 7  
    if (x==495 && y==75) {
        choice = randomChoice(0, 1);
        if (choice == 0 && previousDecision != "right") { randomDecision = "left"; }
        else if (previousDecision != "up") { randomDecision = "down"; }
        cout << "Random chose " << randomDecision;
        cout << " here at number 7" << endl;
        return randomDecision;
            }
     //intersection 8       
    if (x == 495 && y == 255) {
        choice = randomChoice(0, 2);
        if (choice == 0 && previousDecision!="up")randomDecision = "down";
        else if (choice == 1 && previousDecision != "right") randomDecision = "left";
        else if(choice==2 && previousDecision!="down") randomDecision = "up";

        cout << "Random chose " << randomDecision;
        cout << " here at number 6" << endl;
        return randomDecision;
    }
   //corner 9
   if (x==495 && y==495) {
       choice = randomChoice(0, 1);
       if (choice == 0 && previousDecision != "right") { randomDecision = "left"; }
       else if (choice == 1 && previousDecision != "down") { randomDecision = "up"; }
       cout << "Random chose " << randomDecision;
       cout << " here at number 9" << endl;
       return randomDecision;
                }


    return randomDecision;

}

void grid() {
    //setting the window dimensions and title
    const float windowWidth = 600;
    const float windowHeight = 600;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Grid Animation");
    window.setPosition(Vector2i(0, 0)); //window will be at top left corner

    // setting the font for the text which will track the ball's location
    Font font;
    if (!font.loadFromFile("Aller_It.ttf")) {
        cout << "error loading file";
    }
    Text text;
    text.setFont(font);
    text.setFillColor(Color::Black);
    text.setCharacterSize(24);
    String location; //location string variable to dispaly the circle's location

    //setting the characteristics of the ball
    CircleShape circle(15);
    circle.setFillColor(Color::Green);
    float circleXPosition = 75; // initial x position of the circle
    float circleYPosition = 255; // initial y position of the circle
    circle.setPosition(circleXPosition, circleYPosition);

// variables that hold the change in the x and y positions of the circles location
    const float circleXChange = 0.5;
    const float circleYChange = 0.5;
// variables that hold the number of rows and columns into which the grid will be divided
    const int rows = 10;
    const int columns = 10;

// two dimensional array of squares
    RectangleShape squares[rows][columns];

 // variables that track the position of the squares   
    float rectangleXPosition = 0;
    float rectangleYPosition = 0;

// drawing the squares and setting their colors to create the pattern of black and white cells
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
            squares[i][j].setPosition(Vector2f(rectangleXPosition, rectangleYPosition));
            rectangleXPosition += 60; // horizontal move to the right
        }
        rectangleXPosition = 0; // Reset rectangleXPosition for the next row
        rectangleYPosition += 60; // vertical move down
    }


    // variables that hold the current and previous decisions
    string decision = "";
    string previousDecision = "";
   
    //while the window is open
    while (window.isOpen()) {
        
            // calling the decide function to determine the next move
            decision = decide(circle.getPosition().x, circle.getPosition().y, previousDecision);
            previousDecision = decision; // saving the previous decision for the next time we ask the decide function

            /* moving the circle to the right if the random decision was right
          we make sure circle's x position is below 495 to keep it within
          the path*/
            if (decision == "right" && circle.getPosition().x < 495) {

                circleXPosition = circle.getPosition().x + circleXChange;
                circleYPosition = circle.getPosition().y;
                circle.setPosition(Vector2f(circleXPosition, circleYPosition));


            }

            /* moving the circle to the left if the random decision was left
 we make sure circle's x position is above 75 to keep it within
 the path*/
            if (decision == "left" && circle.getPosition().x > 75) {

                circleXPosition = circle.getPosition().x - circleXChange;
                circleYPosition = circle.getPosition().y;
                circle.setPosition(Vector2f(circleXPosition, circleYPosition));

            }

            /* moving the circle up if the random decision was up
we make sure circle's y position is above 75 to keep it within
the path*/
            if (decision == "up" && circle.getPosition().y > 75) {

                circleXPosition = circle.getPosition().x;
                circleYPosition = circle.getPosition().y - circleYChange;  //reduce the vertical position to move up
                circle.setPosition(Vector2f(circleXPosition, circleYPosition));

            }

            /* moving the circle down if the random decision was down
            we make sure circle's x position is below 495 to keep it within
            the path*/

            if (decision == "down" && circle.getPosition().y < 495) {

                circleXPosition = circle.getPosition().x;
                circleYPosition = circle.getPosition().y + circleYChange; // increase the vertical position to move down
                circle.setPosition(Vector2f(circleXPosition, circleYPosition));

            }

            //updating the location string and setting the text
            location = "X: " + to_string(circle.getPosition().x) + " Y: " + to_string(circle.getPosition().y);
            text.setString(location);


// checking to see if the window was closed
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        //drawing the squares
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                window.draw(squares[i][j]);
            }
        }

       //drawing the circle and text
        window.draw(circle);
        window.draw(text);
        window.display();
    }
}

int main() {
    grid();
    return 0;
}
