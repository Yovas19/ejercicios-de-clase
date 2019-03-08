//Semestre 2019 - 2
//Laboratorio de computacion grafica//
//grupo 2//
//Alumno (s): Villegas Guerrero Yovany Rafael //
//Practica 5											******//
//ejercicio de clase										******//
//Fecha: 7 de marzo de 2019//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0f;
float angCodo = 0.0f;
float angMu = 0.0f;




GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	
	//hombro
	glScalef(0.3, 0.5, 0.5);
	glRotatef(angHombro, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	prisma();
	glScalef(3.3, 2.0, 1.0);
	
	//bicep
	glTranslatef(0.65, 0.0, 0.0);
	glScalef(1.0, 0.5, 1.0);  
	glColor3f(0.0, 0.0, 1.0);
	prisma();
	glScalef(1.0, 2.0, 1.0);

	//codo
	glTranslatef(0.60, 0.0, 0.0);
	glRotatef(angCodo, 0.0, 0.0, 1.0); 
	glScalef(0.2, 0.5, 1.0);  
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glScalef(5.0, 2.0, 1.0);

	//antebrazo
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(0.8, 0.5, 1.0);
	glColor3f(0.0, 1.0, 1.0);
	prisma();
	glScalef(1.25, 2.0, 1.0);

	//muñeca
	glTranslatef(0.45, 0.0, 0.0);
	glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.1, 0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	prisma();
	glScalef(10.0, 2.0, 1.0);

	//palma
	glTranslatef(0.35, 0.0, 0.0);
	glScalef(0.6, 0.5, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	prisma();
	glScalef(1.66, 2.0, 1.0);

	//dedo gordo
	glTranslatef(-0.27, 0.35, 0.0);
	//glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.1, 0.25, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	prisma();
	glScalef(10.0, 4.0, 1.0);

	//dedo indice
	glTranslatef(0.75, -0.140, 0.0);
	//glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.35, 0.1, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	prisma();
	glScalef(2.85, 10.0, 1.0);

	//dedo medio
	glTranslatef(0.0, -0.15, 0.0);
	//glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.43, 0.1, 0.5);
	glColor3f(1.0, 1.0, 0.0);
	prisma();
	glScalef(2.32, 10.0, 1.0);

	//dedo anular
	glTranslatef(0.0, -0.15, 0.0);
	//glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.35, 0.1, 0.5);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glScalef(3.3, 10.0, 1.0);

	//dedo meñique
	glTranslatef(-0.05, -0.15, 0.0);
	//glRotatef(angMu, 0.0, 1.0, 0.0);
	glScalef(0.25, 0.1, 0.5);
	glColor3f(1.0, 1.0, 1.0);
	prisma();
	glScalef(3.3, 10.0, 1.0);


	



	

		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'p':
			if (angHombro < 90)
				angHombro += 0.5f;
			printf("ang: %f\n", angHombro);
			break;
		case 'P':
			if (angHombro > -90)
				angHombro -= 0.5f;
			printf("ang: %f\n", angHombro);
			break;
		case 'o':
			if (angCodo < 120)
				angCodo += 0.5f;
			printf("ang: %f\n", angCodo);
			break;
		case 'O':
			if (angCodo > 0)
				angCodo -= 0.5f;
			//printf("ang: %f\n", angCodo);
			break;
		case 'l':
			if (angMu < 45)
				angMu += 0.5f;
			printf("ang: %f\n", angMu);
			break;
		case 'L':
			if (angMu > -90)
				angMu -= 0.5f;
			//printf("ang: %f\n", angCodo);
			break;
		//case 's':
		//case 'S':
			//transZ -= 0.2f;
			//break;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



