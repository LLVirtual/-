#include <iostream>
#include <GL\freeglut.h>
#include "Cmymesh.h"
using namespace std;

MyMesh mesh;
///<summary>
///��Ⱦ����
///</summary>
void RenderScence()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//����ǰ�󻺴�
	glutSwapBuffers();
}

void draw_axis()
{
	glLineWidth(2.0);

	//x axis
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);//��������ϵ
	glEnd();
	//y axis
	glColor3f(0.0, 1.0, 0);		//green
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 1, 0);
	glEnd();

	//z axis
	glColor3f(0.0, 0.0, 1.0);	//blue
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 1);
	glEnd();

	glLineWidth(1.0);

	
}

void draw_mesh() {
	//ͨ�������ҵ����еĶ���
	for (std::list<Face*>::iterator fiter = mesh.faces().begin(); fiter != mesh.faces().end(); fiter++)
	{
		glBegin(GL_POLYGON);
		Face *f = *fiter;
		HalfEdge *pH = f->m_halfedge;
		for (size_t i = 0; i < 3; i++)
		{
			Vertex *v = pH->target();
			Point p = v->m_position;
			//glColor3f(rgb[0], rgb[1], rgb[2]);
			glVertex3d(p.x,p.y,p.z);
			pH = pH->m_next_halfedge;
			if (pH == f->m_halfedge)break;
		}
		glEnd();
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�����ɫ�������Ȼ���

	glPushMatrix();

	draw_mesh();
	draw_axis();

	glPopMatrix();
	//����ǰ�󻺴�
	glutSwapBuffers();
}

void init_openGL(int argc, char *argv[])
{
	//��ʼ��GLUT
	glutInit(&argc, argv);

	//��������
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//��������
	glutInitWindowSize(1280, 720);

	//����λ��
	glutInitWindowPosition(100, 100);

	//���ڱ���
	glutCreateWindow("��߽ṹ���װ汾");

	//��ʼ��Ⱦ
	//glutDisplayFunc(RenderScence);

	glutDisplayFunc(display);

	//���ñ�����ɫ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

}

int main(int argc,char **argv)
{


	mesh.read_m("face.m");
	cout << mesh.numEdge()<<"::"<<mesh.numVertex()<<"::"<<mesh.numFaces() << endl;
	init_openGL(argc, argv);
	system("PAUSE");
	return 0;
}
