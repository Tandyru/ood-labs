#pragma once

class TestOutStream
{
	FILE* fout = nullptr;
	char cout_string_buf[BUFSIZ];
public:
	TestOutStream()
	{
		fout = freopen("NUL", "a", stdout);
		memset(cout_string_buf, '\0', BUFSIZ);
		setvbuf(stdout, cout_string_buf, _IOFBF, BUFSIZ);
	}

	~TestOutStream()
	{
		setvbuf(stdout, nullptr, _IONBF, 2);
		fclose(fout);
	}

	operator const char*() const
	{
		std::cout << '\0';
		fflush(stdout);
		return cout_string_buf;
	}
};