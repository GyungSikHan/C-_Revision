#include <iostream>
using namespace std;

class FileSystemNode
{
public:
	FileSystemNode():name{}{}
	FileSystemNode(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~FileSystemNode(){}
	virtual int GetSize(int cnt = 0) const = 0;
	virtual void Display() = 0;
protected:
	char name[256];
};

class File : public FileSystemNode
{
public:
	File(): size(){}
	File(const char* name, const int size)
		:size(size), FileSystemNode(name){}
	~File(){}
	int GetSize(int cnt = 0) const override
	{
		return size;
	}
	void Display() override
	{
		cout <<"File: " << name << endl;
	}

protected:
	int size;
};

class Folder : public  FileSystemNode
{
public:
	Folder():files{}, count() {}
	Folder(const char* name): FileSystemNode(name), files{}, count()
	{
	}
	int GetSize(int cnt = 0) const override
	{
		if (cnt == count - 1)
			return files[cnt].GetSize();
		
		int sum = this->GetSize(cnt + 1);
		sum += files[cnt].GetSize();

		return sum;
	}
	void Display() override
	{
		cout << "Folder: "<<name << endl;
		for (int i = 0; i < count; ++i)
		{
			files[i].Display();
		}
	}
	void Add(File* file)
	{
		files[count++] = *file;
	}
private:
	File files[10];
	int count;
};

int main()
{
	File f1("doc.txt", 100);
	File f2("image.png", 500);
	Folder folder("MyFolder");
	folder.Add(&f1);
	folder.Add(&f2);
	FileSystemNode* nodes[] = { &f1, &folder };
	for (int i = 0; i < 2; ++i) {
		nodes[i]->Display();
		std::cout << "Size: " << nodes[i]->GetSize() << std::endl;
	}
}