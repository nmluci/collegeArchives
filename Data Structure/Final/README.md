# SuperMarket Simulator
AKA. SupermarketSim

## Model
    Simulator Supermarket, dimana terdapat modul untuk menangani pembayaran, modul untuk menangani stok barang, dan modul untuk menangani keanggotaan.

## Platform Codebase 
- Github (github.com/nmluci/SupermarketSim)

### Breakdown
- Pembayaran (Payment)
- Inventaris Barang (Inventory)
- Keanggotaan (Membership)
- Main Menu
- Backend (Modular, Error Handling)

## Module + Jobdesk
### **Pembayaran / Payment**
- Menghitung kembalian untuk pelanggan (bila ada)
- Menghitung Jumlah pecahan paling optimal yang diperlukan sebagai kembalian (bila ada)
- Penanganan Error (secara abstrak, selanjutnya dikerjakan oleh **module Backend**)
### **Inventaris Barang / Inventory**
- Memeriksa ketersediaan barang yang diminta pelanggan
- Memberikan informasi mengenai barang yang diminta pelanggan
- Melakukan operasi terhadap barang yang ada dalam database (penambahan, pengurangan)
- Penanganan Error (secara abstrak, selanjutnya dikerjakan oleh **module Backend**)
### **Keanggotaan / Membership**
- Memeriksa status pelanggan dalam database
- Melakukan operasi terhadap pelanggan yang ada dalam database (penambahan, pengurangan)
- Mendata point yang diperoleh pelanggan dan memeriksa nilainya 
- Penanganan Error (secara abstrak, selanjutnya dikerjakan oleh **module Backend**)
### **Backend**
- Menyediakan framework untuk Error Handling
- Menyediakan framework untuk Database (bila diperlukan)
- Menyediakan framework untuk menyambungkan mainmenu dengan modul-modul yang ada
### **Main Menu**
- Menyediakan menu untuk interaksi pelanggan
- Menyediakan informasi yang terkait untuk pelanggan
### **Dokumentasi**
- Membuat file **README** yang secara umum menjelaskan fungsi dan panduan untuk program ini
- Membuat Laporan Final :v




