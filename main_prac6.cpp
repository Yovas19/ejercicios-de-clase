//Semestre 2019 - 2
//Laboratorio de computacion grafica//
//Grupo:2//
//Alumno (s): Villegas Guerrero Yovany Rafael//
//PRACTICA 6//
//Ejercicio de clase "sistema Solar//
//Fecha: 12 de marzo de 2019//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna_tierra = 0;
int luna_marte = 0;
int luna_jupiter1 = 0;
int luna_jupiter2 = 0;
int luna_saturno1 = 0;
int luna_saturno2 = 0;
int luna_urano1 = 0;
int luna_urano2 = 0;
int luna_neptuno1 = 0;
int luna_neptuno2 = 0;
int anillo = 0; 




float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	
	glPushMatrix();//sistema solar
		
		glPushMatrix(); // sol
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glutSolidSphere(4.0,12,12);  //Draw Sun (radio,H,V);
		glPopMatrix();//sol

		glPushMatrix();//mercurio
			glRotatef(mercurio, 0, 1, 0); //translacion
			glTranslatef(8.0, 0.0, 0.0);
			glColor3f(1.0, 0.458, 0.078);
			glRotatef(mercurio, 0, 1, 0);//rotacion
			glutSolidSphere(0.5, 12, 12); 
		glPopMatrix(); //mercurio

	

		glPushMatrix();//venus
			glRotatef(venus, 0, 1, 0); //translacion
			glTranslatef(9.0, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.4);
			glRotatef(venus, 0, 1, 0);//rotacion
			glutSolidSphere(0.8, 12, 12); 
		glPopMatrix(); //venus

		glPushMatrix();//tierra
			glRotatef(tierra, 0, 1, 0); //translacion
			glTranslatef(10.0, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glRotatef(tierra, 0, 1, 0);//rotacion
			glutSolidSphere(0.95, 12, 12);

			glPushMatrix();//luna de la tierra
				glRotatef(luna_tierra, 0, 1, 0); //translacion
				glTranslatef(1.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_tierra, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna
			
		glPopMatrix();//tierra
		
			
		glPushMatrix();//marte
			glRotatef(marte, 0, 1, 0); //translacion
			glTranslatef(12.0, 0.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glRotatef(marte, 0, 1, 0);//rotacion
			glutSolidSphere(0.8, 12, 12);

			glPushMatrix();//luna de marte
				glRotatef(luna_marte, 0, 1, 0); //translacion
				glTranslatef(1.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_marte, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de marte
		glPopMatrix(); //marte

		glPushMatrix();//jupiter
			glRotatef(jupiter, 0, 1, 0); //translacion
			glTranslatef(12.0, 0.0, 0.0);
			glColor3f(1.0, 0.4, 0.07);
			glRotatef(jupiter, 0, 1, 0);//rotacion
			glutSolidSphere(2.0, 12, 12);

			glPushMatrix();//luna de jupiter1
				glRotatef(luna_jupiter1, 0, 1, 0); //translacion
				glTranslatef(2.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_jupiter1, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de jupiter1

			glPushMatrix();//luna de jupiter2
				glRotatef(luna_jupiter2, 0, 1, 0); //translacion
				glTranslatef(2.8, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_jupiter2, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de jupiter2

		glPopMatrix(); //jupiter

		glPushMatrix();//saturno
			glRotatef(saturno, 0, 1, 0); //translacion
			glTranslatef(17.0, 0.0, 0.0);
			glColor3f(0.8, 0.5, 0.5);
			glRotatef(saturno, 0, 1, 0);//rotacion
			glutSolidSphere(2.0, 12, 12);

			glPushMatrix();//luna de saturno
				glRotatef(luna_saturno1, 0, 1, 0); //translacion
				glTranslatef(2.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_saturno1, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de saturno

			glPushMatrix();//luna de saturno2
				glRotatef(luna_saturno2, 0, 1, 0); //translacion
				glTranslatef(3.0, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_saturno2, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de saturno 2

			glPushMatrix();//anillo de saturno
				//glRotatef(anillo, 0, 1, 0); //translacion
				glTranslatef(0.0, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				//glRotatef(anillo, 0, 1, 0);//rotacion
				glRotatef(45, 1, 0, 0);
				glutSolidTorus(0.2,2.3,30, 30); 
				glColor3f(0.4, 0.6, 0.9);
				glutSolidTorus(0.2, 2.7, 30, 30);
			glPopMatrix(); //anillo de saturno

		glPopMatrix(); //saturno

		glPushMatrix();//urano
			glRotatef(urano, 0, 1, 0); //translacion
			glTranslatef(21.0, 0.0, 0.0);
			glColor3f(0.2, 0.8, 0.9);
			glRotatef(urano, 0, 1, 0);//rotacion
			glutSolidSphere(1.5, 12, 12);

			glPushMatrix();//luna de urano1
				glRotatef(luna_urano1, 0, 1, 0); //translacion
				glTranslatef(-2.4, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_urano1, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de urano1

			glPushMatrix();//luna de urano2
				glRotatef(luna_urano2, 0, 1, 0); //translacion
				glTranslatef(2.5, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_urano2, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de urano2
		glPopMatrix(); //urano

		glPushMatrix();//neptuno
			glRotatef(urano, 0, 1, 0); //translacion
			glTranslatef(25.0, 0.0, 0.0);
			glColor3f(0.2, 0.2, 0.9);
			//glRotatef(urano, 0, 1, 0);//rotacion
			glutSolidSphere(1.3, 12, 12);

			glPushMatrix();//luna de neptuno1
				glRotatef(luna_neptuno1, 0, 1, 0); //translacion
				glTranslatef(-1.8, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_neptuno1, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de urano1

			glPushMatrix();//luna de neptuno2
				glRotatef(luna_neptuno2, 0, 1, 0); //translacion
				glTranslatef(1.8, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_neptuno2, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); //luna de neptuno2
		glPopMatrix(); //neptuno

	glPopMatrix();//sistema solar

glutSwapBuffers ( );
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 3) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra - 3) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 2) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 2) % 360;
		luna_tierra = (luna_tierra - 3) % 360;
		luna_marte = (luna_marte - 3) % 360;
		luna_jupiter1 = (luna_jupiter1 - 3) % 360;
		luna_jupiter2 = (luna_jupiter2 - 3) % 360;
		luna_saturno1 = (luna_saturno1 - 3) % 360;
		luna_saturno2 = (luna_saturno2 - 3) % 360;
		luna_urano1 = (luna_urano1 - 3) % 360;
		luna_urano2 = (luna_urano2 - 3) % 360;
		luna_neptuno1 = (luna_neptuno1 - 3) % 360;
		luna_neptuno2 = (luna_neptuno2 - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}