#include <iostream>
#include <cstdint>

using rgb_t = std::uint8_t;

class RGBA
{
private:
    
    rgb_t m_red{};
    rgb_t m_green{};
    rgb_t m_blue{};
    rgb_t m_alpha{};

public:
    RGBA(rgb_t r_val=0, rgb_t g_val=0, rgb_t b_val=0, rgb_t a_val=255) 
        : m_red{r_val}
        , m_green{g_val}
        , m_blue{b_val}
        , m_alpha{a_val}
    {}

    void print()
    {
        std::cout << 
        "r=" << static_cast<int>(m_red) << 
        " g=" << static_cast<int>(m_green) << 
        " b=" << static_cast<int>(m_blue) <<
        " a=" << static_cast<int>(m_alpha) << 
        '\n';
    }

};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}
