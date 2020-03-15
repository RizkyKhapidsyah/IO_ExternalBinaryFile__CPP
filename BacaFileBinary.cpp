#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct Mahasiswa
{
	int NIM;
	string Nama;
	string Jurusan;
};

Mahasiswa ambilData(int& Posisi, fstream& fileSaya)
{
	Mahasiswa bufferData;
	
	fileSaya.seekp((Posisi - 1) * sizeof(Mahasiswa));
	fileSaya.read(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));
	
	return bufferData;
}

int main2()
{
	fstream fileSayaX;
	Mahasiswa dataBaca;

	fileSayaX.open("Data.bin", ios::in | ios::binary);
	int PosisiX = 1;
	dataBaca = ambilData(PosisiX, fileSayaX);

	cout << dataBaca.NIM << endl;
	cout << dataBaca.Nama << endl;
	cout << dataBaca.Jurusan << endl;

	fileSayaX.close();

	_getch();
	return 0;
}