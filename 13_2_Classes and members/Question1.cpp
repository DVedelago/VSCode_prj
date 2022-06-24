#include <iostream>


class IntPair
{
private:
    /* data */
public:
    int m_a{};
    int m_b{};

    void set(auto usr1, auto usr2)
    {
        m_a = usr1;
        m_b = usr2;
    }

    void print()
    {
        std::cout << "Pair (" << m_a << ',' << m_b << ')' << '\n';
    }
};


int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}