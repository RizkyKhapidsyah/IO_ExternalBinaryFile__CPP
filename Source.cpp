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

Mahasiswa ambilData(int Posisi, fstream& fileSaya)
{
	Mahasiswa bufferData;

	fileSaya.seekp((Posisi - 1) * sizeof(Mahasiswa));
	fileSaya.read(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));

	return bufferData;
}

void menulisData(Mahasiswa& Data, fstream& fileSaya)
{
	fileSaya.write(reinterpret_cast<char*>(&Data), sizeof(Mahasiswa));
}

void menulisDataByPosisi(int Posisi, Mahasiswa& bufferData, fstream& fileSaya)
{
	fileSaya.seekg((Posisi - 1) * sizeof(Mahasiswa));
	fileSaya.write(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));
}

int main()
{
	fstream fileSaya;
	fileSaya.open("Data.bin", ios::trunc | ios::out | ios::in | ios::binary);

	Mahasiswa Mahasiswa1, Mahasiswa2, Mahasiswa3, Output;
	int Input;

	Mahasiswa1.NIM = 1672638;
	Mahasiswa1.Nama = "Rizky Khapidsyah";
	Mahasiswa1.Jurusan = "Ilmu Komputer";

	Mahasiswa2.NIM = 1635243;
	Mahasiswa2.Nama = "Bambang Aditya";
	Mahasiswa2.Jurusan = "Ilmu Komputer";

	Mahasiswa3.NIM = 1677382;
	Mahasiswa3.Nama = "Dwi Pradana";
	Mahasiswa3.Jurusan = "Ilmu Komputer";
	
	/*
	
	fileSaya.write(reinterpret_cast<char*>(&Mahasiswa1), sizeof(Mahasiswa));
	fileSaya.write(reinterpret_cast<char*>(&Mahasiswa2), sizeof(Mahasiswa));
	fileSaya.write(reinterpret_cast<char*>(&Mahasiswa3), sizeof(Mahasiswa));

	atau bisa juga :
	*/

	menulisData(Mahasiswa1, fileSaya);
	menulisData(Mahasiswa2, fileSaya);
	menulisData(Mahasiswa3, fileSaya);

	Mahasiswa1.Jurusan = "Tata Boga";
	menulisDataByPosisi(1, Mahasiswa1, fileSaya);
	
	cout << "Masukkan Index Data Yang Ingin Ditampilkan (1-3)  : ";
	cin >> Input;
	
	if (Input <= 0 || Input > 3)
	{
		cout << "Udah dibilang cuma 1 sampai 3 aja" << endl;
	}
	else
	{
		Output = ambilData(Input, fileSaya);

		cout << "\nData Yang Ditampilkan Adalah :" << endl;
		cout << "=> NIM      : " << Output.NIM << endl;
		cout << "=> Nama     : " << Output.Nama << endl;
		cout << "=> Jurusan  : " << Output.Jurusan << endl;
	}

	fileSaya.close();

	_getch();
	return 0;
}