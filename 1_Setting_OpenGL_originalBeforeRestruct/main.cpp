//#include "Dependencies\glew\glew.h"
//#include "Dependencies\freeglut\freeglut.h"
#include "glutFunctions.h"
#include <string>
#include <iostream>
#define WIDTH 300
#define HEIGHT 300

using namespace std;


// =============================================================================
// These variables will store the input ppm image's width, height, and color
// =============================================================================
string type;


//int width, height;
//unsigned char *pixmap;

/*Finally, the parameter(for "glDrawPixels()"), pixmap is a pointer to an array of characters
(unsigned char *pixmap) that is used to store the image’s pixmap.*/


// =============================================================================
// setPixels()
//
// This function stores the RGB values of each pixel to "pixmap."
// Then, "glutDisplayFunc" below will use pixmap to display the pixel colors.
// =============================================================================
void setPixels(int argc, char *argv[])
{
	
	pixmap = new unsigned char[WIDTH * HEIGHT * 3];

	for (int y = 0; y < HEIGHT; y++) /*Scanline number.*/ {
		
		for (int x = 0; x < WIDTH; x++) /*Pixel number on scanline.*/ {
			
			int i = (y * WIDTH + x) * 3; /*"i" signifies the value of the pixel value fetched from scanline.*/
										 /*At this point within the function,we are assigning color values to our RGB pixmap array.*/


										 /*This block of code corresponds to command line arguments dictating color of pixmap.*/
										 /*Red option.*/
			if (type == "red") {
				pixmap[i++] = 0xFF;
				pixmap[i++] = 0x00;
				pixmap[i] = 0x00;
			}
			/*Green option.*/
			else if (type == "green") {
				pixmap[i++] = 0x00;
				pixmap[i++] = 0xFF;
				pixmap[i] = 0x00;
			}
			/*Blue option.*/
			else if (type == "blue") {
				pixmap[i++] = 0x00;
				pixmap[i++] = 0x00;
				pixmap[i] = 0xFF;
			}
			/*This block of code corresponds to command line argument for "all" option.*/
			else if (type == "all") {
				//Green quadrant.
				if ((x>(WIDTH / 2)) && (y >= (HEIGHT / 2))) {
					pixmap[i++] = 0x00;
					pixmap[i++] = 0xFF;
					pixmap[i] = 0x00;
				}
				//Red quadrant.
				if ((x <= (WIDTH / 2)) && (y >= (HEIGHT / 2))) {
					pixmap[i++] = 0xFF;
					pixmap[i++] = 0x00;
					pixmap[i] = 0x00;
				}
				//Blue quadrant.
				if ((x <= (WIDTH / 2)) && (y <= (HEIGHT / 2))) {
					pixmap[i++] = 0x00;
					pixmap[i++] = 0x00;
					pixmap[i] = 0xFF;
				}
				//Yellow quadrant.
				if ((x >= (WIDTH / 2)) && (y<(HEIGHT / 2))) {
					pixmap[i++] = 0xFF;
					pixmap[i++] = 0xFF;
					pixmap[i] = 0x00;
				}
			}
			/*This block of code corresponds to command line argument for "circle" option.*/
			else if (type == "circle") {
				float diameter = 10000;
				float y_portion = pow((y - WIDTH / 2), 2);
				float x_portion = pow((x - WIDTH / 2), 2);
				float areaCircle = x_portion + y_portion;


				if (areaCircle <= diameter)
				{		//inside circle yellow. Calls distance function and radius int
					pixmap[i++] = 255;
					pixmap[i++] = 255;
					pixmap[i++] = 0;
				}
				else
				{			//outside circle blue
					pixmap[i++] = 0;
					pixmap[i++] = 0;
					pixmap[i++] = 255;
				}
			}
			/*This block of code corresponds to command line argument for "other" option.*/
			else if (type == "other") {
				float diameter = 50000;
				float y_portion = pow((y - WIDTH / 2), 2);
				float x_portion = pow((x - WIDTH / 2), 2);
				float areaCircle = x_portion + y_portion;




				if (areaCircle <= diameter / 4)
				{		//inside circle yellow. Calls distance function and radius int
					pixmap[i++] = x*y;
					pixmap[i++] = sin(y)*i;
					pixmap[i++] = y;
				}
				else if (areaCircle <= diameter / 2)
				{		//inside circle yellow. Calls distance function and radius int
					pixmap[i++] = x*x;
					pixmap[i++] = y;
					pixmap[i++] = y;
				}
				else if (areaCircle <= diameter)
				{			//outside circle blue
							/*pixmap [i++] = 0;
							pixmap [i++] = i*x*x;
							pixmap [i++] = i*x; */
					pixmap[i++] = x*y;
					pixmap[i++] = x*y;
					pixmap[i++] = y;
				}
			}
			/*This block of code corresponds to command line argument for "other" option.*/
			else {
				cout << "Incorrect input. Now closing." << endl;
				exit(0);
			}
		}
	}
}
/*
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);
	glutSwapBuffers();
}

static void windowResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, (w / 2), 0, (h / 2), 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
*/
//Function responsible for graphics display.
/*
static void windowDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0, 0);
	//Call to "glRasterPos2i(0,0)" assures that the image will be drawn in the window starting at the lower left corner (pixel 0 on scanline 0).
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixmap);
	//Procedure, "glDrawPixels()" that takes an image pixmap and displays it in the graphics window.

	//The width and height parameters to "glDrawPixels()" specify the width, in pixels, of a scanline, and the height of the image, in the number of scanlines.

	//The GL_RGB parameter indicates that the pixels are stored as RGB quadruples, with color primaries stored in the order red, green and blue.

	//GL_UNSIGNED_BYTE parameter indicates that each color primary is stored in a single byte and treated as an unsigned number between zero and 255.
	glFlush();
}*/
/*
static void processMouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
		exit(0);               // Exit on mouse click.
}
*/

void instructionForUser() {
	cout << "Select choice." << endl;
	cout << "Type ""red"" for a red window." << endl;
	cout << "Type ""green"" for a red window." << endl;
	cout << "Type ""blue"" for a red window." << endl;
	cout << "Type ""all"" for all colored window." << endl;
	cout << "Type ""circle"" for a red window." << endl;
	cout << "Type ""other"" for a red window." << endl;	
	cin >> type;
}
/*
void glutInitialize(int argc, char **argv,int width, int height, const char* nameOfProgram) {
	
	//setPixels(argc, argv);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(width, height);
	glutCreateWindow(nameOfProgram);
	glClearColor(1, 1, 1, 1); // Set background color.
	glutReshapeFunc(windowResize);
	glutDisplayFunc(windowDisplay);
	glutMouseFunc(processMouse);
	glutMainLoop();
}
*/
int main(int argc, char **argv)
{
	instructionForUser();
	setPixels(argc, argv);
	glutInitialize(argc, argv,WIDTH, HEIGHT,pixmap, "Program 01");
	
}