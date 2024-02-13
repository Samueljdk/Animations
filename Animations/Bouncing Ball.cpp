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
     int counter = 1;
     while (!stopBouncing && window.isOpen()) {
         if (horizontalPosition < 250 && verticalPosition<500) {
             horizontalPosition+=0.01;
             verticalPosition = horizontalPosition *2;

         }
         
         else {
             reachedBottom = true;
             
         }


         if (reachedBottom && horizontalPosition<500) {
             horizontalPosition += 0.01;
             verticalPosition -= 0.01;
             
         }
        
         
        
         

         circle.setPosition(horizontalPosition, verticalPosition);
         Text text;
         text.setFont(font);
         text.setCharacterSize(24);
         text.setString("W:"+ to_string(horizontalPosition) +" H: " + to_string(verticalPosition));

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
        cout << "Enter 1 to see the bouncing ball animation \n";
        cout << "Enter any other value to exit \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
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
