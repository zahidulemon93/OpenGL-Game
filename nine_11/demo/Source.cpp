#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <gl/glut.h>
#include "imageloader.h"
#include <windows.h>
#include <string.h>


using namespace std;
float moveCZ = 0;
float moveCX = 4.5;
float moveCY = 4.0;
float moveCarZ = 0;
float moveCarX = 0;
float carTurn = -90.0;
float lookX = 0;
float _value = 0.0;
float mov_truckZ = -3;
double zCenterTriangle;
int game_view=0;
int game_score=0;
int temp=0;
char b;
char arr[100]={'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9'};
char arr2[2];
float moving_car_z=0;
float just_view_without_game=0;
//*****************************for game over display

GLfloat UpwardsScrollVelocity = -10.0;
float view = 10.0;

char quote[6][80];
int numberOfQuotes = 0, i;


//************************remove
int colCountL = 0;
int colCountR = 0;




//***************************************************************************

float _angle_2 = 90;
//float i = 0.0f;
bool s =0;
bool second=0;
float bullet_Trans=-0.9;  //
float bullet_Trans_X=-1;
float bullet_Trans_Z=1;


float bullet2_Trans=-0.9;  //
float bullet2_Trans_X=-1;
float bullet2_Trans_Z=1;


float plan_trans=-16.9;
float plan_trans2=-2.2;
float plan_trans3=-10;
float broken_bulding_x=-.19;
float broken_bulding_y=2.1;
float broken_bulding_Signal=0;

float broken_bulding2_x=-.19;
float broken_bulding2_y=2.1;

int d1=0;
int power_Tran=2;
int which_tower_detect=1;
//**********************************************************************end here





//********************************************************************** GAME OVER DISPLAY #GAMEOVER
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}


void timeTick(void)
{
	if (UpwardsScrollVelocity< -600)
		view -= 0.000011;
	if (view < 0) { view = 20; UpwardsScrollVelocity = -10.0; }
	
	UpwardsScrollVelocity -= 0.1;
	glutPostRedisplay();

}


void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.1, 0.1, 0.1);



	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);


		}
		glPopMatrix();
	}

}



void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}


int winner(char a)
{

	strcpy_s(quote[0], "Game Over");

	strcpy_s(quote[1], " your score ");
	strcpy_s(quote[2], "is ");

	//
	temp=game_score/10;
	arr2[0]=arr[temp];
	
	arr2[1]=arr[game_score];
	strcpy_s(quote[3], &arr2[0]);
	
	
	numberOfQuotes = 5;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(1360, 750);
	glutCreateWindow("Game Result");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);

	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ GAME OVER END 




void keyFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'F':
		if (moveCZ > -56)
		{
			moveCZ -= 0.1;
		}
		else
		{
			moveCZ = -56;
		}
		break;

		case 'U':
		if (moveCY < 56)
		{
			moveCY += 0.1;
		}
		else
		{
			moveCY = 56;
		}


		break;


		case 'D':
		if (moveCY >0 )
		{
			moveCY -= 0.1;
		}
		else
		{
			moveCY = 0;
		}


		break;

	case 'B':
		if (moveCZ < 4)
		{
			moveCZ += 0.1;
		}
		else
		{
			moveCZ = 4;
		}
		break;
	case ',':
		if (moveCX > -26.4)
		{
			moveCX -= 0.1;
		}
		else
		{
			moveCX = -26.4;
		}
		break;
	case '.':
		if (moveCX < 40.6)
		{
			moveCX += 0.1;
		}
		else
		{
			moveCX = 40.6;
		}
		break;
	case 'R':
		_value += 4;
		break;

	case 'T':
		_value -= 4;
		break;

	case '0':
		moveCZ = 0;
		moveCX = 4.5;
		moveCY = 4.0;
		just_view_without_game=0;
		break;

	case 'V':
		just_view_without_game=1;
		break;
	case 27:
		exit(0);
	default:
		break;
	}

//****************************************************  
	switch (key) {
	case '1':
		if(s==0)
		{
			s=1;
		}
		else
		{
			second=1;
		}

	
	glutPostRedisplay();
	break;


	case '2':
	second=1;
	glutPostRedisplay();
	break;

glutPostRedisplay();

default:
break;

//***************************************************** KEY BORD END


}
}
void passive(int x, int y)
{
	lookX = x;
	cout << x << endl;

}
GLuint loadTexture(Image* image) {
	GLuint textureId;

	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId7;
GLuint _textureId8;
GLuint _textureId9;
GLuint _textureId10;

//TEXTURE FOR ADDITIONAL BUILDING


//Initializes 3D rendering
void initRendering() {

	glEnable(GL_DEPTH_TEST);
	Image* image1 = loadBMP("brick.bmp");
	Image* image2 = loadBMP("demo.bmp");
	Image* image3 = loadBMP("sky.bmp");
	Image* image4 = loadBMP("grass.bmp");
	Image* image5 = loadBMP("road.bmp");
	Image* image6 = loadBMP("building.bmp");
	//TEXTURE FOR ADDITIONAL BUILDING
	Image* image7 = loadBMP("buildingTwo.bmp");
	Image* image8 = loadBMP("buildingThree.bmp");
	Image* image9 = loadBMP("buildingFour.bmp");
	Image* image10 = loadBMP("cruiseUpper.bmp");


	_textureId1 = loadTexture(image1);
	_textureId2 = loadTexture(image2);
	_textureId3 = loadTexture(image3);
	_textureId4 = loadTexture(image4);
	_textureId5 = loadTexture(image5);
	_textureId6 = loadTexture(image6);
	//TEXTURE FOR ADDITIONAL BUILDING
	_textureId7 = loadTexture(image7);
	_textureId8 = loadTexture(image8);
	_textureId9 = loadTexture(image9);
	_textureId10 = loadTexture(image10);




	delete image1;
	delete image2;
	delete image3;
	delete image4;
	delete image5;
	delete image6;
	delete image7;
	delete image8;
	delete image9;
	delete image10;
	


}



//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 2000000000.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _wheel = 0.0;
float flag = 0;
void sky()
{

	/*SKY*/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1000.0, -80.0, -1000);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1000.0, -80.0, -1000);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1000.0, 600.0, -1000);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1000.0, 600.0, -1000);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);



}



void water()
{
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(0, -1, 0.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-15, 0, 0);
	glTexCoord2f(0, 10); glVertex3f(-15, 0, -50);
	glTexCoord2f(10, 10); glVertex3f(15, 0, -50);
	glTexCoord2f(10, 0); glVertex3f(15, 0, 0);
	glEnd();
	glPopMatrix();
}

void ground()
{
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(0, -1, 0.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-15, 0, 0);
	glTexCoord2f(0, 100); glVertex3f(-15, 0, -50);
	glTexCoord2f(100, 100); glVertex3f(15, 0, -50);
	glTexCoord2f(100, 0); glVertex3f(15, 0, 0);
	glEnd();
	glPopMatrix();
}

void sea()

{
		
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(0, -1, 0.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-15, 0, 0);
	glTexCoord2f(0, 100); glVertex3f(-15, 0, -50);
	glTexCoord2f(100, 100); glVertex3f(15, 0, -50);
	glTexCoord2f(100, 0); glVertex3f(15, 0, 0);
	glEnd();
	glPopMatrix();
}
void road()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(0, -1, 0.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex3f(-15, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(-15, 0, -50);
	glTexCoord2f(1, 1); glVertex3f(15, 0, -50);
	glTexCoord2f(1, 0); glVertex3f(15, 0, 0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}




void bank()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(-5, 0, 0);
	
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1); glVertex3f(-100, 0, -40);
	glTexCoord2f(200, 1); glVertex3f(100, 0, -40);
	glTexCoord2f(200, 0); glVertex3f(100, -3, -40);
	glTexCoord2f(0, 0); glVertex3f(-100, -3, -40);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}

	float z = -0.0;
	float z2=.02;

void plane_one()
{
    glPushMatrix();

	glTranslatef(-plan_trans,1.5, 0.0);
	
		glScalef(0.35,0.35,0.35);
		glPushMatrix();

		//MAIN BODY
		glColor3f(0.0, 0.5, 0.0);
		glTranslatef(-.25, 0.0, 0.0);


		glColor3f(0.0, 1.0, 0.0);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glTranslatef(-.5, 0.0, 0.0);
		glRotatef(90.0, 0.0, 0.1, 0.0);
		gluCylinder(quadratic,0.13,0.1,1.2,30.3,7.3);
		glPopMatrix();


        glPushMatrix();
    
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-.25, 0.0, 0.0);
	

		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);


		glColor3f(1.0,1.0,.0);
		glVertex3f(0.39,0.1, z2);
		glVertex3f(0.63,0.1, z2);
		glVertex3f(0.63,0.4, z2);
		glVertex3f(0.43,0.3, z2);
    

		glColor3f(1.0,1.0,.0);
		glVertex3f(0.63,0.1, 0);
		glVertex3f(0.63,0.1, .02);
		glVertex3f(0.63,0.4, .02);
		glVertex3f(0.63,0.4, 0);


	    glColor3f(1.0,1.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);
    
		glEnd();


		glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-0.7,-0.1, .1);
        glVertex3f(-0.48,-0.1, .1);
        glVertex3f(-0.48,0.1, .1);
        glVertex3f(-0.53,0.1, .1);

		 glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-0.7,-0.1,-.1);
        glVertex3f(-0.48,-0.1,-.1);
        glVertex3f(-0.48,0.1, -.1);
        glVertex3f(-0.53,0.1, -.1);

        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.7,-0.1,.1);
        glVertex3f(-0.53,0.1,.1);
        glVertex3f(-0.53,0.1, -.1);
        glVertex3f(-0.7,-0.1,-.1);

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.7,-0.1,.1);
		glVertex3f(-0.48,-0.1, .1);
		glVertex3f(-0.48,-0.1, -.1);
		glVertex3f(-0.7,-0.1,-.1);
	    glEnd();


		


    //left dana------------------------------------------------

	
	glScalef(0.2,0.2,0.2);
	glTranslatef(.45, 0.4, 6.5);
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,.0);
	glVertex3f(-0.15,-.3, .0);
    glVertex3f(-0.05,-.3, .0);
    glVertex3f(-0.05,-.26, .0);
    glVertex3f(-0.15,-.26, .0);

		float z3=.4;
		z3=7;

    glColor3f(.0,.50,.0);
    glVertex3f(-0.15,-.3,0);
    glVertex3f(-1.9,-.3,-z3);
    glVertex3f(-0.05,-.3,-z3);
    glVertex3f(-0.05,-.3, .0);
	glEnd();

     //left dana end----------------------------------------------
     //right dana-------------------------------------------------
	
	glTranslatef(0.0, 0.0, -13.5);
    glRotatef(180, 1.0, 0.0, 0.0);
    glColor3f(0.0,.5,.0);
    glBegin(GL_QUADS);
	glVertex3f(-0.15,.3, .0);
    glVertex3f(-0.05,.3, .0);
    glVertex3f(-0.05,.26, .0);
    glVertex3f(-0.15,.26, .0);

    glColor3f(0.0,.5,0.0);
    glVertex3f(-0.15,.3,0);
    glVertex3f(-1.9,.3,-z3);
    glVertex3f(-0.05,.3,-z3);
    glVertex3f(-0.05,.3, .0);
	glEnd();
	//rigt dana end-------------------------------------------------

	glPopMatrix();
	glPopMatrix();

}


void plane_two()
{
		glPushMatrix();
		glTranslatef(-plan_trans2,1.3, 0.0);
		
		//glTranslatef(0.44,1.3, 0.0);
		glScalef(0.35,0.35,0.35);
		glPushMatrix();

		//MAIN BODY
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-.25, 0.0, 0.0);


		glColor3f(0.0, 1.0, 0.0);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glTranslatef(-.5, 0.0, 0.0);
		glRotatef(90.0, 0.0, 0.1, 0.0);
		gluCylinder(quadratic,0.13,0.1,1.2,30.3,7.3);
		glPopMatrix();


        glPushMatrix();
    
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-.25, 0.0, 0.0);
	

		glBegin(GL_QUADS);
		glColor3f(1.0,.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);


		glColor3f(1.0,1.0,.0);
		glVertex3f(0.39,0.1, z2);
		glVertex3f(0.63,0.1, z2);
		glVertex3f(0.63,0.4, z2);
		glVertex3f(0.43,0.3, z2);
    

		glColor3f(0.0,1.0,.0);
		glVertex3f(0.63,0.1, 0);
		glVertex3f(0.63,0.1, .02);
		glVertex3f(0.63,0.4, .02);
		glVertex3f(0.63,0.4, 0);


	    glColor3f(0.0,1.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);
    
		glEnd();

		glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.7,-0.1, .1);
        glVertex3f(-0.48,-0.1, .1);
        glVertex3f(-0.48,0.1, .1);
        glVertex3f(-0.53,0.1, .1);

		 glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-0.7,-0.1,-.1);
        glVertex3f(-0.48,-0.1,-.1);
        glVertex3f(-0.48,0.1, -.1);
        glVertex3f(-0.53,0.1, -.1);

        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.7,-0.1,.1);
        glVertex3f(-0.53,0.1,.1);
        glVertex3f(-0.53,0.1, -.1);
        glVertex3f(-0.7,-0.1,-.1);

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.7,-0.1,.1);
		glVertex3f(-0.48,-0.1, .1);
		glVertex3f(-0.48,-0.1, -.1);
		glVertex3f(-0.7,-0.1,-.1);
	    glEnd();

    //left dana------------------------------------------------

	
		glScalef(0.2,0.2,0.2);
		glTranslatef(.45, 0.4, 6.5);
		glBegin(GL_QUADS);
		glColor3f(1.0,.0,.0);
		glVertex3f(-0.15,-.3, .0);
		glVertex3f(-0.05,-.3, .0);
		glVertex3f(-0.05,-.26, .0);
		glVertex3f(-0.15,-.26, .0);

		float z3=.4;
		z3=7;

		glColor3f(1.0,.0,1.0);
		glVertex3f(-0.15,-.3,0);
		glVertex3f(-1.9,-.3,-z3);
		glVertex3f(-0.05,-.3,-z3);
		glVertex3f(-0.05,-.3, .0);
		glEnd();

		 //left dana end----------------------------------------------
		 //right dana-------------------------------------------------
	
		glTranslatef(0.0, 0.0, -13.5);
		glRotatef(180, 1.0, 0.0, 0.0);
		glColor3f(1.0,.0,.0);
		glBegin(GL_QUADS);
		glVertex3f(-0.15,.3, .0);
		glVertex3f(-0.05,.3, .0);
		glVertex3f(-0.05,.26, .0);
		glVertex3f(-0.15,.26, .0);

		glColor3f(1.0,.0,1.0);
		glVertex3f(-0.15,.3,0);
		glVertex3f(-1.9,.3,-z3);
		glVertex3f(-0.05,.3,-z3);
		glVertex3f(-0.05,.3, .0);
		glEnd();
		//rigt dana end-------------------------------------------------

		glPopMatrix();
		glPopMatrix();

}




void twin_tower_two()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	glTranslatef(-5, 0, 0);
	
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1); glVertex3f(-10, 0, -4);
	glTexCoord2f(2, 1); glVertex3f(10, 0, -4);
	glTexCoord2f(2, 0); glVertex3f(10, -3, -4);
	glTexCoord2f(0, 0); glVertex3f(-10, -3, -4);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	
	
}




void tree()
{
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-2.7,-3.5, 0.0);

	//TREE LOWER PART
	glPushMatrix();
    glColor3f(1.0, 0.0, 0.5);
	glScalef(0.2, 1.0, 0.2);
    glutSolidCube(.25);
	
	glPopMatrix();
	    //TREE LEAF LOWRE PART
	    glPushMatrix();
		glColor3f(0.1, 1.0, 0.0);
		glRotatef(90, -1.0, 0.0, 0.0);
		glutSolidCone(.20,.20,20,20);
		glPopMatrix();
		//TREE LEAF UPPER PART
	    glPushMatrix();
		glColor3f(0.1, 1.0, 0.0);
	    glTranslatef(0,.1, 0.0);
		glRotatef(90, -1.0, 0.0, 0.0);
		glutSolidCone(.20,.20,20,20);
		glPopMatrix();
		
	glPopMatrix();
}



void Tank_bullet()
{
	glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
	glTranslatef(bullet_Trans_X,bullet_Trans,bullet_Trans_Z);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(.02,10,10);
	glPopMatrix();
}


void Tank_bullet2()
{
	glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
	glTranslatef(bullet2_Trans_X,bullet2_Trans,bullet2_Trans_Z);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(.02,10,10);
	glPopMatrix();
}

float demo_angle=0;

void broken_building_right()
{
	glPushMatrix();
	glRotatef(demo_angle,0.0, 0.0, -1.0);
    glScalef(1.1, 0.6, 1.0);
	glTranslatef(broken_bulding_x,broken_bulding_y, 0.30);
    
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);


  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   

	glPopMatrix();
}
float demo_angle2=0;
void broken_building_left()
{
	glPushMatrix();
	glRotatef(demo_angle2,0.0, 1.0, 0.0);
    glScalef(1.1, 0.6, 1.0);
	glTranslatef(broken_bulding2_x,broken_bulding2_y, 0.30);
    
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);


  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   

	glPopMatrix();

}



void car()
{
	glPushMatrix();
	glTranslatef(-1.0,-1.0, 0.0);
	glPushMatrix();
	
	glBegin(GL_QUADS);               
 //************************FRONT BODY****************************************
	glColor3f(1, 0, 0);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);


	// bottom of cube
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.2, 0.2, 0.2);


	// front of cube
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.2, 0.2, 0.2);

	/* back of cube.*/
	glColor3f(1,1,0);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);

	/* left of cube*/
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.2, 0.4, 0.6);

	/* Right of cube */
	glVertex3f(0.2, 0.2, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	//
	glVertex3f(0.7, 0.65, 0.6);
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(1.7, 0.65, 0.2);        //top cover
	glVertex3f(1.7, 0.65, 0.6);


	

	//******************MIDDLE BODY************************************
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8, 0.5, 0.6);

	/* bottom of cube*/
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.6);

	/* back of cube.*/
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.5, 0.2);

	//*********************ENTER WINDOW**********************************
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.77, 0.63, 0.2);
	glVertex3f(0.75, 0.5, 0.2);        //quad front window
	glVertex3f(1.2, 0.5, 0.2);
	glVertex3f(1.22, 0.63, 0.2);

	glVertex3f(1.27, 0.63, .2);
	glVertex3f(1.25, 0.5, 0.2);        //quad back window
	glVertex3f(1.65, 0.5, 0.2);
	glVertex3f(1.67, 0.63, 0.2);

	
	

	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.7, 0.65, 0.6);
	glVertex3f(0.6, 0.5, 0.6);        //quad front window
	glVertex3f(1.2, 0.5, 0.6);
	glVertex3f(1.22, 0.65, 0.6);

	glVertex3f(1.27, 0.63, .6);
	glVertex3f(1.25, 0.5, 0.6);        //quad back window
	glVertex3f(1.65, 0.5, 0.6);
	glVertex3f(1.67, 0.63, 0.6);


	

	glVertex3f(1.65, 0.65, 0.6);
	glVertex3f(1.65, 0.5, .6);
	glVertex3f(1.7, 0.5, 0.6);
	glVertex3f(1.7, 0.65, 0.6);
	glEnd();



	//**************************************************************
	glBegin(GL_QUADS);

	/* top of cube*/
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);        //quad front window
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(0.7, 0.65, 0.6);

	glVertex3f(1.7, 0.65, .6);
	glVertex3f(1.7, 0.65, 0.2);        //quad back window
	glVertex3f(1.8, 0.5, 0.2);
	glVertex3f(1.8, 0.5, 0.6);

	glEnd();


	
	glPopMatrix();

	//********************WHEEL*********************************************

	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	//glRotatef(_angle, 0.0, 0.0, 1.0);

	glTranslatef(0.6, 0.2, 0.6);
	//glColor3f(0,0,0);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(0, 0, -0.4);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(1.1, 0, 0);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(0, 0, 0.4);
	glutSolidTorus(0.025, 0.07, 20, 25);
	glPopMatrix();
	glPopMatrix();

	//glDisable(glColor3f);

}

void tank()
{



glPushMatrix();

glPushMatrix();
//gun part
	glTranslatef(-.25, 0.0, 0.0);

	glTranslatef(-.25, 0.0, 0.0);

glColor3f(1.0, .5, 0.0);
	GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glTranslatef(.15, -0.01, -0.2);
    glRotatef(90.0, -1.0, 0.0, 0.0);
	glRotatef(45.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.03,0.03,0.5,10.3,2.5);
glPopMatrix();
//upper_part
glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
glPopMatrix();


glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
//right_side
	glColor3f(1.0, 1.0, 0.9);
	glVertex3f(.1, -.039, .0);
	glVertex3f(.1, .04, .0);
	glVertex3f(-.45, .04, .0);
    glVertex3f(-.45, -.039, .0);
//left_side
 float z6=.5;

	glVertex3f(.1,-.039,-z6);
	glVertex3f(.1,.04,-z6);
	glVertex3f(-.45,.04,-z6);
    glVertex3f(-.45,-.039,-z6);

//fond side

    glVertex3f(.1, -.039, .0);
    glVertex3f(.1, -.039,-z6);
    glVertex3f(.1, .04, -z6);
    glVertex3f(.1, .04, 0);
//back side

	glVertex3f(-.45, .04, .0);
	glVertex3f(-.45, .04, -z6);
    glVertex3f(-.45, -.039, -z6);
    glVertex3f(-.45, -.039, 0.0);
glEnd();


glBegin(GL_QUADS);
//right part
glColor3f(0.0, 1.0, 0.0);
glVertex3f(-.56,-.04,0.0);
glVertex3f(-.54,-.19,0.0);
glVertex3f(.20,-.19,0.0);
glVertex3f(.24,-.04,0.0);
//left part
glVertex3f(-.56,-.04,-z6);
glVertex3f(-.54,-.19,-z6);
glVertex3f(.20,-.19,-z6);
glVertex3f(.24,-.04,-z6);
//font part
glColor3f(.0, .5, 0.0);
glVertex3f(.20,-.19,0.0);
glVertex3f(.20,-.19,-z6);
glVertex3f(.24,-.04,-z6);
glVertex3f(.24,-.04,0.0);

//back part
glVertex3f(-.56,-.04,0.0);
glVertex3f(-.56,-.04,-z6);
glVertex3f(-.54,-.19,-z6);
glVertex3f(-.54,-.19,0.0);

//upper part
glColor3f(0.0, .7, 0.0);
glVertex3f(-.56,-.04,0.0);
glVertex3f(-.56,-.04,-z6);
glVertex3f(.24,-.04,-z6);
glVertex3f(.24,-.04,0.0);

glEnd();
	glPopMatrix();


glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.06, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();
glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.19, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();

glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.32, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();

glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.45, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();

glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.58, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();

glPushMatrix();
    glTranslatef(0.19, 0.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-.67, -0.19, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    gluCylinder(quadratic,0.05,0.05,0.49,60.3,3.6);
glPopMatrix();


}

void twin_toewr_modify()
{

	//----------------------------
	glPushMatrix();
	glScalef(1.1, 0.6, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   


}


void building2()
{
	glPushMatrix();
	glScalef(1.1, 0.6, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   
}





void building3()
{
	glPushMatrix();
	glScalef(1.1, 0.6, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId8);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   
}





void building4()
{
	glPushMatrix();
	glScalef(1.1, 0.6, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId9);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
   
}

float z6=.5;


void cruis_ship()
{

	//@@@@@@@@@@@@@@@@@@@main code

glPushMatrix();

glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

glPushMatrix();

//upper_part
    glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	//glRotatef(_angle, 1.0, 0.0, 0.0);
glPushMatrix();
glBegin(GL_QUADS);
glColor3f(0.0, .95, 2.41);

glTexCoord2f(0, 1); glVertex3f(-.84,.20,0.0);
glTexCoord2f(2, 1); glVertex3f(-.74,.51,0.0);
 glTexCoord2f(2, 0); glVertex3f(.89,.49,.0);
 glTexCoord2f(0, 0); glVertex3f(1.3,.20,0.0);

glVertex3f(-.84,.20,-z6);
glVertex3f(-.74,.51,-z6);
glVertex3f(.89,.49,-z6);
glVertex3f(1.3,.20,-z6);

glVertex3f(-.84,.20,0.0);
glVertex3f(-.84,.20,-z6);
glVertex3f(-.74,.51,-z6);
glVertex3f(-.74,.51,0.0);

glVertex3f(.89,.49,.0);
glVertex3f(.89,.49,-z6);
glVertex3f(1.3,.20,-z6);
glVertex3f(1.3,.20,0.0);

glColor3f(1.0, 0.95, 1.41);
glVertex3f(-.74,.51,0.0);
glVertex3f(-.74,.51,-z6);
glVertex3f(.89,.49,-z6);
glVertex3f(.89,.49,.0);

glEnd();
glPopMatrix();

//lower body
glPushMatrix();
glBegin(GL_QUADS);
//right part
glColor3f(1.0, 1.0, 1.0);

glVertex3f(-1.,-.04,0.0);
glVertex3f(-.9,.2,0.0);
glVertex3f(1.4,.2,0.0);
glVertex3f(1.2,-.04,0.0);

glVertex3f(-1.,-.04,-z6);
glVertex3f(-.9,.2,-z6);
glVertex3f(1.4,.2,-z6);
glVertex3f(1.2,-.04,-z6);


glColor3f(1.0, 1.0, 1.0);
glVertex3f(-1.,-.04,0.0);
glVertex3f(-1.,-.04,-z6);
glVertex3f(-.9,.2,-z6);
glVertex3f(-.9,.2,0.0);

glVertex3f(1.4,.2,0.0);
glVertex3f(1.4,.2,-z6);
glVertex3f(1.2,-.04,-z6);
glVertex3f(1.2,-.04,0.0);

glColor3f(.0, 0.0, 0.8);

glVertex3f(-.9,.2,0.0);
glVertex3f(-.9,.2,-z6);
glVertex3f(1.4,.2,-z6);
glVertex3f(1.4,.2,0.0);



glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_QUADS);

glColor3f(.0, 0.5, 0.8);

glVertex3f(-.5,0.49,0.0);
glVertex3f(-.5,0.8,0.0);
glVertex3f(-.28,0.7,0.0);
glVertex3f(-.21,0.49,0.0);


glVertex3f(-.5,0.49,-z6);
glVertex3f(-.5,0.8,-z6);
glVertex3f(-.28,0.7,-z6);
glVertex3f(-.21,0.49,-z6);


glVertex3f(-.5,0.8,0.0);
glVertex3f(-.5,0.8,-z6);
glVertex3f(-.28,0.7,-z6);
glVertex3f(-.28,0.7,0.0);

glEnd();
glPopMatrix();
glPopMatrix();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
glPopMatrix();





}



void  sea_side()
{
	glPushMatrix();
	glScalef(1.1, 0.6, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	


	//-------------------------

	glPushMatrix();
	//glColor3f(0.0, 1.0, 0.0);

	//Twin Towers1
	// font side

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);  glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
  //back side
float z8=.4;

    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,-z8);

	
//upper side
   
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,1.0,0.0);



//lower side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,-.5,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(2, 0);glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);

	
	
//right side
    
    glTexCoord2f(0, 1); glVertex3f(-.5,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-.5,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-.5,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-.5,-.5,0.0);

	

//left side
 
    glTexCoord2f(0, 1); glVertex3f(-1.0,1.0,0.0);
    glTexCoord2f(2, 1); glVertex3f(-1.0,1.0,-z8);
    glTexCoord2f(2, 0); glVertex3f(-1.0,-.5,-z8);
    glTexCoord2f(0, 0); glVertex3f(-1.0,-.5,0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

    glEnd();
    glPopMatrix();
}

void moving_car()
{
	
glPushMatrix();
//gun part
    glTranslatef(-moving_car_z,0.0, 0.0);
	glPushMatrix();
	glTranslatef(-1.0,-1.0, 0.0);
	glPushMatrix();

	glBegin(GL_QUADS);
 //************************FRONT BODY****************************************
	glColor3f(1, 0, 0);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);


	// bottom of cube
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.2, 0.2, 0.2);


	// front of cube
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.2, 0.2, 0.2);

	/* back of cube.*/
	glColor3f(1,1,0);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);

	/* left of cube*/
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.2, 0.4, 0.6);

	/* Right of cube */
	glVertex3f(0.2, 0.2, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	//
	glVertex3f(0.7, 0.65, 0.6);
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(1.7, 0.65, 0.2);        //top cover
	glVertex3f(1.7, 0.65, 0.6);




	//******************MIDDLE BODY************************************

	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8, 0.5, 0.6);



	/* bottom of cube*/
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.6);

	/* back of cube.*/
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.5, 0.2);





	//*********************ENTER WINDOW**********************************
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.77, 0.63, 0.2);
	glVertex3f(0.75, 0.5, 0.2);        //quad front window
	glVertex3f(1.2, 0.5, 0.2);
	glVertex3f(1.22, 0.63, 0.2);

	glVertex3f(1.27, 0.63, .2);
	glVertex3f(1.25, 0.5, 0.2);        //quad back window
	glVertex3f(1.65, 0.5, 0.2);
	glVertex3f(1.67, 0.63, 0.2);




	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.7, 0.65, 0.6);
	glVertex3f(0.6, 0.5, 0.6);        //quad front window
	glVertex3f(1.2, 0.5, 0.6);
	glVertex3f(1.22, 0.65, 0.6);

	glVertex3f(1.27, 0.63, .6);
	glVertex3f(1.25, 0.5, 0.6);        //quad back window
	glVertex3f(1.65, 0.5, 0.6);
	glVertex3f(1.67, 0.63, 0.6);




	glVertex3f(1.65, 0.65, 0.6);
	glVertex3f(1.65, 0.5, .6);
	glVertex3f(1.7, 0.5, 0.6);
	glVertex3f(1.7, 0.65, 0.6);
	glEnd();



	//**************************************************************
	glBegin(GL_QUADS);

	/* top of cube*/

	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);        //quad front window
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(0.7, 0.65, 0.6);

	glVertex3f(1.7, 0.65, .6);
	glVertex3f(1.7, 0.65, 0.2);        //quad back window
	glVertex3f(1.8, 0.5, 0.2);
	glVertex3f(1.8, 0.5, 0.6);

	glEnd();



	glPopMatrix();

	//********************WHEEL*********************************************

	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	//glRotatef(_angle, 0.0, 0.0, 1.0);

	glTranslatef(0.6, 0.2, 0.6);
	//glColor3f(0,0,0);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(0, 0, -0.4);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(1.1, 0, 0);
	glutSolidTorus(0.025, 0.07, 20, 25);

	glTranslatef(0, 0, 0.4);
	glutSolidTorus(0.025, 0.07, 20, 25);
	glPopMatrix();
	glPopMatrix();
glPopMatrix();
	glEnd();
	glPopMatrix();
}

void plane_three()
{

		glPushMatrix();
		glTranslatef(-plan_trans3,1.15, 0.0);
		
		//glTranslatef(0.44,1.3, 0.0);
		glScalef(0.35,0.35,0.35);
		glPushMatrix();

		//MAIN BODY
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-.25, 0.0, 0.0);


		glColor3f(0.0, 1.0, 0.0);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glTranslatef(-.5, 0.0, 0.0);
		glRotatef(90.0, 0.0, 0.1, 0.0);
		gluCylinder(quadratic,0.13,0.1,1.2,30.3,7.3);
		glPopMatrix();


        glPushMatrix();
    
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(-.25, 0.0, 0.0);
	

		glBegin(GL_QUADS);
		glColor3f(1.0,.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);


		glColor3f(1.0,1.0,.0);
		glVertex3f(0.39,0.1, z2);
		glVertex3f(0.63,0.1, z2);
		glVertex3f(0.63,0.4, z2);
		glVertex3f(0.43,0.3, z2);
    

		glColor3f(0.0,1.0,.0);
		glVertex3f(0.63,0.1, 0);
		glVertex3f(0.63,0.1, .02);
		glVertex3f(0.63,0.4, .02);
		glVertex3f(0.63,0.4, 0);


	    glColor3f(0.0,1.0,.0);
		glVertex3f(0.39,0.1, z);
		glVertex3f(0.63,0.1, z);
		glVertex3f(0.63,0.4, z);
		glVertex3f(0.43,0.3, z);
    
		glEnd();

		glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.7,-0.1, .1);
        glVertex3f(-0.48,-0.1, .1);
        glVertex3f(-0.48,0.1, .1);
        glVertex3f(-0.53,0.1, .1);

		 glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-0.7,-0.1,-.1);
        glVertex3f(-0.48,-0.1,-.1);
        glVertex3f(-0.48,0.1, -.1);
        glVertex3f(-0.53,0.1, -.1);

        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.7,-0.1,.1);
        glVertex3f(-0.53,0.1,.1);
        glVertex3f(-0.53,0.1, -.1);
        glVertex3f(-0.7,-0.1,-.1);

			 glColor3f(1.0, 1.0, 1.0);
			 glVertex3f(-0.7,-0.1,.1);
			 glVertex3f(-0.48,-0.1, .1);
			 glVertex3f(-0.48,-0.1, -.1);
			 glVertex3f(-0.7,-0.1,-.1);
			glEnd();


		


    //left dana------------------------------------------------

	
	glScalef(0.2,0.2,0.2);
	glTranslatef(.45, 0.4, 6.5);
	glBegin(GL_QUADS);
	glColor3f(1.0,.0,.0);
	glVertex3f(-0.15,-.3, .0);
    glVertex3f(-0.05,-.3, .0);
    glVertex3f(-0.05,-.26, .0);
    glVertex3f(-0.15,-.26, .0);

		float z3=.4;
		z3=7;

    glColor3f(1.0,.0,1.0);
    glVertex3f(-0.15,-.3,0);
    glVertex3f(-1.9,-.3,-z3);
    glVertex3f(-0.05,-.3,-z3);
    glVertex3f(-0.05,-.3, .0);
	glEnd();

     //left dana end----------------------------------------------
     //right dana-------------------------------------------------
	
	glTranslatef(0.0, 0.0, -13.5);
    glRotatef(180, 1.0, 0.0, 0.0);
    glColor3f(1.0,.0,.0);
    glBegin(GL_QUADS);
	glVertex3f(-0.15,.3, .0);
    glVertex3f(-0.05,.3, .0);
    glVertex3f(-0.05,.26, .0);
    glVertex3f(-0.15,.26, .0);

    glColor3f(1.0,.0,1.0);
    glVertex3f(-0.15,.3,0);
    glVertex3f(-1.9,.3,-z3);
    glVertex3f(-0.05,.3,-z3);
    glVertex3f(-0.05,.3, .0);
	glEnd();
	//rigt dana end-------------------------------------------------

	glPopMatrix();
	glPopMatrix();

}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(_value, 0, 1, 0);
	gluLookAt(moveCX,moveCY,moveCZ,0,0,-2000, 0,2,1);
  //glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera

 	glTranslatef(0.0, 0.0, -10.0); //Move forward 5 units

	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, -1, 0);
	
	//sky();

	//road();

	

	


	glPushMatrix();
	glTranslatef(0,0,40);
	//bank();/// back
	glPopMatrix();









	




	glPushMatrix();
	//glRotatef(carTurn, 0, 1, 0);
	glPushMatrix();
	//glTranslatef(moveCarX,0,moveCarZ);
	//glRotatef(carTurn, 0, 1, 0);	
	//car();
	glPopMatrix();
	glPopMatrix();


//GROUND
	glPushMatrix();
	glTranslatef(-145,0,0);
	glScaled(10, 1, 5);
	ground();
	glPopMatrix();

//ROAD
	glPushMatrix();
	glTranslatef(0,0.01,0);
	glScaled(0.2, 1, 5);
	road();
	glPopMatrix();
	glPopMatrix();



	//**********************************************************************
	


	glPushMatrix();
    sky();
	glTranslatef(0,0, 2000);
	sky();
	glRotatef(90,0.0,1.0,0.0);
	glTranslatef(2000,0,0);
	sky();
	glTranslatef(0,0, 2000);
	sky();


	glPopMatrix();	

	glTranslatef(0.0, 2.0, -13.0); //Move forward 5 units
	glScaled(5, 5, 5);


	

///plane 1
    plane_one();
///plane 2
	plane_two();
///plane 3
	plane_three();

	
///tank_bullet
	Tank_bullet();
	Tank_bullet2();

	
//TREE
	tree();

//car
	//car();
//tank
	glPushMatrix();
	glTranslatef(-0.83,-0.75,1.1);
	glScalef(0.3, 0.3, 0.3);
	tank();
	glPopMatrix();
	

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@TWIN TOWER MODIFIED
//RIGHT TOWER BOTTOM PART
	glPushMatrix();
	glTranslatef(-0.2,-0.5,0.3);
	twin_toewr_modify();
	glPopMatrix();

//LEFT TOWER BOTTOM PART
	glPushMatrix();
	glTranslatef(-1.0,-0.5,0.3);
	twin_toewr_modify();
	glPopMatrix();


//RIGHT TOWER MIDDLE PART
	glPushMatrix();
	glTranslatef(-0.2,0.4,0.3);
	twin_toewr_modify();
	glPopMatrix();

//LEFT TOWER MIDDLE PART
	glPushMatrix();
	glTranslatef(-1.0,0.4,0.3);
	twin_toewr_modify();
	glPopMatrix();


//2nd additional buliding




	

	//glPopMatrix();
	glPushMatrix();
	glScalef(2.1, 6.0, 6.0);
	glTranslatef(-.6,-0.3,-2.0);
	building3();
	glPopMatrix();

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(-0.9,-0.09,-1.3);
	building4();
	glPopMatrix();

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-1.3);
	building2();
	glPopMatrix();

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-.3);
	building3();
	glPopMatrix();


	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-2.0);
	building3();
	glPopMatrix();


	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-3.0);
	building2();
	glPopMatrix();

	

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-4.0);
	building3();
	glPopMatrix();


	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-5.0);
	building2();
	glPopMatrix();

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-6.0);
	building3();
	glPopMatrix();

//	glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-7.0);
	building2();
	glPopMatrix();


	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-8.0);
	building2();
	glPopMatrix();

	//glPopMatrix();
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(0.2,-0.09,-9.0);
	building3();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(1.9, 2.1, 5.0);
	glTranslatef(-0.9,-0.09,-9.0);
	building3();
	glPopMatrix();


	

 //BROKEN BULIDNIG PERT
	glPushMatrix();
	broken_building_right();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8,0.0,0.0);
	broken_building_left();
	glPopMatrix();


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SEA SIDE
	
	glPushMatrix();
	glScalef(0.2, 0.7, 200.7);
	glTranslatef(6.,-1.5,0.01);
	sea_side();
	glPopMatrix();

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ car

	glPushMatrix();
	glScalef(0.2, 0.2,0.2);
	glRotatef(90,0.0,1.0,0.0);
	glTranslatef(100,-2.5,0.01);
	moving_car();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.2, 0.2,0.2);
	glRotatef(90,0.0,1.0,0.0);
	glTranslatef(10,-2.5,1.01);
	moving_car();
	glPopMatrix();
	
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ship AND SEA

	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	//glRotatef(90,0.0,1.0,0.0);
	glTranslatef(3.0, -1.0, 0.0);
	cruis_ship();
	glPopMatrix();
	

	glPushMatrix();
	glScalef(10.7, 1., 10.7);
	glTranslatef(3.0, 0.0, 5.0);
	sea();
	glPopMatrix();

	



	///energy left of tw1

	glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-1.3,2.2, 0.0);
	glScalef(5, 1.0, 1.0);
	glScalef(power_Tran, 1.0, 1.0);
    glutSolidCube(.05);
	glPopMatrix();







	/*glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(1.50,1.50,1.0);
	//glRotatef(35,1.0,0.0,0.0);
	//glRotatef(-45,0.0,1.0,0.0);
	//glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.55);
	//glutwirecylinder
	glPopMatrix();

*/

	//******************************************************************** end here





//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ GAME OVER FUNCTION #GAMEOVER
	char a = '1';
	char b = '2';
	//#game_terminate_condition

	if (broken_bulding_Signal==2 && just_view_without_game==0)
	{
		winner(a);

	}

		else if (colCountR == 3)
		{
			winner(b);
		}

	glFlush();
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ GAME OVER


	glutSwapBuffers();
}



void update(int value) {
	if(flag==0)
	{		if (moveCarZ > -42)
		{
			moveCarZ -= 0.1f;
			if (moveCarZ <= -40)
			{
				carTurn -= 1;
				moveCarX += 0.1f;
			}
		}
		else if (flag == 0)
		{
			moveCarZ = -42;
			if (carTurn > -180)
			{
				carTurn -= 1;
			}
			if ((moveCarX < 30))
			{
				moveCarX += 0.1f;

			}
			else
			{
				moveCarX = 30;
				if (carTurn > -270)
				{
					carTurn -= 1;

				}
				if (carTurn == -270)
				{
					flag = 1;
				}
			}
		}
	}
	else
	{
		if (moveCarZ < 1)
		{
			moveCarZ += .1f;
		}
		else
		{
			//moveCarZ = -2.9;
			if (carTurn > -360)
			{
				carTurn -= 1;

			}		
			if (moveCarX > -0.5)
			{
				moveCarX -= 0.1f;
			}
			else
			{
				if (carTurn > -450)
				{
					carTurn -= 1;

				}
				if (carTurn == -450)
				{
					flag = 0;
					carTurn = -90;
				}
			}
			
		}

	}

	mov_truckZ += .2f;
	
	if (mov_truckZ > 100)
	{
		mov_truckZ = -100;
	}
	_wheel += 2.0f;
	if (_wheel > 360) {
		_wheel -= 360;
	}



	//******************************************* my code

	
    if(s==1 )
    {

       	if(bullet_Trans<2.5){
		
			/*
           bullet_Trans+=0.0025;
		   bullet_Trans_X+=0.00175;
		   bullet_Trans_Z-=0.00125;
		  
		*/
		  
		   bullet_Trans+=0.05;
		   bullet_Trans_X+=0.035;
		   bullet_Trans_Z-=0.025;
		  
		}

        else{
            s=0;
            bullet_Trans=-0.9;
			bullet_Trans_X=-1;
			 bullet_Trans_Z=1.0;
          }

    }


	//@@@@@@@@@@@@@@@@@@@@@@ button 2 for 2nd bullet

 if(second==1 )
    {

       	if(bullet2_Trans<2.5){
		
			/*
           bullet_Trans+=0.0025;
		   bullet_Trans_X+=0.00175;
		   bullet_Trans_Z-=0.00125;
		  
		*/
		  
		   bullet2_Trans+=0.05;
		   bullet2_Trans_X+=0.035;
		   bullet2_Trans_Z-=0.025;
		  
		}

        else{
			second=0;
            bullet2_Trans=-0.9;
			bullet2_Trans_X=-1;
			 bullet2_Trans_Z=1.0;
          }

    }

//	cout<<"R "<< _value <<" ";
cout<<"x "<< moveCX <<" ";
cout<<"Y "<< moveCY  <<" ";
 cout<<"Z "<< moveCZ <<endl;


if(game_view==0)
{
		//****************** IF BULLET HIT PLANE 1
			   if(bullet_Trans >=1.4 && bullet_Trans <=1.6 && plan_trans<=-0.54 && plan_trans>=-1.05 ){

                
						s=0;
						bullet_Trans=-0.9;
						bullet_Trans_X=-1;
						bullet_Trans_Z=1.0;
						 plan_trans=-16.9;
						 game_score++;


			  }


		//****************** IF BULLET HIT PLANE 2
			if(bullet_Trans >=1.2 && bullet_Trans <=1.4 && plan_trans2<=-0.35 && plan_trans2>=-0.89 ){

                
						s=0;
						bullet_Trans=-0.9;
						bullet_Trans_X=-1;
						bullet_Trans_Z=1;
						plan_trans2=-3.9;
						game_score++;

      }
                   //****************** IF BULLET HIT PLANE 3
			if(bullet_Trans >=1.001 && bullet_Trans <=1.17 && plan_trans3<=-0.27 && plan_trans3>=-0.78 ){

                
						s=0;
						bullet_Trans=-0.9;
						bullet_Trans_X=-1;
						bullet_Trans_Z=1;
						plan_trans3=-10;
						game_score++;

      }




				//****************** IF BULLET two HIT PLANE 1
			   if(bullet2_Trans >=1.4 && bullet2_Trans <=1.6 && plan_trans<=-0.55 && plan_trans>=-1.05 ){

                
				        second=0;
						bullet2_Trans=-0.9;
						bullet2_Trans_X=-1;
						bullet2_Trans_Z=1.0;
						 plan_trans=-16.9;
						 game_score++;

			  }


		//****************** IF BULLET two HIT PLANE 2
			if(bullet2_Trans >=1.2 && bullet2_Trans <=1.4 && plan_trans2<=-0.35 && plan_trans2>=-0.89 ){

                
						second=0;
						bullet2_Trans=-0.9;
						bullet2_Trans_X=-1;
						bullet2_Trans_Z=1;
						plan_trans2=-3.9;
						game_score++;
			}
 
		//****************** IF BULLET two HIT PLANE 3
		  if(bullet2_Trans >=1.05 && bullet2_Trans <=1.17 && plan_trans3<=-0.27 && plan_trans3>=-0.78 ){

                
							second=0;
							bullet2_Trans=-0.9;
							bullet2_Trans_X=-1;
							bullet2_Trans_Z=1;
							plan_trans3=-3.9;
							game_score++;
				}
}




	if(which_tower_detect==1) //which_tower_detect==1 means first tower collide.
	{
      if(plan_trans>=0.9 )
      {
           plan_trans=-16.9;
		
		   broken_bulding_Signal=1;
		   which_tower_detect=2;

      }

        if(plan_trans2>=0.9 )
      {
           plan_trans2=-3.9;

              if(power_Tran!=0)
		   {
			   power_Tran=power_Tran-1;
		   }
           
		   broken_bulding_Signal=1;
		   which_tower_detect=2;

      }

	if(plan_trans3>=0.9 )
      {
           plan_trans3=-10;
		      if(power_Tran!=0)
		   {
			   power_Tran=power_Tran-1;
		   }
          
		   broken_bulding_Signal=1;
		   which_tower_detect=2;

      }
	}
	
	
	if(which_tower_detect==2)
	{
		if(plan_trans>=1.8 )
      {
           plan_trans=-16.9;
		      if(power_Tran!=0)
		   {
			   power_Tran=power_Tran-1;
		   }
           
           
		   broken_bulding_Signal=2;

      }

	if(plan_trans2>=1.8 )
      {
           plan_trans2=-3.9;
		      if(power_Tran!=0)
		   {
			   power_Tran=power_Tran-1;
		   }
           
		   broken_bulding_Signal=2;

      }

		if(plan_trans3>=1.8 )
      {
           plan_trans3=-10;
		      if(power_Tran!=0)
		   {
			   power_Tran=power_Tran-1;
		   }
          
		   broken_bulding_Signal=2;

      }


	}

		if(broken_bulding_Signal==1)
          {
			  if(broken_bulding_y>-0.85){
				  broken_bulding_y-=0.02;
				  broken_bulding_x+=0.01;
				  demo_angle+=0.2;
				}
				else{
					broken_bulding_Signal=0;
					broken_bulding_x=1.31;
					broken_bulding_y=-0.85;
				  }

		 }
		
		else if(broken_bulding_Signal==2)
          {
			  if(broken_bulding2_y>-0.85){
				  broken_bulding2_y-=0.02;
				  broken_bulding2_x+=0.01;
				  demo_angle2+=0.2;
				}
				else{
					broken_bulding_Signal=0;
					broken_bulding2_x=1.31;
					broken_bulding2_y=-0.85;
				  }

		 }





	  





 plan_trans += 0.037f;
	if (plan_trans > 1.9) {
		plan_trans -=16.9;
	}


 plan_trans2 += 0.017f;
	if (plan_trans2 > 9.0) {
		plan_trans2 -=9.9;
	}

	
 plan_trans3 += 0.027f;
	if (plan_trans3 > 9.0) {
		plan_trans3 -=7;
	}


//@@@@@@@@@@@@@@@@@@car moving (depend on clliosoion)
if(broken_bulding_Signal==0)
{
	
	moving_car_z += 0.5f;
	if (moving_car_z > 100.0) {
		moving_car_z -=200;
	}

}




      //*****************************************************my code end

	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 800);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	//glutSpecialFunc(specialKey);
	glutKeyboardFunc(keyFunc);
	glutPassiveMotionFunc(passive);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer
	glutFullScreen();
	
	glutMainLoop();
	return 0;
}





