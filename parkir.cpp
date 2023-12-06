#include <iostream>
#include <string>
using namespace std;

const string username = "Evrilia";
const int password = 123456;

#define MAX 200

struct Kendaraan
{
    string platNomor[MAX];
    string tipeKendaraan[MAX];
    int lamaParkir[MAX];
    int id[MAX];
    int awal = 0, akhir = 0;
} antrean;

void init()
{
    antrean.awal = 0;
    antrean.akhir = 0;
}

bool cekKosong()
{
    return (antrean.akhir == 0);
}

bool parkiranPenuh()
{
    return (antrean.akhir == MAX);
}

void inputData(int jmlKendaraan)
{
    string temp1;
    int temp2, type;
    cin.ignore();
    for (int i = 0; i < jmlKendaraan && antrean.akhir < MAX; i++)
    {
        cout << "Antrean Nomor [" << antrean.akhir + 1 << "]" << endl;
        cout << "Masukkan tipe kendaraan (1 untuk Mobil, 2 untuk Motor): ";
        cin >> type;

        if (type == 1)
            antrean.tipeKendaraan[antrean.akhir] = "Mobil";
        else if (type == 2)
            antrean.tipeKendaraan[antrean.akhir] = "Motor";

        cin.ignore();
        cout << "Masukkan plat nomor: ";
        cin >> temp1;
        cout << "Masukkan lama parkir (jam): ";
        cin >> temp2;

        antrean.platNomor[antrean.akhir] = temp1;
        antrean.id[antrean.akhir] = antrean.akhir;
        antrean.lamaParkir[antrean.akhir] = temp2;
        antrean.akhir++;

        cout << "Berhasil menambahkan data." << endl;
        cout << endl;
    }
}

void cekKendaraan()
{
    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        cout << "Antrean Kendaraan Nomor [" << antrean.id[i] + 1 << "]" << endl;
        cout << "Tipe Kendaraan\t: " << antrean.tipeKendaraan[i] << endl;
        cout << "Plat Nomor\t: " << antrean.platNomor[i] << endl;
        cout << "Lama Parkir\t: " << antrean.lamaParkir[i] << " jam | Biaya: Rp. ";
        cout << (antrean.tipeKendaraan[i] == "Mobil" ? antrean.lamaParkir[i] * 4000 : antrean.lamaParkir[i] * 2000) << endl;
        cout << endl;
    }
}

void kendaraanKeluar(const string &user)
{
    if (cekKosong())
    {
        cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
        return;
    }

    string platKendaraan;
    cout << "Masukkan plat kendaraan yang keluar: ";
    cin.ignore();
    cin >> platKendaraan;

    int index;
    for (index = antrean.awal; index < antrean.akhir; index++)
    {
        if (antrean.platNomor[index] == platKendaraan)
            break;
    }

    if (index == antrean.akhir)
    {
        cout << "Kendaraan dengan plat nomor " << platKendaraan << " tidak ditemukan!" << endl;
        return;
    }

    cout << "Kendaraan dengan plat nomor " << platKendaraan << " berhasil keluar." << endl;

    char pilihan;
    cout << "Apakah Anda ingin mencetak struk? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        cout << "-------------------------------" << endl;
        cout << "         STRUK PARKIR" << endl;
        cout << "-------------------------------" << endl;
        cout << "User           : " << user << endl;
        cout << "Tipe Kendaraan: " << antrean.tipeKendaraan[index] << endl;
        cout << "Plat Nomor     : " << antrean.platNomor[index] << endl;
        cout << "Lama Parkir    : " << antrean.lamaParkir[index] << " jam" << endl;
        cout << "Biaya Parkir   : Rp. " << (antrean.tipeKendaraan[index] == "Mobil" ? antrean.lamaParkir[index] * 4000 : antrean.lamaParkir[index] * 2000) << endl;
        cout << "--------------------------" << endl;
    }

    // Menggeser data kendaraan setelah kendaraan keluar
    for (int i = index; i < antrean.akhir - 1; i++)
    {
        antrean.platNomor[i] = antrean.platNomor[i + 1];
        antrean.tipeKendaraan[i] = antrean.tipeKendaraan[i + 1];
        antrean.lamaParkir[i] = antrean.lamaParkir[i + 1];
        antrean.id[i] = antrean.id[i + 1];
    }
    antrean.akhir--;
}

void sortlamaParkir()
{
    string temp1;
    int temp2;
    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        for (int j = i + 1; j < antrean.akhir; j++)
        {
            if (antrean.lamaParkir[j] < antrean.lamaParkir[i])
            {
                temp1 = antrean.platNomor[i];
                antrean.platNomor[i] = antrean.platNomor[j];
                antrean.platNomor[j] = temp1;

                temp2 = antrean.lamaParkir[i];
                antrean.lamaParkir[i] = antrean.lamaParkir[j];
                antrean.lamaParkir[j] = temp2;
            }
        }
    }
}

void cariKendaraan(string cari)
{
    int ind[MAX];
    int j = 0;
    bool ditemukan = false;

    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        if (antrean.platNomor[i] == cari)
        {
            ind[j] = i;
            j++;
            ditemukan = true;
        }
    }

    if (ditemukan)
    {
        cout << "Plat Nomor Kendaraan " << cari << " Ditemukan" << endl;
        cout << "Data kendaraan yang ditemukan:" << endl;
        for (int k = 0; k < j; k++)
        {
            int index = ind[k];
            cout << "-----------------------------------" << endl;
            cout << "Nomor Plat     : " << antrean.platNomor[index] << endl;
            cout << "Tipe Kendaraan : " << antrean.tipeKendaraan[index] << endl;
            cout << "Lama Parkir    : " << antrean.lamaParkir[index] << " jam" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    else
    {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void clearData()
{
    antrean.akhir = 0;
}

int main()
{
    int jmlKendaraan, pil;
    string cari;
    init();

    cout << "=========================================" << endl;
    cout << " PROGRAM PARKIR TELYUB " << endl;
    cout << "=========================================" << endl;
    cout << "Silahkan Login" << endl;

    int pass;
    string user;
    int coba = 3;

    while (coba > 0)
    {
        cout << "\nUsername : ";
        cin >> user;
        cout << "Password : ";
        cin >> pass;

        if (username == user && password == pass)
        {
            cout << "\nSelamat Bekerja " << user << endl;
            cout << "=========================================" << endl;
            break;
        }
        else
        {
            cout << "Username dan Password Keliru" << endl;
            coba--;
            cout << "\nSisa Kesempatan Login : " << coba << endl;
            if (coba == 0)
            {
                cout << "Akun Anda Terblokir" << endl;
                cout << "=========================================" << endl;
                return 0;
            }
        }
    }

    do
    {
        cout << "------------ .:. Program Parkir Kendaraan .:. -----------" << endl;
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "| Menu:\t\t\t\t\t\t\t|" << endl;
        cout << "| 1. Input Data\t\t\t\t\t\t|" << endl;
        cout << "| 2. View Data\t\t\t\t\t\t|" << endl;
        cout << "| 3. Keluarkan Kendaraan Dari Parkiran\t\t\t|" << endl;
        cout << "| 4. Urutkan Data Lama Parkir\t\t\t\t|" << endl;
        cout << "| 5. Cari Kendaraan (Plat Nomor)\t\t\t|" << endl;
        cout << "| 6. Keluar\t\t\t\t\t\t|" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;

        cout << "Masukan pilihan: ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            if (parkiranPenuh())
            {
                cout << "Parkiran Sudah Penuh!" << endl;
            }
            else
            {
                cout << ".:. Input Data Kendaraan .:." << endl;
                cout << endl;
                cout << "Tipe Kendaraan: " << endl;
                cout << "1. Mobil | Biaya: Rp. 4000 / jam" << endl;
                cout << "2. Motor | Biaya: Rp. 2000 / jam" << endl;
                cout << endl;
                cout << "Masukkan Jumlah Kendaraan: ";
                cin >> jmlKendaraan;
                cout << endl;
                inputData(jmlKendaraan);
            }
            break;
        case 2:
            if (cekKosong())
            {
                cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                cout << "\t.:. Daftar Kendaraan .:." << endl;
                cout << endl;
                cekKendaraan();
            }
            break;
        case 3:
            if (cekKosong())
            {
                cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                kendaraanKeluar(username);
            }
            cekKendaraan();
            break;
        case 4:
            if (cekKosong())
            {
                cout << "Silahkan input Kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                sortlamaParkir();
            }
            cekKendaraan();
            break;
        case 5:
            cout << "Masukan plat kendaraan yang ingin dicari: ";
            cin >> cari;
            cariKendaraan(cari);
            break;
        case 6:
            cout << "Keluar Dari Program..." << endl;
            break;
        default:
            cout << "Masukkan pilihan sesuai di menu!" << endl;
            break;
        }
    } while (pil != 6);

    return 0;
}
