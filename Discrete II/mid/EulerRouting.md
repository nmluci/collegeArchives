NIM. 2008561093


1. Hitung derajat dari tiap vertex yang ada didalam graph
    a. bila semua vertex memiliki derajat genap, pilihlah vertex yang mana saja, yang dimana akan menjadi titik awal
    b. bila ada tepat 2 vertex berderajat ganjil, pilihlah salah satu vertex tersebut, yang dimana akan menjadi titik awal
    c. bila tidak memenuhi salah satu kriteria tersebut, maka tidak ada lintasan euler didalam graph tersebut
2. untuk setiap vertex selanjutnya, piilhlah salah satu vertex yang bersebelahan, lalu hapuskan edge diantaranya, lakukan hal ini sampai tidak ada vertex yang bersebelahan, dan masukkan tiap vertex kedalam stack
3. bila tidak ada yang bersebalah, keluarkan vertex tersebut dari stack, lalu tambahkan kembali edgenya