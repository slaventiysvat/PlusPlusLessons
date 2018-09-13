#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <math.h>

using namespace std;

const int winW = 750;
const int winH = 550;




void setFractal(sf::VertexArray & target_va) {
	float cRe = -0.70176 , cIm = -0.3842;
	// ������������ � ������ ����� ������ � �����
	float newRe, newIm, oldRe, oldIm;
	
	//���������� ����� ������ ����� �������� ������� ������ ���������� ���� ������
	int maxIt = 300;

	//"����������" ������ �������
	for (int x = 0; x < winW; ++x) {
		for (int y = 0; y < winH; ++y){
			//����������� �������� � ������ ����� ����� z
			//�� ������ ������������ ��������,��������������� � �������� �������
			newRe = 1.5 * (x - winW / 2) / (0.5 * winW);
			newIm = (y - winH / 2) / (0.5 * winH);



			//���������� ������� ��������
			int curr_it;
			for (curr_it = 0; curr_it < maxIt; ++curr_it) {
				//���������� �������� ���������� ��������
				oldRe = newRe;
				oldIm = newIm;

				// � ������� �������� ����������� �������������� � ������ ����� 
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;

				// ���� ����� ��������� ��� ����� � �������� 2 - �����������
				if (newRe * newRe + newIm * newIm > 4)
					break;
			}

			sf::Vertex tmp;
			tmp.color = sf::Color((curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 60, (curr_it - 1 * 9) % 150);
			//������ �������

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
			// ������� �������� ���� �� ����� �� ������� � �� ������� Esc
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				return 0;
		}
		window.clear(sf::Color::Black);

		window.draw(va);

		window.display();
	}
	return 0;
}