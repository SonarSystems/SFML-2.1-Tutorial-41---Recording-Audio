#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	if (!sf::SoundBufferRecorder::isAvailable())
	{
		// error
	}

	sf::SoundBufferRecorder recorder;

	recorder.start();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				recorder.stop();
				const sf::SoundBuffer &buffer = recorder.getBuffer();

				buffer.saveToFile("recording.ogg");

				window.close();

				break;

			}
		}

		window.clear();

		window.display();
	}
}