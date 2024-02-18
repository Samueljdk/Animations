#include <SFML/Graphics.hpp> // sfml is a graphics libraary for drawing the shapes
#include <iostream>
using namespace sf;
using namespace std; // used for the Cout and Cin, used in place of writing st:: for each cout/in line  

void bouncingBall() {
    // loading a ttf file to determine the font for the text
    Font font;
    if (!font.loadFromFile("Aller_It.ttf")) //ttf is a font style
    {
        cout << "error loading file"; // message for me if loading fails
    }


    const int windowWidth = 600; // window width constant
    const int windowHeight = 600; // window height constant
    // the circle starts at the top left corner of the window
    float xPosition = 0; // the x component of the circle's coordinates
    float yPosition = 0; // the y component of the circle's coordinates


    // boolean flags used to indicate that the ball has touched the different corners
    bool reachedBottom = false;
    bool reachedRight = false;
    bool reachedTop = false;
    bool reachedLeft = false;

    // creating the window with the width and height constant, and giving it a title
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Bouncing Ball Animation");
    // setting the position of the window at the top left corner of the screen    
    window.setPosition(Vector2i(0, 0));

    //creating the circle shape object
    CircleShape circle(50); // radius of 50


    while (window.isOpen()) // constantly checking to see if the window is open
    { 

        //diagonal move to the bottom from the top left corner
        //xPosition must be less than 250 to ensure the ball hits the middle of the bottom edge
        // reachedBottom is false before the ball reaches bottom 
        // and true after it hits bottom
        if (xPosition < 250 && !reachedBottom) {
            xPosition += 0.1;  //xPosition increments by 0.1 while less than 250
            yPosition = xPosition * 2; // the drop down happens at twice the speed of the lateral move
            // the yPosition has to increase at double the xPosition
            // to ensure the ball hits the middle of the bottom edge
        }

        else {
            reachedBottom = true; // once the ball hits bottom, we make this flag true

        }
        // diagonal move to the right
        if (reachedBottom && !reachedRight) 
        {
            xPosition += 0.1; //xPosition increments after hitting bottom but before hitting the right edge
            yPosition -= 0.1; //yPosition decrements so that the ball can move up

            /*when the ball's xPosition passes 500 we can be sure, it is
            on its way to hit the right edge*/
            if (xPosition >= 500)reachedRight = true;
        }

        // moving diagonally to the left
        // if the ball has hit bottom and right, but not top yet
        if (reachedBottom && reachedRight && !reachedTop) 
        {
            xPosition -= 0.1; // we decrement the xPosition to make it go left
            yPosition -= 0.1;  // we decrement the yPosition to make it go up
            if (yPosition <= 0)reachedTop = true; // when the ball is close to hit the upper edge, we turn the flag to true
        }

        // moving down to left
        // if the ball has hit all the edge except for the left edge
        if (reachedBottom && reachedRight && reachedTop && !reachedLeft) {
            xPosition -= 0.1; // we decrement the xPosition to make it go left
            yPosition += 0.1; // we increment the yPosition to make it go down
            if (xPosition <= 0)reachedLeft = true; // when the ball is close to hitting the lower edge, we turn the reachedBottom flag to true
        }

        // once all edges have been hit, we start to make the ball go down again
                // it follows the same path
        if (reachedBottom && reachedLeft && reachedRight && reachedTop) 
        {

            xPosition += 0.1; //
            yPosition += 0.1;

            /*when the ball is back on left side of the window, and it starts to
            go down again, we turn the flags false
            thus starting the cycle again
            */
            if (xPosition > 250 || yPosition >= 500) 
            {
                reachedBottom = false;
                reachedLeft = false;
                reachedTop = false;
                reachedRight = false;

            }
        }


        //setting the position of the ball
        circle.setPosition(xPosition, yPosition);

        
        /*defining a text object that takes the font which will
        keep track of the ball's location.
        */
        Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        String message = "X: " + to_string(xPosition) + " Y: " + to_string(yPosition);

        if (reachedBottom)circle.setFillColor(Color::Green);
        if (reachedRight)circle.setFillColor(Color::Yellow);
        if (reachedTop)circle.setFillColor(Color::Red);
        if (reachedLeft)circle.setFillColor(Color::Blue);


        text.setString(message);

        Event event;
        while (window.pollEvent(event)) 
        { // keeps checking to see if the user closed the windo
            if (event.type == Event::Closed) 
            {
                window.close(); // closes the window
            }
        }




        window.clear(); // clears the window to prepare to make the next ball drawing
        window.draw(text);
        window.draw(circle); // draws the ball
        window.display(); // displays the ball
    }

}

int main() 
{
    bouncingBall();

    return 0;
}