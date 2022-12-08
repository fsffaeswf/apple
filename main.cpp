#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
using namespace sf;


int main()
{
	

	srand(time(nullptr));
	for (int i = 0; i < n; i++) {
		arr_circles[i].setRadius(r);
		arr_circles[i].setFillColor(Circle_Color);
		arr_circles[i].setPosition(rand()%size1, -rand() % size1/2);
	}
	


 // ������, �������, ����������, �������� ������� ����� ����������
 RenderWindow window(VideoMode(size, size), "SFML Works!");
 // ������� ���� ����������. �����������, ���� ������� ����
 while (window.isOpen())
 {
  // ������������ ������� ������� � �����
  Event event;
  while (window.pollEvent(event))
  {
   // ������������ ����� �� �������� � ����� ������� ����?
   if (event.type == Event::Closed)
    // ����� ��������� ���
    window.close();
  }
  //������� ����
  
  for (int i = 0; i < n; i++) {
	  arr_circles[i].move(0, BatDy);
  }
  for (int i = 0; i < n; i++) {
	  if (arr_circles[i].getPosition().y + ay > size+6*r) {
		  arr_circles[i].setPosition(rand() % size1, -rand() % size1 / 2);
	  }
	  
  }
 // ��������� ���� 


  window.clear();
  for (int i = 0; i < n; i++) {
	  window.draw(arr_circles[i]);
  }
  window.display();
 }
 
 return 0;
}