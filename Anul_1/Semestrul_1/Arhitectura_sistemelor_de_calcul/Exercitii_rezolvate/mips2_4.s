.data
  n: .word 17          # Numărul de verificat (poate fi schimbat)
  x: .byte 0           # Rezultatul: 0 = neprim, 1 = prim
  one: .word 1         # Constanta 1
  two: .word 2         # Constanta 2

.text
main:
  # Inițializare
  lw $t0, n            # $t0 <- n (numărul de verificat)
  li $t1, 2            # $t1 <- 2 (primul divizor de verificat)
  li $t3, 1            # $t3 <- 1 (presupunem că numărul este prim)
  blt $t0, 2, not_prime # Dacă n < 2, nu este prim

check_divisors:
  mul $t2, $t1, $t1    # $t2 <- $t1 * $t1 (verificăm până la sqrt(n))
  bgt $t2, $t0, set_prime # Dacă $t1^2 > n, terminăm verificarea

  # Verificare dacă n este divizibil cu $t1
  div $t4, $t0, $t1    # $t4 <- n / $t1
  mfhi $t5             # $t5 <- restul (modulo)
  beq $t5, 0, not_prime # Dacă restul este 0, n nu este prim

  # Trecem la următorul divizor
  addi $t1, $t1, 1     # $t1 <- $t1 + 1
  j check_divisors     # Reia verificarea

not_prime:
  li $t3, 0            # $t3 <- 0 (n este neprim)

set_prime:
  sb $t3, x            # Salvează rezultatul (1 = prim, 0 = neprim)

  # Termină execuția programului
  li $v0, 10
  syscall
