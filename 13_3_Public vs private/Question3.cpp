#include <iostream>
#include <iterator>
#include <array>
#include <cassert>


class Stack
{
    private:

      	using container_type = std::array<int, 10>;
        using size_type = container_type::size_type;

        container_type m_array{};
        size_type m_next_index;
        

    public:
        void reset()
        {
            m_next_index =0;
        }

        bool push(int z)
        {
            if(m_next_index == m_array.size())
                return false;
            
            m_array[m_next_index++] = z; // set the next free element to the value, then increase m_next
		    return true;
        }

        int& pop()
        {
            assert(m_next_index > 0 && "Can not pop an empty stack");
            return m_array[--m_next_index];
        }

        void print()
        {
            std::cout << "( ";
            for (size_type i{ 0 }; i < m_next_index; ++i)
                std::cout << m_array[i] << ' ';
            
            std::cout << ")\n";      
        }
};




int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}