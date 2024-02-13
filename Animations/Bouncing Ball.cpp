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
     
     bool stopBouncing = false;
     bool reachedBottom = false;
     bool reachedRight = false;
     bool reachedTop = false;
     int counter = 0.01;
     while (!stopBouncing && window.isOpen()) {

         //diagonal move to the bottom
         if (horizontalPosition < 250 && verticalPosition<500 && !reachedBottom) {
             horizontalPosition+=0.01;
             verticalPosition = horizontalPosition *2;

         }
         
         else {
             reachedBottom = true;
             
         }
         // diagonal move to the right
         if (reachedBottom && horizontalPosition<500 && verticalPosition>250) {
             horizontalPosition += 0.01;
             verticalPosition -= 0.01;
    if(horizontalPosition>=500 && verticalPosition<=250)reachedRight = true;
         }

         // moving diagonally to the left
         if (reachedBottom && reachedRight && verticalPosition>0) {
             horizontalPosition -= 0.01;
             verticalPosition -= 0.01;
             if (verticalPosition <= 0)reachedTop = true;
         }
        
        // moving down to left
         if (reachedBottom && reachedRight && reachedTop && horizontalPosition>0) {
             horizontalPosition -= 0.01;
             verticalPosition += 0.01;
            
         }
         if (horizontalPosition <= 0 && verticalPosition<=0) {
             reachedBottom = false;
             reachedRight = false;
             reachedTop = false;
         }
        
         
        
         

         circle.setPosition(horizontalPosition, verticalPosition);
         Text text;
         text.setFont(font);
         text.setCharacterSize(24);
         String message = "W:" + to_string(horizontalPosition) + " H: " + to_string(verticalPosition);
         if (reachedBottom)message += "\n Reached Bottom";
         if (reachedRight)message += "\n Reached Right";

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
    /*bool stopMenu = false;
    int choice = 0;
    while (!stopMenu) {
        cout << "Welcome to the animations program \n";
        cout << "Enter 0.01 to see the bouncing ball animation \n";
        cout << "Enter any other value to exit \n";
        cin >> choice;
        switch (choice)
        {
        case 0.01:
            bouncingBall();
            system("cls"); // clears the screen so that the menu can be displayed on the same spot


            break;
        default:
            stopMenu = true;

            break;
        }

    }*/
    
    return 0;
}
