#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <math.h>

using namespace std;

const int winW = 750;
const int winH = 550;




void setFractal(sf::VertexArray & target_va) {
	float cRe = -0.70176 , cIm = -0.3842;
	// вещественна€ и мнима€ части старой и новой
	float newRe, newIm, oldRe, oldIm;
	
	//ќпредел€ем после какого числа итераций функци€ должна прекратить свою работу
	int maxIt = 300;

	//"перебираем" каждый пиксель
	for (int x = 0; x < winW; ++x) {
		for (int y = 0; y < winH; ++y){
			//вычисл€етс€ реальна€ и мнима€ части числа z
			//на основе расположени€ пикселей,масштабировани€ и значени€ позиции
			newRe = 1.5 * (x - winW / 2) / (0.5 * winW);
			newIm = (y - winH / 2) / (0.5 * winH);



			//начинаетс€ процесс итерации
			int curr_it;
			for (curr_it = 0; curr_it < maxIt; ++curr_it) {
				//«апоминаем значение предыдущей итерации
				oldRe = newRe;
				oldIm = newIm;

				// в текущей итерации вычисл€ютс€ действительна€ и мнима€ части 
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;

				// если точка находитс€ вне круга с радиусом 2 - прерываемс€
				if (newRe * newRe + newIm * newIm > 4)
					break;
			}

			sf::Vertex tmp;
			tmp.color = sf::Color((curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 150);
			//рисуем пиксель

			tmp.position = sf::Vector2f(x, y);

			target_va.append(tmp); 
		}
	}
}



int main() {
	sf::RenderWindow window(sf::VideoMode(winW, winH), "FRACTAL");

	sf::VertexArray va;
	va.setPrimitiveType(sf::Points);

	setFractal(va);

	while (1) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// —обыти€ закрыти€ окну по клику на крестик и по нажатию Esc
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				return 0;
		}
		window.clear(sf::Color::Black);

		window.draw(va);

		window.display();
	}
	return 0;
}