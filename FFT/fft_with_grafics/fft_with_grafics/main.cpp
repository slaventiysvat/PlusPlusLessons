#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>

int count = 0;  // ������ ������ �,�
float* X; // ����� ��� �������� �-��
float* Y; // ����� ��� �������� �-��

void display(){                    // ������� ����������� �������
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 50, 0);   // ��������� ������� ���������
	glVertex3f(0, -50, 0);
	glVertex3f(-50, 0, 0);
	glVertex3f(50, 0, 0);

	for (int i = -11; i < 8; i++){
		glVertex3f(10 + i * 5, -2, 0);
		glVertex3f(10 + i * 5, 2, 0);
	}

	for (int i = -11; i < 8; i++){
		glVertex3f(-2, 10 + i * 5, 0);
		glVertex3f(2, 10 + i * 5, 0);
	}// ����� ��������� ������� �������

	glEnd();

	glBegin(GL_POINTS); // ��������� ����� ������� �������
	float y;
	for (int i = 0; i < count; i++){
		glVertex3f(X[i], Y[i], 0);
	}
	glEnd();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	std::vector<float> arr;  // ������ � ������� ����� ������� ����� �� �����
	std::ifstream fin;       // ��� ������ ����� �� �����
	std::string path;        // ���� � ����� 
	do{                      // ���� ������� ������������ �������� �����
		std::cout << "Enter path: ";
		std::cin >> path;
		fin.open(path.c_str());
		if (!fin.is_open()){
			std::cout << "Error: File not find!\n";
		}
	} while (!fin.is_open());

	float i = 0.0;
	while (!fin.eof()){  // ������ ����� �� ����� � ������
		fin >> i;
		arr.push_back(i);
	}
	fin.close();

	for (int j = 0; j < arr.size(); j++){  // ���� ��� �������� �-�� � ���������
		if (arr[j] > -50.0 && arr[j] < 50.0) // [-50;50]
		{
			count++;
		}
	}
	X = new float[count];  // �������� ������ � �
	Y = new float[count];  // �������� ������ � �

	int n = 0;
	for (int j = 0; j < arr.size(); j++){  // ���� ��� ������ �����(�) ���������
		if (arr[j] > -50.0 && arr[j] < 50.0){ // ��������� � ����� �
			X[n] = arr[j];
			n++;
		}
	}

	for (int j = 0; j < count; j++){
		Y[j] = 2 * sin(X[j])*pow(M_E, 4 / 5);  // ���������� ������ �
	}
	// ����������� �������� ���� � OpenGl
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(20, 810);
	glutCreateWindow("Rownanie");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-55, 55, -55, 55, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	delete[] X;
	delete[] Y;
}