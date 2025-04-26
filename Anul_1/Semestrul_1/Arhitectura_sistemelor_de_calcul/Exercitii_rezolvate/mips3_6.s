.data
s:   .word 0          # Variabila s (rezultat pentru primul apel)
s1:  .word 0          # Variabila s1 (rezultat pentru al doilea apel)

.text
.globl main

# Functia aduna
aduna:
    # Salvare registri pentru apel
    addi $sp, $sp, -16      # Alocam spatiu pe stiva
    sw $ra, 12($sp)         # Salvam $ra
    sw $a0, 8($sp)          # Salvam $a0
    sw $a1, 4($sp)          # Salvam $a1

    # Initializare
    move $t0, $a0           # $t0 <- adresa lui a (salvam pointerul)
    move $t1, $a1           # $t1 <- n (numarul de argumente)
    addi $a2, $a2, 0        # Setam $a2 la $a2 (adresa primului argument suplimentar)
    li $t2, 0               # $t2 <- 0 (initializeaza *a la 0)

    # Va_start deja pregatit (folosim $a2 ca punct de plecare)
    li $t3, 0               # $t3 este i (valoarea initiala)

loop_aduna:
    beq $t3, $t1, end_aduna # Daca i == n, iesim din bucla

    lw $t4, 0($a2)          # $t4 <- argumentul curent
    add $t2, $t2, $t4       # *a += argumentul curent
    addi $a2, $a2, 4        # Trecem la urmatorul argument
    addi $t3, $t3, 1        # Incrementam i
    j loop_aduna            # Sarim inapoi la bucla

end_aduna:
    sw $t2, 0($t0)          # Salvam rezultatul in *a

    # Restaurare registri si intoarcere
    lw $ra, 12($sp)         # Restauram $ra
    lw $a0, 8($sp)          # Restauram $a0
    lw $a1, 4($sp)          # Restauram $a1
    addi $sp, $sp, 16       # Eliberam spatiul pe stiva
    jr $ra                  # Intoarcere

# Functia main
main:
    # Apel aduna(&s, 3, 1, 2, 3)
    la $a0, s               # $a0 <- adresa lui s
    li $a1, 3               # $a1 <- 3 (numarul de argumente)
    li $a2, 1               # $a2 <- primul argument
    li $a3, 2               # $a3 <- al doilea argument
    addi $sp, $sp, -4       # Rezervam loc pentru al treilea argument
    li $t0, 3               # $t0 <- al treilea argument
    sw $t0, 0($sp)          # Salvam al treilea argument pe stiva
    jal aduna               # Apelam functia aduna
    addi $sp, $sp, 4        # Eliberam spatiul pentru argument

    # Apel aduna(&s1, 2, 10, 20)
    la $a0, s1              # $a0 <- adresa lui s1
    li $a1, 2               # $a1 <- 2 (numarul de argumente)
    li $a2, 10              # $a2 <- primul argument
    li $a3, 20              # $a3 <- al doilea argument
    jal aduna               # Apelam functia aduna

    # Terminare program
    li $v0, 10              # Cod pentru terminarea programului
    syscall
