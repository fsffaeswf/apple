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
	


 // Объект, который, собственно, является главным окном приложения
 RenderWindow window(VideoMode(size, size), "SFML Works!");
 // Главный цикл приложения. Выполняется, пока открыто окно
 while (window.isOpen())
 {
  // Обрабатываем очередь событий в цикле
  Event event;
  while (window.pollEvent(event))
  {
   // Пользователь нажал на «крестик» и хочет закрыть окно?
   if (event.type == Event::Closed)
    // тогда закрываем его
    window.close();
  }
  //двигаем круг
  
  for (int i = 0; i < n; i++) {
	  arr_circles[i].move(0, BatDy);
  }
  for (int i = 0; i < n; i++) {
	  if (arr_circles[i].getPosition().y + ay > size+6*r) {
		  arr_circles[i].setPosition(rand() % size1, -rand() % size1 / 2);
	  }
	  
  }
 // Отрисовка окна 


  window.clear();
  for (int i = 0; i < n; i++) {
	  window.draw(arr_circles[i]);
  }
  window.display();
 }
 
 return 0;
}