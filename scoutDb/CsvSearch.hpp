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
		path = " ";
	size_t fileLen;
	FILE* pFile;
	char fileBuf[16384];

	CsvFile(string fileName, string directory) {
		strcpy(name, fileName);
		strcpy(path, directory);
		strcat(path, fileName);
		pFile = fopen(path, "r");
		pFileBuf = 
	}

	short int findStrInFile(string search, unsigned short int appearCt = 0) {
		unsigned long int pos = 0;
		unsigned short int counter = 0;
		bool bDoesMatch = false;

		while(!feof()) {
			if(sgetc() == search[pos]) {
				bDoesMatch = true;
				for(int i = 0; i < strLen; i++) {
					if(strBuf[i] != search[i]) {
						bDoesMatch = false;
						break; //Stop iterating over substring, no reason to keep searching
					}
				}
			}
			if(bDoesMatch)  {
				if(counter == appearCt) {
					return pos;
				}
				else {
					counter++;
				}
			}
			pos++; //Increment pos variable to match sbumpc()
			sbumpc(); //Advance to next character
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

};



#endif /* CSVSEARCH_HPP_ */
