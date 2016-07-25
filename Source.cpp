#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	//sf::RenderWindow window(sf::VideoMode(1280, 720), "ProceduralMapCreaction", sf::Style::Close);
	sf::Image map_image, colors_image;
	std::cout << "Podaj nazwe pliku" << std::endl;
	
	std::string filename = "";

	std::cin >> filename;

	std::string path = "Graphics/" + filename + ".png";
	map_image.loadFromFile(path);
	colors_image.loadFromFile("Graphics/Colors.png");
	
	int width_color_image = colors_image.getSize().x;
	int height_color_image = colors_image.getSize().y;

	int width_map_image = map_image.getSize().x;
	int height_map_image = map_image.getSize().y;
	std::cout << width_map_image << " " << height_map_image << std::endl;
	std::vector<sf::Color> color_vector;
	std::vector<std::vector<int>> map_matrix;
	map_matrix.resize(width_map_image);
	for (int i = 0; i < map_matrix.size(); i++)
		map_matrix[i].resize(height_map_image);


	for (int x = 0; x < width_color_image; x++)
		for (int y = 0; y < height_color_image; y++)
			color_vector.push_back(colors_image.getPixel(x, y));
	std::cout << "wczytywanie kolorow zakonczone " << color_vector.size() << std::endl;
	for (int x = 0; x < map_matrix.size(); x++)
	{
		for (int y = 0; y < map_matrix[x].size(); y++)
		{
			int i = 0;
			while (color_vector[i] != map_image.getPixel(x,y)) i++;
			map_matrix[x][y] = i;
			//std::cout << x << " " << y << std::endl;;
		}

	}
	
	std::cout << "Konwersja mapy zakonczona" << std::endl;
	std::fstream map_file;
	

	map_file.open("Maps/Test_map.txt", std::ios::out);
	map_file << width_map_image << " " << height_map_image << std::endl;
	for (int y = 0; y < map_matrix[0].size(); y++)
	{
		for (int x = 0; x < map_matrix.size(); x++)
			map_file << map_matrix[x][y] << " ";
		map_file << "\n";
	}
	map_file.close();
	std::cout << "Zapis pliku zakonczony" << std::endl;
	std::cin >> width_color_image;
	return 0;

}