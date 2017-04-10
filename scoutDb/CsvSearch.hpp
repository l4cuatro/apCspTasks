/*
 * CsvSearch.hpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Lentil
 */

using namespace std;

#ifndef CSVSEARCH_HPP_
#define CSVSEARCH_HPP_

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>

class CsvFile {
	string name,
		path,
		parseStr;
	size_t fileLen;
	FILE* pFile;
	char fileBuf[16384];

	CsvFile(string fileName, string directory) {
		strcpy(name, fileName);
		strcpy(path, directory);
		strcat(path, fileName);
		pFile = fopen(path, "r");
		fgets(fileBuf, (sizeof(fileBuf) / sizeof(char)), pFile);
	}

	short int findStrInFile(string search, unsigned short int appearCt = 0) {
		unsigned long int searchPos = 0,
			filePos = 0;
		unsigned short int counter = 0;
		bool bDoesMatch = false;

		while(filePos < sizeof(fileBuf) / sizeof(char)) {
			if(fileBuf[filePos] == search[pos]) {
				bDoesMatch = true;
				for(int i = 0; i < (sizeof(fileBuf) / sizeof(char); i++) {
					if(fileBuf[i] != search[i]) {
						bDoesMatch = false;
						break; //Stop iterating over substring, no reason to keep searching
					}
				}
			}
			if(bDoesMatch)  {
				if(counter == appearCt) {
					return filePos;
				}
				else {
					counter++;
				}
			}
			searchPos++; //Read next char
			filePos++;
		}
		return -1;
	}

	unsigned char countChar(char search) {
		unsigned char count = 0;
		while(sgetc() != EOF) {
			if(sgetc() == search)
				count++;
			sbumpc();
		}
		return count;
	}

	unsigned char countChar(char search, unsigned short int startPos, unsigned short int endPos) {
		unsigned char count = 0;
		unsigned int pos = 0;

		for(int i = 0; i < startPos; i++) {
			sbumpc();
			pos++;
		}
		while(sgetc() != EOF && pos <= endPos) {
			if(sgetc() == search)
				count++;
			sbumpc();
		}
		return count;
	}

	unsigned char countStr(string search) {
		unsigned long int searchPos = 0,
			filePos = 0;
		unsigned short int counter = 0;
		bool bDoesMatch = false;

		while(filePos < sizeof(fileBuf) / sizeof(char)) {
			if(fileBuf[filePos] == search[pos]) {
				bDoesMatch = true;
				for(int i = 0; i < (sizeof(fileBuf) / sizeof(char); i++) {
					if(fileBuf[i] != search[i]) {
						bDoesMatch = false;
						break; //Stop iterating over substring, no reason to keep searching
					}
				}
			}
			if(bDoesMatch)
				counter++;
			searchPos++; //Read next char
			filePos++;
		}
		return count;
	}
	
};



#endif /* CSVSEARCH_HPP_ */
