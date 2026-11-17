#include <iostream>

using namespace std;
int main()
{
    char pil = '0';
    while (pil != '8')
    {
        cout << "========Sistem Organ Inti Nirwana========" << endl
             << endl;
        cout << "1. Tambah Energi" << endl;
        cout << "2. Lihat Energi Dalam Antrean" << endl;
        cout << "3. Proses Energi" << endl;
        cout << "4. Lihat Energi Yang Sudah Terserap" << endl;
        cout << "5. Hapus Riwayat Energi teratas" cout << "6. Cari energi Di Organ" << endl;
        cout << "7. Lihat isi organ" << endl;
        cout << "8. Gunakan Energi" << endl;
        cout << "9. Keluar" << endl;
    }
}

struct nodeQueue
{
    int kodeenergi;
    string nama;
    nodeQueue *next;
};

struct nodeStack
{
    int kodeenergi;
    string nama;
    nodeStack *next;
};

struct nodeTree
{
    int kodeenergi;
    string nama;
    nodeTree *kiri;
    nodeTree *kanan;
};

nodeQueue *front = NULL;
nodeQueue *last = NULL;
nodeStack *top = NULL;
nodeTree *root = NULL;

nodeTree *tambah_tree(nodeTree *akar, int kodeenergi, string nama)
{
    if (akar == NULL)
    {
        return new nodeTree{kodeenergi, nama, NULL, NULL};
    }
    if (kodeenergi < akar->kodeenergi)
    {
        akar->kiri = tambah_tree(akar->kiri, kodeenergi, nama);
    }
    else
    {
        akar->kanan = tambah_tree(akar->kanan, kodeenergi, nama);
    }
    return akar;
}

nodeTree *cari_tree(nodeTree *akar, int kodeenergi)
{
    if (akar == NULL || akar->kodeenergi == kodeenergi)
    {
        return akar;
    }
    if (kodeenergi < akar->kodeenergi)
    {
        return cari_tree(akar->kiri, kodeenergi);
    }
    return cari_tree(akar->kanan, kodeenergi);
}

nodeTree *hapus_tree(nodeTree *akar, int kodeenergi)
{
    if (akar == NULL)
    {
        return NULL;
    }
    if (kodeenergi < akar->kodeenergi)
    {
        akar->kiri = hapus_tree(akar->kiri, kodeenergi);
    }
    else if (kodeenergi > akar->kodeenergi)
    {
        akar->kanan = hapus_tree(akar->kanan, kodeenergi);
    }
    else if (akar->kiri == NULL)
    {
        nodeTree *sisa = akar->kanan;
        delete akar;
        return sisa;
    }
    else if (akar->kanan == NULL)
    {
        nodeTree *sisa = akar->kiri;
        delete akar;
        return sisa;
    }
    else
    {
        nodeTree *pengganti = akar->kanan;
        while (pengganti->kiri != NULL)
        {
            pengganti = pengganti->kiri;
        }
        akar->kodeenergi = pengganti->kodeenergi;
        akar->nama = pengganti->nama;
        akar->kanan = hapus_tree(akar->kanan, pengganti->kodeenergi);
    }
    return akar;
}

void prosesenergi(nodeTree *akar, int &no)
{
    if (akar == NULL)
    {
        return;
    }
    cout << no << ". [" << akar->kodeenergi << "]" << akar->nama << endl;
    no++;
    prosesenergi(akar->kiri, no);
    prosesenergi(akar->kanan, no);
}

void inorder(nodeTree *akar, int &no)
{
    if (akar == NULL)
    {
        return;
    }
    inorder(akar->kiri, no);
    cout << no << ". [" << akar->kodeenergi << ""] " << akar->nama << endl;
    no++;
    inorder(akar->kanan, no);
}

void postorder(nodeTree *akar, int &no)
{
    if (akar == NULL)
    {
        return;
    }
    postorder(akar->kiri, no);
    postorder(akar->kanan, no);
}

void tambah_energi()
{
    int energi;
    string nama;
    cout << "Masukkan kode energi: ";
    cin >> kodeenergi;
    if (cin.fail() || kodeenergi <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Kode energi harus berupa angka lebih dari 0!" << endl
             << endl;
        return;
    }
}
nodeQueue *nb = new nodeQueue{kodenergi, nama, NULL};

cout << "Masukkan energi" << endl
     << endl;
}
