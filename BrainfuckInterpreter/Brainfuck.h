#include <iostream>
#include <vector>
class Brainfuck
{
private :
	 std::vector<char> buf;
	 std::string _word;
	 std::string _interpreted;

public :
	Brainfuck(const std::string& str) : _word(str){
		buf.resize(30000, 0);
		buf.shrink_to_fit();
	}

	void print_buffer() {
		for (auto ch : buf)
			std::cout << ch;
	}


	void interpret() {
		auto word_iter = _word.begin();
		auto const word_iter_end = _word.end();
		auto buf_iter = std::begin(buf);
		size_t brackets = 0;

		for (; word_iter != word_iter_end; ++word_iter) {
			switch (*word_iter) {
			case '>':
				++buf_iter;
				break;
			case '<':
				--buf_iter;
				break;
			case '+':
				(*buf_iter)++;
				break;
			case '-':
				(*buf_iter)--;
				break;
			case '.':
				std::cout << *buf_iter;
				break;
			case ',':
				std::cin >> *buf_iter;
				break;
			case '[':
				if (*buf_iter == 0) {
					++brackets;
					while (brackets != 0)
					{
						++word_iter;
						if ((*word_iter) == '[')
							++brackets;
						else if ((*word_iter) == ']')
							--brackets;
					}
				}
				else
					continue;
				break;
			case ']':
				if (*buf_iter != 0) {
					++brackets;
					while (brackets) {
						--word_iter;
						if ((*word_iter) == '[')
							--brackets;
						else if ((*word_iter) == ']')
							++brackets;
					}
				}
				else
					continue;
				break;
			default:
				std::cout << std::endl << "Bad input : " << *word_iter << std::endl;
				break;
			}
		}
	}
};

