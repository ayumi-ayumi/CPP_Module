#include "replace.hpp"

int main()
{
	createNewFile("sample.txt", "Tokyo", "Berlin");
}

/*
sample.txt

I am living in Tokyo.
Tokyo is in Germany.
Have you been to Tokyo?


<Permission control>
- No permission to any users
chmod a-r sample.txt

- Give permission to all
chmod a+r sample.txt
*/
