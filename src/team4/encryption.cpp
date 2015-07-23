#include "encryption.h"
#include "UI.h"
#include <string>
#include <sstream>
using namespace std;
using namespace Utilities;

void Encryption::execute()
{	
	string key;
	File* inFile = getFile();
	if(inFile == nullptr)
	{
		return;
	}
	UI::println("Enter a password or phrase.");
	key = UI::readLine();
	encrypt(inFile, &key);
	return;
}

File* Encryption::getFile()
{
	string filename;
	FileSystem& fs = FileSystem::getInstance();
	UI::println("Enter a file to Encrypt/Decrypt:");
	filename = UI::readLine();
	File* file = fs.fLocate(filename);
	if(file == nullptr)
	{
		UI::println("No such file exists.");
	}
	return file;
}

int Encryption::encrypt(File* file, string* key)
{
	string input = file->getContents();
	stringstream outstream;
	for(size_t i = 0; i < input.size(); i++)
	{
		outstream << (char) (input[i] ^ (*key)[i % key->size()]);
	}
	file->setContents(outstream.str());

	return 0;
}
