#include <cstdlib>
#include <string>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char *arvg[])
{
    std::string data;
    std::string line;
    while (std::getline(std::cin, line))
    {
        data.append(line);
    }
    if (data.length() != 81)
    {
        std::cerr << "Board data must contain exactly 81 digits." << std::endl;
        return EXIT_FAILURE;
    }
    int cell_size = 40;
    int padding = cell_size / 10;
    std::string stroke_color = "#222";
    std::cout << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << (9 * cell_size + 2 * padding) << "\" height=\"" << (9 * cell_size + 2 * padding) << "\" version=\"1.1\">" << std::endl
              << " <style>" << std::endl
              << " text {" << std::endl
              << "  font-family: \"Courier New\", Courier, monospace;" << std::endl
              << "  font-size: " << ((float)cell_size / 1.618) << "px;" << std::endl
              << "  text-anchor: middle;" << std::endl
              << "  dominant-baseline: middle;" << std::endl
              << "  color: " << stroke_color << std::endl
              << " }" << std::endl
              << " </style>" << std::endl
              << " <g transform=\"translate(" << padding << " " << padding << ")\" stroke=\"" << stroke_color << "\">" << std::endl
              << "  <rect x=\"0\" y=\"0\" width=\"" << (9 * cell_size) << "\" height=\"" << (9 * cell_size) << "\" fill=\"white\" />" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        float stroke_width = (i % 3) == 0
                                 ? 2.f
                                 : 0.5f;
        std::cout << "  <line stroke-width=\"" << stroke_width << "\" x1=\"" << (i * cell_size) << "\" y1=\"0\" x2=\"" << (i * cell_size) << "\" y2=\"" << (9 * cell_size) << "\"/>" << std::endl
                  << "  <line stroke-width=\"" << stroke_width << "\" x1=\"0\" y1=\"" << (i * cell_size) << "\" x2=\"" << (9 * cell_size) << "\" y2=\"" << (i * cell_size) << "\"/>" << std::endl;
    }
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            char cell = data.at(static_cast<size_t>(row * 9 + col));
            if (cell != '0')
            {
                std::cout << "  <text x=\"" << ((col + 0.5) * cell_size) << "\" y=\"" << ((row + 0.5) * cell_size) << "\">" << cell << "</text>" << std::endl;
            }
        }
    }
    std::cout << " </g>" << std::endl
              << "</svg>" << std::endl;
    return EXIT_SUCCESS;
}