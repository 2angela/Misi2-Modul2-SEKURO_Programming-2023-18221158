# Misi 2 Modul 2 SEKURO 2023

Pada misi 2 modul 2 SEKURO 2023, cakru diminta membuat program untuk mencatat transaksi pelanggan pada warung milik Kang Roger. **Program dibuat dalam bahasa C dan menggunakan library stdio.h, stdlib.h, dan string.h.**

Folder data berisi file .txt yang menyimpan daftar menu.\
Folder doc berisi file dokumentasi dengan format pdf.\
Folder src berisi semua file source code.

Program dimulai dengan menampilkan view Pemilik Toko yang berisi pilihan 1 untuk tutup atau 2 untuk pelanggan masuk. Jika memilih pelanggan masuk, program akan meminta masukan nama pelanggan dan diarahkan ke view Pelanggan. Pada view Pelanggan, ditampilkan pilihan 1 untuk melihat menu, pilihan 2 untuk memesan makanan/minuman, dan pilihan 3 untuk keluar. Pada pilihan 1, ditampilkan daftar menu berisi 10 makanan/minuman, lalu diarahkan kembali view Pelanggan. Pada pilihan 2, program akan meminta masukan angka yaitu ID makanan/minuman yang ingin dipesan dan jumlahnya. Pada pilihan 3, pengguna diarahkan kembali ke view Pemilik Toko. Pada view Pemilik Toko, pilihan 1 (tutup) menampilkan riwayat penjualan dan program memberikan opsi untuk menyimpan riwayat pada sebuah file txt. File riwayat penjualan akan disimpan pada folder data. Setelah itu, program selesai.

Berikut cara compile program di directory 
``Misi2-Modul2-SEKURO_Programming-2023-18221158/src``

gcc main.c console.c menu.c history.c -o main

<p>&nbsp;</p>

***Nama: Angela Geraldine H. P.***\
***NIM: 18221158***
