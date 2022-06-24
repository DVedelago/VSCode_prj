#include <iostream>

class Ball 
{
    private:
        std::string m_colour {};
        double m_radius {};
    
    public:
        Ball()
        {
            m_colour = "black";
            m_radius = 10.0;
        }

        Ball(const std::string& str)
        {
            m_colour = str;
        }

        Ball(double r)
        {
            m_radius = r;
        }

        Ball(const std::string& s, double r)
        {
            m_colour = s;
            m_radius = r;
        }

        void printBalls()
        {
            std::cout << "colour: " << m_colour << ", radius: " << m_radius << '\n';
        }
};

int main()
{
	Ball def{};
	def.printBalls();

	Ball blue{ "blue" };
	blue.printBalls();

	Ball twenty{ 20.0 };
	twenty.printBalls();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.printBalls();

	return 0;
}