.data
  matrix: .word 1, 2, 3, 8, 1, 5, 1, 2, 4  # Matrice liniarizată (3x3)
  rows: .word 3                           # Numărul de rânduri
  cols: .word 3                           # Numărul de coloane
  sum: .word 0                            # Variabila pentru suma rezultată

.text
main:
  # Inițializare
  lw $t0, rows             # $t0 <- numărul de rânduri
  lw $t1, cols             # $t1 <- numărul de coloane
  li $t2, 0                # $t2 <- indexul coloanei curente
  li $t3, 0                # $t3 <- suma maximelor

compute_max:
  bge $t2, $t1, save_sum   # Dacă am terminat toate coloanele, sari la salvarea sumei

  # Găsește maximul pe coloana $t2
  li $t4, -2147483648      # $t4 <- maximul curent, inițial -∞ (valoarea minimă pe 32 biți)
  li $t5, 0                # $t5 <- indexul rândului curent

find_max:
  bge $t5, $t0, next_col   # Dacă am terminat toate rândurile, sari la următoarea coloană

  # Calculează indexul elementului curent din matrice
  mul $t6, $t5, $t1        # $t6 <- rând_curent * nr_coloane
  add $t6, $t6, $t2        # $t6 <- index liniarizat pentru matrice
  mul $t6, $t6, 4          # $t6 *= 4 (offset în bytes)
  la $t7, matrix           # $t7 <- adresa bazei matricei
  add $t7, $t7, $t6        # $t7 <- adresa elementului curent
  lw $t8, 0($t7)           # $t8 <- valoarea elementului curent

  # Compară elementul curent cu maximul
  bgt $t8, $t4, update_max # Dacă elementul curent este mai mare, actualizează maximul
  j skip_update

update_max:
  move $t4, $t8            # $t4 <- elementul curent

skip_update:
  addi $t5, $t5, 1         # $t5 += 1 (treci la următorul rând)
  j find_max               # Continuă să cauți maximul

next_col:
  add $t3, $t3, $t4        # Adaugă maximul coloanei curente la sumă
  addi $t2, $t2, 1         # $t2 += 1 (treci la următoarea coloană)
  j compute_max            # Reia calculul pentru următoarea coloană

save_sum:
  sw $t3, sum              # Salvează suma în variabila `sum`

  # Terminare program
  li $v0, 10
  syscall
