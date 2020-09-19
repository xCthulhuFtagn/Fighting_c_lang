#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <malloc.h>
int main()
{
	FILE* in, * out;
	int tmp, sum = 0, i;
	char length = 0, num_symb = 0, str[257], * res;
	in = fopen("vot.txt", "w+");
	out = fopen("buba.bin", "w+b");
	if (in != NULL)
	{
		while (((tmp = fgetc(in)) != 10) && (tmp != EOF)) {
			length++;//symbols
			sum += tmp;
			if (((tmp >= 65) && (tmp <= 90)) || ((tmp >= 97) && (tmp <= 122))) {
				num_symb++;//letters
			}
		}
		fgets(str, 257, in);
		fclose(in);
	}
	for (i = 0; str[i] != '/0'; i++) {}
	res = (char*)malloc((i - 1) * sizeof(char));
	fwrite(&length, sizeof(char), 1, out);
	fwrite(&num_symb, sizeof(char), 1, out);
	fwrite(&sum, sizeof(int), 1, out);
	fwrite(str, sizeof(char), i - 1, out);
	fclose(out);
	out = fopen("buba.bin", "r+b");
	fread(&tmp, sizeof(char), 1, out);
	printf("result is %d\n", tmp);
	fread(&tmp, sizeof(char), 1, out);
	printf("result is %d\n", tmp);
	fread(&tmp, sizeof(int), 1, out);
	printf("result is %d\n", tmp);
	fread(res, sizeof(int), i - 1, out);
	for (tmp = 0; tmp < (i - 1); tmp++) {
		printf("res[%d] is %d\n", tmp, res[tmp]);
	}
	fclose(out);
	return 0;
	free(res);
}
