#include <stdio.h>
#include <string>
#include <cstring>

int main()
{
	std::string str = "ifconfig wlan0 | awk '/inet6 2402:/{print $2}'";
	FILE *fp = popen(str.c_str(), "r");

	if (fp == NULL)
	{
		fprintf(stderr, "unable to open\n");
		return 0;
	}
	//char buffer[1024];
	char *out = nullptr;
	size_t len = 0;
	//fgets(buffer, 1024, fp);
	getline(&out, &len, fp); 

	pclose(fp);

	printf("%s, len = %d, strlen() = %d\n", out, len, strlen(out));

	//delete the \n 
	out[strlen(out) - 1] = 0;
	printf("%s, len = %d, strlen() = %d", out, len, strlen(out));

	free(out);

	return 0;
}
