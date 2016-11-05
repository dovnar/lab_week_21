#include <stdio.h>
#include <iostream>

int main()
{
	char* filePath = "tekst.txt";
	FILE* file = fopen(filePath, "rt"); 
	char* filePath1 = "tekst1.txt";
	FILE* file1 = fopen(filePath1, "wt+"); 
	if (file == nullptr)
	{
		std::cout << "can't open file: " << filePath << std::endl;
		return 1;
	}
	fseek(file, 0, SEEK_END);
	int sizeFile = ftell(file);

	char* buffer = new char[sizeFile];

	int objCount = 0;
	fseek(file, 0, SEEK_SET);
	memset(buffer, 0, sizeFile);
	objCount = fread(buffer, sizeFile, 1, file);
	std::cout << buffer << std::endl;
	for (int i = 0; i < sizeFile; i++)
	{
		fseek(file1, i, SEEK_SET);
		int j = 0;
		char* temp = new char[];
		for ( ; buffer[i+j] != ' '; j++)
		{
			temp[j] = buffer[i + j];
		}
		temp[j] = ' ';
		if (j >= 7)
		{
			fwrite(temp, j, 1, file1);
		}
		delete[] temp;
		i += j;
	}

	fflush(file1);
	int closeResult = fclose(file);	
	if (closeResult == 0)
	{
		file = nullptr;
	}
	closeResult = fclose(file1);	
	if (closeResult == 0)
	{
		file1 = nullptr;
	}
	delete[] buffer;
}

/*Дан текстовый файл. Необходимо создать новый файл, в который переписать 
из исходного файла все слова, состоящие не менее чем из семи букв.*/